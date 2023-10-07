#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} node;

int v;
node** adjL;    //list of head pointers

node* append(node* a, node* b) {
  if (a == NULL) {
    a = b;
  }
  else {
    node* p = a;
    while (p -> next != NULL) {
      p = p -> next;
    }
    p -> next = b;
  }
  return a;
}

node** constructAdjL (node** adjL) {
  adjL = (node**) malloc(sizeof(node*) * v);
  for (int i = 0; i < v; i++) {
    adjL[i] = (node*) malloc(sizeof(node));
    adjL[i] = NULL;
  }
  int e, counter = 0;
  printf("Enter number of edges: "); scanf("%d", &e);
  while (counter < e) {
    int a, b;
    printf("Enter two points connected by an edge: "); scanf("%d %d", &a, &b);
    if ((a != b) && (a < v) && (b < v)) {
      node* p = (node*) malloc(sizeof(node)), *q = (node*) malloc(sizeof(node));
      p -> data = b, p -> next = NULL;
      q -> data = a, q -> next = NULL;
      adjL[a] = append(adjL[a], p), adjL[b] = append(adjL[b], q);
      counter++;
    }
    else printf("\nInvalid.");
  }
  return adjL;
}

int isAdj(node** adjL, int a, int b) {
  node* p = adjL[a];
  while (p != NULL) {
    if (p -> data == b) return 1;
    p = p -> next;
  }
  return 0;
}

void BFS(node** adjL, int i) {
  printf("BFS Traversal: \n");
  int* visited = (int*) calloc(sizeof(int), v);
  int queue[v], front = -1, rear = front;
  printf("%d ", i);
  visited[i] = 1;
  queue[++rear] = i;
  while (front != rear) {
    int u = queue[++front];
    for (int adj = 0; adj < v; adj++) {
      if (isAdj(adjL, u, adj) && !visited[adj]) {
        printf("%d ", adj);
        visited[adj] = 1;
        queue[++rear] = adj;
      }
    }
  }
}

void DFS(node** adjL, int i, int* visited) {
  if (visited == NULL) {
    printf("DFS Traversal: \n");
    visited = (int*) calloc(sizeof(int), v);
  }
  printf("%d ", i);
  visited[i] = 1;
  for (int adj = 0; adj < v; adj++) {
    if (isAdj(adjL, i, adj) && !visited[adj]) DFS(adjL, adj, visited);
  }
}

void displayAdjL(node** adjL) {
  for (int i = 0; i < v; i++) {
    node* p = adjL[i];
    printf("%d: ", i);
    while (p != NULL) {
      printf("%d ", p -> data);
      p = p -> next;
    }
    printf("\n");
  }
}

void main() {
  printf("Enter number of vertices: "); scanf("%d", &v);
  adjL = constructAdjL(adjL);
  BFS(adjL, 0);
  printf("\n");
  DFS(adjL, 0 , NULL);
}