#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
// test return from head vs stack

typedef struct node {
  int data;
  struct node *next;
} LinkListNode;

LinkListNode *CreateNode(void){
  LinkListNode *p, *Heap, Stack;

  Heap = (LinkListNode *) malloc(sizeof(LinkListNode));
  Heap->data = 6;
  Heap->next = NULL;

  Stack = *Heap;
  // p = &Stack;
  p = Heap;
  
  return p;
}

int main() {

  LinkListNode *xPtr, *yPtr, *p;
  xPtr = (LinkListNode *) malloc(sizeof(LinkListNode));
  xPtr->next = NULL;

  yPtr = (LinkListNode *) malloc(sizeof(LinkListNode));
  yPtr->next = NULL;
  xPtr->data = 6;
  yPtr->data = 8;
  xPtr->next = yPtr;

  printf("xPtr: %p\n", xPtr->next);
  printf("yPtr: %p, %d\n", yPtr, yPtr->data);
  
  return 0;
}





