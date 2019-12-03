#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

typedef struct node
{
  int number;
  struct node *p_next;
} NODE;

void AddNumber(NODE **pp_head, NODE **pp_tail, int data)
{
  if (*pp_head != NULL) {
    (*pp_tail)->p_next = (NODE *) malloc (sizeof(NODE));
    *pp_tail = (*pp_tail)->p_next;
  }else{
    *pp_head = (NODE*) malloc(sizeof(NODE));
    *pp_tail = *pp_head;
  }
  (*pp_tail) -> number = data;
  (*pp_tail) -> p_next = NULL;
}

void main()
{
  NODE *p_head = NULL, *p_tail = NULL, *p;
  int sum = 0, temp;
  int cnt = 0, suc = 0;
  
  srand(time(NULL)); 

  while(cnt < 1000) {
    AddNumber(&p_head, &p_tail, 1);
    if(rand()%10==1) malloc(sizeof(char));
    if(p_head == NULL) printf("p_head is null\n");
    cnt++;
  }
  p = p_head;
  struct node *ptr;
  while(p!= NULL){
    ptr = p -> p_next;
    p = p -> p_next;
    if(p->p_next == NULL) break;
    if((p->p_next-ptr) != 2) {
      suc++;
    }
  }
  printf("successive count: %d\n", suc);

  while(p_head != NULL) {
    p = p_head;
    p_head = p_head -> p_next;
    free(p);
  }
  p_tail = p_head;
}
