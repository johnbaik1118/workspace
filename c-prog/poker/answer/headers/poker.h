#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

/* [ Chapter 9: Structures and Unions ]  
 *
 *	Define "typedef struct" of card, deck, and player 
 *	and Appropriate "Data Structure" (just one of stack, queue, linked list)
 *
 *  CARD has 
 *	1) integer of pips 
 *	2) character of suit 
 *	3) bool of flipped or not
 * 	4) pointer which points next card
 *
 *  DECK has
 * 	1) pointer of top card
 * 	2) size indicates how many cards are inside the deck
 * 	
 *  PLAYER has
 *	1) string name
 *	2) pointer of a DECK
 *	3) int account
 *
 *  Functions to create
 *  
 *	1) newcard(-,-): Use malloc
 *
 *	2) newdeck(): Use malloc 
 *	
 * 	3) newplayer(): Use malloc
 *
 *  	4) eject(): only can pop out from the top of the DECK 
 *		    (pop from the bottom is not allowed) 
 *
 *	5) inject(): push a card at the bottom of the DECK
 *
 *	6) shuffle(-): use srand/rand
 */

/* typedef structs to define */
typedef struct Card{
	char suit;		// 1 Bytes
	_Bool flipped;		// 1 Bytes
	int pips; 		// 4 Bytes
	struct Card *next;	// (In 64-bit) 8 Bytes
}CARD;

typedef struct Deck{
	CARD *top;
	int size;
}DECK;

typedef struct PLAYER {
	char* name;
	CARD* c1;
	CARD* c2;
	int account;
}PLAYER;

/* function to complete -----> work in ../sources/poker_comp.c */
CARD* newcard(int,char);
DECK* newdeck();
PLAYER* newplayer(char*,int);
CARD* eject(DECK*);
void inject(DECK*,CARD*);
void shuffle(DECK*);

/* print functions */
void print_card(CARD*);
void print_deck(DECK*);
void print_game();

/* Calculation of scores */
void print_score(PLAYER*, CARD*[5]);

