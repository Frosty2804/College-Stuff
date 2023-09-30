#include <stdio.h>
#include <stdlib.h>

int* queue, front = 0, rear = 0, length = 0;

void enqueue(int element) {
  rear = (rear + 1) % length;
  if (rear == front) {
    printf("\nOverflow");
    if (rear == 0) rear = length - 1;
    else rear--;
  }
  else queue[rear] = element;
}

int dequeue() {
  if (front == rear) {
    printf("\nUnderflow");
    return -1;
  }
  front = (front + 1) % length;
  return queue[front];
}

void printCircluarQueue() {
  if (rear > front) {
    for (int i = front + 1; i <= rear; i++) {
      printf("\nElement: %d", queue[i]);
    }
  }
  else {
    for (int i = front + 1; i < length; i++) {
      printf("\nElement: %d", queue[i]);      
    }
    for (int i = 0; i <= rear; i++) {
      printf("\nElement: %d", queue[i]);
    }
  }
}

void main() {
  printf("Enter length of the queue: "); scanf("%d", &length);
  queue = (int*) malloc(sizeof(int) * (++length));
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  dequeue();
  enqueue(4);
  dequeue();
  printCircluarQueue();
}