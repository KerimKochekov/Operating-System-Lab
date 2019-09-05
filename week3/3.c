#include "stdio.h"
#include "stdlib.h"

struct node{ 
  int val; 
  struct node *next; 
}; 
void insert_node(struct node* x, int y) {
    if(x==NULL){
		printf("Error, node not found");
        return; 
    } 
    struct node* tmp=(struct node*)malloc(sizeof(struct node)); 
    tmp->val=y; tmp->next=x->next; 
    x->next=tmp; 
}
void delete_node(struct node* x, struct node* y) {
    if(y==NULL){
		printf("Error, node not found");
        return; 
    } 
	while(x->next!=y)
		x=x->next;
	x->next=y->next;
}
void print_list(struct node *x){
	x=x->next;//skipping head
  while(x!=NULL){ 
     printf("%d ",x->val); 
     x=x->next; 
  } 
  puts("");
} 
int main(){ 
  struct node* head=(struct node*)malloc(sizeof(struct node)); 
  head->val=-1;head->next=NULL;
  insert_node(head, 123);
  insert_node(head->next, 46); 
  insert_node(head, 1);
  print_list(head); 
  delete_node(head, head->next);
  print_list(head); 
  return 0; 
} 