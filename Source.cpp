
#include "DataBase.h"
#include "IO.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	system("title DATABASE");
	cout << "Enter the file name" << endl;
	string filename;
	cin >> filename;
	vector<string> * Data = ParseFile(filename);

	vector<STUDENT*> Students;
	for (int i = 0; i < Data->size(); ++i)
	{
		STUDENT* test = InitStudent((*Data)[i]);
		Students.push_back(test);
	}

	for (int i = 0; i < Students.size(); ++i)
		PrintStudent(Students[i]);

	int a;
	cin >> a;
	system("cls");
	AddStudent(&Students);
	PrintIntoFile(filename, &Students);

	for (int i = 0; i < Students.size(); ++i)
		PrintStudent(Students[i]);
	string name;
	cout << "Enter the name to delete" << endl;
	cin >> name;
	system("cls");
	DeleteStudentByName(&Students, name);

	for (int i = 0; i < Students.size(); ++i)
		PrintStudent(Students[i]);

	cout << "Enter the name to change mark" << endl;
	cin >> name;
	system("cls");
	ChangeMarkByName(&Students, name, 10);
	for (int i = 0; i < Students.size(); ++i)
		PrintStudent(Students[i]);

	cout << "Enter the name to find student" << endl;
	cin >> name;
	system("cls");
	STUDENT* student = FindStudentByName(&Students, name);

	PrintStudent(student);

	cout << "Enter something to sort table by name" << endl;
	cin >> name;
	system("cls");
	SortByName(&Students);
	for (int i = 0; i < Students.size(); ++i)
		PrintStudent(Students[i]);



	return 0;
}