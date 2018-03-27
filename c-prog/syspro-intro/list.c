#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

typedef struct{
	int size;
	struct node* first_node;
}list;

node* newnode(int n){
	node* temp = (node*)malloc(sizeof(node));
	temp->val=n;
	temp->next=NULL;
	return temp;
}
int isEmpty(list* list){
	return list->size<=0;
}
list* initialize_list(){
    list* flist= (list*)malloc(sizeof(list));
	(flist->size)=0;
	flist->first_node=NULL;
	return flist;
}
node* get_node(list* list, int index)
{
	node* current;
	current=(list->first_node);
	if(current!=NULL){
	    for(int i = 0; i < index; i++)
	    {
		current = current->next;
	    }
	}
	else {printf("get_node ERROR");}
	return current;
}
void appendTo(list* list, node* newnode){
		if(list->first_node==NULL)
		{
			list->first_node=newnode;
			(list->size)++;
		}
		else
		{
			node* temp=get_node(list,list->size-1);
			temp->next=newnode;
			(list->size)++;
		}
		printf("size of list is %d",list->size);
}

void delAt(list *target, int n){
	if(n<0||isEmpty(target)||target->size<n)
		printf("INPUT VALUE ERROR");
	else
	{
		node* temp;
		node *pre_temp;
		temp=get_node(target,n);
		pre_temp=get_node(target,n-1);
		pre_temp->next=get_node(target,n+1);
		free(temp);
		target->size--;
	}
	
}

void print(list *list){
	for(int k = 0; k < list->size;k++){
		printf("%d\n",get_node(list,k)->val);
	}
}

int main(int argc, char const *argv[])
{
	list* linked = initialize_list();
	int i;
	for(i=1;i<6;i++){
		appendTo(linked, newnode(i));
	}
	print(linked);
	delAt(linked, -1);
	delAt(linked,  0);
	print(linked);
	delAt(linked,  3);
	print(linked);
	return 0;
}
