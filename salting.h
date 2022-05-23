#pragma once
#include <iostream>
#include <conio.h>
#include "sha256.h"

using namespace std;

//Лист для соли
const char list[] = { '0','1','2','3','4','5','6','7','8','9','0',
	'!','@','#','$','%','^','&','*','(',')','_','+','-','=',
	'`', '~', '<', ',', '>', '.', '?', '/', ':', ';' ,'{','[',
	'}',']','"','|','a','b','c','d','e','f','g','h','i','j','k',
	'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
	'P','Q','R','S','T','U','V','W','X','Y','Z' };

// Ввод со звездочками
string starsInput()
{
	string pass;
	int ch = 0;               // Переменная для символа.
	while (true)
	{
		ch = _getch();        // Помещаем код нажатой клавиши в переменную.
		if (ch == 13)         // Установка Enter на прерывание цикла.
		{
			break;         // Прерывание цикла.
		}
		if (ch == 27) exit(0);   // Установка Esc на выход из консоли.     

		if (ch == 8)     // Установка Backspace на удаление символов.
		{
			cout << (char)8 << ' ' << char(8);
			/*Смещение курсора на одну позицию  в лево вывод пробела и
			снова смещение курсора влево, то есть при нажатии Backspace
			символ будет стираться, а курсор перемещаеться. */
			if (!pass.empty()) //Если строка pass не являеться пустой
				pass.erase(pass.length() - 1);// Позволяет удалить последний символ из строки pass
		}
		else
		{
			cout << '*';            // Замена символов на *
			pass += (char)ch;       // Преврашение кода из целого числа в символ.
		}
	}
	cout << endl;
	return pass;
}
// Получение соли
string Salting()
{
	string salt;
	int a = 5;
	srand(time(0));
	while (a > 0)
	{
		salt += list[rand() % 92];
		a--;
	}
	return salt;
}
// Ввод пароля с шифрованием
string passInput(string salt) {
	cout << "Введите пароль: ";
	string pass = starsInput();
	pass += salt;
	return sha256(pass);
}

