#include <stdio.h>

int main(int argc, const char* argv[])
{
	int a, b, sum;
	
	printf("Input two integers : ");
	scanf("%d%d", &a, &b);
	sum = a + b;
	printf("%d + %d = %d\n", a, b, sum);
	return 0;
}
