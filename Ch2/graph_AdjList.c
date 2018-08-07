#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8
#define VERTEX_MAX_NUM 100
typedef int VexType;

typedef struct AdjNode {
  int adjvex;
  struct AdjNode *next;
} AL_AdjNode;

typedef struct {
  VexType vertex;
  struct AdjNode *link;
} AL_VexNode;

// typedef struct {
//   struct A_VexNode VexList[VERTEX_MAX_NUM];
//   int VexNum, ArcNum;
// } AL_Graph;






