#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define LIST_SIZE 1024
typedef struct SequenList {
  ElemType data[LIST_SIZE];
  int last;
} SequenList;

SequenList *LPtr;

int Insert_SqList(SequenList *LPtr, ElemType x, int k){
  int j;
  
  // check if full
  if (LPtr->last >= LIST_SIZE-1) return 0;
  // check if index out of range
  else if (k<0 || k>(LPtr->last+1)) return 0;
  // valid index
  else {
    for(j=LPtr->last; j>=k; j--){
      // move elements one address backward
      LPtr->data[j+1] = LPtr->data[j];
    }
    LPtr->data[k] = x;
    LPtr->last = LPtr->last+1;
  }
  return 1;
}

int Delete_SqList(SequenList *LPtr, int k){
  // check if out of range
  if (k<0 || k>(LPtr->last)) {
    printf("out of range\n");
    return 0;
  }
  else {
    for(int j=k; j<=LPtr->last; j++ ){
      LPtr->data[j] = LPtr->data[j+1];
    }
    LPtr->last--;
  }
  return 1;
}

int Locate_SqList(SequenList *LPtr, ElemType x){
  for(int j=0; j< LPtr->last; j++){
    if(LPtr->data[j] == x){
      return j;
    }
  }
  return -1;
}





int main(void){

  struct SequenList seq = {
    {1,2,3,4,5,8},
    6
  };

  ElemType x = 5;
  int result = Locate_SqList( &seq, 2);
  
  printf("%d\n", result);
  return 0;
}









