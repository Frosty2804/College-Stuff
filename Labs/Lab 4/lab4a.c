#include <stdio.h>
#include <stdlib.h>

//Implementation of Doubly Linked Lists
typedef struct node {
  int data;
  struct node* prev;
  struct node* next;
} node;

node* head = NULL;

node* createDoubleLinkedList(int noOfElements) {
  node* headTemp, *p;
  for (int i = 0; i < noOfElements; i++) {
    if (i == 0) {
      headTemp = (node*) malloc(sizeof(node));
      printf("Enter Data in node %d: ", i); scanf("%d", &(headTemp -> data));
      headTemp -> prev = NULL, headTemp -> next = NULL;
      p = headTemp;
    }
    else {
      node* q = (node*) malloc(sizeof(node));
      printf("Enter Data in node %d: ", i); scanf("%d", &(q -> data));
      q -> next = NULL;
      p -> next = q;
      q -> prev = p;
      p = p -> next; 
    }
  }
  return headTemp;
}

int listLength(node* head) {
  node* p = head;
  int length = 0;
  while (p != NULL) {
    length++;
    p = p -> next;
  }
  return length;
}

void printLLElements(node *head) {
  node* p = head; 
  int i = 0;
  while (p != NULL) {
    printf("\nelement at index %d: %d", i, p -> data);
    p = p -> next;
    i++;
  }
}

void insertAtN(int n, int element) {
  node* p = head;
  node* q = (node*) malloc(sizeof(node));
  q -> data = element;
  if (n == 0 || (head == NULL && n != 1)) {
    printf("Invalid position!");
    return;
  }
  if (n > listLength(head)) {
    printf("Invalid position");
    return;
  }
  if (n == 1) {
    if (head == NULL) head = q;
    else {
      q -> prev = NULL, q -> next = head;
      head = q;
    }
  }
  else {
    for (int i = 0; i < n - 2; i++) {
      p = p -> next;
    }
    q -> prev = p, q -> next = p -> next;
    p -> next = q;
  }
}

void deleteNthElement(int n) {
  node* p = head, *toDelete;
  if (n == 0 || n > listLength(head)) {
    printf("Invalid position!");
    return;
  }
  if (n == 1) {
    toDelete = p;
    p = p -> next;
    p -> prev = NULL;
    head = p;
    free(toDelete); 
    return;
  }
  for (int i = 0; i < n - 2; i++) {
    p = p -> next;
  }
  toDelete = p -> next;
  p -> next = toDelete -> next;
  p -> next -> prev = p;
  free(toDelete);
}

int returnDataAtN(int n) {
  node* p = head;
  if (n == 0 || n > listLength(head)) {
    printf("Invalid position!");
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    p = p -> next;
  }
  return p -> data;
}

int main() {
  insertAtN(1, 10);
  insertAtN(2, 10);
  insertAtN(2, 4);
  insertAtN(1, 6);
  printLLElements(head);
  deleteNthElement(1);
  printLLElements(head);
}