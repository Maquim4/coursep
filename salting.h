#pragma once
#include <iostream>
#include <conio.h>
#include "sha256.h"

using namespace std;

//���� ��� ����
const char list[] = { '0','1','2','3','4','5','6','7','8','9','0',
	'!','@','#','$','%','^','&','*','(',')','_','+','-','=',
	'`', '~', '<', ',', '>', '.', '?', '/', ':', ';' ,'{','[',
	'}',']','"','|','a','b','c','d','e','f','g','h','i','j','k',
	'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
	'P','Q','R','S','T','U','V','W','X','Y','Z' };

// ���� �� �����������
string starsInput()
{
	string pass;
	int ch = 0;               // ���������� ��� �������.
	while (true)
	{
		ch = _getch();        // �������� ��� ������� ������� � ����������.
		if (ch == 13)         // ��������� Enter �� ���������� �����.
		{
			break;         // ���������� �����.
		}
		if (ch == 27) exit(0);   // ��������� Esc �� ����� �� �������.     

		if (ch == 8)     // ��������� Backspace �� �������� ��������.
		{
			cout << (char)8 << ' ' << char(8);
			/*�������� ������� �� ���� �������  � ���� ����� ������� �
			����� �������� ������� �����, �� ���� ��� ������� Backspace
			������ ����� ���������, � ������ �������������. */
			if (!pass.empty()) //���� ������ pass �� ��������� ������
				pass.erase(pass.length() - 1);// ��������� ������� ��������� ������ �� ������ pass
		}
		else
		{
			cout << '*';            // ������ �������� �� *
			pass += (char)ch;       // ����������� ���� �� ������ ����� � ������.
		}
	}
	cout << endl;
	return pass;
}
// ��������� ����
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
// ���� ������ � �����������
string passInput(string salt) {
	cout << "������� ������: ";
	string pass = starsInput();
	pass += salt;
	return sha256(pass);
}

