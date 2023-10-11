#include <stdio.h>
#include <stdlib.h>

int** graph, v, e;

int** constructGraph(int** graph) {
  graph = (int**) malloc(sizeof(int*) * v);
  for (int i = 0; i < v; i++) {
    graph[i] = (int*) calloc(sizeof(int), v);
  }
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

int** sortEdgeList(int** graph) {
  int** edgeList = (int**) malloc(sizeof(int*) * 3);
  for (int i = 0; i < 3; i++) {
    edgeList[i] = (int*) calloc(sizeof(int), e);
  }
  int edgeNo = 0;
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      if (j > i && graph[i][j] != 0) {
        edgeList[0][edgeNo] = i, edgeList[1][edgeNo] = j, edgeList[2][edgeNo] = graph[i][j];
        edgeNo++;
      }
    }
  }
  for (int i = 0; i < e - 1; i++) {
    for (int j = 0; j < e - i - 1; j++) {
      if (edgeList[2][j] > edgeList[2][j + 1]) {
        int temp1 = edgeList[0][j], temp2 = edgeList[1][j], temp3 = edgeList[2][j];
        edgeList[0][j] = edgeList[0][j + 1], edgeList[1][j] = edgeList[1][j + 1], edgeList[2][j] = edgeList[2][j + 1];
        edgeList[0][j + 1] = temp1, edgeList[1][j + 1] = temp2, edgeList[2][j + 1] = temp3;
      }
    }
  }
  return edgeList;
}

//set operations

int findParent(int* set, int x) {
  while (set[x] > 0) {
    x = set[x];
  }
  return x;
}

int* unionSet(int* set, int a, int b) {
  if (set[a] <= set[b]) {
    set[a] += set[b];
    set[b] = a;
  }
  else {
    set[b] += set[a];
    set[a] = b;
  }
  return set;
}

int isCycle(int* set, int start, int end) {
  if (findParent(set, start) == findParent(set, end)) return 1;
  else return 0;
}

int** KruskalMST(int** graph) {
  int** edgeList = sortEdgeList(graph);
  //create two additional data structures
  int** MST = (int**) malloc(sizeof(int*) * 2);
  for (int i = 0; i < 2; i++) {
    MST[i] = (int*) malloc(sizeof(int) * (v-1));
  }
  int* set = (int*) malloc(sizeof(int) * v);     //set to detect cycle
  for (int i = 0; i < v; i++) {
    set[i] = -1;
  }
  int lastAdded = -1;
  for (int i = 0; i < e; i++) {
    int start = edgeList[0][i], end = edgeList[1][i];
    if (!isCycle(set, start, end)) {
      lastAdded++;
      MST[0][lastAdded] = start, MST[1][lastAdded] = end;
      set = unionSet(set, findParent(set, start), findParent(set, end));
    }
  }
  return MST;
}

void displayMST(int** MST) {
  for (int i = 0; i < v - 1; i++) {
    printf("Edge %d: %d -> %d\n", i + 1, MST[0][i], MST[1][i]);
  }
}

void main() {
  printf("Enter number of vertices: "); scanf("%d", &v);
  graph = constructGraph(graph);
  int** MST = KruskalMST(graph);
  printf("MST\n");
  displayMST(MST);
}