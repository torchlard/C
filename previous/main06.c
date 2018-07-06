#include <stdio.h>
#include <stdlib.h>

int strLen(char *);
char* strCat(char *,char *);

int main(int argc, char *argv[]){
  // char str[16] = "this is a book.";
  // char str1[16];
  // char *ptr1, *ptr=str;
  // int i =0;
  // 
  // ptr1 = "this is an apple.";
  // printf("str = %s\n", str);
  // printf("ptr = %c\n", *(ptr+6) );
  // printf("ptr1 = %s\n", ptr1);
  // 
  // ptr1 = str1;
  // while(*ptr != 'p'){
  //   *(ptr1+i) = *ptr++;
  //   i++;
  // }
  // *(ptr1+i) = '\0';
  // printf("str1 = %s\n", str1);
  // printf("ptr1 = %s\n", ptr1);
  
  // char *name2[4] = {"sam", "chan", "kelvin", "snith"};
  // for (int i=0; i<4; i++){
  //   char *ptr = name2[i];
  //   for (int j=0; *(ptr+j)!='\0'; j++){
  //     printf("%c", *(ptr+j)+1 );
  //   }
  //   printf("\n");
  // }
  
  // int i;
  // printf("program has %d arguments\n", argc-1);
  // if (argc > 1){
  //   for (i=0; i<argc; i++)
  //     printf("argv[%d]=%s\n", i, argv[i] );
  // }
  
  // char st1[10]="abc", st2[10]="def";
  char st1[10]="abc", st2[10]="def";
  char *ab; strcpy(ab,"fdsa");
  
  // printf("pls enter str: ");
  // scanf("%s", st );
  // printf("str length = %d\n", strLen(st));
  
  printf("result = %s\n", strCat(st1,st2));
  printf("%s\n", ab);
  
  for (int i=0,j=3; i<3; i++,j--){
    printf("%d %d\n",i,j);
  }
  
  return 0;
}

int strLen(char *str){
  char *ptr = str;
  while (*ptr != '\0') ptr++;
  return ptr-str;
}

char *strCat(char *str1, char *str2){
  char *ptr = str1;
  while (*ptr++ != '\0'); // navigate to last character '\0'
  ptr--; // move 1 step forward
  while ( (*ptr++ = *str2++) != '\0' );
  
  return str1;
}











