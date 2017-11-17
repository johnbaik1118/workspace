#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 7777   
#define BUFSIZE 1024
#define SIZE 200

char recvHeader(void);

int main()
{
    int sockfd;
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    char recvBuffer[BUFSIZE];
    char check;
    int clntLen;
    int recvLen;
    int counter=0;
    /* john added */
    int len = 20;
    char buffer[len];

    printf("AF_INET = %s\n", inet_ntop(AF_INET, &(servAddr.sin_addr), buffer, len) );
 
    if((sockfd=socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
       perror("sock failed");
       exit(1);
    }else{
       printf("sock success\n");

  
    memset(&servAddr, 0, sizeof(servAddr));

    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
       perror("bind failed");
       exit(1);
    }


    while(1) {
       clntLen = sizeof(clntAddr);
       
       if((recvLen=recvfrom(sockfd, recvBuffer, BUFSIZE-1, 0, (struct sockaddr*)&clntAddr, &clntLen)) == -1) {
          perror("recvfrom failed");
          exit(1);
       }
       recvBuffer[recvLen] = '\0';            
/*       if (counter == 0 || (check + 1 == recvBuffer[1] && recvHeader()==recvBuffer[0])){
		   check = recvBuffer[1];
		   if (check == '9')
			   check = '0'-1;
		   
		   printf("Train recevied: %s\n", recvBuffer);
		   printf("Seq:%c, Data:%c \n", recvBuffer[1], recvBuffer[2]);
		   counter++; 
       }
*/
       printf("%s\n", recvBuffer);
    }
 }
    return 0;
}


char recvHeader(void)
{
	static char header = '*';
	return header;
}

