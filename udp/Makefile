CC=gcc

make:
	$(CC) -o client UDPEchoClient.c DieWithMessage.c AddressUtility.c
	$(CC) -o server UDPEchoServer.c DieWithMessage.c AddressUtility.c

clean: 
	rm client server
