#include <stdio.h>
#include <stdlib.h>

//implentation of a stack using linked list
typedef struct node {
  int data;
  struct node* next;
} node;

node* top = NULL;

void push(int element) {
  node* p = (node*) malloc(sizeof(node));
  p -> data = element, p -> next = NULL;
  if (top == NULL) top = p;
  else {
    node* temp = top;
    top = p;
    p -> next = temp;
  }
}

int pop() {
  if (top == NULL) {
    printf("\nStack Underflow");
    return -1;
  }
  node* temp = top;
  int element = top -> data;
  top = top -> next;
  free(temp);
  return element;
}

void displayStack() {
  node* p = top; 
  int i = 0;
  while (p != NULL) {
    printf("\nelement at index %d: %d", i, p -> data);
    p = p -> next;
    i++;
  }
}

void main() {
  push(4);
  push(5);
  push(6);
  displayStack();
  pop();
  displayStack();
}