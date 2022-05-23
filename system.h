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

//	�������� ���� �������
void showStudentsData(vector <Student> vec_of_students)
{
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(4) << "�" << "|" << setw(16) << "����� ������" << "|" << setw(14) << "���" << "|" << setw(16) << "����� ��������"
		<< "|" << setw(12) << "������" << "|" << setw(10) << "������" << "|" << setw(8) << "��.����" << "|" << setw(14) << "����������" << "|\n";
	cout << "-------------------------------------------------------------------------------------------------------\n";
	for (size_t i = 0; i < vec_of_students.size(); i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(16) << vec_of_students.at(i).group << "|" << setw(14) << vec_of_students.at(i).lastname << "|" << setw(16) << vec_of_students.at(i).form << "| ��" << setw(9);
		if (vec_of_students.at(i).credit1) cout << "�����"; else cout << "�������";
		cout << "| ����" << setw(5) << vec_of_students.at(i).mark1 << "|" << setw(8) << vec_of_students.at(i).mark << "|" << setw(14) << vec_of_students.at(i).activity << "|\n";
		cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(14) << vec_of_students.at(i).firstname << "|" << setw(21) << "| ���" << setw(8);
		if (vec_of_students.at(i).credit2) cout << "�����"; else cout << "�������";
		cout << "| �����" << setw(4) << vec_of_students.at(i).mark2 << "|" << setw(9) << "|" << setw(16) << "|\n";
		cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(14) << vec_of_students.at(i).middlename << "|" << setw(21) << "| ���" << setw(8);
		if (vec_of_students.at(i).credit3) cout << "�����"; else cout << "�������";
		cout << "| ����" << setw(5) << vec_of_students.at(i).mark3 << "|" << setw(9) << "|" << setw(16) << "|\n";
		cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(15) << "|" << setw(21) << "| ���" << setw(8);
		if (vec_of_students.at(i).credit4) cout << "�����"; else cout << "�������";
		cout << "| ����" << setw(5) << vec_of_students.at(i).mark4 << "|" << setw(9) << "|" << setw(16) << "|\n";
		cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(15) << "|" << setw(22) << "| ����" << setw(7);
		if (vec_of_students.at(i).credit5) cout << "�����"; else cout << "�������";
		cout << "|" << setw(11) << "|" << setw(9) << "|" << setw(16) << "|\n";
		cout << "-------------------------------------------------------------------------------------------------------\n";
	}
}
//	�������� �������� ���������
void showScholarship(vector <Student>& vec_of_students, double scholar)
{
	double s25;
	s25 = scholar / 4;
	for (size_t i = 0; i < vec_of_students.size(); i++)
		if (vec_of_students.at(i).form == "���������" && vec_of_students.at(i).credit && vec_of_students.at(i).mark > 5) // ���� ������ + ��� ������ ����� + ��.���� ���� 5
		{
			vec_of_students.at(i).scholar = scholar;
			if (vec_of_students.at(i).mark >= 9) vec_of_students.at(i).scholar += s25; // �������� 25% ����������
			if (vec_of_students.at(i).activity == "��������") vec_of_students.at(i).scholar += s25; // �������� 50% � ����� ���������� - ����������
		}
		else vec_of_students.at(i).scholar = 0;
	cout << "------------------------------------------" << "\n";
	cout << "|" << setw(4) << "�" << "|" << setw(10) << "����� ������" << "|" << setw(12) << "�������" << "|" << setw(6) << "���������" << "|\n";
	cout << "------------------------------------------" << "\n";
	for (size_t i = 0; i < vec_of_students.size(); i++)
		if (vec_of_students.at(i).scholar != 0) { // ����� ��������� �� ���������� 
			cout << "|" << setw(4) << i + 1 << "|" << setw(12) << vec_of_students.at(i).group << "|"
				<< setw(12) << vec_of_students.at(i).lastname << "|" << setw(9) << fixed << setprecision(2) << vec_of_students.at(i).scholar << "|\n";
			cout << "------------------------------------------" << "\n";
		}
}
// ���������� ��������
void addStudent(vector <Student>& vec_of_students)
{
	Student student_temp;
	vector<Student>::iterator iter = vec_of_students.begin();
	int choice, n;
	bool check;
	cout << "������� ����� ������: ";
	student_temp.group = inputNum(LR_0, RR_NUM);
	cout << "������� ��� ��������" << endl;
	cout << "�������: ";
	cin >> student_temp.lastname;
	cout << "���: ";
	cin >> student_temp.firstname;
	cout << "��������: ";
	cin >> student_temp.middlename;
	cout << "����� ��������: " << "\n\t1. �������" << "\n\t2. ���������" << "\n��������: ";
	choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.form = "�������"; break; case 2: student_temp.form = "���������"; break; }
									cout << "����� �� �� : " << "\n\t1. �����" << "\n\t2. �������" << "\n��������: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit1 = 1; break; case 2: student_temp.credit1 = 0; break; }
									cout << "����� �� ��� : " << "\n\t1. �����" << "\n\t2. �������" << "\n��������: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit2 = 1; break; case 2: student_temp.credit2 = 0; break; }
									cout << "����� �� ������ : " << "\n\t1. �����" << "\n\t2. �������" << "\n��������: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit3 = 1; break; case 2: student_temp.credit3 = 0; break; }
									cout << "����� �� �����������: " << "\n\t1. �����" << "\n\t2. �������" << "\n��������: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit4 = 1; break; case 2: student_temp.credit4 = 0; break; }
									cout << "����� �� ����: " << "\n\t1. �����" << "\n\t2. �������" << "\n��������: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.credit5 = 1; break; case 2: student_temp.credit5 = 0; break; }
									cout << "������� ������ �� �����: ";
									student_temp.mark1 = inputNum(LR_1, RR_10);
									cout << "������� ������ �� ����: ";
									student_temp.mark2 = inputNum(LR_1, RR_10);
									cout << "������� ������ �� ����: ";
									student_temp.mark3 = inputNum(LR_1, RR_10);
									cout << "������� ������ �� ����: ";
									student_temp.mark4 = inputNum(LR_1, RR_10);
									cout << "������� � ������������ ������: " << "\n\t1. ��������" << "\n\t2. ���������" << "\n��������: ";
									choice = inputNum(LR_1, RR_2);
			switch (choice) { case 1: student_temp.activity = "��������"; break; case 2: student_temp.activity = "���������"; break; }
									student_temp.mark = ((double)student_temp.mark1 + student_temp.mark2 + student_temp.mark3 + student_temp.mark4) / 4.;
									if (student_temp.credit1 && student_temp.credit2 && student_temp.credit3 && student_temp.credit4 && student_temp.credit5)
										student_temp.credit = 1;
									else student_temp.credit = 0;
									student_temp.scholar = 0;
									check = isNewAdd();
									if (check) {
										cout << "\n���� �� ������ �������� ������?" << endl;
										cout << "\t1. � ������\n" << "\t2. � �����\n" << "\t3. �� ������\n\n";
										cout << "��������: ";
										choice = inputNum(LR_1, RR_3);
										switch (choice)
										{
										case 1: vec_of_students.emplace(iter, student_temp); break;
										case 2: vec_of_students.push_back(student_temp); break;
										case 3: cout << "������� �����: ";
											n = inputNum(LR_1, vec_of_students.size() + 1);
											iter += n - 1;
											vec_of_students.emplace(iter, student_temp); break;
										}
									}
}
//	����� �� �������
void searchByIndex(vector <Student>& vec_of_students, int index)
{
	cout << "-------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(4) << index + 1 << "|" << setw(16) << vec_of_students.at(index).group << "|" << setw(14) << vec_of_students.at(index).lastname << "|" << setw(16) << vec_of_students.at(index).form << "| ��" << setw(9);
	if (vec_of_students.at(index).credit1) cout << "�����"; else cout << "�������";
	cout << "| ����" << setw(5) << vec_of_students.at(index).mark1 << "|" << setw(8) << vec_of_students.at(index).mark << "|" << setw(14) << vec_of_students.at(index).activity << "|\n";
	cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(14) << vec_of_students.at(index).firstname << "|" << setw(21) << "| ���" << setw(8);
	if (vec_of_students.at(index).credit2) cout << "�����"; else cout << "�������";
	cout << "| �����" << setw(4) << vec_of_students.at(index).mark2 << "|" << setw(9) << "|" << setw(16) << "|\n";
	cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(14) << vec_of_students.at(index).middlename << "|" << setw(21) << "| ���" << setw(8);
	if (vec_of_students.at(index).credit3) cout << "�����"; else cout << "�������";
	cout << "| ����" << setw(5) << vec_of_students.at(index).mark3 << "|" << setw(9) << "|" << setw(16) << "|\n";
	cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(15) << "|" << setw(21) << "| ���" << setw(8);
	if (vec_of_students.at(index).credit4) cout << "�����"; else cout << "�������";
	cout << "| ����" << setw(5) << vec_of_students.at(index).mark4 << "|" << setw(9) << "|" << setw(16) << "|\n";
	cout << "|" << setw(5) << "|" << setw(17) << "|" << setw(15) << "|" << setw(22) << "| ����" << setw(7);
	if (vec_of_students.at(index).credit5) cout << "�����"; else cout << "�������";
	cout << "|" << setw(11) << "|" << setw(9) << "|" << setw(16) << "|\n";
	cout << "-------------------------------------------------------------------------------------------------------\n";
}
//	�������������� ������
void edit_students(vector <Student>& vec_of_students)
{
	int choice, index, group, mark;
	string lastname, firstname, middlename, form, activity;
	bool ready = true;
	showStudentsData(vec_of_students);
	cout << " ������� ����� ������������� ������: ";
	index = inputNum(LR_1, vec_of_students.size())-1;
	while (ready)
	{
		searchByIndex(vec_of_students, index);
		cout << " ��� �� ������ ���������������? " <<
			"\n\t1. �������" <<
			"\n\t2. ���" <<
			"\n\t3. ��������" <<
			"\n\t4. ����� ������" <<
			"\n\t5. ����� ��������" <<
			"\n\t6. ������" <<
			"\n\t7. ������" <<
			"\n\t8. ����������" <<
			"\n\t0. �����\n\n";
		cout << "��������: ";
		choice = inputNum(LR_0, RR_8);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1:  while (ready) {
			cout << "������� ����� �������: ";
			cin >> lastname;
			for (size_t i = 0; i < lastname.length(); i++) {
				if (isalpha(lastname[i])) { cout << "C����� ���� ��� �� ����� ��������� ����� ��� ������ ������������ ������\n"; ready = true; break; }
				else ready = false;
			}
		} 
			  vec_of_students.at(index).lastname = lastname; 
			  ready = true;
			  break;
		case 2: while (ready) {
			cout << "������� ����� ���: ";
			cin >> firstname;
			for (size_t i = 0; i < firstname.length(); i++) {
				if (isalpha(firstname[i])) { cout << "C����� ���� ��� �� ����� ��������� ����� ��� ������ ������������ ������\n"; ready = true; break; }
				else ready = false;
			}
		} 
			  vec_of_students.at(index).firstname = firstname;
			  ready = true;
			  break;
		case 3: while (ready) {
			cout << "������� ����� ��������: ";
			cin >> middlename;
			for (size_t i = 0; i < middlename.length(); i++) {
				if (isalpha(middlename[i])) { cout << "C����� ���� ��� �� ����� ��������� ����� ��� ������ ������������ ������\n"; ready = true; break; }
				else ready = false;
			}
		}
			  vec_of_students.at(index).middlename = middlename;
			  ready = true;
			  break;
		case 4: cout << "������� ����� ����� ������: ";
			group = inputNum(LR_0, RR_NUM);
			vec_of_students.at(index).group = group;
			break;
		case 5:  vec_of_students.at(index).form == "�������" ? vec_of_students.at(index).form = "���������" : vec_of_students.at(index).form = "�������";
			break;
		case 6:   cout << " �������� �������: " <<
			"\n\t1. ��" <<
			"\n\t2. ���" <<
			"\n\t3. ������" <<
			"\n\t4. �����" <<
			"\n\t5. ����\n\n";
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
		case 7:cout << " �������� �������: " <<
			"\n\t1. ����" <<
			"\n\t2. �����" <<
			"\n\t3. ����" <<
			"\n\t4. ����\n\n";
			choice = inputNum(LR_1, RR_5);
			cout << " ������� ������: ";
			mark = inputNum(LR_1, RR_10);
			switch (choice)
			{
			case 1:  vec_of_students.at(index).mark1 = mark; break;
			case 2:  vec_of_students.at(index).mark2 = mark; break;
			case 3:  vec_of_students.at(index).mark3 = mark; break;
			case 4:  vec_of_students.at(index).mark4 = mark; break;
			}
			break;
		case 8: vec_of_students.at(index).activity == "��������" ? vec_of_students.at(index).activity = "���������" : vec_of_students.at(index).activity = "��������"; break;
		}
		vec_of_students.at(index).mark = ((double)vec_of_students.at(index).mark1 + vec_of_students.at(index).mark2 + vec_of_students.at(index).mark3 +
			vec_of_students.at(index).mark4) / 4.;
		if (vec_of_students.at(index).credit1 && vec_of_students.at(index).credit2 && vec_of_students.at(index).credit3 && vec_of_students.at(index).credit4 && vec_of_students.at(index).credit5)
			vec_of_students.at(index).credit = 1;
		else vec_of_students.at(index).credit = 0;
		vec_of_students.at(index).scholar = 0;
	}
}
//	����� ��������������
void edit_mode(vector <Student>& vec_of_students)
{
	Student student_temp;
	int choice, index;
	bool  ready, check;
	ready = check = true;
	while (ready)
	{
		cout << " ����� �������������� " <<
			"\n\t1. ��������" <<
			"\n\t2. ����������" <<
			"\n\t3. ��������" <<
			"\n\t4. ��������������" <<
			"\n\t0. �����\n\n";
		cout << "��������: ";
		choice = inputNum(LR_0, RR_4);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1:
			cout << "\n -�������� ������- " << endl;
			if (vec_of_students.size() == 0) cout << "��� ������!" << endl;
			else showStudentsData(vec_of_students);
			break;
		case 2:
			cout << "\n -���������� ������- " << endl;
			addStudent(vec_of_students); break;
		case 3:
			cout << "\n -�������� ������- " << endl;
			if (vec_of_students.size() == 0) cout << "��� ������!" << endl;
			else
			{
				cout << "\t1. ���\n" << "\t2. �� �������\n" << "\t0. �����\n\n";
				cout << "��������: ";
				choice = inputNum(LR_0, RR_2);
				switch (choice)
				{
				case 0: break;
				case 1:
					check = isDelete();
					if (check) vec_of_students.clear(); break;
				case 2:
					cout << "������� � (�� 1 �� " << vec_of_students.size() << "): ";
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
// �������� ������ � ������ ���������
void showScholarshipData(vector <Student>& vec_of_students)
{
	bool ready = true;
	double scholar;
	int choice;
	cout << "\n -�������� ������- " << endl;
	if (vec_of_students.size() == 0) cout << "��� ������!" << endl;
	else {
		while (ready) {
			cout << "\t1. �������� ���������" <<
				"\n\t2. ������� ���������" <<
				"\n\t0. �����\n\n";
			cout << "��������: ";
			choice = inputNum(LR_0, RR_2);
			switch (choice)
			{
			case 0:ready = false; break;
			case 1: cout << "------------------------------------------" << "\n";
				cout << "|" << setw(4) << "�" << "|" << setw(10) << "����� ������" << "|" << setw(12) << "�������" << "|" << setw(6) << "���������" << "|\n";
				cout << "------------------------------------------" << "\n";
				for (size_t i = 0; i < vec_of_students.size(); i++)
					if (vec_of_students.at(i).scholar != 0) { // ����� ��������� �� ���������� 
						cout << "|" << setw(4) << i + 1 << "|" << setw(12) << vec_of_students.at(i).group << "|"
							<< setw(12) << vec_of_students.at(i).lastname << "|" << setw(9) << fixed << setprecision(2) << vec_of_students.at(i).scholar << "|\n";
						cout << "------------------------------------------" << "\n";
					} break;
			case 2:
				cout << "������� ������� ������ ���������: ";
				scholar = inputNum(LR_D, RR_D);
				showScholarship(vec_of_students, scholar);
				break;
			}
		}
	}
}
// �� ��������
const bool sortByABC(const Student first, const Student second)
{
	return first.lastname < second.lastname;
}
// �� �������� �����
const bool sortByMark(const Student first, const Student second)
{
	return first.mark > second.mark;
}
// �� ������� ���������
const bool sortByScholarship(const Student first, const Student second)
{
	return first.scholar > second.scholar;
}
// ���������� ������
void sorting(vector <Student> vec_of_students)
{
	int choice;
	while (true)
	{
		system("cls");
		cout << " ���������� ������" << endl
			<< "1. ������������� �� ��������" << endl
			<< "2. ������������� �� ��.�����" << endl
			<< "3. ������������� �� ���������" << endl
			<< "0. �����" << endl;
		cout << "��������: ";
		choice = inputNum(LR_0, RR_3);
		if (choice == 1)
		{
			system("cls");
			sort(vec_of_students.begin(), vec_of_students.end(), sortByABC);
			cout << "\t\t\t-���������� �� ��������-\t\t\t" << endl;
			showStudentsData(vec_of_students);
			system("pause");
		}
		if (choice == 2)
		{
			system("cls");
			cout << "\t\t\t-���������� �� �������� �����-\t\t\t" << endl;
			sort(vec_of_students.begin(), vec_of_students.end(), sortByMark);
			showStudentsData(vec_of_students);
			system("pause");
		}
		if (choice == 3)
		{
			system("cls");
			cout << "\t\t\t-���������� �� ���������-\t\t\t" << endl;
			sort(vec_of_students.begin(), vec_of_students.end(), sortByScholarship);
			cout << "------------------------------------------" << "\n";
			cout << "|" << setw(4) << "�" << "|" << setw(10) << "����� ������" << "|" << setw(12) << "�������" << "|" << setw(6) << "���������" << "|\n";
			cout << "------------------------------------------" << "\n";
			for (size_t i = 0; i < vec_of_students.size(); i++)
				if (vec_of_students.at(i).scholar != 0) { // ����� ��������� �� ���������� 
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
// ����� �� �������
void searchInfo(vector <Student> vec_of_students)
{
	int choice, i = 0, group, index;
	string lastname;
	bool ready = true;
	while (true)
	{
		int count = 0;
		system("cls");
		cout << " -����� ������- \n"
			<< "1. �� �������\n"
			<< "2. �� ������ ������\n"
			<< "3. �� �������\n"
			<< "0. �����\n"
			<< "��� �����: ";
		choice = inputNum(LR_0, RR_3);
		switch (choice)
		{
		case 1:
		{
			system("cls");
			while (ready) {
				cout << "������� �������: ";
				cin >> lastname;
				for (size_t i = 0; i < lastname.length(); i++) {
					if (isalpha(lastname[i])) { cout << "C����� ���� ��� �� ����� ��������� ����� ��� ������ ������������ ������\n"; ready = true; break; }
					else ready = false;
				}
			}
			for (size_t i = 0; i < vec_of_students.size(); i++)
				if (vec_of_students.at(i).lastname == lastname) {
					searchByIndex(vec_of_students, i);
					count++;
				}
			if (!count) cout << " ������ �� ������� �����!\n";
			system("pause");
		}
		break;
		case 2:
		{
			system("cls");
			cout << "������� ����� ������: ";
			group = inputNum(LR_0, RR_NUM);
			for (size_t i = 0; i < vec_of_students.size(); i++)
				if (vec_of_students.at(i).group == group) {
					searchByIndex(vec_of_students, i);
					count++;
				}
			if (!count) cout << " ������ �� ������� �����!\n";
			system("pause");
		}
		break;
		case 3:
		{
			system("cls");
			cout << "������� ������: ";
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
//	����� ��������� ������
void process_mode(vector <Student>& vec_of_students)
{
	int choice;
	bool  ready, check;
	ready = check = true;
	while (ready)
	{
		cout << " ����� ��������� ������ " <<
			"\n\t1. �������� ������" <<
			"\n\t2. ����������" <<
			"\n\t3. �����" <<
			"\n\t0. �����\n\n";
		cout << "��������: ";
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
//	���� ������ � �������
void menu_scolarship(vector <Student>& vec_of_students)
{
	int choice;
	bool  ready, check;
	ready = check = true;
	while (ready)
	{
		cout << " ������ � ������� " <<
			"\n\t1. ����� ��������������" <<
			"\n\t2. ����� ��������� ������" <<
			"\n\t0. �����\n\n";
		cout << "��������: ";
		choice = inputNum(LR_0, RR_2);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1: edit_mode(vec_of_students); break;
		case 2: process_mode(vec_of_students); break;
		}
	}
}












