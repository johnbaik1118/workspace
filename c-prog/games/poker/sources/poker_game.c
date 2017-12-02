#include "../headers/poker.h"

int main(int argc, char** argv)
{
	Deck* deck = newdeck();
	for(int i=0; i < 100; i++) {
		shuffle(deck);
		print_deck(deck);
		printf("=======================[ %d ]======================\n",i);
	}
	
	return 0;
}
