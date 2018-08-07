#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef char AtomType;
typedef enum {ATOM, LIST} ElemTag; // atom=0, list=1

typedef struct GL {
  ElemTag tag;
  union {
    AtomType data;
    struct GL *firstchildPtr;
    struct GL *siblingPtr;
  };
} GLNode;

GLNode *CreateGL(char *s){
  GLNode *NodePtr, *prePtr, *head;
  GLNode *stack[MAXSIZE];

  int topH = -1;  // stack 1
  int topB = MAXSIZE; // stack 2
  int flag = 1;

  while(*s != '\0'){
    switch(*s){
      case '(':
        // init empty NodePtr
        NodePtr = (GLNode*) malloc(sizeof(GLNode));
        NodePtr->tag = LIST;
        NodePtr->firstchildPtr = NULL;
        NodePtr->siblingPtr = NULL;
        if(*(s-2)==')'){
          if(topB != MAXSIZE) stack[++topH] = stack[topB++];
        }
        if(flag == 1){ // not atomtype
          flag=0;
          head = NodePtr;
          stack[++topH] = NodePtr;
          break;
        }
        prePtr = stack[topH--];
        stack[++topH] = NodePtr;
        if(topB == MAXSIZE){  // if stack full
          stack[--topB] = NodePtr;
        }
        prePtr->siblingPtr = NodePtr;
        break;

      case ')': break;
      case ',': break;
      default:
        // init new NodePtr with data from s
        NodePtr = (GLNode*) malloc(sizeof(GLNode));
        NodePtr->tag = ATOM;
        NodePtr->data = *s;
        NodePtr->siblingPtr = NULL;
        // get previous node from stack
        prePtr = stack[topH--];
        stack[++topH] = NodePtr;

        if(prePtr->tag == LIST){  // if prev=list, link first child ptr
          prePtr->firstchildPtr = NodePtr;
          prePtr->siblingPtr = NULL;
        } else { // if previous=atom, link sibling ptr
          prePtr->siblingPtr = NodePtr;
        }
        break;
    }
    s++;
  }
  return head;

}




