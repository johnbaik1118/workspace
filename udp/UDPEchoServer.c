#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include "Practical.h"

int main(int argc, char *argv[])
{
	if(argc != 2) // 명령어 행의 인자 개수가 알맞은지 확인
		DieWithUserMessage("Parameter(s)", "<Server Port/Service>");

	char *service = argv[1]; 	// 첫 번째 인자: 지역 포트/서비스 이름

	for(;;){
		printf("server socket() start\n");
		// 서버 주소 구조체 생성
		struct addrinfo addrCriteria;				// 원하는 주소 기준 설정
		memset(&addrCriteria, 0, sizeof(addrCriteria));		// 구조체를 0으로 초기화
		addrCriteria.ai_family = AF_UNSPEC;			// IPv4, IPv6 모두 반환
		addrCriteria.ai_flags = AI_PASSIVE;			// 주소/포트에 무관하게 반환
		addrCriteria.ai_socktype = SOCK_DGRAM;			// 에이터그램 소켓만 반환
		addrCriteria.ai_protocol = IPPROTO_UDP;			// UDP만 반환

		
		struct addrinfo *servAddr;				// 서버 주소 리스트
		int rtnVal = getaddrinfo(NULL, service, &addrCriteria, &servAddr);
		if(rtnVal != 0) DieWithUserMessage("getaddrinfo() failed", gai_strerror(rtnVal));
	
		// 들어오는 연결을 처리하기 위한 소켓 생성
		int sock = socket(servAddr->ai_family, servAddr->ai_socktype, servAddr->ai_protocol);
		if(sock < 0) DieWithSystemMessage("socket() failed!");

		  /* setsockopt: Handy debugging trick that lets 
		   * us rerun the server immediately after we kill it; 
		   * otherwise we have to wait about 20 secs. 
		   * Eliminates "ERROR on binding: Address already in use" error. 
		   */
		int optval = 1;
		setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,
			(const void *)&optval , sizeof(int));

		// 지역 주소에 바인드
		if(bind(sock, servAddr->ai_addr, servAddr->ai_addrlen) < 0)
			DieWithSystemMessage("bind() failed");
		
		// getaddrinfo()에 의해 할당된 주소 리스트의 메모리 반환
		freeaddrinfo(servAddr);

		printf("freed address\n");
		
		struct sockaddr_storage clntAddr;	// 클라이언트 주소
		// 클라이언트 주소 구조체 길이 설정(입출력 파라미터)
		socklen_t clntAddrLen = sizeof(clntAddr);
		// 클라이언트의 메시지를 받을 때까지 대기(block)
		char buffer[MAXSTRINGLENGTH]; 		// 입출력 버퍼
		// 수신 메시지의 크기
		ssize_t numBytesRcvd = recvfrom(sock, buffer, MAXSTRINGLENGTH, 0, (struct sockaddr*) &clntAddr, &clntAddrLen);
		printf("recv from success()\n");
		if(numBytesRcvd < 0) DieWithSystemMessage("recvfrom() failed");
		
		fputs("Handling client ", stdout);
		PrintSocketAddress((struct sockaddr *) &clntAddr, stdout);
		fputc('\n',stdout);
	
		// 수신 데이터그램을 클라이언트에게 돌려 보냄
		ssize_t numBytesSent = sendto(sock, buffer, numBytesRcvd, 0, (struct sockaddr *) &clntAddr, sizeof(clntAddr));
		if(numBytesSent < 0 ) DieWithSystemMessage("sendto() failed");
		else if(numBytesSent != numBytesRcvd) DieWithUserMessage("sendto()", "sent unexpected number of bytes");
		close(sock);
	}
}
