#include <stdio.h>
#include <stdlib.h>

//merge sort

int* arr, n;

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
  if (start < end) {
    int m = (start + end)/2;
    mergeSort(start, m);
    mergeSort(m + 1, end);  //diving the array into two halves
    merge(start, m, end);
  }
}

void displayFunTree(int start, int end) {
  if (start < end) {
    printf("MS(%d, %d) calls: ", start + 1, end + 1);
    int m = (start + end)/2;
    printf("MS(%d, %d), ", start + 1, m + 1);
    printf("MS(%d, %d) and ", m + 2, end + 1);
    printf("merge(%d, %d, %d)", start + 1, m + 1, end + 1);
    printf("\n");
    displayFunTree(start, m);
    displayFunTree(m + 1, end);
  }
}

void main() {
  printf("How many elements? "); scanf("%d", &n);
  arr = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1); scanf("%d", &arr[i]);
  }
  displayFunTree(0, n - 1);
  printf("\nSorted Elements: ");
  mergeSort(0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
