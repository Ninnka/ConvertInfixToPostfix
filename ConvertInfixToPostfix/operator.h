#include<stdio.h>
#define MaxSize 1024

typedef struct {
	char data[MaxSize];
	int top;
}Operator;

void initOperatorStack(Operator *op);
void pushOperatorStack(Operator *op, char ch);
char popOperatorStack(Operator *op);

//��ʼ�������ջ
void initOperatorStack(Operator *op) {
	op->top = -1;
	op->top++;
	op->data[op->top] = '=';
}

//���������ջ
void pushOperatorStack(Operator *op, char ch) {
	op->top++;
	op->data[op->top] = ch;
}

//���������ջ
char popOperatorStack(Operator *op) {
	if (op->top > -1) {
		char popChar = op->data[op->top];
		op->top--;
		return popChar;
	}
}