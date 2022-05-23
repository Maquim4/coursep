#include "readwrite.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	vector <User> vec_of_users;
	vector <Student> vec_of_students;
	int amount = getCountOfStucturesInFile(AUTH_PATH);
	vec_of_users.reserve(amount);// резервируем память 
	if (amount) readFileUsers(vec_of_users);
	amount = getCountOfStucturesInFile(SCH_PATH);
	vec_of_students.reserve(amount);
	if (amount) readFileStudents(vec_of_students);
	entry(vec_of_users, vec_of_students);
	writeFileUsers(vec_of_users);
	writeFileStudents(vec_of_students);
	system("pause");

}
