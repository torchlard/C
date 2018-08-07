#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int ElemType;
typedef struct node {
  struct node *next;
  ElemType data; 
} circ;

circ *insert(circ *header, circ *node, ElemType e)
{
  circ *block = (circ *)malloc(sizeof(circ));
  block->data = e;
  block->next = header;
  node->next = block;

  return block;
}

circ* init(){
  int arr[] = {1,2,3,4,5,6};
  circ *header = (circ *)malloc(sizeof(circ));
  header->data = arr[0];
  circ* node = header;

  for(int i=1; i<6; i++){
    node = insert(header, node, arr[i]);
  }
}

void print(circ* node){
  circ* first = node;
  printf("%d ", node->data);
  printf("node: %p ", node);
  printf("next: %p \n", node->next);
  node = node->next;

  while(node != first){
    printf("%d ", node->data);
    printf("node: %p ", node);
    printf("next: %p \n", node->next);
    node = node->next;
  }
  printf("\n");
}

circ* del_prev(circ* node){
  circ* orig = node;
  
  while(node->next->next != orig){
    node = node->next;
  }
  node->next = orig;
  
  return node;
}

void main(){
  puts("-------");
  
  circ* node = init();
  // node = del_prev(node);
  print(node);
  
}











