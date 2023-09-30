//heaps
#include <stdio.h>
#include <stdlib.h>

int* arr, length;

void printArr(int* arr) {
  printf("\n");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
}

void maxHeapify(int* arr, int parentIndex) {
  int leftIndex = 2 * parentIndex + 1, rightIndex = leftIndex + 1, largest;
  if (leftIndex < length && arr[leftIndex] > arr[parentIndex]) largest = leftIndex;
  else largest = parentIndex;
  if (rightIndex < length && arr[rightIndex] > arr[largest]) largest = rightIndex;
  if (largest != parentIndex) {
    int temp = arr[parentIndex];
    arr[parentIndex] = arr[largest];
    arr[largest] = temp;
    maxHeapify(arr, largest);
  }
}

void buildMaxHeap(int* arr) {
  //start from the smallest leaf node and apply maxHeapify
  for (int i = length/2 - 1; i >= 0; i--) {
    maxHeapify(arr, i);
  }
}

void heapSort(int* arr) {
  buildMaxHeap(arr);
  int originalLength = length;
  for (int i = length - 1; i >= 1; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    length--;
    maxHeapify(arr, 0);
  }
  length = originalLength;
}

int main() {
  printf("Enter number of elements in the list: "); scanf("%d", &length);
  arr = (int*) malloc(sizeof(int) * length);
  printf("\n");
  for (int i = 0; i < length; i++) {
    printf("Enter element at index %d: ", i); scanf("%d", &arr[i]);
  }
  buildMaxHeap(arr);
  heapSort(arr);
  printArr(arr);
}