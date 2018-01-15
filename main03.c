#include <stdio.h>
#include <stdlib.h>

#define LEN 6
int max(int,int);
int min(int,int);
int compare(int,int, int(*)(int,int));

int main(void){
  // int var = 100;
  // int *ptr = &var;
  // int **ptr1 = &ptr;
  //
  // **ptr1 = **ptr1+1;
  // *ptr = *ptr+1;
  //
  // printf("var=%d, addr=%p\n", var, &var );
  // printf("val=%d, ptr=%p, addr=%p\n", *ptr, ptr, &ptr);
  // printf("val=%d, ptr1=%p, addr=%p\n", **ptr1, ptr1, &ptr1);

  int result;
  result = compare(4,6, min);
  printf("result=%d\n", result );

  return 0;
}

int max(int x, int y){
  if (x>y) return x;
  else return y;
}

int min(int x, int y){
  if (x<y) return x;
  else return y;
}

int compare (int a, int b, int (*ptr)(int,int)){
  return (*ptr)(a,b);
}




