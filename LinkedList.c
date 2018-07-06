#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// define LinkedList data structure
typedef struct node {
  ElemType data;
  struct node *next;
} LinkListNode;

LinkListNode* initialize_LkList(void) {
  LinkListNode *head;
  head = (LinkListNode*) malloc(sizeof(LinkListNode));
  if(head == NULL) exit(0);
  head->next = NULL;
  return head;
}

LinkListNode *Create_Rear_LkList(ElemType a[], int n){
  LinkListNode *head, *p, *q;
  int i;

  head = (LinkListNode *) malloc(sizeof(LinkListNode));
  q = head;

  printf("head: %p\n", head);
  for(i=0; i<n; i++){
    // apply new memory
    p = (LinkListNode *) malloc(sizeof(LinkListNode));
    p->data = a[i];
    q->next = p;

    printf("%p, %d %p\n",q, p->data, q->next);
    q = p;  // move to next node p, q as current node

  }
  p->next = NULL;

  printf("head->next: %p\n", head->next);

  return head;

}

LinkListNode *Create_Front_LkList(ElemType a[], int n){
  LinkListNode *head, *p;
  int i;

  head = (LinkListNode *) malloc(sizeof(LinkListNode));
  head->next = NULL;

  // printf("%p, %d\n", tail, tail->data);
  for(i=n-1; i>=0; i--){
    p = (LinkListNode *) malloc(sizeof(LinkListNode));
    p->data = a[i];
    p->next = head->next;
    head->next = p; //continue renew head position, only update 'next'

    printf("%p, %d %p\n", p, p->data, p->next);
  }

  return head;
}

// insert a at index k
int Insert_LkList(LinkListNode* header , ElemType a, int k) {
  LinkListNode *q, *p;

  if(k < 0) return 0;

  if (k == 0) q = header;
  else {
    q = header->next;
    for(int i=1; i<k; i++){
      // if over range, exit
      if(q->next == NULL) return 0;
      q = q->next;
    }
  }

  printf("current q: %d\n", q->data);
  p = (LinkListNode *) malloc(sizeof(LinkListNode));
  p->data = a;
  p->next = q->next;
  q->next = p;

  return 1;
}

int Delete_LkLis(LinkListNode* header, int k){
  LinkListNode *q;

  if (k<0) return 0;
  if (k == 0) q = header;
  else {
    q = header->next;
    for(int i=1; i<k; i++){
      // if over range, exit
      if(q->next == NULL) return 0;
      q = q->next;
    }
  }

  q->next = q->next->next;
  return 1;
}

void show_LkList(LinkListNode* head){
  LinkListNode* node;

  node = head->next;
  printf("------------\n");
  while(node != NULL) {
    printf("%d ", node->data );
    node = node->next;
    
  }
  puts(""); 

}

void PrintReverse(LinkListNode* L){
  if(L->next != NULL) PrintReverse(L->next);
  printf("%d ", L->data);
}



int main(){

  LinkListNode *header;
  
  int array[] = {9, 5, 4, 7, 2, 8};
  header = Create_Rear_LkList(array, 6);
  // LinkListNode* node = Create_Front_LkList(array, 1);

  // show_LkList(header);
  // // int res = Insert_LkList(header, 18, 8);
  // int res = Delete_LkLis(header, 5);
  // printf("success: %d\n", res);

  // show_LkList(header);

  PrintReverse(header->next);
  puts("");
  

  return 0;  
  
}

