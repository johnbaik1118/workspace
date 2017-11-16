#include <stdio.h>

int main(int argc, const char* argv[])
{
	int i = 0, power = 1;

	while (++i <= 10)
		printf("%-6d", power *= 2);
	printf("\n");
	return 0;
}
