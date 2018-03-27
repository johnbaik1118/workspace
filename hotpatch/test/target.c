#include <stdio.h>
#include <stdlib.h>

void a(){
	printf("I'm a()\n");
}

void b(){
	printf("I'm b()\n");
}

int main(void) {
	for(;;)	a();
	return 1;
}
