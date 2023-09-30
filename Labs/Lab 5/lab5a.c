#include <stdio.h>
#include <stdlib.h>

//Implementation of graph and performing breath first search

typedef struct node {
  int data;
  struct node* next;
} node;

typedef struct graph {
  int e, v;
  int** adjMatrix;
} graph;

graph* g = NULL;

void graphAddEdge(graph* g, int start, int end) {
  if (start > g -> v || end > g -> v) {
    printf("Invalid.");
    return;
  }
  g -> adjMatrix[start][end] = 1;
}

graph* createGraph() {
  graph* g = (graph*) malloc(sizeof(graph));
  int noOfVertices, noOfEdges;
  printf("\nEnter number of vertices: "); scanf("%d", &noOfVertices);
  printf("\nEnter the number of edges: "); scanf("%d", &noOfEdges);
  g -> v = noOfVertices, g -> e = noOfEdges;
  g -> adjMatrix = (int**) malloc(sizeof(int*) * noOfVertices);
  for (int i = 0; i < noOfVertices; i++) {
    g -> adjMatrix[i] = (int*) calloc(sizeof(int), noOfVertices);
  }
  printf("Enter edges: ");
  for (int i = 0; i < noOfEdges; i++) {
    int firstVertice, secondVertice;
    printf("\nEnter first vertice and second vertice: "); scanf("%d %d", &firstVertice, &secondVertice);
    graphAddEdge(g, firstVertice, secondVertice);
  }
  return g;
}

void graphBFS(int v) {
  int* visitedArray = (int*) calloc(sizeof(int), g -> v);
  int queue[g -> v], front = 0, rear = 0;
  visitedArray[v] = 1, queue[rear++] = v;

  while (front != rear) {     //while queue is not empty
    v = queue[front++];
    printf("%d ", v);
    for (int adjacent = 0; adjacent < g -> v; adjacent++) {
      if (g-> adjMatrix [v][adjacent] == 1 && visitedArray[adjacent] == 0) {
        visitedArray[adjacent] = 1;
        queue[rear++] = adjacent;
      }
    }
  }
}

void main() {
g = createGraph();
printf("BFS Traversal: \n");
graphBFS(0);
}