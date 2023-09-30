#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

//evaluation of postfix expressions

//declaring a stack
int stack[SIZE], top = -1, validOperatorCount = 4;
char validOperators[4] = {'+', '-', '*', '/'};

void push(int element) {
  if (top >= SIZE - 1 ) {
    printf("Stack Overflow");
    return;
  }
  else stack[++top] = element;
}

int pop() {
	if (top < 0) {
		printf("STACK UNDERFLOW");
		return -1;
	}
  else {
		int element = stack[top--];
		return element;
	}
}

int topElement() {
  return stack[top];
}

// define function that is used to determine whether any symbol is operator or not
int isOperator(char element) {
  for (int i = 0; i < validOperatorCount; i++) {
    if (element == validOperators[i]) return 1;
  }
  return 0;
}

// define function that is used to assign precendence to operator.
int precedenceOf(char element) {
  if (element == validOperators[2] || element == validOperators[3]) return 2;
  if (element == validOperators[0] || element == validOperators[1]) return 1;
  else return 0;
}

int postfixEval(char* postfixExpressionn) {
  for (int i = 0; i < strlen(postfixExpressionn); i++) {
    char current = postfixExpressionn[i];
    if (!isOperator(current)) push(current - '0');
    else {
      int oprnd1 = pop();
      int oprnd2 = pop();
      switch(current) {
        case '+':
          push(oprnd1 + oprnd2);
          break;
        case '-':
          push(oprnd1 - oprnd2);
          break;
        case '*':
          push(oprnd1 * oprnd2);
          break;
        case '/':
          push(oprnd1 / oprnd2);
          break;
      }
    }
  }
  return topElement();
}

void main() {
  char postfixExpression[] = "46*17/-8+";
  printf("\n%d", postfixEval(postfixExpression));
  printf("\n%d", 4*6-1/7+8);
}