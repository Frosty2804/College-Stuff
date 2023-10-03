#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_VERTICES 5

// Prim’s Minimum Spanning Tree (MST) Algorithm
int** graph;

void addEdge(int a, int b, int weight) {
  if (a < MAX_VERTICES && b < MAX_VERTICES && (a != b)) graph[a][b] = weight;
}

int minKeyIndex(int* vertexKeyVal, bool* mstVertices) {
  int min = INT_MAX, minIndex = 0;
  for (int i = 0; i < MAX_VERTICES; i++) {
    if (!mstVertices[i] && vertexKeyVal[i] < min) {
      min = vertexKeyVal[i], minIndex = i;
    }
  }
  return minIndex;
}

int printMST(int* MST, int** graph) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < MAX_VERTICES; i++)
        printf("%d - %d \t%d \n", MST[i], i,
               graph[i][MST[i]]);
}
 

void primMST(int** graph) {
  int MST[MAX_VERTICES];            //to store the constructed MST
  //partitioning vertices into two sets
  bool mstVertices[MAX_VERTICES];    //to store the vertices that are present in the incomplete MST
  int vertexKeyVal[MAX_VERTICES];   //define key values for each of the verteces not in mstVertices[]

  for (int i = 0; i < MAX_VERTICES; i++) {    //init
    vertexKeyVal[i] = INT_MAX;
    mstVertices[i] = false;
  }
  vertexKeyVal[0] = 0, MST[0] = -1;

  for (int i = 0; i < MAX_VERTICES - 1; i++) {    //MST has MAX_VERTICES number of vertices
    int minKey = minKeyIndex(vertexKeyVal, mstVertices);
    mstVertices[minKey] = true;       //adding minimum vertex to the set of min. spanning tree vertices
    for (int j = 0; j < MAX_VERTICES; j++) {
      if (graph[minKey][j] /*MEANS ELEMENTS ADJACENT TO minKey*/ && !mstVertices[j] /*UPDATE THE KEY ONLY IF IT ISN'T IN MST*/ && graph[minKey][j] < vertexKeyVal[j] /*IF WEIGHT CORREPONDING TO INDEXES IS LESS THAN KEY VAL.*/) {
        MST[j] = minKey, vertexKeyVal[j] = graph[minKey][j];
      }
    }
  }
  printMST(MST, graph);
}

int main() {
  graph = (int**) malloc(sizeof(int*) * MAX_VERTICES);
  for (int i = 0; i < MAX_VERTICES; i++) {
    graph[i] = (int*) calloc(sizeof(int), MAX_VERTICES);
  }
  int noOfEdges;
  printf("How many edges? "); scanf("%d", &noOfEdges);
  for (int i = 0; i < noOfEdges; i++) {
    int a, b, w;
    printf("Enter starting index, ending index and weight: "); scanf("%d %d %d", &a, &b, &w);
    addEdge(a, b, w);
  }

  primMST(graph);
}