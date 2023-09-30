//a heap used to sort strings alphabetically
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** strArr, length;

void printArray(char** arr) {
  for (int i = 0; i < length; i++) {
    printf("\nName %d : %s", i + 1, arr[i]);
  }
}

int isLarger(char* str1, char* str2) {
  if(strcmp(str1, str2) > 0) return 1;
  else return 0;
}

void maxHeapify(char** arr, int parentIndex) {
  int leftIndex = 2 * parentIndex + 1, rightIndex = leftIndex + 1, largest;
  if (leftIndex < length && isLarger(arr[leftIndex], arr[parentIndex])) largest = leftIndex;
  else largest = parentIndex;
  if (rightIndex < length && isLarger(arr[rightIndex], arr[largest])) largest = rightIndex;
  if (largest != parentIndex) {
    char* temp = (char*) malloc(sizeof(char) * (strlen(arr[parentIndex]) + 1));
    strcpy(temp, arr[parentIndex]);
    strcpy(arr[parentIndex], arr[largest]);
    strcpy(arr[largest], temp);
    maxHeapify(arr, largest);
  }
}

void buildMaxHeap(char** arr) {
  //start from the smallest leaf node and apply maxHeapify
  for (int i = length/2 - 1; i >= 0; i--) {
    maxHeapify(arr, i);
  }
}

void heapSort(char** arr) {
  buildMaxHeap(arr);
  int originalLength = length;
  for (int i = length - 1; i >= 1; i--) {
    char* temp = (char*) malloc(sizeof(char) * (strlen(arr[0]) + 1));
    strcpy(temp, arr[0]);
    strcpy(arr[0], arr[i]);
    strcpy(arr[i], temp);
    length--;
    maxHeapify(arr, 0);
  }
  length = originalLength;
}

void main() {
  printf("How many elements do you want to enter: "); scanf("%d", &length);
  strArr = (char**) malloc(sizeof(char*) * length);
  char tempStr[50];
  for (int i = 0; i < length; i++) {
    printf("Enter name %d: ", i+1); scanf("%s", tempStr);
    int nameLength = strlen(tempStr) + 1;
    strArr[i] = (char*) malloc(sizeof(char) * nameLength);
    strcpy(strArr[i], tempStr);
  }
  heapSort(strArr);
  printArray(strArr);
}