#include "../headers/poker.h"

int main(int argc, char** argv)
{
	Deck* deck = newdeck();
	for(int i=0; i < 100000; i++) {
		shuffle(deck);
		print_deck(deck);
		printf("==============================================\n");
	}
	
	return 0;
}
