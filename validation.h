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
		cin.clear(); // сбрасывает флаги ошибок, в противном случае повторный вызов cin не сработает
		cin.ignore(256, '\n'); // очисткa потока  до первого перевода строки включительно
		return false;
	}
}
bool isNumRangeCorrect(int number, int lr, int rr) {
	return number >= lr && number <= rr;
}
bool isNumRangeCorrect(double number, double lr, double rr) {
	return number >= lr && number <= rr;
}
//	Проверка корректности ввода для int
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
		cout << "Некорректный ввод! Введите числа в дипазоне: от " << lr << " до " << rr << " включительно " << ": ";
	}
}
//	Проверка корректности ввода для double
double inputNum(double lr, double rr)
{
	double num;
	while (true)
	{
		cin >> num;
		if (isNumNumeric() && isNumRangeCorrect(num, lr, rr)) return num;
		cout << "Некорректный ввод! Введите числа в дипазоне: от " << lr << " до " << rr << " включительно. " << "(Вместо \",\" используйте \".\"): ";
	}
}

//	Подтверждение удаления
bool isDelete()
{
	int choice = 0;
	bool del = true;
	cout << "Вы уверены что хотите удалить?" <<
		"\n\t1. Да" <<
		"\n\t2. Нет\n\n";
	cout << "Выберите: ";
	choice = inputNum(LR_1, RR_2);
	if (choice == 1) cout << "Данные успешно удалены!" << endl;
	return del = (choice == 1 ? true : false);
}
//	Подтверждение редактирования
bool isEdit()
{
	int choice = 0;
	bool edit = true;
	cout << "Вы уверены что хотите отредактировать?" <<
		"\n\t1. Да" <<
		"\n\t2. Нет\n\n";
	cout << "Выберите: ";
	choice = inputNum(LR_1, RR_2);
	if (choice == 1) cout << "Данные успешно отредактированы!" << endl;
	return edit = (choice == 1 ? true : false);
}
//	Подтверждение добавления
bool isNewAdd()
{
	int choice = 0;
	bool check = true;
	cout << "Вы уверены что хотите добавить данные?" <<
		"\n\t1. Да" <<
		"\n\t2. Нет\n\n";
	cout << "Выберите: ";
	choice = inputNum(LR_1, RR_2);
	if (choice == 1) cout << "Данные успешно добавлены!" << endl;
	return check = (choice == 1 ? true : false);
}

