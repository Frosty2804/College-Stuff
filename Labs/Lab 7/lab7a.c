#include <stdio.h>
#include <stdlib.h>

//sorting algorithms

int* arr, n;

void bubbleSort() {
  int swapped = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = 1;
      }
    }
    if (!swapped) return;
  }
}

void selectionSort() {
  int minIndex;
  for (int i = 0; i < n - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) minIndex = j;
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

void insertionSort() {
  for (int i = 2; i < n; i++) {
    int j = i - 1;
    while (j > 0 && arr[j] > arr[i]) {
      int temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
      j--;
    }
  }
}

void main() {
  printf("How many elements? "); scanf("%d", &n);
  arr = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1); scanf("%d", &arr[i]);
  }
  quickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}