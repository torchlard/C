#include <stddef.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node *next;
} LinkListNode;

LinkListNode* initialize_LkList(void) {
  LinkListNode *head;
  head = (LinkListNode*) malloc(sizeof(LinkListNode));
  if(head == NULL) exit(0);
  head->next = NULL;
  return head;
}

int main(){
  LinkListNode x,y,*p;

  x.data = 6;
  x.next = NULL;
  y.data = 8;
  y.next = NULL;

  p = &y;
  x.next = p;

  printf("&x: %p\n", &x);
  printf("&y: %p\n", &y);
  printf("x.next: %p\n", x.next);

  return 0;  
  
}

