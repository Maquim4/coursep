#pragma once
#include <Windows.h>
#include <fstream>
#include "entry.h"

using namespace std;

//	Название файлов
const string AUTH_PATH = "DB_Authentication.txt";
const string SCH_PATH = "DB_Scholarship.txt";

//	Переменные для работы с файлом
fstream file;

//Вычисление количества структур (пользователей) в файле
int getCountOfStucturesInFile(string file_path)
{
	ifstream file(file_path, ios::in); // Открыли текстовый файл для чтения
	int number_of_strings = 0;
	if (file.is_open())
	{
		while (file.ignore(256, '\n'))
			number_of_strings++;
	}
	file.close();
	//number_of_strings--;
	return number_of_strings;
}
//	Чтение пользователей из файла	
void readFileUsers(vector <User>& vec_of_users)
{
	file.open(AUTH_PATH, ios::in);
	if (!file.is_open()) cout << "Ошибка открытия файла! Пользователи не загружены!" << endl;
	else
	{
		User user_temp;
		while (!file.eof())
		{
			file >> user_temp.login
				>> user_temp.pass
				>> user_temp.salt
				>> user_temp.access;
			vec_of_users.push_back(user_temp);
		}
		if (getCountOfStucturesInFile(AUTH_PATH) != 0) cout << "Найдено " << getCountOfStucturesInFile(AUTH_PATH) << " пользователей." << endl << endl;
	}
	file.close();
}
//	Запись пользователей в файл	
void writeFileUsers(vector <User> vec_of_users)
{
	file.open(AUTH_PATH, ios::out);
	for (size_t i = 0; i < vec_of_users.size(); i++)
	{

		file << vec_of_users.at(i).login << " "
			<< vec_of_users.at(i).pass << " "
			<< vec_of_users.at(i).salt << " "
			<< vec_of_users.at(i).access;
		if (i < vec_of_users.size() - 1)
			file << endl;
	}
	file.close();
}
//	Чтение студентов из файла	
void readFileStudents(vector <Student>& vec_of_students)
{
	file.open(SCH_PATH, ios::in);
	if (!file.is_open()) cout << "Ошибка открытия файла!" << endl;
	else
	{
		Student student_temp;
		while (!file.eof())
		{
			file >> student_temp.lastname >> student_temp.firstname >> student_temp.middlename >> student_temp.group >> student_temp.form
				>> student_temp.credit1 >> student_temp.credit2 >> student_temp.credit3 >> student_temp.credit4 >> student_temp.credit5
				>> student_temp.credit >> student_temp.mark1 >> student_temp.mark2 >> student_temp.mark3 >> student_temp.mark4
				>> student_temp.mark >> student_temp.activity >> student_temp.scholar;
			vec_of_students.push_back(student_temp);
		}
		if (getCountOfStucturesInFile(SCH_PATH) != 0) cout << "Найдено " << getCountOfStucturesInFile(SCH_PATH) << " записей." << endl << endl;
	}
	file.close();
}
//	Запись студентов в файл	
void writeFileStudents(vector <Student> vec_of_students)
{
	file.open(SCH_PATH, ios::out);
	for (size_t i = 0; i < vec_of_students.size(); i++)
	{

		file << vec_of_students.at(i).lastname << " " << vec_of_students.at(i).firstname << " " << vec_of_students.at(i).middlename << " "
			<< vec_of_students.at(i).group << " " << vec_of_students.at(i).form << " " << vec_of_students.at(i).credit1 << " "
			<< vec_of_students.at(i).credit2 << " " << vec_of_students.at(i).credit3 << " " << vec_of_students.at(i).credit4 << " "
			<< vec_of_students.at(i).credit5 << " " << vec_of_students.at(i).credit << " " << " " << vec_of_students.at(i).mark1 << " "
			<< vec_of_students.at(i).mark2 << " " << vec_of_students.at(i).mark3 << " " << vec_of_students.at(i).mark4 << " "
			<< vec_of_students.at(i).mark << " " << vec_of_students.at(i).activity << " " << vec_of_students.at(i).scholar;
		if (i < vec_of_students.size() - 1)
			file << endl;
	}
	file.close();
}
