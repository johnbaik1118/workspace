#include "../headers/poker.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	for(;;) {
		system("clear");
		print_game();
		usleep(100000);
	}
	return 0;
}
