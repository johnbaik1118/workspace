#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>

void PrintSocketAddress(const struct sockaddr *address, FILE *stream) {
	// Test for address and stream
	if (address == NULL || stream == NULL) return;
	void *numericAddress; // Pointer to binary address
	// Buffer to contain result (IPv6 sufficient to hold IPv4)
	char addrBuffer[INET6_ADDRSTRLEN];
	in_port_t port; 	// Port to print
	// Set pointer to address based on address family
	switch (address->sa_family) {
	case AF_INET:
		numericAddress = &((struct sockaddr_in *) address)->sin_addr;
		port = ntohs(((struct sockaddr_in *) address)->sin_port);
		break;
	default:
		fputs("[unknown type]", stream); 	// Unhandled type
		return;
	}
	// Convert binary to printable address
	if (inet_ntop(address->sa_family, numericAddress, addrBuffer, sizeof(addrBuffer)) == NULL)
		fputs("[invalid address]", stream);
	else {
		fprintf(stream, "%s", addrBuffer);
		if(port != 0)
			fprintf(stream, "-%u", port);
	}
}
