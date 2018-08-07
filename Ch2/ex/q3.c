#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int ElemType;
typedef struct node
{
  struct node *next;
  ElemType data;
} linked;

linked* insert(linked* node, ElemType e)
{
  linked *block = (linked *)malloc(sizeof(linked));
  block->data = e;
  block->next = NULL;
  node->next = block;

  return block;
}

linked* init()
{
  int arr[] = {4,2,56,3,26,95};
  linked *header = (linked *)malloc(sizeof(linked));
  header->next = NULL;
  linked* node = header;

  for (int i = 0; i < 6; i++)
  {
    node = insert(node, arr[i]);
  }

  return header;
}

linked* revert(linked* front, linked* current){
  
  linked* rear = current->next;
  current->next = front;
  if(rear == NULL){
    return current;
  }

  return revert(current, rear);
}

linked* revert_init(linked* head){
  
  linked* node = head->next;
  linked *end = revert(node, node->next);
  
  node->next = NULL;
  head->next = end;

  return head;
}

void show(linked* head){
  linked* node = head->next;

  while(node != NULL){
    printf("%d ", node->data);
    printf("%p\n", node);
    node = node->next;
  }
  printf("\n");
}

void reverse_linear(int* arr, int N){
  int tmp, a=0,b=N;

  while(a<b){
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
    a++;
    b--;
  }
}

void show_linear(int* arr,int N){
  for (int i = 0; i < N; i++)
  {
    printf("%d ", arr[i]);
    printf("%p ", arr[i]);
  }
  printf("\n");
}

void main(){
  puts("---------");

  linked* lin = init();
  show(lin);
  linked* head = revert_init(lin);
  show(head);

  int N=6;
  int arr[] = {1,2,3,4,5,6};
  show_linear(arr, N);
  reverse_linear(arr, N-1);
  show_linear(arr, N);

}








