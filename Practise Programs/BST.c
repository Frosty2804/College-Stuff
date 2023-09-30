//creating a binary search tree
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node* left, *right;
} node;

void insertNode(node** root, int element) {
  node* p = *root, *q = (node*) malloc(sizeof(node));
  q -> data = element, q -> left = q -> right = NULL;
  if (!p) *root = q;
  else {
    if (element < p -> data) insertNode(&(p -> left), element);
    else if (element > p -> data) insertNode(&(p -> right), element);
  }
}

node* createBST() {
  node* rootTemp = NULL;
  int noOfElements;
  printf("How many elements? "); scanf("%d", &noOfElements);
  for (int i = 0; i < noOfElements; i++) {
    int element;
    printf("Enter data: "); scanf("%d", &element);
    insertNode(&rootTemp, element);
  }
  return rootTemp;
}

int Search(node* root, int element) {
  node* p = root;
  if (!p) return false;
  if (element == p -> data) return true;
  else if (element < p -> data) Search(p -> left, element);
  else Search(p -> right, element);
}

void main() {
  node* root = createBST();
  if (Search(root, 5)) printf("Found");
  else printf("Not Found");
}