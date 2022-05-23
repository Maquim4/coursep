#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "validation.h"

using namespace std;

struct Student
{
	string lastname;
	string firstname;
	string middlename;
	string form;
	string activity;
	bool credit1;
	bool credit2;
	bool credit3;
	bool credit4;
	bool credit5;
	bool credit;
	int group;
	int mark1;
	int mark2;
	int mark3;
	int mark4;
	double scholar;
	double mark;
};

//	Просмотр всех записей
void showStudentsData(vector <Student> vec_of_students)
{
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(4) << "№" << "|" << setw(16) << "Номер группы" << "|" << setw(14) << "ФИО" << "|" << setw(16) << "Форма обучения"
		<< "|" << setw(12) << "Зачеты" << "|" << setw(10) << "Оценки" << "|" << setw(8) << "Ср.Балл" << "|" << setw(14) << "Активность" << "|\n";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	for (size_t i = 0; i < vec_of_students.size(); i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(16) << vec_of_students.at(i).group << "|" << setw(14) << vec_of_students.at(i).lastname << "|" << setw(16) << vec_of_students.at(i).form << "| МА" << setw(9);
		if (vec_of_students.at(i).credit1) cout << "Зачет"; else cout << "Незачет";
		cout << "| ИнАД" << setw(5) << vec_of_students.at(i).mark1 << "|" << setw(8) << vec_of_students.at(i).mark << "|" << setw(14) << vec_of_students.at(i).activity << "|\n";
		cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(14) << vec_of_students.at(i).firstname << "|" << setw(21) << "| ИКГ" << setw(8);
		if (vec_of_students.at(i).credit2) cout << "Зачет"; else cout << "Незачет";
		cout << "| ЛАиАГ" << setw(4) << vec_of_students.at(i).mark2 << "|" << setw(9) << "|" << setw(16) << "|\n";
		cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(14) << vec_of_students.at(i).middlename << "|" << setw(21) << "| Лог" << setw(8);
		if (vec_of_students.at(i).credit3) cout << "Зачет"; else cout << "Незачет";
		cout << "| ОАиП" << setw(5) << vec_of_students.at(i).mark3 << "|" << setw(9) << "|" << setw(16) << "|\n";
		cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(15) << "|" << setw(21) << "| Пол" << setw(8);
		if (vec_of_students.at(i).credit4) cout << "Зачет"; else cout << "Незачет";
		cout << "| ТРПО" << setw(5) << vec_of_students.at(i).mark4 << "|" << setw(9) << "|" << setw(16) << "|\n";
		cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(15) << "|" << setw(22) << "| ИнЯз" << setw(7);
		if (vec_of_students.at(i).credit5) cout << "Зачет"; else cout << "Незачет";
		cout << "|" << setw(11) << "|" << setw(9) << "|" << setw(16) << "|\n";
		cout << "-------------------------------------------------------------------------------------------------------\n";
	}
}
//	Просмотр рассчета стипендии
void showScholarship(vector <Student>& vec_of_students, double scholar)
{
	double s25;
	s25 = scholar / 4;
	for (size_t i = 0; i < vec_of_students.size(); i++)
		if (vec_of_students.at(i).form == "Бюджетная" && vec_of_students.at(i).credit && vec_of_students.at(i).mark > 5) // Если бюджет + все зачеты сданы + ср.балл выше 5
		{
			vec_of_students.at(i).scholar = scholar;
			if (vec_of_students.at(i).mark >= 9) vec_of_students.at(i).scholar += s25; // Надбавка 25% отличникам
			if (vec_of_students.at(i).activity == "Активное") vec_of_students.at(i).scholar += s25; // Надбавка 50% в сумме отличникам - активистам
		}
		else vec_of_students.at(i).scholar = 0;
	cout << "------------------------------------------" << "\n";
	cout << "|" << setw(4) << "№" << "|" << setw(10) << "Номер группы" << "|" << setw(12) << "Фамилия" << "|" << setw(6) << "Стипендия" << "|\n";
	cout << "------------------------------------------" << "\n";
	for (size_t i = 0; i < vec_of_students.size(); i++)
		if (vec_of_students.at(i).scholar != 0) { // Вывод студентов со стипендией 
			cout << "|" << setw(4) << i + 1 << "|" << setw(12) << vec_of_students.at(i).group << "|"
				<< setw(12) << vec_of_students.at(i).lastname << "|" << setw(9) << fixed << setprecision(2) << vec_of_students.at(i).scholar << "|\n";
			cout << "------------------------------------------" << "\n";
		}
}
// Добавление студента
void addStudent(vector <Student>& vec_of_students)
{
	Student student_temp;
	vector<Student>::iterator iter = vec_of_students.begin();
	int choice, n;
	bool check;
	cout << "Введите номер группы: ";
	student_temp.group = inputNum(LR_0, RR_NUM);
	cout << "Введите ФИО студента" << endl;
	cout << "Фамилия: ";
	cin >> student_temp.lastname;
	cout << "Имя: ";
	cin >> student_temp.firstname;
	cout << "Отчество: ";
	cin >> student_temp.middlename;
	cout << "Форма обучения: " << "\n\t1. Платная" << "\n\t2. Бюджетная" << "\nВыберите: ";
	choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.form = "Платная"; break; case 2: student_temp.form = "Бюджетная"; break; }
									cout << "Зачет по МА : " << "\n\t1. Зачет" << "\n\t2. Незачет" << "\nВыберите: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit1 = 1; break; case 2: student_temp.credit1 = 0; break; }
									cout << "Зачет по ИКГ : " << "\n\t1. Зачет" << "\n\t2. Незачет" << "\nВыберите: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit2 = 1; break; case 2: student_temp.credit2 = 0; break; }
									cout << "Зачет по Логике : " << "\n\t1. Зачет" << "\n\t2. Незачет" << "\nВыберите: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit3 = 1; break; case 2: student_temp.credit3 = 0; break; }
									cout << "Зачет по Политологии: " << "\n\t1. Зачет" << "\n\t2. Незачет" << "\nВыберите: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit4 = 1; break; case 2: student_temp.credit4 = 0; break; }
									cout << "Зачет по ИнЯз: " << "\n\t1. Зачет" << "\n\t2. Незачет" << "\nВыберите: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit5 = 1; break; case 2: student_temp.credit5 = 0; break; }
									cout << "Введите оценку по ЛАиАГ: ";
									student_temp.mark1 = inputNum(LR_1, RR_10);
									cout << "Введите оценку по ОАиП: ";
									student_temp.mark2 = inputNum(LR_1, RR_10);
									cout << "Введите оценку по ТРПО: ";
									student_temp.mark3 = inputNum(LR_1, RR_10);
									cout << "Введите оценку по ИнАД: ";
									student_temp.mark4 = inputNum(LR_1, RR_10);
									cout << "Участие в общественной работе: " << "\n\t1. Активное" << "\n\t2. Неучастие" << "\nВыберите: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.activity = "Активное"; break; case 2: student_temp.activity = "Неучастие"; break; }
									student_temp.mark = ((double)student_temp.mark1 + student_temp.mark2 + student_temp.mark3 + student_temp.mark4) / 4.;
									if (student_temp.credit1 && student_temp.credit2 && student_temp.credit3 && student_temp.credit4 && student_temp.credit5)
										student_temp.credit = 1;
									else student_temp.credit = 0;
									student_temp.scholar = 0;
									check = isNewAdd();
									if (check) {
										cout << "\nКуда вы хотите добавить данные?" << endl;
										cout << "\t1. В начало\n" << "\t2. В конец\n" << "\t3. По номеру\n\n";
										cout << "Выберите: ";
										choice = inputNum(LR_1, RR_3);
										switch (choice)
										{
										case 1: vec_of_students.emplace(iter, student_temp); break;
										case 2: vec_of_students.push_back(student_temp); break;
										case 3: cout << "Введите номер: ";
											n = inputNum(LR_1, vec_of_students.size() + 1);
											iter += n - 1;
											vec_of_students.emplace(iter, student_temp); break;
										}
									}
}
//	Поиск по индексу
void searchByIndex(vector <Student>& vec_of_students, int index)
{
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(4) << index + 1 << "|" << setw(16) << vec_of_students.at(index).group << "|" << setw(14) << vec_of_students.at(index).lastname << "|" << setw(16) << vec_of_students.at(index).form << "| МА" << setw(9);
	if (vec_of_students.at(index).credit1) cout << "Зачет"; else cout << "Незачет";
	cout << "| ИнАД" << setw(5) << vec_of_students.at(index).mark1 << "|" << setw(8) << vec_of_students.at(index).mark << "|" << setw(14) << vec_of_students.at(index).activity << "|\n";
	cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(14) << vec_of_students.at(index).firstname << "|" << setw(21) << "| ИКГ" << setw(8);
	if (vec_of_students.at(index).credit2) cout << "Зачет"; else cout << "Незачет";
	cout << "| ЛАиАГ" << setw(4) << vec_of_students.at(index).mark2 << "|" << setw(9) << "|" << setw(16) << "|\n";
	cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(14) << vec_of_students.at(index).middlename << "|" << setw(21) << "| Лог" << setw(8);
	if (vec_of_students.at(index).credit3) cout << "Зачет"; else cout << "Незачет";
	cout << "| ОАиП" << setw(5) << vec_of_students.at(index).mark3 << "|" << setw(9) << "|" << setw(16) << "|\n";
	cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(15) << "|" << setw(21) << "| Пол" << setw(8);
	if (vec_of_students.at(index).credit4) cout << "Зачет"; else cout << "Незачет";
	cout << "| ТРПО" << setw(5) << vec_of_students.at(index).mark4 << "|" << setw(9) << "|" << setw(16) << "|\n";
	cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(15) << "|" << setw(22) << "| ИнЯз" << setw(7);
	if (vec_of_students.at(index).credit5) cout << "Зачет"; else cout << "Незачет";
	cout << "|" << setw(11) << "|" << setw(9) << "|" << setw(16) << "|\n";
	cout << "-------------------------------------------------------------------------------------------------------\n";
}
//	Редактирование записи
void edit_students(vector <Student>& vec_of_students)
{
	int choice, index, group, mark;
	string lastname, firstname, middlename, form, activity;
	bool ready = true;
	showStudentsData(vec_of_students);
	cout << " Введите номер редактируемой записи: ";
	index = inputNum(LR_1, vec_of_students.size())-1;
	while (ready)
	{
		searchByIndex(vec_of_students, index);
		cout << " Что вы хотите отредактировать? " <<
			"\n\t1. Фамилию" <<
			"\n\t2. Имя" <<
			"\n\t3. Отчество" <<
			"\n\t4. Номер группы" <<
			"\n\t5. Форму обучения" <<
			"\n\t6. Зачеты" <<
			"\n\t7. Оценки" <<
			"\n\t8. Активность" <<
			"\n\t0. Назад\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_8);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1:  while (ready) {
			cout << "Введите новую фамилию: ";
			cin >> lastname;
			for (size_t i = 0; i < lastname.length(); i++) {
				if (isalpha(lastname[i])) { cout << "Cтрока типа ФИО не может содержать цифру или другой неподходящий символ\n"; ready = true; break; }
				else ready = false;
			}
		} 
			  vec_of_students.at(index).lastname = lastname; 
			  ready = true;
			  break;
		case 2: while (ready) {
			cout << "Введите новое имя: ";
			cin >> firstname;
			for (size_t i = 0; i < firstname.length(); i++) {
				if (isalpha(firstname[i])) { cout << "Cтрока типа ФИО не может содержать цифру или другой неподходящий символ\n"; ready = true; break; }
				else ready = false;
			}
		} 
			  vec_of_students.at(index).firstname = firstname;
			  ready = true;
			  break;
		case 3: while (ready) {
			cout << "Введите новое отчество: ";
			cin >> middlename;
			for (size_t i = 0; i < middlename.length(); i++) {
				if (isalpha(middlename[i])) { cout << "Cтрока типа ФИО не может содержать цифру или другой неподходящий символ\n"; ready = true; break; }
				else ready = false;
			}
		}
			  vec_of_students.at(index).middlename = middlename;
			  ready = true;
			  break;
		case 4: cout << "Введите новый номер группы: ";
			group = inputNum(LR_0, RR_NUM);
			vec_of_students.at(index).group = group;
			break;
		case 5:  vec_of_students.at(index).form == "Платная" ? vec_of_students.at(index).form = "Бюджетная" : vec_of_students.at(index).form = "Платная";
			break;
		case 6:   cout << " Выберите предмет: " <<
			"\n\t1. МА" <<
			"\n\t2. ИКГ" <<
			"\n\t3. Логика" <<
			"\n\t4. Полит" <<
			"\n\t5. ИнЯз\n\n";
			choice = inputNum(LR_1, RR_5);
			switch (choice)
			{
			case 1: vec_of_students.at(index).credit1 ? vec_of_students.at(index).credit1 = 0 : vec_of_students.at(index).credit1 = 1; break;
			case 2: vec_of_students.at(index).credit2 ? vec_of_students.at(index).credit2 = 0 : vec_of_students.at(index).credit2 = 1; break;
			case 3: vec_of_students.at(index).credit3 ? vec_of_students.at(index).credit3 = 0 : vec_of_students.at(index).credit3 = 1; break;
			case 4: vec_of_students.at(index).credit4 ? vec_of_students.at(index).credit4 = 0 : vec_of_students.at(index).credit4 = 1; break;
			case 5: vec_of_students.at(index).credit5 ? vec_of_students.at(index).credit5 = 0 : vec_of_students.at(index).credit5 = 1; break;
			}
			break;
		case 7:cout << " Выберите предмет: " <<
			"\n\t1. ИнАД" <<
			"\n\t2. ЛАиАГ" <<
			"\n\t3. ОАиП" <<
			"\n\t4. ТРПО\n\n";
			choice = inputNum(LR_1, RR_5);
			cout << " Введите оценку: ";
			mark = inputNum(LR_1, RR_10);
			switch (choice)
			{
			case 1:  vec_of_students.at(index).mark1 = mark; break;
			case 2:  vec_of_students.at(index).mark2 = mark; break;
			case 3:  vec_of_students.at(index).mark3 = mark; break;
			case 4:  vec_of_students.at(index).mark4 = mark; break;
			}
			break;
		case 8: vec_of_students.at(index).activity == "Активное" ? vec_of_students.at(index).activity = "Неучастие" : vec_of_students.at(index).activity = "Активное"; break;
		}
		vec_of_students.at(index).mark = ((double)vec_of_students.at(index).mark1 + vec_of_students.at(index).mark2 + vec_of_students.at(index).mark3 +
			vec_of_students.at(index).mark4) / 4.;
		if (vec_of_students.at(index).credit1 && vec_of_students.at(index).credit2 && vec_of_students.at(index).credit3 && vec_of_students.at(index).credit4 && vec_of_students.at(index).credit5)
			vec_of_students.at(index).credit = 1;
		else vec_of_students.at(index).credit = 0;
		vec_of_students.at(index).scholar = 0;
	}
}
//	Режим редактирования
void edit_mode(vector <Student>& vec_of_students)
{
	Student student_temp;
	int choice, index;
	bool  ready, check;
	ready = check = true;
	while (ready)
	{
		cout << " Режим редактирования " <<
			"\n\t1. Просмотр" <<
			"\n\t2. Добавление" <<
			"\n\t3. Удаление" <<
			"\n\t4. Редактирование" <<
			"\n\t0. Назад\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_4);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1:
			cout << "\n -Просмотр данных- " << endl;
			if (vec_of_students.size() == 0) cout << "Нет данных!" << endl;
			else showStudentsData(vec_of_students);
			break;
		case 2:
			cout << "\n -Добавление данных- " << endl;
			addStudent(vec_of_students); break;
		case 3:
			cout << "\n -Удаление данных- " << endl;
			if (vec_of_students.size() == 0) cout << "Нет данных!" << endl;
			else
			{
				cout << "\t1. Все\n" << "\t2. По индексу\n" << "\t0. Назад\n\n";
				cout << "Выберите: ";
				choice = inputNum(LR_0, RR_2);
				switch (choice)
				{
				case 0: break;
				case 1:
					check = isDelete();
					if (check) vec_of_students.clear(); break;
				case 2:
					cout << "Введите № (от 1 до " << vec_of_students.size() << "): ";
					index = inputNum(LR_1, vec_of_students.size());
					check = isDelete();
					if (check) {
						vec_of_students.erase(vec_of_students.begin() + index - 1);
					} break;
				}
			} break;
		case 4: edit_students(vec_of_students); break;
		}
	}
}
// Просмотр данных и расчет стипендии
void showScholarshipData(vector <Student>& vec_of_students)
{
	bool ready = true;
	double scholar;
	int choice;
	cout << "\n -Просмотр данных- " << endl;
	if (vec_of_students.size() == 0) cout << "Нет данных!" << endl;
	else {
		while (ready) {
			cout << "\t1. Просмотр стипендии" <<
				"\n\t2. Рассчет стипендии" <<
				"\n\t0. Назад\n\n";
			cout << "Выберите: ";
			choice = inputNum(LR_0, RR_2);
			switch (choice)
			{
			case 0:ready = false; break;
			case 1: cout << "------------------------------------------" << "\n";
				cout << "|" << setw(4) << "№" << "|" << setw(10) << "Номер группы" << "|" << setw(12) << "Фамилия" << "|" << setw(6) << "Стипендия" << "|\n";
				cout << "------------------------------------------" << "\n";
				for (size_t i = 0; i < vec_of_students.size(); i++)
					if (vec_of_students.at(i).scholar != 0) { // Вывод студентов со стипендией 
						cout << "|" << setw(4) << i + 1 << "|" << setw(12) << vec_of_students.at(i).group << "|"
							<< setw(12) << vec_of_students.at(i).lastname << "|" << setw(9) << fixed << setprecision(2) << vec_of_students.at(i).scholar << "|\n";
						cout << "------------------------------------------" << "\n";
					} break;
			case 2:
				cout << "Введите базовый размер стипендии: ";
				scholar = inputNum(LR_D, RR_D);
				showScholarship(vec_of_students, scholar);
				break;
			}
		}
	}
}
// По алфавиту
const bool sortByABC(const Student first, const Student second)
{
	return first.lastname < second.lastname;
}
// По среднему баллу
const bool sortByMark(const Student first, const Student second)
{
	return first.mark > second.mark;
}
// По размеру стипендии
const bool sortByScholarship(const Student first, const Student second)
{
	return first.scholar > second.scholar;
}
// Сортировка данных
void sorting(vector <Student> vec_of_students)
{
	int choice;
	while (true)
	{
		system("cls");
		cout << " Сортировка данных" << endl
			<< "1. Отсортировать по алфавиту" << endl
			<< "2. Отсортировать по ср.баллу" << endl
			<< "3. Отсортировать по стипендии" << endl
			<< "0. Назад" << endl;
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_3);
		if (choice == 1)
		{
			system("cls");
			sort(vec_of_students.begin(), vec_of_students.end(), sortByABC);
			cout << "\t\t\t-Сортировка по алфавиту-\t\t\t" << endl;
			showStudentsData(vec_of_students);
			system("pause");
		}
		if (choice == 2)
		{
			system("cls");
			cout << "\t\t\t-Сортировка по среднему баллу-\t\t\t" << endl;
			sort(vec_of_students.begin(), vec_of_students.end(), sortByMark);
			showStudentsData(vec_of_students);
			system("pause");
		}
		if (choice == 3)
		{
			system("cls");
			cout << "\t\t\t-Сортировка по стипендии-\t\t\t" << endl;
			sort(vec_of_students.begin(), vec_of_students.end(), sortByScholarship);
			cout << "------------------------------------------" << "\n";
			cout << "|" << setw(4) << "№" << "|" << setw(10) << "Номер группы" << "|" << setw(12) << "Фамилия" << "|" << setw(6) << "Стипендия" << "|\n";
			cout << "------------------------------------------" << "\n";
			for (size_t i = 0; i < vec_of_students.size(); i++)
				if (vec_of_students.at(i).scholar != 0) { // Вывод студентов со стипендией 
					cout << "|" << setw(4) << i + 1 << "|" << setw(12) << vec_of_students.at(i).group << "|"
						<< setw(12) << vec_of_students.at(i).lastname << "|" << setw(9) << fixed << setprecision(2) << vec_of_students.at(i).scholar << "|\n";
					cout << "------------------------------------------" << "\n";
				}
			system("pause");
		}
		if (choice == 0)
		{
			break;
		}

	}
}
// Поиск по записям
void searchInfo(vector <Student> vec_of_students)
{
	int choice, i = 0, group, index;
	string lastname;
	bool ready = true;
	while (true)
	{
		int count = 0;
		system("cls");
		cout << " -Поиск записи- \n"
			<< "1. По фамилии\n"
			<< "2. По номеру группы\n"
			<< "3. По индексу\n"
			<< "0. Назад\n"
			<< "Ваш выбор: ";
		choice = inputNum(LR_0, RR_3);
		switch (choice)
		{
		case 1:
		{
			system("cls");
			while (ready) {
				cout << "Введите фамилию: ";
				cin >> lastname;
				for (size_t i = 0; i < lastname.length(); i++) {
					if (isalpha(lastname[i])) { cout << "Cтрока типа ФИО не может содержать цифру или другой неподходящий символ\n"; ready = true; break; }
					else ready = false;
				}
			}
			for (size_t i = 0; i < vec_of_students.size(); i++)
				if (vec_of_students.at(i).lastname == lastname) {
					searchByIndex(vec_of_students, i);
					count++;
				}
			if (!count) cout << " Ничего не удалось найти!\n";
			system("pause");
		}
		break;
		case 2:
		{
			system("cls");
			cout << "Введите номер группы: ";
			group = inputNum(LR_0, RR_NUM);
			for (size_t i = 0; i < vec_of_students.size(); i++)
				if (vec_of_students.at(i).group == group) {
					searchByIndex(vec_of_students, i);
					count++;
				}
			if (!count) cout << " Ничего не удалось найти!\n";
			system("pause");
		}
		break;
		case 3:
		{
			system("cls");
			cout << "Введите индекс: ";
			index = inputNum(LR_1, vec_of_students.size());
			searchByIndex(vec_of_students, index - 1);
			system("pause");
		}
		break;
		case 0:
		{
			system("cls");
			return;
		}
		}
	}
}
//	Режим обработки данных
void process_mode(vector <Student>& vec_of_students)
{
	int choice;
	bool  ready, check;
	ready = check = true;
	while (ready)
	{
		cout << " Режим обработки данных " <<
			"\n\t1. Просмотр данных" <<
			"\n\t2. Сортировка" <<
			"\n\t3. Поиск" <<
			"\n\t0. Назад\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_3);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1: showScholarshipData(vec_of_students);  break;
		case 2: sorting(vec_of_students);  break;
		case 3: searchInfo(vec_of_students); break;
		}
	}

}
//	Меню работы с данными
void menu_scolarship(vector <Student>& vec_of_students)
{
	int choice;
	bool  ready, check;
	ready = check = true;
	while (ready)
	{
		cout << " Работа с данными " <<
			"\n\t1. Режим редактирования" <<
			"\n\t2. Режим обработки данных" <<
			"\n\t0. Назад\n\n";
		cout << "Выберите: ";
		choice = inputNum(LR_0, RR_2);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1: edit_mode(vec_of_students); break;
		case 2: process_mode(vec_of_students); break;
		}
	}
}












