#include <stdio.h>
#include <iostream>
#include "priority.h"
#include "operator.h"
#include "digit.h"
#include "utility.h"
#define EXPMAXSIZE 1024

using namespace std;

//��׺ת���ɺ�׺����Ҫ����
void convert(char *exp, Operator *op, Digit *digit);

//ȫ�ֱ���
static char check;	//ѭ�������ʶ
static bool firstPrefix = true;	//�Ƿ�Ϊ��һ�ַ���ʶ
static char compChar = ' ';	//�Ա����ַ�

void main() {

	//׼����ر���
	Operator *op = (Operator *)malloc(sizeof(Operator));
	Digit *digit = (Digit *)malloc(sizeof(Digit));;
	char exp[EXPMAXSIZE];

	//˵��
	cout << "˵����\nת����ı��ʽ�����֡����������������ÿո����\nת��������Ż���#���棬���Ż���@����\n" << endl;

	//ѭ������
	while (true) {

		//������׺���ʽ
		printf("����������׺���ʽ��֧��������ǰ׺��C��׼�ı�����\n");
		cin >> exp;

		//��ʼ������
		initOperatorStack(op);
		initDigitStack(digit);
		firstPrefix = true;
		compChar = ' ';

		//��ʼת��
		convert(exp, op, digit);

		//ѯ���Ƿ����
		cout << "�Ƿ��������y����Y�������������˳���" << endl;
		cin >> check;
		if (check != 'y' && check != 'Y') {
			break;
		}

	}
}

//ת������
void convert(char *exp, Operator *op, Digit *digit) {

	//��ʱ����
	char tempChar;

	//��Ǳ��ʽ����ȷ���
	bool regular = true;

	while (*exp != '\0') {

		if (isOperator(*exp)) {

			//�ַ�Ϊ������
			if (firstPrefix == true && isPrefix(*exp)) {
				/*
				* ���ǵ�һ�ַ���ִ�����²���
				* ת���ַ�Ϊ������������
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

			//�Ա����Ҳ��������ȼ��������ز���
			switch (ComparisionOfPriority(op->data[op->top], compChar)) {
				case 0:
					//�������ȼ����
					popOperatorStack(op);
					exp++;
					break;
				case 1:
					//���ַ����ȼ��������ַ������ȼ�
					pushOperatorStack(op, compChar);
					compChar = ' ';
					exp++;

					//������һ���ַ��Ƿ�Ϊ������
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
					//���ַ����ȼ��������ַ����ȼ�
					tempChar = popOperatorStack(op);
					pushDigitStack(digit, tempChar);
					pushDigitStack(digit, ' ');
					break;
				default:
					break;
			}
		} else if (isAlpha(*exp)) {
			
			//�ַ�ΪӢ���ַ������»��ߡ�_��
			if (firstPrefix == true) {
				firstPrefix = false;
			}
			//�����жϺ����ַ��Ƿ�Ϊ�ַ����»��ߡ�����
			while (isAlpha(*exp) || isDigit(*exp)) {
				pushDigitStack(digit, *exp);
				exp++;
			}

			//���ַ������ַ����»��ߡ����ֻ����������˱��ʽ�Ƿ�
			if (!isOperator(*exp) && *exp != '\0') {
				regular = false;
				break;
			}
			pushDigitStack(digit, ' ');
		} else {
			if (firstPrefix == true) {
				firstPrefix = false;
			}

			//�����жϺ����ַ��Ƿ�Ϊ����
			while (isDigit(*exp)) {
				pushDigitStack(digit, *exp);
				exp++;
				if (isDot(*exp)) {
					pushDigitStack(digit, *exp);
					exp++;
				}
			}

			//���ַ������ַ����»��ߡ����ֻ����������˱��ʽ�Ƿ�
			if (!isOperator(*exp) && *exp != '\0') {
				regular = false;
				break;
			}
			pushDigitStack(digit, ' ');
		}

	}

	if (regular == true) {

		//�����ʽ�Ϸ�
		//ѭ����ȡ������ջ���ַ�����������ջ��
		while (op->data[op->top] != '=') {
			char convertChar = popOperatorStack(op);
			pushDigitStack(digit, convertChar);
			pushDigitStack(digit, ' ');
		}
		pushDigitStack(digit, '\0');

		//���ת����ĺ�׺���ʽ
		cout << digit->data << endl;

		cout << "�ɹ�ת��" << endl;
	} else {

		//���ʽ���Ϸ�
		cout << "��������׺���ʽ" << endl;
	}

}