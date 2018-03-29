#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <sys/syscall.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <wait.h>
#include <assert.h>
#include <signal.h>
#include <sched.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <libgen.h>
#include <errno.h>

#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY_NUM     		9529
#define MEM_SIZE    		1024
#define MAX_THREADS  		1024
#define PTRACE_EVENT_STOP  	7
#define BUF_SIZE 		1024

int main(int argc, char *argv[])
{
  int child = -1, status, i;
  int   shm_id, fd, code_size;
  void *shm_addr;
  void *t_addr;
  long target_addr = 0;
  char buf[BUF_SIZE];
  char trampoline[12];
  int kn;

  union u {
    void *val;
    unsigned char chars[long_size];
  } data;

  kn = atoi(argv[4]);								// 공유메모리 접근번호인데, 사용자가 임의로 지정한다. 지금의 경우는 pid + 1.
  printf("%d\n", kn);
  if ( -1 == ( shm_id = shmget( (key_t)kn, MEM_SIZE, IPC_CREAT|0777))) {	//  IPC_CREAT: 커널 안에 존재하지 않는다면 세그먼트를 만든다.
      printf( "공유 메모리 생성 실패\n");
      return -1;
  }
  if ( ( void *)-1 == ( shm_addr = shmat( shm_id, ( void *)0, 0))) {		//  공유메모리를 사용하는 방법. 이 함수를 사용하면 함수 내에서 사용할 수 있는 주소를 반환해준다.
      printf( "공유 메모리 첨부 실패\n");
      return -1;
  } 
  child = atoi(argv[1]);							//  타켓 어플리케이션의 pid
  target_addr = strtol(argv[2], NULL, 0);					//  핫패칭 트렘플린 코드를 삽입하려는 타겟 함수의 주소    

  seize_process(child);								//  해당 어플리케이션의 권한을 가져온다. 모든 Thread의 메모리 공간 접근 및 수정 가능
  f_shared_memory(child, shm_id);						//  타겟 어플리케이션에 공유메모리를 강제로 삽입

  //open patch image  
  fd = open(argv[3], O_RDONLY);					
  code_size = read(fd, buf, BUF_SIZE);
  memcpy(shm_addr, buf, code_size);

  // generate trampoline code
  data.val = target_address;
  trampoline[0] = 0x48;								//  MOVABS $(공유메모리주소), RAX  *산술연산에 사용되는 레지스터	
  trampoline[1] = 0xb8;
  for (i = 0; i < 8; i++)							//  공유메모리 주소를 복사하는 부분이다. f_shared_memory() 함수를 통해 data.chars에 공유메모리 주소가 들어가게 된다.
    trampoline[i+2] = data.chars[i];
  trampoline[10] = 0xff;							//  JMP *$RAX
  trampoline[11] = 0xe0;
  
  // inject trampoline
  for (i = 0; i < nr_threads; i++) {
      assert(!ptrace(PTRACE_INTERRUPT, tids[i], NULL, NULL));			//  타겟 어플리케이션의 모든 쓰레드 인터럽트를 걸어서 멈춘다.
      putdata(tids[i], target_addr,trampoline, 12);				//  위에서 발생시킨 트램플린 코드를 각 프로세스에 넣는다. 삽입하는 타겟 주소는 
      assert(!ptrace(PTRACE_CONT, tids[i], NULL, NULL));			//  타겟 어플리케이션을 계속해서 실행한다.
  }
  return 0;
}
