#include <stdio.h>
#define MaxSize 1024

typedef struct {
	char data[MaxSize];
	int top;
}Digit;

void initDigitStack(Digit *digit);
void pushDigitStack(Digit *digit, char ch);
char popDIgitStack(Digit *digit);

//��ʼ��������ջ
void initDigitStack(Digit *digit) {
	digit->top = -1;
}

//��ʼ��������ջ
void pushDigitStack(Digit *digit, char ch) {
	digit->top++;
	digit->data[digit->top] = ch;
}

//����������ջ
char popDIgitStack(Digit *digit) {
	if (digit->top > -1) {
		char popChar = digit->data[digit->top];
		digit->top--;
		return popChar;
	}
}