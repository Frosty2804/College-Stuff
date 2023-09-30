#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
} node;

typedef struct doubleNode {
  int data;
  struct doubleNode* prev;
  struct doubleNode* next;
} doubleNode;

typedef struct matrixNode {
  int data;
  struct matrixNode* down;
  struct matrixNode* right;
} matrixNode;

typedef struct treeNode {
  int data;
  struct treeNode* left;
  struct treeNode* right;
} treeNode;


node* head = NULL;
doubleNode* head2 = NULL;
treeNode* root = NULL;

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

doubleNode* createDoubleLinkedList(int noOfElements) {
  doubleNode* head2Temp, *p;
  for (int i = 0; i < noOfElements; i++) {
    if (i == 0) {
      head2Temp = (doubleNode*) malloc(sizeof(doubleNode));
      printf("Enter Data in node %d: ", i); scanf("%d", &(head2Temp -> data));
      head2Temp -> prev = NULL, head2Temp -> next = NULL;
      p = head2Temp;
    }
    else {
      doubleNode* q = (doubleNode*) malloc(sizeof(doubleNode));
      printf("Enter Data in node %d: ", i); scanf("%d", &(q -> data));
      q -> next = NULL;
      p -> next = q;
      q -> prev = p;
      p = p -> next; 
    }
  }
  return head2Temp;
}

void insertInTree(treeNode** root, int data) {
  if (*root == NULL) {
    *root = (treeNode*) malloc(sizeof(treeNode));
    (*root) -> data = data;
    (*root) -> left = NULL, (*root) -> right = NULL; 
  }
  else if (data <= (*root) -> data) {
    insertInTree(&((*root) -> left), data);
  }
  else {
    insertInTree(&((*root) -> right), data);
  }
}

treeNode* createTree(int arr[], int length) {
  treeNode* rootTemp;
  for (int i = 0; i < length; i++) {
    insertInTree(&rootTemp, arr[i]);
  }
  return rootTemp;
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

void printDoubleLLElements(doubleNode* head2) {
  doubleNode* p = head2; 
  int i = 0;
  while (p != NULL) {
    printf("\nelement at index %d: %d", i, p -> data);
    p = p -> next;
    i++;
  }
}

void reversePrintDoubleLLElements(doubleNode* head2) {
  doubleNode* p = head2;
  while (p -> next != NULL) {
    p = p -> next;
  }
  while (p != NULL) {
    printf("\nElement: %d", p -> data);
    p = p -> prev;
  }
}

void inOrderTraversalAndStore(treeNode* root, int arr[]) {
  static int index = 0;
  if (root != NULL) {
    inOrderTraversalAndStore(root -> left, arr);
    arr[index++] = root->data;
    inOrderTraversalAndStore(root -> right, arr);
  }
}

void inOrderTraversal(treeNode* root) {
  if (root != NULL) {
    inOrderTraversal(root -> left);
    printf("%d", root->data);
    inOrderTraversal(root -> right);
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

int listLengthDoubleLL (doubleNode* head2) {
  doubleNode* p = head2;
  int length = 0;
  while (p != NULL) {
    length++;
    p = p -> next;
  }
  return length;
}

node* updateSecondLast(node* head) {
  node* p = head;
  if (p == NULL || p -> next == NULL) return NULL;
  while (p -> next -> next != NULL) {
    p = p -> next;
  }
  return p;
}

node* updateTail(node* head) {
  node* p = head;
  if (p == NULL) return p;
  while (p -> next != NULL) {
    p = p -> next;
  }
  return p;
}

doubleNode* updateTailDoubleLL (doubleNode* head2) {
  doubleNode* p = head2;
  if (p == NULL) return p;
  while (p -> next != NULL) {
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

node* getStartingOfLoop(node* head) {
//to find the starting node of the loop, after the slow and fast pointer meet, bring slow pointer back to the start and let the fast pointer remain at the meeting point, move both pointers one at a time now, their meeting point will be the start of the loop
  node* slow = head, *fast = head, *loopStart = NULL;
  int loopExists = 1;
  while (loopExists) {
    slow = slow -> next;
    fast = fast -> next -> next;
    if (fast == NULL || fast -> next == NULL) {
      loopExists = 0;
      break;
    }
    if (fast == slow) {
      slow = head;
      break;
    }
  }
  if (loopExists == 0) {
    printf("Loop does not exist");
    return loopStart;
  }
  while (slow != fast) {
    slow = slow -> next;
    fast = fast -> next;
  }
  loopStart = slow;
  return loopStart;
}

//Q1 Convert singly linked list into circular linked list
void singleLinkedToCircular() {
  node* tail = updateTail(head);
  tail -> next = head;
}

//Q2 Reverse a linked list in groups of given size
void reverseInGroups(int groupSize) {
  int groups = listLength(head) / groupSize;
  node* p = head;
  for (int i = 0; i < groups; i++) {
    node* startPoint = p;
    int* arr = (int*) malloc(sizeof(int) * groupSize);
    for (int j = 0; j < groupSize; j++) {
      arr[j] = p -> data;
      p = p -> next;
    }
    p = startPoint;
    for (int j = 0; j < groupSize; j++) {
      p -> data = arr[groupSize - 1 - j];
      p = p -> next;
    }
  }
}

//Q3  Merge two sorted linked lists
void mergeLists(node* list1, node* list2) {
  node* p = list1, *q = list2, *list1Tail = updateTail(list2);
  int length1 = listLength(list1), length2 = listLength(list2);
  int* arr = (int*) malloc(sizeof(int) * (length1+length2));
  for (int i = 0; i < length1; i++) {
    arr[i] = p -> data;
    p = p -> next;
  }
  for (int i = length1; i < length1 + length2; i++) {
    arr[i] = q -> data;
    q = q -> next;
  }
  bubbleSortArray(arr, length1 + length2);
  p = list1;
  for (int i = 0; i < length1; i++) {
    p -> data = arr[i];
    p = p -> next;
  }
  for (int i = 0; i < length2; i++) {
    node* q = (node*) malloc(sizeof(node));
    q -> data = arr[length1 + i];
    q -> next = NULL;
    p = updateTail(list1);
    p -> next = q;
  }
}

//Q4 Remove loop in Linked List
void removeLoop() {
  node* p = head, *loopStart = getStartingOfLoop(head);
  while (p -> next != loopStart) {
    p = p -> next;
  }
  p -> next = NULL;
}

//Q5 Function to check if a singly linked list is palindrome
void isPalindrome() {
  node* p = head;
  int length = listLength(head);
  int* arr = (int*) malloc(length * sizeof(int));
  for (int i = 0; i < length; i++) {
    arr[i] = p -> data;
    p = p -> next;
  }
  p = head;
  for (int i = 0; i < length; i++) {
    if (p -> data != arr[length - i - 1]) {
      printf("\nNot a palindrome.");
      return;
    }
    p = p -> next;
  }
  printf("\nIs a palindrome");
}

//Q6 Remove all occurrences of one Linked list in another Linked list
void removeOccurances(node** head, node* filterList) {
  node* p = *head, *q = filterList;
  int length1 = listLength(*head), length2 = listLength(filterList);
  if (length2 > length1) {
    printf("Invalid\n");
    return;
  }
  while (p -> next != NULL) {
    node* startDeletion, *endDeletion, *current = p -> next;
    if (current -> data == q -> data) {
      startDeletion = p;
      for (int i = 0; i < length2; i++) {
        if (current -> data != q -> data) break;
        current = current -> next;
        q = q -> next;
      }
      if (q == NULL) {
        endDeletion = current;
        startDeletion -> next = endDeletion;
      }
    }
    q = filterList;
    p = p -> next;
  }
}

//Q7 Intersection point in Y shaped Linked lists
int getIntersectionNode(node* branch1, node* branch2) {
  node* p = branch1, *q = branch2;
  while (p != NULL) {
    for (int i = 0; i < listLength(branch2); i++) {
      if (p == q -> next) return (p -> data);
      q = q -> next;
    }
    q = branch2;
    p = p -> next;
  }
  return -1;
}

//Q8 Intersection of two Sorted Linked Lists
node* findCommon(node* list1, node* list2) {
  node* p = list1, *q = list2, *list3 = NULL;
  while (p != NULL) {
    for (int i = 0; i < listLength(list2); i++) {
      if (p -> data == q -> data) {
        if (list3 == NULL) {
          list3 = (node*) malloc(sizeof(node));
          list3 -> data = p -> data;
          list3 -> next = NULL;
        }
        else {
          node* r = (node*) malloc(sizeof(node));
          r -> data = p -> data;
          r -> next = NULL;
          node* list3Tail = updateTail(list3);
          list3Tail -> next = r;
        }
      }
      q = q -> next;
    }
    q = list2;
    p = p -> next;
  }
  return list3;
}

//Q9 Split a Circular Linked List into two halves
void splitCircularList(node** head1, node** head2) {
  if (head == NULL || head -> next == NULL) return;
  node* p = head, *loopStartNode = getStartingOfLoop(head), *q = loopStartNode;
  int noOfLoopElements = 0, middleIndex;
  do {
    noOfLoopElements++;
    q = q -> next;
  }
  while (q != loopStartNode);
  if (noOfLoopElements % 2 == 0) {
    middleIndex = noOfLoopElements/2 - 1;
  }
  else if (noOfLoopElements % 2 != 0) {
    middleIndex = noOfLoopElements/2;
  }
  for (int i = 0; i < middleIndex; i++) {
    p = p -> next;
  }
  node* r = p -> next;
  *head1 = head, p -> next = *head1;
  *head2 = r;
  while (r -> next != loopStartNode) {
    r = r -> next;
  }
  r -> next = *head2;
}

//Q10 Find pairs with given sum in doubly linked list
void findPairsWithSumInList(int sum) {
  doubleNode* p = head2, *q;
  while (p) {
    doubleNode* q = p -> next;
    while (q) {
      if (p -> data + q -> data == sum) {
        printf("Pair of Numbers equal to %d are: %d + %d\n", sum, p -> data, q -> data);
      }
      q = q -> next;
    }
    p = p -> next;
  }
}

//Q11 Remove duplicates from an unsorted doubly linked list
void removeDuplicatesFromDoubleLL() {
  doubleNode* p = head2;
  while (p -> next != NULL) {
    doubleNode* q = p -> next;
    while (q != NULL) {
      if (q -> data == p -> data) {
        (q -> prev) -> next = q -> next;
      }
      q = q -> next;
    }
    q = p -> prev;
    while (q != NULL) {
      if (q -> data == p -> data) {
        (q -> prev) -> next = q -> next;
      }
      q = q -> next;
    }
    p = p -> next;
  }
}

//Q12 Intersection point of two Linked Lists.
//same as Q7

//Q13 Add two numbers represented by Linked lists
void addLinkedLists(node* list1, node* list2) {
  node* p = list1, *q = list2;
  int length1 = listLength(list1), length2 = listLength(list2), *arr1, *arr2, *resultArr, carry = 0;
  if (length1 > length2) {
    arr1 = (int*) malloc(sizeof(int) * length1), arr2 = (int*) malloc(sizeof(int) * length1), resultArr = (int*) malloc(sizeof(int) * length1);
    for (int i = 0; i < length1; i++) {
      arr1[length1 - 1 - i] = p -> data;
      p = p -> next;
    }
    for (int i = 0; i < length1 - length2; i++) {
      arr2[length1 - 1 - i] = 0;
    }
    for (int i = length1 - length2; i < length1; i++) {
      arr2[length1 - 1 - i] = q -> data;
      q = q -> next;
    }
    for (int i = 0; i < length1; i++) {
      int sum = arr1[i] + arr2[i] + carry;
      if (sum > 9) {
        resultArr[i] = sum % 10;
        carry = sum / 10;
      }
      else {
      resultArr[i] = sum;
      carry = 0;
      }
    }
    if (carry != 0) printf("%d", carry);
    for (int i = 0; i < length1; i++) {
      printf("%d", resultArr[length1 - 1 - i]);
    }
  }
  else {
    arr1 = (int*) malloc(sizeof(int) * length2), arr2 = (int*) malloc(sizeof(int) * length2), resultArr = (int*) malloc(sizeof(int) * length2);
    for (int i = 0; i < length2; i++) {
      arr2[length2 - 1 - i] = q -> data;
      q = q -> next;
    }
    for (int i = 0; i < length2 - length1; i++) {
      arr1[length2 - 1 -i] = 0;
    }
    for (int i = length2 - length1; i < length2; i++) {
      arr1[length2 - 1 -i] = p -> data;
      p = p -> next;
    }
    for (int i = 0; i < length2; i++) {
      int sum = arr1[i] + arr2[i] + carry;
      if (sum > 9) {
        resultArr[i] = sum % 10;
        carry = sum / 10;
      }
      else {
      resultArr[i] = sum;
      carry = 0;
      }
    }
    if (carry != 0) printf("%d", carry);
    for (int i = 0; i < length2; i++) {
      printf("%d", resultArr[length2 - 1 - i]);
    }   
  }
}

//Q14 Multiply two numbers represented by Linked Lists
void multiplyinkedLists(node* list1, node* list2) {
  node* p = list1, *q = list2;
  int num1 = 0, num2 = 0, result;
  while (p || q) {
    if (p) {
      num1 = num1 * 10 + p -> data;
      p = p -> next;
    }
    if (q) {
      num2 = num2 * 10 + q -> data;
      q = q -> next;
    }
  }
  result = num1 * num2;
  printf("Result: %d", result);
}

//Q15 Swap Kth node from beginning with Kth node from end in a Linked List
void swapKthStartEnd(int k) {
  if (head == NULL) return;
  node* p = head, *q = head, *r, *s, *t;
  if (k == 1) {
    node* tail = updateTail(head);
    p = head, r = head -> next, q = updateSecondLast(head), s = q -> next;
    head = s;
    s -> next = r;
    q -> next = p;
    p -> next = NULL;
    return;
  }
  for (int i = 0; i < k - 2; i++) {
    p = p -> next;
  }
  r = p -> next;
  for (int i = 0; i < listLength(head) - k - 1; i++) {
    q = q -> next;
  }
  s = q -> next, t = s -> next;
  p -> next = s;
  s -> next = r -> next;
  q -> next = r;
  r -> next = t;
}

//Q16 Sort a k sorted doubly linked list
void sortDoubleList(int k) {
  doubleNode* p = head2;
  int temp, isSwap = 0, length = listLengthDoubleLL(head2), dataArr[length];
  for (int i = 0; i < length; i++) {
    dataArr[i] = p -> data;
    p = p -> next;
  }
  for (int i = 0; i < length - 1; i++) {
    isSwap = 0;
    for (int j = 0; j < length - i - 1; j++) {
      if (dataArr[j] > dataArr[j + 1]) {
        temp = dataArr[j];
        dataArr[j] = dataArr[j + 1];
        dataArr[j + 1] = temp;
        isSwap = 1;
      }
    }
    if (!isSwap) break;
  }
  p = head2;
  for (int i = 0; i < length; i++) {
    p -> data = dataArr[i];
    p = p -> next;
  } 
}

//Q17 Rotate Doubly linked list by N nodes
void rotateDoubleLL(int n) {
  doubleNode* p = head2, *tail = updateTailDoubleLL(head2);
  if (n > listLengthDoubleLL(head2)) n = n % listLengthDoubleLL(head2);
  n = listLengthDoubleLL(head2) - n;
  if (n == 0) return;
  for (int i = 0; i < n - 1; i++) {
    p = p -> next;
  }
  tail -> next = head2; 
  head2 -> prev = tail;
  head2 = p -> next;
  head2 -> prev = NULL;
  p -> next = NULL;
}

//Q18 Convert a Binary Tree into Doubly Linked List in spiral fashion


//Q19 Convert a given Binary Tree to Doubly Linked List
doubleNode* binTreeToDoubleLL(int noOfElements) {
  doubleNode* head2Temp = NULL, *p;
  int dataArr[noOfElements];
  inOrderTraversalAndStore(root ,dataArr);
  for (int i = 0; i < noOfElements; i++) {
    if (i == 0) {
      head2Temp = (doubleNode*) malloc(sizeof(doubleNode));
      head2Temp -> data = dataArr[i];
      head2Temp -> prev = NULL, head2Temp -> next = NULL;
      p = head2Temp;
    }
    else {
      doubleNode* q = (doubleNode*) malloc(sizeof(doubleNode));
      q -> data = dataArr[i];
      q -> next = NULL;
      p -> next = q;
      q -> prev = p;
      p = p -> next; 
    }
  }
  return head2Temp;
}

//Q20 Construct a linked list from 2D matrix
matrixNode* convertMatrixToList(int noOfRows, int noOfColumns, int matrix[][noOfColumns]) {
  matrixNode* headArr[noOfRows], *rowPtr;
  for (int i = 0; i < noOfRows; i++) {
    headArr[i] = NULL;
    rowPtr = headArr[i];
    for (int j = 0; j < noOfColumns; j++) {
      matrixNode* q = (matrixNode*) malloc(sizeof(matrixNode));
      q -> data = matrix[i][j];
      q -> right = NULL, q -> down = NULL;
      if (headArr[i] == NULL) headArr[i] = q;
      else rowPtr -> right = q;
      rowPtr = q; //q = rowPtr -> right;
    }
  }
  for (int i = 0; i < noOfRows; i++) {
    matrixNode* nthRow = headArr[i], *nextRow = headArr[i + 1];
    while (nthRow && nextRow) {
      nthRow -> down = nextRow;
      nthRow = nthRow -> right, nextRow = nextRow -> right;
    }
  }
  return headArr[0];
}

//Q21 Reverse a doubly linked list in groups of given size
void reverseInGroupsDoubleLL(int groupSize) {
  int groups = listLengthDoubleLL(head2) / groupSize;
  doubleNode* p = head2;
  for (int i = 0; i < groups; i++) {
    doubleNode* startPoint = p;
    int* arr = (int*) malloc(sizeof(int) * groupSize);
    for (int j = 0; j < groupSize; j++) {
      arr[j] = p -> data;
      p = p -> next;
    }
    p = startPoint;
    for (int j = 0; j < groupSize; j++) {
      p -> data = arr[groupSize - 1 - j];
      p = p -> next;
    }
  }
}

int main() {
  int arr[] = {3, 1, 4, 13}, arr2[4];
  root = createTree(arr, 4);
  head2 = binTreeToDoubleLL(4);
  printDoubleLLElements(head2);
}