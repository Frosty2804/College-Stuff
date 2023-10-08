#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** graph, v;

int** constructGraph(int** graph) {
  graph = (int**) malloc(sizeof(int*) * v);
  for (int i = 0; i < v; i++) {
    graph[i] = (int*) malloc(sizeof(int) * v);
  }
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      graph[i][j] = INT_MAX;
    }
  }
  int e;
  printf("Enter number of edges: "); scanf("%d", &e);
  int counter = 0;
  while (counter < e) {
    int a, b, w;
    printf("Enter two points connected by a edge and enter their weight: "); scanf("%d %d %d", &a, &b, &w);
    if ((a != b) && (a < v) && (b < v)) {
      graph[a][b] = w, graph[b][a] = w;
      counter++;
    }
    else printf("Invalid.\n");
  }
  return graph;
}

int* findMinEdge(int** graph) {
  int min = INT_MAX, *minIndex = (int*) calloc(sizeof(int), 2);
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      if (i > j && graph[i][j] < min) {    //check only the lower triangular matrix
        min = graph[i][j];
        minIndex[0] = i, minIndex[1] = j;
      }
    }
  }
  return minIndex;
}

int* findMinNearEdge(int** graph, int* near) {
  int min = INT_MAX, *minIndex = (int*) calloc(sizeof(int), 2);
  for (int i = 0; i < v; i++) {
    if (near[i] != -1 && graph[i][near[i]] < min) {
      min = graph[i][near[i]];
      minIndex[0] = near[i], minIndex[1] = i; 
    }
  }
  return minIndex;
}

int* primMST(int** graph) {
  //we need two additional data structures
  int* MST = (int*) malloc(sizeof(int) * v), near[v];  //near is used to store the closer between two vertices from any other vertice
  for (int i = 0; i < v; i++) {
    near[i] = INT_MAX;
  }
  //initial step
  int* minEdge = findMinEdge(graph);
  int start = minEdge[0], current = minEdge[1];
  MST[0] = start, MST[1] = current; //the minimum edge is stored as the first edge in the MST
  near[start] = near[current] = -1;
  //filling near array
  for (int i = 0; i < v; i++) {
    if (near[i] != -1) {
      if (graph[i][start] < graph[i][current]) near[i] = start;
      else near[i] = current;
    }
  }
  for(int i = 2; i < v; i++) {
    minEdge = findMinNearEdge(graph, near);
    MST[i] = minEdge[1];
    //filling near array again
    current = MST[i], near[current] = -1;
    for (int i = 0; i < v; i++) {
      if (near[i] != -1 && graph[i][current] < graph[i][near[i]]) near[i] = current;
    }
  }
  return MST;
}

void displayAdjM(int** graph) {
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
} 

void main() {
  printf("Enter number of vertices: "); scanf("%d", &v);
  graph = constructGraph(graph);
  int* MST = primMST(graph);
  for (int i =0; i < v; i++) {
    printf("%d ", MST[i]);
  }
}