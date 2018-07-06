#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 2

// struct point {
//   int x;
//   int y;
// };
// struct point setXY(int,int);
// struct point offset(struct point, int);

struct test {
  int midtermGrade;
  char *finalGrade;
};
struct test students[MAXSIZE], *ptr;

int main(void){
  // struct point p, p1;
  // p = setXY(150,200);
  // printf("(%d,%d)\n", p.x, p.y);
  // p1 = offset(p, 50);
  // printf("(%d,%d)\n", p1.x, p1.y );
  
  int i,sum=0;
  students[0].midtermGrade = 10;
  students[0].finalGrade = "15";
  students[1].midtermGrade = 20;
  students[1].finalGrade = "25";
  
  // ptr = &students[1];
  // printf("%d\n", ptr->finalGrade );
  
  for (i=0; i<MAXSIZE; i++){
    printf("%d, %s\n", students[i].midtermGrade, students[i].finalGrade );
  }
  
  return 0;
}

// struct point setXY(int x,int y){
//   struct point p;
//   p.x = x;
//   p.y=y;
//   return p;
// }
// 
// struct point offset(struct point pp, int len ){
//   pp.x += len;
//   pp.y += len;
//   return pp;
// }

