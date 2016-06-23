#include<stdio.h>
#define OPPRIMAXLENGTH 9

//���������ȶ�ջ
struct opPriority {
	char ch;
	int pri;
}
leftPri[] = { { '=', 0 }, { '(', 1 }, { '+', 3 }, { '-', 3 }, { '*', 5 }, { '/', 5 }, { ')', 9 }, { '@', 8 }, { '#', 8 } },
rightPri[] = { { '=', 0 }, { '(', 9 }, { '+', 2 }, { '-', 2 }, { '*', 4 }, { '/', 4 }, { ')', 1 }, { '@', 7 }, { '#', 7 } };

//��ȡ���ַ����ȶ�
int getLeftPriority(char op) {
	int i = 0;
	for (; i < OPPRIMAXLENGTH; i++) {
		if (leftPri[i].ch == op) {
			return leftPri[i].pri;
		}
	}
	return -1;
}

//��ȡ���ַ����ȶ�
int getRightPriority(char op) {
	int i = 0;
	for (; i < OPPRIMAXLENGTH; i++) {
		if (rightPri[i].ch == op) {
			return rightPri[i].pri;
		}
	}
	return -1;
}

//�ж��ַ��Ƿ�Ϊ������
bool isOperator(char ch) {
	switch (ch) {
		case '(':
		case '+':
		case '-':
		case '*':
		case '/':
		case ')':
			return true;
			break;
		default:
			break;
	}
	return false;
}

//�Ա������ַ����ȶ�
int ComparisionOfPriority(char leftOp, char rightOp) {
	int leftOpPri = getLeftPriority(leftOp);
	int rightOpPri = getRightPriority(rightOp);
	if (leftOpPri == rightOpPri) {
		return 0;
	} else if (leftOpPri > rightOpPri) {
		return -1;
	} else {
		return 1;
	}
}