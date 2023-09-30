#include <stdio.h>
//towers of hanoi
void printMoveDisk(int start, int end) {
  printf("%d -> %d\n", start, end);
}

void henoi(int noOfDisks, int start, int end) {
  int other = 6 - (start + end);
  if (noOfDisks == 1) printMoveDisk(start, end);
  else {
    henoi(noOfDisks - 1, start, other);
    printMoveDisk(start, end);
    henoi(noOfDisks - 1, other, end);
  }
}

//print 'n' elements of the Fibonacci Series
int printFibonacci(int n) {
  if (n == 1) {
    printf("%d", 0);
  }
  else if (n == 2) {
    printf("%d", 1);
    printFibonacci(n - 1);
  }
  else {
    
  }
}

void main() {
  // henoi(4, 1, 3);
  printFibonacci(15);
}