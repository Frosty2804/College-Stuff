#include <stdio.h>
#include <stdlib.h>

//linked list implementation of queue
typedef struct node {
  int data;
  struct node* next;
} node;

node* head = NULL, *tail = NULL;

node* updateTail() {
  node* p = head;
  if (p == NULL) return p;
  while (p -> next != NULL) {
    p = p -> next;
  }
  return p;
}

void enqueue(int element) {
  node* p = (node*) malloc(sizeof(node));
  p -> data = element;
  p -> next = NULL;
  if (head == NULL && tail == NULL) head = p;
  else tail -> next = p;
}

void dequeue() {
  node* p = head;
  head = p -> next;
  free(p);
}

void printLLElements() {
  node* p = head; 
  int i = 0;
  while (p != NULL) {
    printf("\nelement at index %d: %d", i, p -> data);
    p = p -> next;
    i++;
  }
}

void main() {
  int exit = 0;
  while (exit != 1) {
    int element;
    printf("Enter element to push: "); scanf("%d", &element);
    tail = updateTail();
    enqueue(element);
    printf("Do you want to quit? (1/0) "); scanf("%d", &exit);
  }
  printLLElements();
}