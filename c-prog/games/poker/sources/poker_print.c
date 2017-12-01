#include "../headers/poker.h"

void print_card(card* _card)
{
	/************************************/
	char pips 	= _card->pips;
	char suit 	= _card->suit;
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
	/************************************/
	printf(
		"%s"
		"┏━━━━━┓\n"
		"┃%s    ┃\n"
		"┃  %c  ┃\n"
		"┃    %s┃\n"
		"┗━━━━━┛\n"
		RESET,
		color, shape, pips, shape
     	);
	return;
}

void print_game()
{
	printf(
		"================================ THE POKER GAME ================================\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"=                                                                              =\n"
		"================================ THE POKER GAME ================================\n"
	);	
	return;
}

