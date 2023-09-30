//evaluation of a polynomial using a doubly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int coeff, expo;
  struct node* prev, *next;
} node;

int listLength(node* head) {
  node* p = head;
  int length = 0;
  while (p != NULL) {
    length++;
    p = p -> next;
  }
  return length;
}

void insertAtPos(node** head, node* q, int pos) {
  node* p = *head;
  if (pos == 0) {
    *head = q;
    q -> next = p;
    p -> prev = q;
  }
  for (int i = 0; i < pos - 1; i++) {
    p = p -> next;
  }
  node* nextNode = p -> next;
  p -> next = q, q -> prev = p;
  q -> next = nextNode, nextNode -> prev = q;
}

void insertNode(node** head, int coeff, int expo) {
  node* p = *head;
  node* q = (node*) malloc(sizeof(node));
  q -> coeff = coeff, q -> expo = expo, q -> prev = NULL, q -> next = NULL;
  if (p == NULL) *head = q;
  else if (p -> next == NULL) {
    if (q -> expo > p -> expo) {
      *head = q;
      q -> next = p;
      p -> prev = q;
    }
    else if (p -> expo > q -> expo) {
      p -> next = q;
      q -> prev = p;
    }
  }
  else {
    int pos = 0;
    for (int i = 0; i < listLength(*head); i++) {
      if (p -> next == NULL && p -> expo > expo) {
        p -> next = q;
        q -> prev = p;
        return;
      }
      if (p -> expo > expo && p -> next -> expo < expo) {
        pos = i + 1;
        break;
      }
      p = p -> next;
    }
    p = *head;
    insertAtPos(head, q, pos);
  }
}

node* createPolynomial() {
  node* headTemp = NULL;
  int n;
  printf("How many terms? "); scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int coeff, expo;
    printf("Enter Coefficient of term %d: ", i + 1); scanf("%d", &coeff);
    printf("Enter Exponent of term %d: ", i + 1); scanf("%d", &expo);
    insertNode(&headTemp, coeff, expo);
  }
  return headTemp;
}

node* addPolynomials(node* head1, node* head2) {
  node* p = head1, *q = head2, *result = NULL;
  int length1 = listLength(p), length2 = listLength(q), resultCoeff, resultExpo;
  while (p != NULL && q != NULL) {
    if (p -> expo == q -> expo) {
      resultCoeff = p -> coeff + q -> coeff, resultExpo = p -> expo;
      insertNode(&result, resultCoeff, resultExpo);
      p = p -> next, q = q -> next;
    }
    else {
      if (p -> expo > q -> expo) {
        insertNode(&result, p -> coeff, p -> expo);
        p = p -> next;
      }
      else if (q -> expo > p -> expo) {
        insertNode(&result, q -> coeff, q -> expo);
        q = q -> next;  
      }
    }
  }
  while (p != NULL) {
    insertNode(&result, p -> coeff, p -> expo);
    p = p -> next;    
  }
  while (q != NULL) {
    insertNode(&result, q -> coeff, q -> expo);
    q = q -> next;   
  }
  return result;
}

node* multiplyPolynomials(node* head1, node* head2) {
  node* p = head1, *q = head2, *result = NULL;
  int length1 = listLength(p), length2 = listLength(q);
  node** partialProducts = (node**) malloc(sizeof(node*) * length1);
  for (int i = 0; i < length1; i++) {
    node* partialProduct = NULL;
    while (q != NULL) {
      insertNode(&partialProduct, p -> coeff * q -> coeff, p -> expo + q -> expo);
      q = q -> next;
    }
    partialProducts[i] = partialProduct;
    q = head2;
    p = p -> next;
  }
  if (length1 == 1) {
    result = partialProducts[0];
  }
  else {
    result = addPolynomials(partialProducts[0], partialProducts[1]);
    for (int i = 2; i < length1; i++) {
      result = addPolynomials(result, partialProducts[i]);
    }
  }
  return result;
}

void printPolynomial(node* polynomial) {
  node* p = polynomial;
  while (p != NULL) {
    if (p -> expo == 0) printf("%d", p -> coeff); 
    else if (p -> expo == 1) printf("%dx", p -> coeff); 
    else printf("%dx^%d", p -> coeff, p -> expo);
    if (p -> next != NULL) printf(" + ");
    p = p -> next;
  }
}

void main() {
  node* head1 = NULL, *head2 = NULL, *result = NULL;
  printf("Enter a polynomial: \n");
  head1 = createPolynomial();
  printf("\n");
  head2 = createPolynomial();
  printf("\n");
  result = multiplyPolynomials(head1, head2);
  printPolynomial(head1);
}