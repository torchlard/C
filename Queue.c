#include <stdlib.h>
#include <stdio.h>
#define M 32

typedef int datatype;
typedef struct {
  datatype data[M];
  int fornt,rear;
} SeqQueue;


int main(){
  int n = 63;
  int queue[M] = {0,1,1,0};

  int front=1, rear=4;
  for(int i=0; i<n; i++){
    queue[rear] = queue[(front-1+M)%M] + queue[front];
    printf("%d ", queue[rear]);
    // rear++;
    rear = (rear+1)%M;
    if(queue[front] == 0){
      queue[rear] = 0; // add separator 0
      // rear++;
      rear = (rear+1)%M;
      puts("");
    }
    // front++;
    front = (front+1)%M;

    if ( (rear+1)%M == front) {
      puts("list is full!");
      exit(0);
    }
  }
  puts("");

  return 0;
  
}



