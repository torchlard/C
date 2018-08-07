#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int ElemType;
typedef struct node
{
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

circ* init(int N)
{
  circ *header = (circ *)malloc(sizeof(circ));
  header->data = 1;
  header->next = header;
  circ *node = header;

  for (int i = 2; i <= N; i++)
  {
    node = insert(header, node, i);
  }

  return header;
}

void print(circ *node)
{
  circ *first = node;
  printf("%d ", node->data);
  node = node->next;

  while (node != first)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

circ* export(circ* prev, circ* node){
  printf("%d ", node->data);
  prev->next = node->next;

  return prev;
}

void josephus(int n, int k){
  circ *head = init(n);
  print(head);

  circ* node = head;
  for (int i = 0; i < n - 1; i++)
  {
    node = node->next;
  }

  while(node->next != node){
    for(int i=0; i<k-1; i++){
      node = node->next;
    }
    node = export(node, node->next);
  }
  printf("%d\n", node->data);
}



void main()
{
  puts("-------");

  josephus(8, 2);
}














