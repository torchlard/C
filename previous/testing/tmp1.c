#include <stdio.h>
#include <string.h>

int *max(int x[],int y[],int *p,int *c){
    int i;
    int *m=&x[0];
    for(i=0;i<9; i++){
        if(*m<x[i]){
            *m=x[i];
            *p=i;
            *c=1;
        }
    }
    for(i=0;i<4;i++){
        if(*m<y[i]){
            *m=y[i];
            *p=i;
            *c=2;
        }
    }
    return m;
}

int main(void){
  int c1[10]={1,2,3,4,5,6,7,8,9,0};
  int c2[5]={11,12,13,14,15};
  int n,c,*p;
  // puts("pls input a and b");
  // scanf("%d %d",&a,&b);
  p=max(c1,c2,&n,&c);
  printf("max no is %d, position in array %d is %d\n",*p,c,n);

  return 0;
}
