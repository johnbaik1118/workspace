#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"

// Define 'list' using typedef and struct
typedef struct _stack {
	node *top;
	int size;
} stack;

stack* init_stack();
void push(stack*, node*);
int pop(stack*);
int top(stack*);

int main(int argc, char const *argv[])
{
	stack *s = init_stack();
	int i;
	push(s,newnode(1));
	printf("top : %d\n", top(s));
	pop(s);
	pop(s);
	for (i = 2; i < 6; i++) {
		push(s, newnode(i));
	}
	for (i = 0; i < 3; i++) pop(s);
	printf("top : %d\n", top(s));
	return 0;
}

stack *init_stack()
{	
	stack* tmp_stack = malloc(sizeof(stack));
	tmp_stack->top = NULL;
	tmp_stack->size = 0;
	return tmp_stack;
}

void push(stack* s, node *n)
{	
	if(s->size == 0) s->top = n; 
	else{
		node *cursor = s->top;
		for (int i = 0; i < s->size; i++)
			cursor = cursor->next;
		cursor->next = n;
	}
	s->size++;
	
}

int pop(stack* s)
{
	if (s->size == 0){
		printf("stack is empty");
		return 0;
	}
	node *cursor = s->top->next;
	int popped_val = s->top->val;
	s->top = cursor;
	return popped_val;
}

int top(stack* s)
{
	if (s->size == 0){
		printf("stack is empty");
		return 0;
	}
	node *cursor = s->top;
	return s->top->val;
}



