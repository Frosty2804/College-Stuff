#include <stdio.h>
#include <stdlib.h>

int* heap, length;

void printArray() {
  for (int i = 0; i < length; i++) {
    printf("%d ", heap[i]);
  }
}

void maxHeapify(int* arr, int index) {
  int leftIndex = 2 * index + 1, rightIndex = 2 * index + 2, largest;
  if (leftIndex < length && arr[leftIndex] > arr[index]) largest = leftIndex;
  else largest = index;
  if (rightIndex < length && arr[rightIndex] > arr[largest]) largest = rightIndex;
  if (largest != index) {
    int temp = arr[index];
    arr[index] = arr[largest];
    arr[largest] = temp;
    maxHeapify(arr, largest);
  }
}

void buildMaxHeap() {
  for (int i = (length/2) - 1; i >= 0; i--) {
    maxHeapify(heap, i);
  }
}

int main() {
  printf("\nHow many elements: "); scanf("%d", &length);
  heap = (int*) malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++) {
    printf("\nEnter Element %d: ", i + 1); scanf("%d", &heap[i]);
  }
  printf("\nOriginal List: \n");
  printArray();
  buildMaxHeap();
  printf("Modified List: \n");
  printArray();
}  