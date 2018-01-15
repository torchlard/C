#include <stdio.h>
#include <stdlib.h>
#include "main01.h"

static void maxvalue(void);
static void minvalue(void);
int var1, var2;
static int result;

static void maxvalue(){
  if (var1 > var2) result = var1;
  else result = var2;
}
static void minvalue(){
  if (var1 < var2) result=var1;
  else result=var2;
}

void cmpresult(int type){
  if (type == MAXCMP){
    maxvalue();
    printf("max: %d\n", result );
  } else {
    minvalue();
    printf("min: %d\n", result );
  }
}

// int main(void){
//   var1=45, var2=70;
//   cmpresult(0);
//   return 0;
// }

