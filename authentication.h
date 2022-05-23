#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include "validation.h"
#include "salting.h"

using namespace std;

struct User
{
	string login;
	string pass;
	string salt;
	int access;
};

//Проверка, есть ли заявки 
bool isApplicationsHave(vector <User> vec_of_users)
{
	int count = 0;
	for (size_t i = 0; i < vec_of_users.size(); i++)
		if (vec_of_users.at(i).access == 0) count++;
	return (count > 0) ? true : false;

}
// Подтверждение действия 
bool areYouSure()
{
	int choice = 0;
	bool del = true;
	cout << "Вы уверены?" <<
		"\n\t1. Да" <<
		"\n\t2. Нет\n\n";
	cout << "Выберите: ";
	choice = inputNum(LR_1, RR_2);
	return del = (choice == 1 ? true : false);
}
//	Проверка на существующий логин	
bool isLoginExists(vector <User> vec_of_users, const string lg)
{
	for (size_t i = 0; i < vec_of_users.size(); i++)
		if (vec_of_users[i].login == lg) return true;
	return false;
}
// Ищем соль 
string findSalt(vector <User> vec_of_users, string lg)
{
	for (size_t i = 0; i < vec_of_users.size(); i++)
		if (vec_of_users[i].login == lg) return vec_of_users[i].salt;
	return "NO SALT";
}
//	Просмотр данных пользователей
void showStudentsData(vector <User>& vec_of_users)
{
	bool ready = true;
	while (ready)
	{
		int  choice;
		size_t i;
		bool check;
		cout << "-----------------------------------------------\n";
		cout << "|" << setw(4) << "№" << setw(4) << "|" << setw(10) << "Login" << setw(10) << "|" << setw(10) << "Status" << setw(9) << "|" << endl;
		cout << "-----------------------------------------------\n";
		for (i = 0; i < vec_of_users.size(); i++)
		{
			if (vec_of_users.at(i).access == 0) continue;
			else {
				cout << "|" << setw(4) << i << setw(4) << "|" << setw(10) << vec_of_users.at(i).login << setw(10) << "|" << setw(10);
				if (vec_of_users.at(i).access == 1) cout << "active"; else cout << "blocked";
				cout << setw(9) << "|" << endl;
				cout << "-----------------------------------------------\n";
			}
		}
		i--;
		cout << "\n\t1. Заблокировать аккаунт" <<
			"\n\t2. Разблокировать аккаунт" <<
			"\n\t0. Назад\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_2);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1: cout << "Введите номер аккаунта\n";
			choice = inputNum(LR_0, i);
			if (vec_of_users.at(choice).access == 2) {
				cout << "Аккаунт уже заблокирован!\n";
				break;
			}
			check = areYouSure();
			if (check) vec_of_users.at(choice).access = 2; break;
		case 2:
			cout << "Введите номер аккаунта\n";
			choice = inputNum(LR_0, i);
			if (vec_of_users.at(choice).access == 1) {
				cout << "Аккаунт не заблокирован!\n";
				break;
			}
			check = areYouSure();
			if (check) vec_of_users.at(choice).access = 1; break;
		}
	}
}
//	Удаление по определенному логину 
void deleteByLogin(vector <User>& vec_of_users, string lg)
{
	int del = 0;
	for (size_t i = 0; i < vec_of_users.size(); i++)
	{
		if (vec_of_users[i].login == lg) break;
		del++;
	}
	vec_of_users.erase(vec_of_users.begin() + del);
}
//	Просмотр заявок
void showApplications(vector <User>& vec_of_users)
{

	bool ready = true;
	while (ready)
	{
		if (!isApplicationsHave(vec_of_users)) {
			cout << "Заявок нет!\n";
			return;
		}
		int choice;
		size_t i;
		bool check;
		cout << "----------------------------\n";
		cout << "|" << setw(4) << "№" << setw(4) << "|" << setw(10) << "Login" << setw(9) << "|" << endl;
		cout << "----------------------------\n";
		for (i = 0; i < vec_of_users.size(); i++)
		{
			if (vec_of_users.at(i).access) continue;
			else {
				cout << "|" << setw(4) << i << setw(4) << "|" << setw(10) << vec_of_users.at(i).login << setw(10) << "|\n";
				cout << "----------------------------\n";
			}
		}
		i--;
		cout << "\n\t1. Одобрить заявку" <<
			"\n\t2. Удалить заявку" <<
			"\n\t0. Назад\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_2);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1: cout << "Введите номер заявки\n";
			choice = inputNum(LR_0, i);
			vec_of_users.at(choice).access = 1;
			cout << "Заявка одобрена!\n";
			break;
		case 2:
			cout << "Введите номер заявки\n";
			choice = inputNum(LR_0, i);
			check = isDelete();
			if (check) deleteByLogin(vec_of_users, vec_of_users.at(choice).login);
			break;
		}
	}
}
//	Редактирование логина и пароля	
void edit_all(vector <User>& vec_of_users, string lg)
{
	string lg_new, pass_new, salt_new;
	bool check;
	cout << "Введите новый логин: ";
	cin >> lg_new;
	check = isLoginExists(vec_of_users, lg_new);
	if (!check)
	{
		salt_new = Salting();
		pass_new = passInput(salt_new);
		for (size_t i = 0; i < vec_of_users.size(); i++)
		{
			if (vec_of_users[i].login == lg)
			{
				check = isEdit();
				if (check)
				{
					vec_of_users[i].login = lg_new;
					vec_of_users[i].pass = pass_new;
					vec_of_users[i].salt = salt_new;

				}
				break;
			}
		}
	}
	else cout << "Пользователь под логином \"" << lg_new << "\" уже есть!" << endl;
}
//	Редактирование логина	
void edit_lg(vector <User>& vec_of_users, string lg)
{
	string lg_new;
	bool check;
	cout << "Введите новый логин: ";
	cin >> lg_new;
	check = isLoginExists(vec_of_users, lg_new);
	if (!check)
	{
		for (size_t i = 0; i < vec_of_users.size(); i++)
		{
			if (vec_of_users[i].login == lg)
			{
				check = isEdit();
				if (check) vec_of_users[i].login = lg_new;
				break;
			}
		}
	}
	else cout << "Пользователь под логином \"" << lg << "\" уже есть!" << endl;
}
//	Редактирование пароля	
void edit_pass(vector <User>& vec_of_users, string lg)
{
	string pass_new, salt_new;
	bool check;
	salt_new = Salting();
	pass_new = passInput(salt_new);
	for (size_t i = 0; i < vec_of_users.size(); i++)
	{
		if (vec_of_users[i].login == lg)
		{
			check = isEdit();
			if (check) {
				vec_of_users[i].pass = pass_new;
				vec_of_users[i].salt = salt_new;
			}
			break;
		}

	}
}
//	Проверка доступа	
bool isAccessTrue(vector <User> vec_of_users, const string lg)
{
	size_t i;
	for (i = 0; i < vec_of_users.size(); i++)
		if (vec_of_users[i].login == lg) break;
	if (vec_of_users.at(i).access == 1) return true;
	if (vec_of_users.at(i).access == 0) cout << "Регистрация еще не одобрена администратором.\n";
	if (vec_of_users.at(i).access == 2) cout << "Ваш аккаунт находится в блокировке.\n";
	return false;
}
//	Меню работы с учетными записями
void menu_authentication(vector <User>& vec_of_users)
{
	User user_temp;
	int choice = 0;
	bool ready, check;
	string lg, pass, salt;
	ready = check = true;

	while (ready)
	{
		cout << " Работа с учетными записями " <<
			"\n\t1. Просмотр" <<
			"\n\t2. Добавление" <<
			"\n\t3. Редактирование по логину" <<
			"\n\t4. Удаление" <<
			"\n\t0. Назад\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_4);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1: while (ready) {
			cout << "\n Просмотр пользователей " << endl;
			cout << "\t1. Показать всех пользователей " <<
				"\n\t2. Показать заявки на вход" <<
				"\n\t0. Назад\n\n";
			cout << "Выберите: ";
			choice = inputNum(LR_0, RR_2);
			switch (choice)
			{
			case 0: ready = false; break;
			case 1: if (!vec_of_users.size()) cout << "Нет пользователей!" << endl;
				  else showStudentsData(vec_of_users); break;
			case 2: if (!vec_of_users.size()) cout << "Нет пользователей!" << endl;
				  else showApplications(vec_of_users); break;
			}
		}
			  ready = true;
			  break;
		case 2:
			cout << "\n Добавление пользователя " << endl;
			cout << "Введите логин: ";
			cin >> user_temp.login;
			check = isLoginExists(vec_of_users, user_temp.login);
			if (!check)
			{
				user_temp.access = 1;
				user_temp.salt = Salting();
				user_temp.pass = passInput(user_temp.salt);
				check = isNewAdd();
				if (check) { vec_of_users.push_back(user_temp); }
			}
			else {
				cout << "Пользователь под логином \"" << user_temp.login << "\" уже есть!" << endl;
				choice = 0;
			}
			break;
		case 3:
			cout << "\n Редактирование пользователя " << endl;
			cout << "Введите логин: ";
			cin >> lg;
			check = isLoginExists(vec_of_users, lg);
			if (check)
			{
				cout << "Отредактировать: "
					<< "\n\t1. Логин и пароль"
					<< "\n\t2. Логин"
					<< "\n\t3. Пароль"
					<< "\n\t0. Назад\n\n";
				cout << "Выберите: ";
				choice = inputNum(LR_0, RR_3);
				switch (choice)
				{
				case 0: break;
				case 1: edit_all(vec_of_users, lg); break;
				case 2: edit_lg(vec_of_users, lg); break;
				case 3: edit_pass(vec_of_users, lg); break;
				}
			}
			else cout << "Пользователь под логином \"" << lg << "\" не найден!" << endl;
			break;
		case 4:
			cout << "\n Удаление пользователей " << endl;
			cout << "\t1. По логину" <<
				"\n\t2. Все" <<
				"\n\t0. Назад\n\n";
			cout << "Выберите: ";
			choice = inputNum(LR_0, RR_2);
			switch (choice)
			{
			case 0: break;
			case 1:
				cout << "Введите логин: ";
				cin >> lg;
				check = isLoginExists(vec_of_users, lg);
				if (check)
				{
					check = isDelete();
					if (check) deleteByLogin(vec_of_users, lg);
				}
				else cout << "Пользователь под логином \"" << lg << "\" не найден!" << endl;
				break;
			case 2:
				if (!vec_of_users.size()) cout << "Нету пользователей!" << endl;
				else {
					check = isDelete();
					if (check) vec_of_users.clear();
				}
				break;
			}
			break;
		}
	}
}