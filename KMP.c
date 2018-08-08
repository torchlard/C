#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define MaxSize 60

typedef struct {
  char ch[MaxSize];
  int len;
} SqString;

// construct next table for jumping if failure
void GetNext(SqString t, int next[]) {
  int j=0, k=-1;
  next[0] = -1;

  while(j < t.len){
    if(k==-1 || t.ch[j] == t.ch[k]) {
      j++; k++;
      next[j] = k;
    }
    else k = next[k];
  }

  for(int i1=0; i1<t.len; i1++){
    printf("%d ",next[i1]);
  }
  puts("");
}

int KMPIndex(SqString s, SqString t) {
  int next[MaxSize], i=0, j=0, v;
  
  GetNext(t, next);
  
  while(i<s.len && j<t.len){

    if (j==-1 || s.ch[i]==t.ch[j]) {
      i++; j++; // match char, move forward main string
    }

    // not match, find starting pos in next comparison
    else j=next[j];

    printf("i=%d, j=%d\n", i, j);
  }
  if(j >= t.len) v = i-t.len;
  else v=-1;

  return v;
}

int main(){
  // SqString S = {"ababcabcacbab", 13};
  // SqString T = {"abcac", 5};
  SqString S = {"babcbabcabcaabcabcabcacabc", 26};
  SqString T = {"abcabcacab", 10};

  int k;
  k = KMPIndex(S,T);
  printf("\nMatching location: %d\n", k);

  return 0;
}



