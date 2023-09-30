#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
} node;

node* head = NULL;

node* createLinkedList(int noOfElements) {
  node* headTemp, *p;

  for (int i = 0; i < noOfElements; i++) {
    if (i == 0) {
      headTemp = (node*) malloc(sizeof(node));
      printf("Enter Data in node %d: ", i); scanf("%d", &(headTemp -> data));
      headTemp -> next = NULL;
      p = headTemp;
    }
    else {
      node* q = (node*) malloc(sizeof(node));
      printf("Enter Data in node %d: ", i); scanf("%d", &(q -> data));
      q -> next = NULL;
      p -> next = q;
      p = p -> next; 
    }
  }
  return headTemp;
}

void addNodeStart() {
  node* q = (node*) malloc(sizeof(node));
  printf("Enter Data in new node 0: "); scanf("%d", &(q -> data));
  q -> next = head;
  head = q;
}

void addNodeEnd() {
  node* p = head;
  int i = 0;
  while (p -> next != NULL) {
    p = p -> next;
    i++;
  }

  node* q = (node*) malloc(sizeof(node));
  printf("Enter Data in node %d: ", i+1); scanf("%d", &(q -> data));
  q -> next = NULL;
  p -> next = q;
}

void addNthNode(int index) {
  node* p = head;
  for (int i = 0; i < index; i++) {
    p = p -> next;
  }

  node* q = (node*) malloc(sizeof(node));
  printf("Enter Data in new node %d: ", index); scanf("%d", &(q -> data));  
  q -> next = p -> next;
  p -> next = q;
}

void pop() {
  node* p = head;
  if (p = NULL) return;
  if (p -> next = NULL) {
    head = NULL;
    free(p);
  }
  else{
    while (p -> next -> next != NULL) {
      p = p -> next;
    }
    node* q = p -> next;
    p -> next = NULL;
    free(q);
  }
}

void removeNthNode(int index) {
  node* p = head;
  if (p == NULL) return;
  if (index == 0) {
    if (p -> next == NULL) {
      head = NULL;
    }
    else {
      head = p -> next;
    }
    free(p);
    return;
  }
  
  for (int i = 0; i < index - 1; i++) {
    p = p -> next;
  }
  node* q = p -> next;
  p -> next = q -> next;
  free(q);
}

node* arrToList(int arr[], int length) {
  node* headTemp = NULL, *p;
  for (int i = 0; i < length; i++) {
    if(i == 0) {
      headTemp = (node*) malloc(sizeof(node));
      headTemp -> data = arr[0];
      headTemp -> next = NULL;
      p = headTemp;
    }
    else {
      node* q = (node*) malloc(sizeof(node));
      q -> data = arr[i];
      q -> next = NULL;
      p -> next = q;
      p = p -> next;
    }
  }
  return headTemp;
}

node* reverseList() {
  node* headTemp = head;
  node* current = headTemp, *prev = NULL, *next;
  while (current != NULL) {
    next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
  }
  headTemp = prev;
  return headTemp;
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

void printLLElementsReverse(node* headPtr, int index) {
  node* p = headPtr;
  if (p == NULL) return;
  index++;
  printLLElementsReverse(p -> next, index);
  printf("\nElement at index %d: %d", --index, p -> data);
  index--;
}

void main() {
  int arr[] = {0, 1, 2 ,15 ,4 ,5};
  int length = sizeof(arr)/ sizeof(int);
  head = arrToList(arr, length);
  printLLElements();
  printLLElementsReverse(head, 0);
}