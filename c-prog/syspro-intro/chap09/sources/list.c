#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"

// Define 'list' using typedef and struct
typedef struct _list {
	node *head;
	int size;
} list;

list *init_list();
void appendTo(list* list, node* newnode);
void delAt(list* list, int n);
void print_list(list* list);

int main(int argc, char const *argv[])
{
	list *linked = init_list();
	int i;
	for (i = 1; i < 6; i++)	appendTo(linked, newnode(i));
	print_list(linked);
	delAt(linked, -1);
	delAt(linked, 1);
	print_list(linked);
	delAt(linked, 3);
	print_list(linked);
	
	return 0;
}

list *init_list()
{
	list* tmp_list = malloc(sizeof(list));
	tmp_list->head = NULL; 
	tmp_list->size = 0;
	return tmp_list;
}

void appendTo(list *list, node *newnode)
{
	if (list->size < 1) {
		list->head = newnode;
	} else {
		node *cursor = list->head;
		for (int i = 0; i < list->size-1; i++)
			cursor = cursor->next;
		cursor->next = newnode;
	}
	list->size++;
}

void delAt(list *list, int n)
{
	if (list->size < 1 || n > ((list->size) - 1) || n < 0) {
		return;
	} else if (n == 0) {
		if (list->size < 2) {
			list->head = NULL;
		} else {
			list->head = list->head->next;
		}	
	} else {
		node *cursor = list->head;
		for (int i = 0; i < n - 1; i++)
			cursor = cursor->next;	
		cursor->next = cursor->next->next;
	}	
	list->size--;
}

void print_list(list *list)
{	
	if (list->size < 1) return;
	node *cursor = list->head;
	while (1) {
		printf("%d ", cursor->val);
		if (cursor->next == NULL) break;
		cursor = cursor->next;
	}
	putchar('\n');
	return;
}
