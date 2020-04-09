CC=arm-linux-gnueabihf-gcc

make: client server
	$(CC) -o client UDPEchoClient.c DieWithMessage.c AddressUtility.c
	$(CC) -o server UDPEchoServer.c DieWithMessage.c AddressUtility.c

clean: 
	rm client server
