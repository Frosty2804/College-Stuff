#include <stdio.h>
#include <stdlib.h>

int** graph, v;

int** constructGraph(int** graph) {
  graph = (int**) malloc(sizeof(int*) * v);
  for (int i = 0; i < v; i++) {
    graph[i] = (int*) calloc(sizeof(int), v);
  }
  int e;
  printf("Enter number of edges: "); scanf("%d", &e);
  int counter = 0;
  while (counter < e) {
    int a, b;
    printf("Enter two points connected by a edge: "); scanf("%d %d", &a, &b);
    if ((a != b) && (a < v) && (b < v)) {
      graph[a][b] = 1, graph[b][a] = 1;
      counter++;
    }
    else printf("\nInvalid.");
  }
  return graph;
}

void BFS(int** graph, int i) {
  printf("BFS Traversal: \n");
  int* visited = (int*) calloc(sizeof(int), v);
  int queue[v], front = -1, rear = front;
  printf("%d ", i);
  visited[i] = 1;
  queue[++rear] = i;
  while (front != rear) {
    int u = queue[++front];
    for (int adj = 0; adj < v; adj++) {
      if (graph[u][adj] == 1 && !visited[adj]) {
        printf("%d ", adj);
        visited[adj] = 1;
        queue[++rear] = adj;
      }
    }
  }
}

void DFS(int** graph, int i, int* visited) {
  if (visited == NULL) {
    printf("DFS Traversal: \n");
    visited = (int*) calloc(sizeof(int), v);
  }
  printf("%d ", i);
  visited[i] = 1;
  for (int adj = 0; adj < v; adj++) {
    if (graph[i][adj] == 1 && !visited[adj]) DFS(graph, adj, visited);
  }
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
  DFS(graph, 0, NULL);
}