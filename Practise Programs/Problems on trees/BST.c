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

void inorderTraversal(node* root) {
  node* p = root;
  if (!p) return;
  inorderTraversal(p -> left);
  printf("%d ", p -> data);
  inorderTraversal(p -> right);
}

void postOrderTraversal(node* root) {
  node* p = root;
  if (!p) return;
  inorderTraversal(p -> right);
  inorderTraversal(p -> left);
  printf("%d ", p -> data);
}

void preorderTraversal(node* root) {
  node* p = root;
  if (!p) return;
  printf("%d ", p -> data);
  inorderTraversal(p -> left);
  inorderTraversal(p -> right);
}

int heightOf(node* root) {
  node* p = root;
  if (!p) return 0;
  int lheight = heightOf(p -> left), rheight = heightOf(p -> right);
  if (lheight > rheight) return ++lheight;
  else return ++rheight; 
}

void mirrorTree(node* root) {
  node* p = root, *temp;
  if (!p) return;
  temp = p -> left;
  p -> left = p -> right, p -> right = temp;
  mirrorTree(p -> left), mirrorTree(p -> right);
}

bool identicalTrees(node* root1, node* root2) {
  node* p = root1, *q = root2;
  if (!p && !q) return true;
  if (p -> data == q -> data) return true;
  
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
  printf("\nInorder Traversal: "); inorderTraversal(root);
  mirrorTree(root);
  printf("\nInorder Traversal: "); inorderTraversal(root);
}