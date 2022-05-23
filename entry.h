#pragma once
#include "authentication.h"
#include "system.h"


using namespace std;

//	логин и пароль Администратора
const string AdminLogin = "admin";
const string AdminPass = "admin";

//	Проверка логина и пароля	
int authentication(vector <User> vec_of_users, string lg, string pass)
{
	if (lg == AdminLogin && pass == AdminPass) return 1;
	else if (vec_of_users.size() != 0)	//Если есть другие пользователи 
	{
		for (size_t i = 0; i < vec_of_users.size(); i++)
			if (vec_of_users.at(i).login == lg && vec_of_users.at(i).pass == pass) return 2;
	}
	cout << "\nЛогин или пароль введен неправильно!\n\n";
	return 110901;
}
// Меню Администратора и пользователя
int menu(int choice, vector <User>& vec_of_users, vector <Student>& vec_of_students)
{

	bool ready = true;
	// Меню Администратора
	if (choice == 1) while (ready)
	{
		cout << "\n Меню Администратора " <<
			"\n\t1. Работа с учетными записями" <<
			"\n\t2. Работа с данными" <<
			"\n\t3. Вернуться к авторизации" <<
			"\n\t0. Выход\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_3);
		switch (choice)
		{
		case 0: ready = false; choice = 2022; break;
		case 1: menu_authentication(vec_of_users); break;
		case 2: menu_scolarship(vec_of_students); break;
		case 3: ready = false; choice = 0; break;
		}
	}
	//	Меню Пользователя
	if (choice == 2) while (ready)
	{
		cout << "\n Меню Пользователя " <<
			"\n\t1. Просмотр стипендии" <<
			"\n\t2. Поиск" <<
			"\n\t3. Сортировка" <<
			"\n\t4. Просмотр данных" <<
			"\n\t5. Вернуться к авторизации" <<
			"\n\t0. Выход\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_5);
		switch (choice)
		{
		case 0: ready = false; choice = 2022; break;
		case 1: showScholarshipData(vec_of_students); break;
		case 2:	searchInfo(vec_of_students);  break;
		case 3:	sorting(vec_of_students);  break;
		case 4: cout << "\n -Просмотр данных- " << endl;
			if (vec_of_students.size() == 0) cout << "Нет данных!" << endl;
			else showStudentsData(vec_of_students);
			break;
		case 5: ready = false; choice = 0; break;
		}
	}
	return choice;
}
//	Ввод в аккаунт 
void entry(vector <User>& vec_of_users, vector <Student>& vec_of_students)
{
	bool check;
	int choice = 0;
	string lg, pass, salt;
	while (choice != 2022)
	{
		cout << "\n\t1. Вход"
			<< "\n\t2. Регистрация\n\n"
			<< "\n\t3. Выход\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_1, RR_3);
		if (choice == 1)
		{
			choice = 0;
			while (!choice)
			{
				cout << "Введите логин:\t";
				cin >> lg;
				if (lg == "admin")
				{
					cout << "Введите пароль: ";
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
					cout << "Пользователь под логином \"" << lg << "\" не найден!" << endl;
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
				cout << "Введите логин: ";
				cin >> user_temp.login;
				check = isLoginExists(vec_of_users, user_temp.login);
				if (!check)
				{
					user_temp.access = 0;
					user_temp.salt = Salting();
					user_temp.pass = passInput(user_temp.salt);
					vec_of_users.push_back(user_temp);
					cout << "Регистрация прошла успешно! Ожидайте одобрения администратором. " << endl;
					break;
				}
				else {
					cout << "Пользователь под логином \"" << user_temp.login << "\" уже есть!" << endl;
					choice = 0;
				}
			}
		}
		if (choice == 3) choice = 2022;
	}
}




