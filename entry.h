#pragma once
#include "authentication.h"
#include "system.h"


using namespace std;

//	����� � ������ ��������������
const string AdminLogin = "admin";
const string AdminPass = "admin";

//	�������� ������ � ������	
int authentication(vector <User> vec_of_users, string lg, string pass)
{
	if (lg == AdminLogin && pass == AdminPass) return 1;
	else if (vec_of_users.size() != 0)	//���� ���� ������ ������������ 
	{
		for (size_t i = 0; i < vec_of_users.size(); i++)
			if (vec_of_users.at(i).login == lg && vec_of_users.at(i).pass == pass) return 2;
	}
	cout << "\n����� ��� ������ ������ �����������!\n\n";
	return 110901;
}
// ���� �������������� � ������������
int menu(int choice, vector <User>& vec_of_users, vector <Student>& vec_of_students)
{

	bool ready = true;
	// ���� ��������������
	if (choice == 1) while (ready)
	{
		cout << "\n ���� �������������� " <<
			"\n\t1. ������ � �������� ��������" <<
			"\n\t2. ������ � �������" <<
			"\n\t3. ��������� � �����������" <<
			"\n\t0. �����\n\n";
		cout << "��������: ";
		choice = inputNum(LR_0, RR_3);
		switch (choice)
		{
		case 0: ready = false; choice = 2022; break;
		case 1: menu_authentication(vec_of_users); break;
		case 2: menu_scolarship(vec_of_students); break;
		case 3: ready = false; choice = 0; break;
		}
	}
	//	���� ������������
	if (choice == 2) while (ready)
	{
		cout << "\n ���� ������������ " <<
			"\n\t1. �������� ���������" <<
			"\n\t2. �����" <<
			"\n\t3. ����������" <<
			"\n\t4. �������� ������" <<
			"\n\t5. ��������� � �����������" <<
			"\n\t0. �����\n\n";
		cout << "��������: ";
		choice = inputNum(LR_0, RR_5);
		switch (choice)
		{
		case 0: ready = false; choice = 2022; break;
		case 1: showScholarshipData(vec_of_students); break;
		case 2:	searchInfo(vec_of_students);  break;
		case 3:	sorting(vec_of_students);  break;
		case 4: cout << "\n -�������� ������- " << endl;
			if (vec_of_students.size() == 0) cout << "��� ������!" << endl;
			else showStudentsData(vec_of_students);
			break;
		case 5: ready = false; choice = 0; break;
		}
	}
	return choice;
}
//	���� � ������� 
void entry(vector <User>& vec_of_users, vector <Student>& vec_of_students)
{
	bool check;
	int choice = 0;
	string lg, pass, salt;
	while (choice != 2022)
	{
		cout << "\n\t1. ����"
			<< "\n\t2. �����������\n\n"
			<< "\n\t3. �����\n\n";
		cout << "��������: ";
		choice = inputNum(LR_1, RR_3);
		if (choice == 1)
		{
			choice = 0;
			while (!choice)
			{
				cout << "������� �����:\t";
				cin >> lg;
				if (lg == "admin")
				{
					cout << "������� ������: ";
					pass = starsInput();
					choice = authentication(vec_of_users, lg, pass);
					break;
				}
				check = isLoginExists(vec_of_users, lg);
				if (check) {
					check = isAccessTrue(vec_of_users, lg);
					if (check) {
						salt = findSalt(vec_of_users, lg);
						pass = passInput(salt);
						choice = authentication(vec_of_users, lg, pass);
					}
					else choice = 2202;
				}
				else {
					cout << "������������ ��� ������� \"" << lg << "\" �� ������!" << endl;
					choice = 0;
				}
			}
			choice = menu(choice, vec_of_users, vec_of_students);
		}
		if (choice == 2)
		{
			while (true)
			{
				User user_temp;
				cout << "������� �����: ";
				cin >> user_temp.login;
				check = isLoginExists(vec_of_users, user_temp.login);
				if (!check)
				{
					user_temp.access = 0;
					user_temp.salt = Salting();
					user_temp.pass = passInput(user_temp.salt);
					vec_of_users.push_back(user_temp);
					cout << "����������� ������ �������! �������� ��������� ���������������. " << endl;
					break;
				}
				else {
					cout << "������������ ��� ������� \"" << user_temp.login << "\" ��� ����!" << endl;
					choice = 0;
				}
			}
		}
		if (choice == 3) choice = 2022;
	}
}




