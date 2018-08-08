#include <stdlib.h>
#include <stdio.h>
#define M 32

typedef int datatype;
typedef struct {
  datatype data[M];
  int front,rear;
} SeqQueue;

SeqQueue* clear(SeqQueue* queue){
  
  queue->front = 0;
  queue->rear = 0;

  return queue;
}

int isEmpty(SeqQueue* queue){
  if(queue->front == queue->rear)
    return 1;
  else
    return 0;
}

int isFull(SeqQueue* queue){
  if( (queue->rear+1)%M == queue->front)
    return 1;
  return 0;
}

int pop(SeqQueue* queue){
  if (isEmpty(queue)){
    printf("queue is empty.\n");
    return -1;
  }

  int tmp = queue->data[queue->front];
  queue->front = (queue->front+1)%M ;
  return tmp;
}

int insert(SeqQueue* queue, datatype e){
  if(isFull(queue)){
    printf("full already!\n");
    return -1;
  }
  queue->data[queue->rear] = e;
  queue->rear = (queue->rear+1)%M;

  return 1;
}

int head(SeqQueue* queue){
  if(isEmpty(queue)){
    printf("no element!\n");
    return -1;
  }
  return queue->data[queue->front];
}

void print(SeqQueue* queue){
  if(isEmpty(queue)){
    printf("no element!\n");
    return;
  }

  int i = queue->front;
  while(i != queue->rear ){
    printf("%d ", queue->data[i]);
    i = (i+1)%M;
  }
  printf("\n");
}


void main(){
  puts("----------");
  SeqQueue* queue = (SeqQueue*) malloc(sizeof(SeqQueue));

  queue = clear(queue);
  for(int i=1; i<10; i++){
    insert(queue, i);
  }
  print(queue);

  pop(queue);
  pop(queue);
  print(queue);
}















// int main(){
//   int n = 63;
//   int queue[M] = {0,1,1,0};

//   int front=1, rear=4;
//   for(int i=0; i<n; i++){
//     queue[rear] = queue[(front-1+M)%M] + queue[front];
//     printf("%d ", queue[rear]); 
//     // rear++;
//     rear = (rear+1)%M;
//     if(queue[front] == 0){
//       queue[rear] = 0; // add separator 0
//       // rear++;
//       rear = (rear+1)%M;
//       puts("");
//     }
//     // front++;
//     front = (front+1)%M;

//     // ensure not overflow
//     if ( (rear+1)%M == front) {
//       puts("list is full!");
//       exit(0);
//     }
//   }
//   puts("");

//   return 0;
  
// }
















