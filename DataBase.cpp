#define _CRT_SECURE_NO_WARNINGS
#include "DataBase.h"
#include "IO.h"
#include <algorithm>

enum KEYS {
	name,
	group,
	phone,
	lessonName,
	teacherName,
	teacherEmail,
	date,
	mark
};

STUDENT* InitStudent(string Data)
{
	STUDENT* p = new STUDENT;
	vector<string> * parsed = ParseString(Data);
	p->name = (*parsed)[name];
	p->group = StringToInt((*parsed)[group]) ;
	p->phone = (*parsed)[phone];
	p->lessonName = (*parsed)[lessonName];
	p->teacherName = (*parsed)[teacherName];
	p->teacherEmail = (*parsed)[teacherEmail];
	p->date = (*parsed)[date];
	p->mark = StringToInt((*parsed)[mark]) ;
	return p;
}

void AddStudent(vector<STUDENT*> * students)
{
	string inp;
	cout << "Enter the data about student" << endl;
	cin.get();
	getline(cin, inp);
	// isCorrect();
	STUDENT* p = InitStudent(inp);
	students->push_back(p);
}

void DeleteStudentByName(vector<STUDENT*>* students , string name)
{
	for (int i = 0; i < students->size(); ++i)
		if ((*students)[i]->name == name)
		{
			students->erase(students->begin() + i);
			return;
		}
}

void DeleteStudentByPhone(vector<STUDENT*>* students, string phone)
{
	for (int i = 0; i < students->size(); ++i)
		if ((*students)[i]->phone == phone)
		{
			students->erase(students->begin() + i);
			return;
		}
}

void ChangePhoneByName(vector<STUDENT*>* students, string name , string newPhone)
{
	for (int i = 0; i < students->size(); ++i)
		if ((*students)[i]->name == name)
		{
			(*students)[i]->phone = newPhone;
			return;
		}
}

void ChangeGroupByName(vector<STUDENT*>* students, string name, int newGroup)
{
	for (int i = 0; i < students->size(); ++i)
		if ((*students)[i]->name == name)
		{
			(*students)[i]->group = newGroup;
			return;
		}
}

void ChangeMarkByName(vector<STUDENT*>* students, string name, int newMark)
{
	for (int i = 0; i < students->size(); ++i)
		if ((*students)[i]->name == name)
		{
			(*students)[i]->mark = newMark;
			return;
		}
}

STUDENT * FindStudentByName(vector<STUDENT*>* students, string name)
{
	for (int i = 0; i < students->size(); ++i)
		if ((*students)[i]->name == name)
			return (*students)[i];
}

bool WayToSort(STUDENT* a, STUDENT* b)
{
	return a->name < b->name;
}
void SortByName(vector<STUDENT*>* students)
{
	sort(students->begin(), students->end(), WayToSort);
}