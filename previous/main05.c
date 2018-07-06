#include <stdio.h>
#include <stdlib.h>
#define LEN 5

void swap(float*, float*);
float *ptr;

int main(void){

  float data[LEN] = {2.3, 5.6, 1.2, 8.5, 3.54};
  ptr = data;

  // bubble sort
  for (int i=0; i<LEN-1; i++){
    for (int j=0; j<LEN-i-1; j++){
      if (*(ptr+j) > *(ptr+j+1)){
        swap(ptr+j, ptr+j+1);
      }
    }
  }

  // print data array
  for (int i=0; i<LEN; i++){
    printf("%f ", *(ptr+i));
  }
  printf("\n");

  return 0;
}

void swap(float *a, float *b){
  float tmp = *a;
  *a = *b;
  *b = tmp;
}

