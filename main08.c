#include <stdio.h>
#include <stdlib.h>

int main(void){
  double *fp;
  fp = (double *) malloc(sizeof(double));
  if (fp != NULL){
    *fp = 3.1415926f;
    printf("fp pointer addr: %p\n", fp);
    printf("val: %f\n", *fp);
    printf("allo: %ld\n" ,sizeof(double));
    free(fp);
  } else printf("error\n");
  
  return 0;
}
