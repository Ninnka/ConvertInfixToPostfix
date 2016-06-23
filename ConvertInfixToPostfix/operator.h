#include<stdio.h>
#define MaxSize 1024

typedef struct {
	char data[MaxSize];
	int top;
}Operator;

void initOperatorStack(Operator *op);
void pushOperatorStack(Operator *op, char ch);
char popOperatorStack(Operator *op);

//初始化运算符栈
void initOperatorStack(Operator *op) {
	op->top = -1;
	op->top++;
	op->data[op->top] = '=';
}

//将运算符入栈
void pushOperatorStack(Operator *op, char ch) {
	op->top++;
	op->data[op->top] = ch;
}

//将运算符出栈
char popOperatorStack(Operator *op) {
	if (op->top > -1) {
		char popChar = op->data[op->top];
		op->top--;
		return popChar;
	}
}