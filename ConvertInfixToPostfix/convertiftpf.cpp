#include <stdio.h>
#include <iostream>
#include "priority.h"
#include "operator.h"
#include "digit.h"
#include "utility.h"
#define EXPMAXSIZE 1024

using namespace std;

//中缀转换成后缀的主要方法
void convert(char *exp, Operator *op, Digit *digit);

//全局变量
static char check;	//循环输入标识
static bool firstPrefix = true;	//是否为第一字符标识
static char compChar = ' ';	//对比用字符

void main() {

	//准备相关变量
	Operator *op = (Operator *)malloc(sizeof(Operator));
	Digit *digit = (Digit *)malloc(sizeof(Digit));;
	char exp[EXPMAXSIZE];

	//说明
	cout << "说明：\n转换后的表达式中数字、变量、操作符会用空格隔开\n转换后的正号会以#代替，负号会以@代替\n" << endl;

	//循环输入
	while (true) {

		//输入中缀表达式
		printf("输入正规中缀表达式，支持正负号前缀及C标准的变量：\n");
		cin >> exp;

		//初始化变量
		initOperatorStack(op);
		initDigitStack(digit);
		firstPrefix = true;
		compChar = ' ';

		//开始转换
		convert(exp, op, digit);

		//询问是否继续
		cout << "是否继续（‘y’或‘Y’继续，其他退出）" << endl;
		cin >> check;
		if (check != 'y' && check != 'Y') {
			break;
		}

	}
}

//转换方法
void convert(char *exp, Operator *op, Digit *digit) {

	//临时变量
	char tempChar;

	//标记表达式的正确与否
	bool regular = true;

	while (*exp != '\0') {

		if (isOperator(*exp)) {

			//字符为操作符
			if (firstPrefix == true && isPrefix(*exp)) {
				/*
				* 若是第一字符则执行以下操作
				* 转换字符为正负号特殊标记
				*/
				if (isPlusPrefix(*exp)) {
					compChar = '#';
				}
				if (isMinusPrefix(*exp)) {
					compChar = '@';
				}
				firstPrefix = false;
			} else {
				compChar = *exp;
			}

			//对比左右操作符优先级后进行相关操作
			switch (ComparisionOfPriority(op->data[op->top], compChar)) {
				case 0:
					//左右优先级相等
					popOperatorStack(op);
					exp++;
					break;
				case 1:
					//右字符优先级大于左字符的优先级
					pushOperatorStack(op, compChar);
					compChar = ' ';
					exp++;

					//立即下一个字符是否为正负号
					if (isPrefix(*exp)) {
						if (isPlusPrefix(*exp)) {
							compChar = '#';
						}
						if (isMinusPrefix(*exp)) {
							compChar = '@';
						}
						pushOperatorStack(op, compChar);
						compChar = ' ';
						exp++;
					}
					break;
				case -1:
					//左字符优先级大于右字符优先级
					tempChar = popOperatorStack(op);
					pushDigitStack(digit, tempChar);
					pushDigitStack(digit, ' ');
					break;
				default:
					break;
			}
		} else if (isAlpha(*exp)) {
			
			//字符为英文字符或者下划线‘_’
			if (firstPrefix == true) {
				firstPrefix = false;
			}
			//立即判断后续字符是否为字符、下划线、数字
			while (isAlpha(*exp) || isDigit(*exp)) {
				pushDigitStack(digit, *exp);
				exp++;
			}

			//若字符不是字符、下划线、数字或操作符，则此表达式非法
			if (!isOperator(*exp) && *exp != '\0') {
				regular = false;
				break;
			}
			pushDigitStack(digit, ' ');
		} else {
			if (firstPrefix == true) {
				firstPrefix = false;
			}

			//立即判断后续字符是否为数字
			while (isDigit(*exp)) {
				pushDigitStack(digit, *exp);
				exp++;
				if (isDot(*exp)) {
					pushDigitStack(digit, *exp);
					exp++;
				}
			}

			//若字符不是字符、下划线、数字或操作符，则此表达式非法
			if (!isOperator(*exp) && *exp != '\0') {
				regular = false;
				break;
			}
			pushDigitStack(digit, ' ');
		}

	}

	if (regular == true) {

		//若表达式合法
		//循环读取操作符栈的字符放入运算数栈中
		while (op->data[op->top] != '=') {
			char convertChar = popOperatorStack(op);
			pushDigitStack(digit, convertChar);
			pushDigitStack(digit, ' ');
		}
		pushDigitStack(digit, '\0');

		//输出转换后的后缀表达式
		cout << digit->data << endl;

		cout << "成功转换" << endl;
	} else {

		//表达式不合法
		cout << "非正规中缀表达式" << endl;
	}

}