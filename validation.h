#pragma once
#include <iostream>
using namespace std;

const int LR_0 = 0;
const int LR_1 = 1;
const int RR_1 = 1;
const int RR_2 = 2;
const int RR_3 = 3;
const int RR_4 = 4;
const int RR_5 = 5;
const int RR_8 = 8;
const int RR_10 = 10;
const int RR_NUM = 1000000;

const double LR_D = 0;
const double RR_D = 1000;

bool isNumNumeric()
{
	if (cin.get() == '\n') return true;
	else
	{
		cin.clear(); // ���������� ����� ������, � ��������� ������ ��������� ����� cin �� ���������
		cin.ignore(256, '\n'); // ������a ������  �� ������� �������� ������ ������������
		return false;
	}
}
bool isNumRangeCorrect(int number, int lr, int rr) {
	return number >= lr && number <= rr;
}
bool isNumRangeCorrect(double number, double lr, double rr) {
	return number >= lr && number <= rr;
}
//	�������� ������������ ����� ��� int
int inputNum(int lr, int rr)
{
	int num;
	while (true)
	{
		cin >> num;
		if (isNumNumeric() && isNumRangeCorrect(num, lr, rr))
		{
			system("cls");
			return num;
		}
		cout << "������������ ����! ������� ����� � ��������: �� " << lr << " �� " << rr << " ������������ " << ": ";
	}
}
//	�������� ������������ ����� ��� double
double inputNum(double lr, double rr)
{
	double num;
	while (true)
	{
		cin >> num;
		if (isNumNumeric() && isNumRangeCorrect(num, lr, rr)) return num;
		cout << "������������ ����! ������� ����� � ��������: �� " << lr << " �� " << rr << " ������������. " << "(������ \",\" ����������� \".\"): ";
	}
}

//	������������� ��������
bool isDelete()
{
	int choice = 0;
	bool del = true;
	cout << "�� ������� ��� ������ �������?" <<
		"\n\t1. ��" <<
		"\n\t2. ���\n\n";
	cout << "��������: ";
	choice = inputNum(LR_1, RR_2);
	if (choice == 1) cout << "������ ������� �������!" << endl;
	return del = (choice == 1 ? true : false);
}
//	������������� ��������������
bool isEdit()
{
	int choice = 0;
	bool edit = true;
	cout << "�� ������� ��� ������ ���������������?" <<
		"\n\t1. ��" <<
		"\n\t2. ���\n\n";
	cout << "��������: ";
	choice = inputNum(LR_1, RR_2);
	if (choice == 1) cout << "������ ������� ���������������!" << endl;
	return edit = (choice == 1 ? true : false);
}
//	������������� ����������
bool isNewAdd()
{
	int choice = 0;
	bool check = true;
	cout << "�� ������� ��� ������ �������� ������?" <<
		"\n\t1. ��" <<
		"\n\t2. ���\n\n";
	cout << "��������: ";
	choice = inputNum(LR_1, RR_2);
	if (choice == 1) cout << "������ ������� ���������!" << endl;
	return check = (choice == 1 ? true : false);
}

