#include <stdio.h>
int main(void){
    int array[2][3]={1,2,3,4,5,6};
    int i,j,*p;
    p=&array[0][0];
    puts("using legacy method:");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d ",array[i][j] );
        }
    }
    puts("\nusing pointer");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d ",*(*(array+i)+j));
        }
    }
    puts("\nnext method");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d ", *(p+3*i+j));
        }
    }
}