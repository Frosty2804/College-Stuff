#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

//inflix to postfix conversion

char stack[SIZE];
int top = -1, validOperatorCount = 4;
char validOperators[4] = {'+', '-', '*', '/'};

//defining stack operations
void push(char element) {
  if (top >= SIZE - 1) {
    printf("Stack Overflow.");
  }
  else {
    stack[++top] = element;
  }
}

char pop() {
	if (top < 0) {
		printf("STACK UNDERFLOW");
		return -1;
	}
  else {
		char element = stack[top--];
		return element;
	}
}

char topElement() {
  return stack[top];
}

// define function that is used to determine whether any symbol is operator or not
int isOperator(char element) {
  for (int i = 0; i < validOperatorCount; i++) {
    if (element == validOperators[i]) return 1;
    else return 0;
  }
}

// define function that is used to assign precendence to operator.
int precedenceOf(char element) {
  if (element == validOperators[2] || element == validOperators[3]) return 2;
  if (element == validOperators[0] || element == validOperators[1]) return 1;
  else return 0;
}

char* infixToPostfix(char* infixExpression) {
  char* postfixExpression = (char*) malloc(sizeof(char) * (strlen(infixExpression) + 1));
  int i = 0, j = 0;
  while (infixExpression[i] != '\0') {
    char current = infixExpression[i];
    if (!isOperator(current)) {
      postfixExpression[j] = infixExpression[i];
      i++, j++;
    }
    else {
      if (precedenceOf(current) > precedenceOf(topElement())) {
        push(current);
        i++;
      }
      else postfixExpression[j++] = pop();
    }
  }
  while (top != -1) { 
    postfixExpression[j++] = pop();
  }
  postfixExpression[j] = '\0';
  return postfixExpression;
}

int main() {
  char* infix = "4*6-1/7+8";
  char* postfix = infixToPostfix(infix);
  printf("\n%s", postfix);
}