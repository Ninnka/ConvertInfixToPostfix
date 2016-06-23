#include <stdio.h>
#include <iostream>

bool isAlpha(char ch);
bool isDigit(char ch);
bool isDot(char ch);
bool isPrefix(char ch);
bool isPlusPrefix(char ch);
bool isMinusPrefix(char ch);

//�ж��ַ��Ƿ�Ϊ�ַ����»���
bool isAlpha(char ch) {

	if (ch >= 'A' && ch <= 'Z') {
		return true;
	} else if (ch >= 'a' && ch <= 'z') {
		return true;
	} else if (ch == '_') {
		return true;
	} else {
		return false;
	}

	return false;

}

//�ж��ַ��Ƿ�Ϊ����
bool isDigit(char ch) {

	if (ch >= '0' && ch <= '9') {
		return true;
	} else {
		return false;
	}

}

//�ж��ַ��Ƿ�Ϊ��.��
bool isDot(char ch) {
	if (ch == '.') {
		return true;
	} else {
		return false;
	}
}

//�ж��Ƿ�Ϊ������ǰ׺
bool isPrefix(char ch) {
	if (ch == '+' || ch == '-') {
		return true;
	}
	return false;
}

//�ж��Ƿ�Ϊ����
bool isPlusPrefix(char ch) {
	if (ch == '+') {
		return true;
	}
	return false;
}

//�ж��Ƿ�Ϊ����
bool isMinusPrefix(char ch) {
	if (ch == '-') {
		return true;
	}
	return false;
}