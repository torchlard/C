#include <stdlib.h>
#include <stdio.h>
#define m 60

typedef int datatype;
typedef struct stack {
  int top[2];
  datatype stack[m];
} Double_Stack;

Double_Stack* init(){
  Double_Stack* stack = (Double_Stack*)malloc(sizeof(Double_Stack));

  stack->top[0] = -1;
  stack->top[1] = m;

  return stack;
}

int isEmpty(Double_Stack* sq, int k){
  if (k == 0 && sq->top[0]==-1 || k==1 && sq->top[1]==m)
    return 1;
  return 0;
}

int isFull(Double_Stack* sq){
  if(sq->top[0]+1 == sq->top[1])
    return 1;
  return 0;
}

void insert(Double_Stack* sq, datatype e, int k){
  if(isFull(sq)){
    puts("already full");
    return;
  }
    
  if(k == 0){
    sq->top[0]++;
    sq->stack[sq->top[0]] = e;
  } else if (k==1){
    sq->top[1]--;
    sq->stack[sq->top[1]] = e;
  }
  else {
    puts("k either 0/1.");
  }
}

void delete(Double_Stack* sq, int k){
  if (k != 0 & k != 1){
    puts("k either 0/1.");
    return;
  }

  if(isEmpty(sq,k)) {
    puts("already empty!");
    return;
  }

  if (k == 0){
    sq->top[0]--;
  } else if (k==1){
    sq->top[1]++;
  }
}

void print(Double_Stack* sq){
  int a=sq->top[0], b=sq->top[1];
  printf("top[0]: ");
  while(a >= 0){
    printf("%d ", sq->stack[a]);
    a--;
  }
  puts("");

  printf("top[1]: ");
  while (b < m)
  {
    printf("%d ", sq->stack[b]);
    b++;
  }
  puts("");
}

void main(){
  puts("=======");
  Double_Stack* stack = init();

  printf("%d\n", isFull(stack));
  printf("%d\n", isEmpty(stack,1));
  insert(stack, 1, 0);
  insert(stack, 2, 0);
  insert(stack, 3, 1);
  insert(stack, 4, 1);
  insert(stack, 5, 1);
  delete(stack, 1);

  print(stack);
}











