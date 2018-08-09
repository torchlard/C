#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define M 32

typedef struct node
{
  int data, level;
  struct node *lchild, *rchild;
} btree;

btree *Q[16];
btree *CreateBTree()
{
  char ch;
  int front = 1, rear = 0;
  btree *root = NULL, *s;

  // char str[] = "ABCDEF";
  int str[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i = 0; i < 10; i++)
  {
    ch = str[i];
    s = NULL;
    if (ch != '@')
    {
      s = (btree *)malloc(sizeof(btree));
      s->data = ch;
      s->lchild = NULL;
      s->rchild = NULL;
    }

    Q[++rear] = s;

    if (rear == 1)
      root = s;
    else
    {
      if (s && Q[front])
      {
        if (rear % 2 == 0){
          Q[front]->lchild = s;
          printf(",l %d", ch);
        }
        else {
          Q[front]->rchild = s;
          printf(",r %d", ch);
        }
      }
      if (rear % 2 == 1)
        front++;
    }
  }
  puts("");
  return root;
}

typedef btree* datatype;
typedef struct
{
  datatype data[M];
  int front, rear;
} SeqQueue;

SeqQueue *queue_init()
{
  SeqQueue *queue = (SeqQueue*)malloc(sizeof(SeqQueue));
  queue->front = 0;
  queue->rear = 0;

  return queue;
}

int queue_isEmpty(SeqQueue *queue)
{
  if (queue->front == queue->rear)
    return 1;
  else
    return 0;
}

int queue_isFull(SeqQueue *queue)
{
  if ((queue->rear + 1) % M == queue->front)
    return 1;
  return 0;
}

btree* queue_pop(SeqQueue *queue)
{
  if (queue_isEmpty(queue))
  {
    printf("queue is empty.\n");
    return NULL;
  }
  btree *tmp = queue->data[queue->front];
  queue->front = (queue->front + 1) % M;

  return tmp;
}

int queue_insert(SeqQueue *queue, datatype e)
{
  if (queue_isFull(queue))
  {
    printf("full already!\n");
    return -1;
  }
  queue->data[queue->rear] = e;
  queue->rear = (queue->rear + 1) % M;

  return 1;
}

// =============
#define STACK_SIZE 20
typedef struct Stack
{
  datatype stack[STACK_SIZE];
  int top;
} SeqStack;

void InitStack(SeqStack *s){
  s->top = -1;
}

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

// =====================
#define MAX 20
void DLR_stack(btree *tree){
  btree *ptr;
  btree *stack[MAX];
  int top = 0;

  ptr = tree;
  do {
    while(ptr != NULL){
      // printf("%d ", ptr->data);    // DLR
      stack[top] = ptr;
      top++;
      ptr = ptr->lchild;
    }

    if (top>0){
      top--;
      ptr = stack[top];
      printf("%d ", ptr->data);    // LDR
      ptr = ptr->rchild;
    }
  } while (top > 0 || ptr != NULL);
}

void LRD_stack(btree *tree){
  // btree *ptr;
  // btree *stack[MAX];
  // int flag[MAX]; // 0: on left, 1: alr visit right
  // int top = 0;

  // ptr = tree;
  // int count = 0;
  // do {
  //   while(ptr != NULL){ // skip when no left/right child
  //     stack[top] = ptr;
  //     flag[top] = 0;
  //     top++;
  //     ptr = ptr->lchild;
  //     puts("a");
  //   }

  //   if (flag[top-1] != 1){
  //     top--;
  //     ptr = stack[top];
  //     ptr = ptr->rchild;
  //     flag[top] = 1;
  //     top++;
  //     puts("b");

  //   } else {

  //     if (top>0){
  //       top--;
  //       ptr = stack[top];
  //       printf("%d ", ptr->data);
  //       top--;
  //       ptr = stack[top];
  //       puts("c");
  //     }
  //   }
  //   puts("--");
  //   count++;

  // } while((top > 0 || ptr != NULL) && count<10);
}

btree* revert(btree* root){
  btree* node = root;
  btree* tmp;

  tmp = node->lchild;
  node->lchild = node->rchild;
  node->rchild = tmp;

  if(node->lchild != NULL)
    revert(node->lchild);
  if(node->rchild != NULL)
    revert(node->rchild);

  return root;
}

int indi = 0;
int DLR(btree *tree){
  if(indi == 1) return 1;
  printf("%d ", tree->data);
  int left = 0, right=0;
  if(tree->lchild != NULL)
    DLR(tree->lchild);
  else
    left=1;

  if(tree->rchild != NULL)
    DLR(tree->rchild);
  else
    right=1;

  if (left == 1 && right == 0){
    puts("incomplete binary tree!");
    indi = 1;
  }
}

int l1=0,l2=0;
void LDR(btree *tree, int level){
  if(level == 1) l1++;
  if(level == 2) l2++;
  level++;
  if(tree->lchild != NULL)
    LDR(tree->lchild, level);
  printf("%d ", tree->data);
  printf("level: %d\n", level-1);
  if(tree->rchild != NULL)
    LDR(tree->rchild, level);
}

void LRD(btree *tree){
  if (tree->lchild != NULL)
    LRD(tree->lchild);
  if (tree->rchild != NULL)
    LRD(tree->rchild);
  printf("%d ", tree->data);
}

void BFP(SeqQueue* queue){
  if(queue_isEmpty(queue)) return;

  btree *node = queue_pop(queue);
  printf("%d ", node->data);

  if (node->lchild != NULL)
    queue_insert(queue, node->lchild);
  if(node->rchild != NULL)
    queue_insert(queue, node->rchild);
  
  // printf("level=%d\n", level);
  // level++;
  BFP(queue);
}


void main(){
  puts("---------");
  btree *tree = CreateBTree(); 
  SeqQueue *queue = queue_init();

  printf("DLR_stack: ");
  DLR_stack(tree);
  puts("");

  // printf("LRD_stack: ");
  // LRD_stack(tree);
  // puts("");

  printf("DLR: ");
  DLR(tree);
  printf("indi=%d\n", indi);

  printf("LDR: ");
  LDR(tree,0);
  printf("l1=%d, l2=%d",l1,l2);
  puts("");

  printf("LRD: ");
  LRD(tree);
  puts("");

  queue_insert(queue, tree);
  printf("BFS: ");
  BFP(queue);
  puts("");


  // tree = revert(tree);
  // queue = queue_init();
  // queue_insert(queue, tree);
  // printf("BFS: ");
  // BFP(queue);
  // puts("");

}








