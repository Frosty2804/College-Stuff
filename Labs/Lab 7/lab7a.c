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

void merge(int start, int m, int end) {
  int l1 = m - start + 1, l2 = end - m;
  int Larr[l1], Rarr[l2];   //creating temp arrays
  for (int i = 0; i < l1; i++) {
    Larr[i] = arr[start + i];
  }
  for (int i = 0; i < l2; i++) {
    Rarr[i] = arr[(m + 1) + i];
  }
  int i = 0, j = 0, k = start; 
  while (i < l1 && j < l2) {
    if (Larr[i] <= Rarr[j]) {
      arr[k++] = Larr[i++];
    }
    else {
      arr[k++] = Rarr[j++];
    }
  }
  //if there are any elements remaining in Larr and Rarr
  while (i < l1) {
    arr[k++] = Larr[i++];
  }
  while (j < l2) {
    arr[k++] = Rarr[j++];
  }
}

void mergeSort(int start, int end) {
  if (start >= end) return;
  int m = (start + end)/2;
  mergeSort(start, m);
  mergeSort(m + 1, end);  //diving the array into two halves
  merge(start, m, end);
}

void main() {
  printf("How many elements? "); scanf("%d", &n);
  arr = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1); scanf("%d", &arr[i]);
  }
  bubbleSort();
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}