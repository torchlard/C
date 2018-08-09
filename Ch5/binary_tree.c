#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int datatype;
typedef struct node {
  datatype data;
  struct node *lchild, *rchild;
} btree;

btree *Q[16];
btree *CreateBTree(){
  char ch;
  int front=1, rear=0;
  btree *root = NULL, *s;

  // char str[] = "ABCDEF";
  int str[10] = {1,2,3,4,5,6,7,8,9,10};
  for(int i=0; i<10; i++) {
    ch = str[i];
    s = NULL;
    if(ch!='@'){
      s = (btree*)malloc(sizeof(btree));
      s->data = ch;
      s->lchild = NULL;
      s->rchild = NULL;
    }

    Q[++rear] = s;

    if(rear==1) root=s;
    else {
      if(s && Q[front]){
        if(rear%2 == 0) 
          Q[front]->lchild = s;
        else 
          Q[front]->rchild = s;
      }
      if(rear%2 == 1) front++;
    }
  }

  return root;
}

void DFP_l(btree *tree){
  printf("%d ", tree->data);
  if(tree->lchild != NULL)
    DFP_l(tree->lchild);
  if(tree->rchild != NULL)
    DFP_l(tree->rchild);
}

void BFP(btree *tree){
  if (tree->lchild != NULL)
    printf("%d ", tree->lchild->data);
  if (tree->rchild != NULL)
    printf("%d ", tree->rchild->data);
  if (tree->lchild != NULL)
    BFP(tree->lchild);
  if (tree->rchild != NULL)
    BFP(tree->rchild);
}


void main(){
  puts("---------");
  btree *tree = CreateBTree(); 

  DFP_l(tree);
  puts("");
  BFP(tree);
  puts("");
}








