#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5

//Kruskal’s Minimum Spanning Tree (MST) Algorithm
int** graph;

void addEdge(int a, int b, int weight) {
  if (a < MAX_VERTICES && b < MAX_VERTICES && (a != b)) graph[a][b] = weight;
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
}