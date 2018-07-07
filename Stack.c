#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define STACK_SIZE 6

typedef int datatype; 

typedef struct Stack {
  datatype stack[STACK_SIZE];
  int top;
} SeqStack;

typedef struct {
  datatype stack[STACK_SIZE];
  int top1, top2;
} DSegStack;

typedef struct node {
  datatype data;
  struct node *next;
} LinkStack;


void InitStack(SeqStack *s){
  s->top = -1;
}

// void InitLStack(){
//   *top = -1;
// }

SeqStack* push(SeqStack* s, datatype x){
  if (s->top != STACK_SIZE-1) {
    s->top++;
    s->stack[s->top] = x;
  }
  
  return s;
}

SeqStack* pop(SeqStack *s, datatype *x ){
  if (s->top != -1) {
    *x = s->stack[s->top];
    s->top --;
  }
  return s;
  
}

LinkStack *pushLStack(LinkStack *top, datatype x){
  LinkStack *p;
  p = malloc(sizeof(LinkStack));
  p->data = x;
  p->next = top; // next point to lower stack
  top = p;
  return top;
}

LinkStack* popLStack(LinkStack *top){
  if(top->next != NULL) {
    datatype x = top->data;
    LinkStack *p = top;
    top = top->next;
    free(p);
  }

  return top;
}

int showStack(SeqStack *s){
  if (s->top == -1) return 0;
  for(int i=s->top; i>=0; i--){
    printf("%d ", s->stack[i]);
  }
  puts("");
  return 1;
}

void showLStack(LinkStack *top){
  while(top->next != NULL){
    printf("%d ", top->data);
    top = top->next;
  }
  puts("");
}

void conversion(SeqStack *s, int n){
  int p, target=8;
  int e;
  p = n;
  do {
    s = push(s, p % target);
    p = p/target;
  } while (p > 0);

  showStack(s);
  // while(!s->top == -1){
  //   s = pop(s, &e);
  //   printf("%d\n", e);
  // }
  puts("");
}


int main(){
  SeqStack* sa = malloc(sizeof(SeqStack));

  // LinkStack *top = malloc(sizeof(LinkStack));
  // top->next = NULL;

  InitStack(sa);
  conversion(sa, 1348);

  /** Seq Stack */
  // pass by value
  // InitStack(&sa);
  // sa = push(sa, 7);
  // sa = push(sa, 8);
  // sa = push(sa, 4);
  // sa = push(sa, 2);
  // sa = pop(sa, x);
  // printf("top: %d\n", sa.top);
  // showStack(&sa);

  /** Linked Stack */
  // top = pushLStack(top, 7);
  // top = pushLStack(top, 8);
  // top = pushLStack(top, 3);
  // top = pushLStack(top, 5);
  // top = popLStack(top);
  // top = popLStack(top);
  // showLStack(top);
  
  return 0;
}










