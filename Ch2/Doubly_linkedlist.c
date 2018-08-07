#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node {
  ElemType data;
  struct node *prev;
  struct node *next;
} Doubly_LL;

Doubly_LL* init(ElemType e){
  Doubly_LL *list = (Doubly_LL*) malloc(sizeof(Doubly_LL));
  list->prev = NULL;
  list->next = NULL;
  list->data = e;

  return list;
}

Doubly_LL* insert(Doubly_LL* header, ElemType e){
  Doubly_LL *node = (Doubly_LL *)malloc(sizeof(Doubly_LL));
  node->data = e;
  node->next = NULL;
  node->prev = header;
  header->next = node;

  return node;
}

Doubly_LL* delete(Doubly_LL* header, int k){
  Doubly_LL* node = header;

  for(int i=0; i<k; i++){
    node = node->next;
    if (node == NULL) {
      fprintf(stderr, "%s", "out of range\n");
      return NULL;
    }
  }

  Doubly_LL* right = node->next;
  Doubly_LL* left = node->prev;
  if(right != NULL){
    if (left != NULL)
      right->prev = left; 
    else
      right->prev = NULL;
  }
  if (left != NULL){
    if (right != NULL)
      left->next = right;
    else
      left->next = NULL;
  }

  if(left == NULL) return right;
  return header;
}


void print(Doubly_LL* header){
  Doubly_LL* node;
  node = header;

  while(node != NULL){
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

int main(){
  puts("-----------");
  Doubly_LL *list;
  Doubly_LL *header = init(1);
  list = header;

  int arr[] = {2,3,4,5,6,7};
  for(int i=0; i<5; i++){
    list = insert(list, arr[i]);
  }
  header = delete (header, 0);
  header = delete (header, 4);

  print(header);
  
  return 0;
}






