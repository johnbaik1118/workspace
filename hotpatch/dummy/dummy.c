#include <stdio.h>
#include <unistd.h>

short k = 1;
void dummy2()
{ k = k + 3; }

void dummy(int *i) 
{
	*i = *i + 1;  printf("dummy!");
	dummy2(); sleep(1);
}

void main(void)
{
	
}
