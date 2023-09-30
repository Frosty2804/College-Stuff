#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char data[30];
  struct node* next;
} node;

//implementation of a queue using linked list to store strings
node* head = NULL, *tail = NULL;

node* updateTail() {
  node* p = head;
  if (p == NULL) return p;
  while (p -> next != NULL) {
    p = p -> next;
  }
  return p;
}

void printLLElements() {
  node* p = head; 
  int i = 0;
  while (p != NULL) {
    printf("\nelement at index %d: %s", i, p -> data);
    p = p -> next;
    i++;
  }
}

void insertElement(node* p, char element[]) {
  int length = strlen(element);
  for (int i = 0; i < length; i++) {
    p -> data[i] = element[i];
  }
  p -> data[length] = '\0';
}

void enqueue(char element[]) {
  tail = updateTail();
  node* p = (node*) malloc(sizeof(node));
  insertElement(p, element);
  p -> next = NULL;
  if (tail == NULL) head = p;
  else tail -> next = p;
}

void dequeue() {
  node* p = head;
  head = head -> next;
  free(p);
}

void main() {
  enqueue("Sylvan");
  enqueue("Meow");
  enqueue("Figma");
  printLLElements();
  dequeue();
  printf("\n");
  printLLElements();
}