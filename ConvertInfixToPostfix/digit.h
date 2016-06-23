#include <stdio.h>
#define MaxSize 1024

typedef struct {
	char data[MaxSize];
	int top;
}Digit;

void initDigitStack(Digit *digit);
void pushDigitStack(Digit *digit, char ch);
char popDIgitStack(Digit *digit);

//初始化操作数栈
void initDigitStack(Digit *digit) {
	digit->top = -1;
}

//初始化操作数栈
void pushDigitStack(Digit *digit, char ch) {
	digit->top++;
	digit->data[digit->top] = ch;
}

//将操作数出栈
char popDIgitStack(Digit *digit) {
	if (digit->top > -1) {
		char popChar = digit->data[digit->top];
		digit->top--;
		return popChar;
	}
}