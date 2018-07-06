#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ltrim(char *);
char *rtrim(char *);

int main(){
  char str[30] = "   hel lod       ";
  // test(str);
  printf("%s|\n", rtrim(str));
  return 0;
}

char *ltrim(char *str){
  char *ptr = str;
  while (*ptr++ == ' ');
  ptr--;
  // printf("%s\n", ptr);
  // ptr1 = ptr;
  
  return ptr;
}

char* rtrim(char* string)
{
    char* original = string + strlen(string);
    while(*--original == ' ');
    *(original + 1) = '\0';
    return string;
}
