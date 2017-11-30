#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include "Practical.h"

int main(int argc, char *argv[]) {
	if (argc < 3 || argc > 4) // 명령어 행 인자의 개수가 알맞은지 확인
		DieWithUserMessage("Parameter(s)",
			"<Server Address/Name> <Echo Word> [<Server Port/Service>]");

	char *server = argv[1];		// 첫 번째 인자: 서버의 주소/이름
	char *echoString = argv[2];	// 두 번째 인자: 에코 문자열

	size_t echoStringLen = strlen(echoString);
	if (echoStringLen > MAXSTRINGLENGTH)	// 일력 문자열의 길이 확인
		DieWithUserMessage(echoString, "string too long");
	
	// 세 번째 인자(옵션): 서버 포트/서비스 이름
	char *servPort = (argc == 4) ? argv[3] : "echo";

	// 어떤 형태의 주소를 원하는지 시스템에 알림
	struct addrinfo addrCriteria;		// 원하는 주소 기준 설정
	memset(&addrCriteria, 0 ,sizeof(addrCriteria));	// 구조체를 0으로 초기화
	addrCriteria.ai_family = AF_UNSPEC;		// IPv4, IPv6 모두 반환
	// 아래 필드의 경우, 0을 사용하면 종류에 상관 없이 반환
	addrCriteria.ai_socktype = SOCK_DGRAM;		// 데이터그램 소켓만 반환
	addrCriteria.ai_protocol = IPPROTO_UDP;		// TCP만 반환

	// 주소(들) 획득
	struct addrinfo *servAddr;			// 서버 주소의 리스트
	int rtnVal = getaddrinfo(server, servPort, &addrCriteria, &servAddr);
	if (rtnVal != 0)
		DieWithUserMessage("getaddrinfo() failed", gai_strerror(rtnVal));

	// 데이터그램/UDP 소켓 생성
	int sock = socket(servAddr->ai_family, servAddr->ai_socktype,
		servAddr->ai_protocol);			// 클라이언트 소켓 식별자
	if (sock < 0)
		DieWithSystemMessage("socket() failed");
		
	// 문자열을 서버로 전송
	ssize_t numBytes = sendto(sock, echoString, echoStringLen, 0,
		servAddr->ai_addr, servAddr->ai_addrlen);
	if (numBytes < 0)
		DieWithSystemMessage("sendto() failed");
	else if (numBytes != echoStringLen)
		DieWithUserMessage("sendto() error", "sent unexpected number of bytes");
	
	// 응답을 수신

	struct sockaddr_storage fromAddr;		// 서버의 주소
	// 원격지 주소를 저장할 구조체의 길이 설정(입출력 파라미터)
	socklen_t fromAddrLen = sizeof(fromAddr);
	char buffer[MAXSTRINGLENGTH + 1];		// 입출력 버퍼
	numBytes = recvfrom(sock, buffer, MAXSTRINGLENGTH, 0,
		(struct sockaddr *) &fromAddr, &fromAddrLen);
	if (numBytes < 0)
		DieWithSystemMessage("recvfrom() failed");
	else if (numBytes != echoStringLen)
		DieWithUserMessage("recvfrom() error", "received unexpected number of bytes");

	// 서버로부터 온 데이터인지 확인
	if (!SockAddrsEqual(servAddr->ai_addr, (struct sockaddr *) &fromAddr))
		DieWithUserMessage("recvfrom()", "received a packet from unknown source");

	freeaddrinfo(servAddr);

	buffer[echoStringLen] = '\0';		// 수신한 데이터에 null 추가
	printf("Received: %s\n", buffer);	// 수신한 에코 문자열을 출력
	
	close(sock);
	exit(0);
}
