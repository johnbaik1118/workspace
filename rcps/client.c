#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 7777   
#define BUFSIZE 1024
#define SIZE 200

void updateProtocol(char* Buffer);

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servAddr;
    char sendBuffer[BUFSIZE];
   
    if(argc != 2) {
       fprintf(stderr, "Usage: %s IP_address\n", argv[0]);
       exit(1);
    }

 
    if((sockfd=socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
       perror("sock failed");
       exit(1);
    }

    memset(&servAddr, 0, sizeof(servAddr));
   
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(argv[1]);
    servAddr.sin_port = htons(PORT);
	
    sendBuffer[0] = '*'; // header
    sendBuffer[1] = '0'; // sequence
    sendBuffer[2] = '1'; // data
		    
    while(1) {
       printf("Administartor sending message ==> %s\n", sendBuffer);
 
       if(sendto(sockfd, sendBuffer, strlen(sendBuffer), 0, (struct sockaddr*)&servAddr, sizeof(servAddr)) != strlen(sendBuffer)) {
          perror("sendto failed");
          exit(1);
       }

       updateProtocol(sendBuffer);

       usleep(700000);	

     }
    close(sockfd);
    exit(0);
}

void updateProtocol(char* Buffer)
{
	Buffer[0] = '*';
	Buffer[2] = '1';

	if (Buffer[1] == '9')
		Buffer[1] = '0';
	else
		Buffer[1]++;
}

