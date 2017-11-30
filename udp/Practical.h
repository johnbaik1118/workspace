#ifndef PRACTICAL_H_
#define PRACTICAL_H_

#include <stdbool.h>
#include <stdio.h>
#include <sys/socket.h>

void DieWithUserMessage(const char *msg, const char *detail);
void DieWithSystemMessage(const char *msg);
void PrintSocketAddress(const struct sockaddr *address, FILE *stream);
bool SockAddrsEqual(const struct sockaddr *, const struct sockaddr *);

enum sizeConstants {
	MAXSTRINGLENGTH = 128,
	BUSIZE = 512,
};

#endif
