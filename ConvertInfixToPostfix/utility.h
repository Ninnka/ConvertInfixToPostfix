#include <stdio.h>
#include <iostream>

bool isAlpha(char ch);
bool isDigit(char ch);
bool isDot(char ch);
bool isPrefix(char ch);
bool isPlusPrefix(char ch);
bool isMinusPrefix(char ch);

//判断字符是否为字符、下划线
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

//判断字符是否为数字
bool isDigit(char ch) {

	if (ch >= '0' && ch <= '9') {
		return true;
	} else {
		return false;
	}

}

//判断字符是否为‘.’
bool isDot(char ch) {
	if (ch == '.') {
		return true;
	} else {
		return false;
	}
}

//判断是否为正负号前缀
bool isPrefix(char ch) {
	if (ch == '+' || ch == '-') {
		return true;
	}
	return false;
}

//判断是否为正号
bool isPlusPrefix(char ch) {
	if (ch == '+') {
		return true;
	}
	return false;
}

//判断是否为负号
bool isMinusPrefix(char ch) {
	if (ch == '-') {
		return true;
	}
	return false;
}