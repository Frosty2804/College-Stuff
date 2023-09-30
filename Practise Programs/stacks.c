#include <stdio.h>
#include <stdlib.h>

//implementation of array based stack functions
// int top = -1, length = 5, *arr;

// void push(int element) {
//   top++;
//   if (top >= length) {
//     printf("\nStack is full!");
//     top--;
//   }
//   else arr[top] = element;
// }

// void pop() {
//   if (top == -1) {
//     printf("\nArray is empty");
//     return;
//   }
//   top = top - 1;
// }

// void extend(int newLength) {
//   length = newLength;
//   arr = (int*)realloc(arr, newLength*sizeof(int));
// }

// void displayStack() {
//   for (int i = 0; i < length; i++) {
//     printf("%d ", arr[i]);
//     printf("\n");
//   }
// }

//implementation of stacks using linked list
typedef struct node{
  int data;
  struct node* next;
} node;

node* head = NULL;

void printList() {
  node* p = head;
  while (p != NULL) {
    printf("\n%d", p -> data);
    p = p -> next;
  }
}

void push(int element) {
  node* p = head;
  node* q = (node*)malloc(sizeof(node));
  q -> data = element;
  head = q;
  q -> next = p;
}

void pop() {
  node* p = head;
  if (head = NULL) printf("List is empty!");
  else {
  head = p -> next;
  free(p);
  }
}

int main() {
  push(5);
  printList();
  push(10);
  push(15);
  printList();
  pop();
  printList();
}