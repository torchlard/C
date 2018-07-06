#define STACK_SIZE 64

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

LinkStack *top;














