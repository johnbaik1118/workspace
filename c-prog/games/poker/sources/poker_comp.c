#include "../headers/poker.h"

/* [ Chapter 9: Structures and Unions ]  
 *
 *  Functions to create
 *  
 *	1) newcard(-,-): Use malloc
 *
 *	2) newdeck(): Use malloc 
 *	
 * 	3) newplayer(): Use malloc
 *
 *  	4) eject(): only can pop out from the top of the Deck 
 *		    (pop from the bottom is not allowed) 
 *
 *	5) inject(): push a card at the bottom of the Deck
 *
 *	6) shuffle(-): use srand/rand
 */

/* function to complete */
Card* newcard(int _pips,char _suit){
	Card* card = (Card*)malloc(sizeof(Card));
	card->pips = _pips;
	card->suit = _suit;
	card->flipped = 0;
	card->next = NULL;
	return card;	
}
	
Deck* newdeck(){
	Deck* deck = (Deck*)malloc(sizeof(Deck));
	deck->top=NULL;
	deck->size=0;

	Card* cursor;	
	for(char s = 0; s <= 3; s++) {
		for(int p = 2; p <= 14; p++) {
			if(deck->top == NULL) { 
				deck->top = newcard(p,s);
				cursor = deck->top;
			} else {
				cursor->next = newcard(p,s);
				cursor = cursor->next;
				print_card(cursor);
				
			} deck->size++;
		}
	}
	return deck;
}

Player* newplayer(char* _name,Deck* _deck,int _account){
	Player* player = (Player*)malloc(sizeof(Player));
	player->name = _name;
	player->deck = _deck;
	player->account = _account;
	return player;
}

Card* eject(Deck* deck) {
	Card* temp = deck->top;
	if(deck->top == NULL){
		printf("error failed!\n");
		return temp;
	}
	deck->top = deck->top->next;
	deck->size--;
	return temp;
}

void shuffle(Deck* deck){
	Deck* temp = (Deck*)malloc(sizeof(Deck));	/* 분리하는 섞음 카드 뭉치를 임시 저장하는 공간이다. */

	srand(clock()); 	/* time(NULL) 보다 훨씬 빠른 주기로 시드를 변경한다. 프로그램이 실행된 이후 얼만큼의 cpu clock tick이 경과했는지 측정한다. */

	unsigned char index = rand()%(deck->size);
	
	Card *cursor_a, *cursor_b, *cursor_c;
	cursor_a = deck->top;
	for(int i = 0; i < index-1; i++) {
		cursor_a = cursor_a->next;
	}
	cursor_c = cursor_a;
	cursor_a = cursor_a->next;
	cursor_c->next = NULL;
	cursor_b = cursor_a;
	while(cursor_b->next != NULL) cursor_b = cursor_b->next;
	cursor_b->next = deck->top;
	deck->top = cursor_a;
	
	/*
	unsigned char endex = rand()%(deck->size - index);
	printf("shuffle index: %u, endex: %u\n",index,endex);
		
	Card* cursor = deck->top;
	Card* sep_a = 
	for(int i = 0; i < index; i++) { 		// 섞음 뭉치를 분리할 index를 찾아간다. 
		cursor = cursor->next;
	}
	Card* sep_a = 
	temp->top = cursor;
	for(int i = 0; i < endex; i++) {		// 섞음 카드 뭉치를 분리할 endex를 찾아간다.
		cursor = cursor->next;
	}
	*/
	

	free(temp); 		
	return;
}

void freedeck(Deck* deck){  	/* malloc을 해줬던 메모리 영역들에 대하여 free()를 하지 않으면 메모리 문제가 발생하여 런타임 에러가 날 수 있다. */
	return;
}
