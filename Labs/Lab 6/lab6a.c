#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
  int data;
  struct node* next;
} node;

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
      if (j > i && graph[i][j] < min) {    //check only the upper triangular matrix
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

node* addEdge(node* edgePtr, int start, int current) {
  node* p = (node*) malloc(sizeof(node)), *q = (node*) malloc(sizeof(node));
  p -> data = start, p -> next = q;
  q -> data = current, q -> next = NULL;
  edgePtr = p;
  return edgePtr;
}

node** primMST(int** graph) {
  //we need two additional data structures
  node** MST = (node**) malloc(sizeof(node*) * (v-1));  //a list of linked list headers to store edges
  for (int i = 0; i < v - 1; i++) {
    MST[i] = (node*) malloc(sizeof(node));
    MST[i] = NULL;
  }
  int* near = (int*) malloc(sizeof(int) * v) ;  //near is used to store the closer between two vertices from any other vertice
  for (int i = 0; i < v; i++) {
    near[i] = INT_MAX;
  }
  //initial step
  int* minEdge = findMinEdge(graph);
  int start = minEdge[0], current = minEdge[1];
  //the minimum edge is stored as the first edge in the MST
  MST[0] = addEdge(MST[0], start, current);
  near[start] = near[current] = -1;
  //filling near array
  for (int i = 0; i < v; i++) {
    if (near[i] != -1) {
      if (graph[i][start] < graph[i][current]) near[i] = start;
      else near[i] = current;
    }
  }
  for(int i = 1; i < v - 1; i++) {
    minEdge = findMinNearEdge(graph, near);
    start = minEdge[0], current = minEdge[1];
    MST[i] = addEdge(MST[i], start, current);
    //filling near array again
    near[current] = -1;
    for (int i = 0; i < v; i++) {
      if (near[i] != -1 && graph[i][current] < graph[i][near[i]]) near[i] = current;
    }
  }
  return MST;
}

void displayMSTEdges(node** MST) {
  for (int i = 0; i < v - 1; i++) {
    node* p = MST[i];
    printf("Edge %d: ", i + 1);
    while (p != NULL) {
      printf("%d ", p -> data);
      if (p -> next != NULL) printf("-> ");
      p = p -> next;
    }
    printf("\n");
  }
}

void main() {
  printf("Enter number of vertices: "); scanf("%d", &v);
  graph = constructGraph(graph);
  node** MST = primMST(graph);
  displayMSTEdges(MST);
}