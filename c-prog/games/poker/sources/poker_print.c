#include "../headers/poker.h"

void print_card(Card* _card)
{
	/************************************/
	int pips 	= _card->pips;
	char suit 	= _card->suit;
	char pips_printformat = 0;
	/************************************/
	char* color;
	char* shape;
	/************************************/
	switch (suit) {
		case 0: 
			color = BOLDRED;
			shape = HEART; 
			break;
		case 1:
			color = RED;
			shape = SPADE;
			break;
		case 2:
			color = BOLDBLUE;
			shape = CLUB;
			break;
		case 3:
			color = BLUE;
			shape = DIAMOND;
			break;
		default:
			break;
	}
	switch (pips) {
		case 2: pips_printformat = '2'; break;
		case 3: pips_printformat = '3'; break;
		case 4: pips_printformat = '4'; break;
		case 5: pips_printformat = '5'; break;
		case 6: pips_printformat = '6'; break;
		case 7: pips_printformat = '7'; break;
		case 8: pips_printformat = '8'; break;
		case 9: pips_printformat = '9'; break;
		case 10: pips_printformat = 'X'; break;
		case 11: pips_printformat = 'J'; break;
		case 12: pips_printformat = 'Q'; break;
		case 13: pips_printformat = 'K'; break;
		case 14: pips_printformat = 'A'; break;
		default: break;
	}
	/************************************/
	printf(
		"%s┏━━━━━┓\n"
		"┃%s    ┃\n"
		"┃  %c  ┃\n"
		"┃    %s┃\n"
		"┗━━━━━┛"RESET"\n",
		color,shape,pips_printformat,shape
	);
	return;
}

void print_deck(Deck* deck) {
	Card* cursor = deck->top;
	for(int i = 0; i < deck->size; i++){
		print_card(cursor);
		cursor = cursor->next;
	}
	return;
}
