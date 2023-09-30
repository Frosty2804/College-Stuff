#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;


//creating and traversing a binary search tree

node* root = NULL;

node* createTreeNode(int element) {
  node* p = (node*) malloc(sizeof(node));
  p -> data = element;
  p -> left = NULL, p -> right = NULL;
  return p;
}

node* createBinTree(node* root, int element) {
  node* rootTemp = root;
  if (!rootTemp) {
    rootTemp = createTreeNode(element);
  }
  else if (element < root -> data) {
    rootTemp -> left = createBinTree(rootTemp -> left, element);
  }
  else if (element > root -> data) {
    rootTemp -> right = createBinTree(rootTemp -> right, element);
  }
  return rootTemp; 
}

//inorder traversal
void inorderTraversal(node* root) {
  node* p = root;
  if (!p) return;
  inorderTraversal(p -> left);
  printf("%d ", p -> data);
  inorderTraversal(p -> right);
}

//preorder traversal
void preorderTraversal(node* root) {
  node* p = root;
  if (!p) return;
  printf("%d ", p -> data);
  preorderTraversal(p -> left);
  preorderTraversal(p -> right);
}

//postorder traversal
void postorderTraversal(node* root) {
  node* p = root;
  if (!p) return;
  postorderTraversal(p -> left);
  postorderTraversal(p -> right);
  printf("%d ", p -> data);
}

void main() {
  int noOfelements;
  printf("How many elements do you want to enter?: "); scanf("%d", &noOfelements);
  for (int i = 0; i < noOfelements; i++) {
    int element;
    printf("Enter an element: "); scanf("%d", &element);
    root = createBinTree(root, element);
  }
  printf("\nInorder Traversal:\n");
  inorderTraversal(root);
  printf("\nPreorder Traversal:\n");
  preorderTraversal(root);
  printf("\nPostorder Traversal:\n");
  postorderTraversal(root);
}

