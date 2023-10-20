#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data, height;
  struct node* left, *right;
} node;

int max(int a, int b) {
  return (a > b) ? a : b;
}

int height(node* root) {
  if (root == NULL) return 0;
  return root -> height;
}

int balanceFactor(node* root) {
  if (root == NULL) return 0;
  return height(root -> left) - height(root -> right);
}

node* rightRotate(node* root) {
  node* p = root, *q = p -> left, *r = q -> right;
  q -> right = p, p -> left = r;
  p -> height = 1 + max(height(p -> left), height(p -> right));
  q -> height = 1 + max(height(q -> left), height(q -> right));
  return q;
}

node* leftRotate(node* root) {
  node* p = root, *q = p -> right, *r = q -> left;
  q -> left = p, p -> right = r;
  p -> height = 1 + max(height(p -> left), height(p -> right));
  q -> height = 1 + max(height(q -> left), height(q -> right));
  return q;  
}

node* insertNode(node* root, int element) {
  node* q = (node*) malloc(sizeof(node));
  q -> data = element, q -> height = 0; q -> left = NULL, q -> right = NULL;
  if (root == NULL) root = q;
  else {
    if (element < root -> data) root -> left = insertNode(root -> left, element);
    else if (element > root -> data) root -> right = insertNode(root -> right, element);
    else return root;
    root -> height = 1 + max(height(root -> left), height(root -> right));
    int balance = balanceFactor(root);

    //4 cases
    if (balance > 1 && element < root -> left -> data) {     // LL Imbalance
      root = rightRotate(root);
    }
    if (balance < -1 && element > root -> right -> data) {   // RR Imbalance
      root = leftRotate(root);
    }
    if (balance > 1 && element > root -> left -> data) {     // LR Imbalance
      root -> left = leftRotate(root -> left);
      root = rightRotate(root);
    }
    if (balance < -1 && element < root -> right -> data) {   // RL Imbalance
      root -> right = rightRotate(root -> right);
      root = leftRotate(root);
    }
  }
  return root;
}

node* createAVLTree() {
  node* root = (node*) malloc(sizeof(node));
  root = NULL;
  int n;
  printf("How many elements? "); scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int element;
    printf("Enter data: "); scanf("%d", &element);
    root = insertNode(root, element);
  }
  return root;
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
  node* root = (node*) malloc(sizeof(node));
  root = createAVLTree();
  inorderTraversal(root);
}