#include <stdio.h>
#include <stdlib.h>

void main() {
  int ***block, blocks = 3, rows = 4, columns = 5;
  block = (int***) malloc(sizeof(int**) * blocks);
  for (int i = 0; i < blocks; i++) {
    block[i] = (int**) malloc(sizeof(int*) * rows);
    for (int j = 0; j < rows; j++) {
      block[i][j] = (int*) calloc(sizeof(int), columns);
    }
  }
  printf("memory address: %u", &block[1][2][3]);
  int* address = &block[0][0][0] + sizeof(int)*((rows)*(blocks)*(1) + (columns)*(2) + (3));
  printf("\nmemory address: %u", address);
}