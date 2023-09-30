#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} node;

typedef struct addressNode {
  node* address;
  struct addressNode* next;
} addressNode;

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

void printLLElements(node* head) {
  node* p = head; 
  int i = 0;
  while (p != NULL) {
    printf("\nelement at index %d: %d", i, p -> data);
    p = p -> next;
    i++;
  }
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

int circularListLength(node* head) {
  node* p = head;
  int length = 0;
  do {
    p = p -> next;
    length++;
  }
  while (p != head);

  return length;
}

node* updateTail(node* head) {
  node* p = head;
  if (p == NULL) return p;
  while (p -> next != NULL) {
    p = p -> next;
  }
  return p;
}

node* updateTailCircularList(node* head) {
  node* p = head, *q = p -> next;
  while (q != head) {
    q = q -> next;
    p = p -> next;
  }
  return p;
}

node* updateSecondLast(node* head) {
  node* p = head;
  if (p == NULL || p -> next == NULL) return NULL;
  while (p -> next -> next != NULL) {
    p = p -> next;
  }
  return p;
}

node* updateSecondLastCircularList(node* head) {
  node* p = head;
  if (p -> next -> next == NULL) {
    return p;
  }
  node* q = p -> next -> next;
  while (q != head) {
    q = q -> next;
    p = p -> next;
  }
  return p;
}

void bubbleSortArray(int arr[], int length) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

//Q1  Print the Middle of a given linked list
int grabMiddleElement(node* head) {
  node* p = head;
  if (p == NULL) return 0;
  int length = listLength(p), middleIndex = length/2;
  for (int i = 0; i < middleIndex; i++) {
    p = p -> next;
  }
  return (p -> data);
}

//Q2 Reverse a linked list
void reverseList(node* p, node** head) {
  if (p -> next == NULL) {
    *head = p;
    return;
  }
  reverseList(p -> next, head);
  node* q = p -> next;
  q -> next = p;
  p -> next = NULL;
}

//Q4 Rotate a linked list.
//rotate Anti-Clockwise
void shiftLeft(node** head, int shift, int length) {
  if (shift == 0) return;
  if (shift >= length) shift %= length;
  node* p = *head, *tail = updateTail(*head);
  for (int i = 0; i < shift - 1; i++) {
    p = p -> next;
  }
  node* q = p -> next;
  p -> next = NULL;
  tail -> next = *head;
  *head = q;
}

//rotate Clockwise
void shiftRight(node** head, int shift, int length) {
  if (shift >= length) shift %= length;
  shiftLeft(head, length - shift, length);
}

//Q5 Find Nth node from end of linked list
int findFromLast(node* head, int n) {
  if (n > listLength(head)) {
    printf("Not a valid indice.\n");
    return -1;    
  }
  node* p = head;
  int nodeFromFront = listLength(head) + 1 - n;
  for (int i = 0; i < nodeFromFront - 1; i++) {
    p = p -> next;
  }
  return p -> data;
}

//Q6 Delete last occurrence of an item from linked list
void deleteLastOccurrence(node** head, int element) {
  node* p = *head;
  int index = 0, elementAtIndex = 0;
  while (p != NULL) {
    if (p -> data == element) elementAtIndex = index;
    index++;
    p = p -> next;
  }
  p = *head;
  if (elementAtIndex == 0) {
    *head = p -> next;
    free(p);
  }
  else {
    for (int i = 0; i < elementAtIndex - 1; i++) {
      p = p -> next;
    }
    node* q = p -> next;
    p -> next = q -> next;
    free(q);
  }
}

//Q7 Delete middle of linked list
void deleteMiddleElement(node* head) {
  node* p = head;
  if (p == NULL) return;
  int length = listLength(p), middleIndex = length/2;
  for (int i = 0; i < middleIndex - 1; i++) {
    p = p -> next;
  }
  node* q = p -> next;
  p -> next = q -> next;
  free(q);
}

//Q8 Remove duplicate elements from sorted linked list
void removeDuplicates(node* head) {
  node* p = head;
  while (p -> next != NULL) {
    node* q = p -> next;
    if (p -> data == q -> data) {
      p -> next = q -> next;
      free(q);
    }
    p = p -> next;
  }
}

//Q9 Detect Loop in linked list
void detectLoop(node* head) {
  node* slow = head, *fast = slow;
  while (fast != NULL && fast -> next != NULL) {
    slow = slow -> next;
    fast = fast -> next -> next;
    if (fast == slow) {
      printf("Loop exists in given List.");
      return;
    }
  }
  printf("Loop dosent exist in given List.");
}

//Q10 Delete N nodes after M nodes of a linked list
void deleteNAfterM(node* head, int m, int n) {
  if ((m + n > listLength(head)) || (m == 0 && n >= listLength(head))) {
    printf("indices not valid");
    return;
  }
  node* p = head;
  for (int i = 0; i < m - 1; i++) {
    p = p -> next;
  }
  for (int i = 0; i < n; i++) {
    node* q = p -> next;
    p -> next = q -> next;
    free(q);
  }
}

//Q11 Merge a linked list into another linked list at alternate positions
void alternateMerge(node* list1, node** ptrToList2) {
  node* list2 = *(ptrToList2);
  node* p = list1, *q = list2;
  int length1 = listLength(list1), length2 = listLength(list2);
  for (int i = 0; i < length1; i++) {
    if (q == NULL) break;
    node* r = p -> next;
    node* s = q;
    q = q -> next;
    p -> next = s;
    s -> next = r;
    p = r;
  }
  *(ptrToList2) = q;
}

//Q12 Circular Linked List Traversal
void traverseCircularList(node* head) {
  node* p = head;
  int index = 0;
  if (p == NULL) return;
  do {
    printf("\nElement at index %d: %d", index, p -> data);
    index++;
    p = p -> next;
  }
  while (p != head);
}

//Q13 Deletion from a Circular Linked List
void deleteNthNodeCircularList(node** head, int n) {
  node* p = *head, *tail = updateTailCircularList(*head), *secondLast = updateSecondLastCircularList(*head);
  if (p == NULL) return;
  if (n == 1) {
    *head = p -> next;
    free(p);
    tail -> next = *head;
    return;
  }
  if (n == circularListLength(*head)) {
    secondLast -> next = *head;
    free(tail);
    return;
  }

  for (int i = 0; i < n - 2; i++) {
    p = p -> next;
  }
  node* q = p -> next;
  p -> next = q -> next;
  free(q);
}

//Q14 Delete without head pointer
void deleteNodeWithoutHead(node* p) {
  if (p -> next == NULL) {
    node* q = p;
    p = NULL;
    free(q);
    return;
  }
  node* nextNode = p -> next;
  p -> data = nextNode -> data;
  p -> next = nextNode -> next;
  free(nextNode);
}

//Q15 Implement Queue using Linked List
void enqueue(int element, node* head, node* tail) {
  node* p = (node*) malloc(sizeof(node));
  p -> data = element;
  p -> next = NULL;
  if (head == NULL && tail == NULL) head = p;
  else tail -> next = p;
}

void dequeue(node* head) {
  node* p = head;
  head = p -> next;
  free(p);
}

//Q16 Implement a stack using singly linked list
void push(node** head, int element) {
  node* p = *head;
  node* q = (node*)malloc(sizeof(node));
  q -> data = element;
  *head = q;
  q -> next = p;
}

void pop(node** head) {
  node* p = *head;
  if (*head = NULL) printf("List is empty!");
  else {
  *head = p -> next;
  free(p);
  }
}

//Q17 Remove every k-th node of the linked list
void deleteEveryKthNode(node** head, int k) {
  node* p = *head;
  if (k == 1) head = NULL;
  for (int i = 0; p != NULL; i++) {
    if (k == 1) {
      node* q = p;
      p = p -> next;
      free(q);
    }
    else {
      if ((i + 2) % k == 0) {
        node* q = p -> next;
        p -> next = q -> next;
        free(q);
        i = -1;
      }
      p = p -> next;
    }
  }
}

//Q18 Pairwise swap of a Linked list
void swapPairwise(node** head) {
  node* p = *head;
  while (p -> next != NULL) {
    node* q = p -> next;
    if (p == *head) {
      p -> next = q -> next;
      q -> next = p;
      *head = q;
    }
    else {
      node* r = q -> next;
      if (r == NULL) return;
      q -> next = r -> next;
      r -> next = q;
      p -> next = r;
      p = q;
    }
  }
}

//Q19 Occurrence of an integer in a Linked List
int elementCount(node* head, int element) {
  node* p = head;
  int count = 0;
  while (p != NULL) {
    if (p -> data == element) count++;
    p = p -> next;
  }
  return count;
}

//Q20 Given a Linked list of 0s, 1s and 2s, sort it
node* sort(node* head) {
  node* p = head;
  int length = listLength(head);
  int* arr = (int*) malloc(length * sizeof(int));
  for(int i = 0; i < length; i++) {
    *(arr+i) = p -> data;
    p = p -> next;
  }
  bubbleSortArray(arr, length);
  p = head;
  for(int i = 0; i < length; i++) {
    p -> data = *(arr+i);
    p = p -> next;
  }  
}

//Q21 Deletion in Linked List
void removeNthNode(node** head, int n) {
  node* p = *head;
  if (p == NULL) return;
  if (n == 1) {
    if (p -> next == NULL) {
      *head = NULL;
    }
    else {
      *head = p -> next;
    }
    free(p);
    return;
  }
  
  for (int i = 0; i < n - 2; i++) {
    p = p -> next;
  }
  node* q = p -> next;
  p -> next = q -> next;
  free(q);
}

void main() {
  node* head = createLinkedList(5);
  shiftRight(&head, 3, 5);
  printLLElements(head);
}