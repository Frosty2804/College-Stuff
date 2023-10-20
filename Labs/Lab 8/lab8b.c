#include <stdio.h>
#include <stdlib.h>

//quick sort

int* arr, n;

int partition(int* arr, int start, int end) {
  int pivot = arr[end];   //choose last element as pivot
  int i = start - 1, temp;
  for (int j = start; j < end; j++) {
    if (arr[j] < pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  i++;
  temp = arr[i];
  arr[i] = pivot;
  arr[end] = temp;
  return i;
}

void quickSort(int* arr, int start, int end) {
  if (start < end) {
    int part = partition(arr, start, end);
    quickSort(arr, start, part - 1);
    quickSort(arr, part + 1, end);
  }
}

void displayFunTree(int* arr, int start, int end) {
  if (start < end) {
    printf("QS(%d, %d) calls: ", start + 1, end + 1);
    printf("partition(%d, %d), ", start + 1, end + 1);
    int part = partition(arr, start, end);
    printf("QS(%d, %d) and ", start + 1, part);
    printf("QS(%d, %d)", part + 2, end + 1);
    printf("\n");
    displayFunTree(arr, start, part - 1);
    displayFunTree(arr, part + 1, end);
  }
}

void main() {
  printf("How many elements? "); scanf("%d", &n);
  arr = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1); scanf("%d", &arr[i]);
  }
  displayFunTree(arr, 0, n - 1);
  quickSort(arr, 0, n - 1);
  printf("\nSorted Elements: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
