#include <stdio.h>
#include <stdlib.h>

int numcmp(int*, int*);
int chrcmp(char*,char*);
int compare(void *,void *,int(*)(void *,void *));


int main(void){
  int x=15,y=10,result;
  int *ptr1=&x, *ptr2=&y;
  char a='F',b='F';
  char *ptr3=&a, *ptr4=&b;

  result = compare((void *)ptr1, (void *)ptr2, (int(*)(void *,void *))chrcmp );
  printf("x=%d,y=%d, val=%d\n", *ptr1,*ptr2, result );

  result = compare((void *)ptr3, (void *)ptr4, (int(*)(void *,void *))chrcmp );
  printf("a=%c, b=%c, val=%d\n", *ptr3, *ptr4, result );

}

int compare(void *a, void *b, int (*comp)(void *,void *)){
  return (*comp)(a,b);
}

int numcmp(int *a, int *b){
  if (*a == *b) return 0;
  else if (*a > *b) return 1;
    else return -1;
}

int chrcmp(char *a, char *b){
  if (*a == *b) return 0;
  else if (*a > *b) return 1;
    else return -1;
}


