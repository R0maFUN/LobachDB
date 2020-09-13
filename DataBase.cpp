#define _CRT_SECURE_NO_WARNINGS
#include "DataBase.h"
#include "IO.h"
#include <algorithm>

enum KEYS {
	name,
	phone,
	email,
	salary,
	managerName,
	managerPhone,
	date
};

ELEMENT* InitElement(string Data)
{
	ELEMENT* p = new ELEMENT;
	vector<string> * parsed = ParseString(Data);
	p->name = (*parsed)[name];
	p->phone = (*parsed)[phone];
	p->email = (*parsed)[email];
	p->salary = StringToInt((*parsed)[salary]);
	p->managerName = (*parsed)[managerName];
	p->managerPhone = (*parsed)[managerPhone];
	p->date = (*parsed)[date];
	return p;
}

void AddElement(vector<ELEMENT*> * elements)
{
	string inp;
	cout << "Enter the data about element" << endl;
	cin.get();
	getline(cin, inp);
	// isCorrect();
	ELEMENT* p = InitElement(inp);
	elements->push_back(p);
}

void DeleteElementByName(vector<ELEMENT*>* elements , string name)
{
	for (int i = 0; i < elements->size(); ++i)
		if ((*elements)[i]->name == name)
		{
			elements->erase(elements->begin() + i);
			return;
		}
}

void DeleteElementByPhone(vector<ELEMENT*>* elements, string phone)
{
	for (int i = 0; i < elements->size(); ++i)
		if ((*elements)[i]->phone == phone)
		{
			elements->erase(elements->begin() + i);
			return;
		}
}

void ChangePhoneByName(vector<ELEMENT*>* elements, string name , string newPhone)
{
	FindStudentByName(elements, name)->phone = newPhone;
}

void ChangeEmailByName(vector<ELEMENT*>* elements, string name, string newEmail)
{
	FindStudentByName(elements, name)->email = newEmail;
}

void ChangeSalaryByName(vector<ELEMENT*>* elements, string name, int newSalary)
{
	FindStudentByName(elements, name)->salary = newSalary;
}

void ChangeManagerByName(vector<ELEMENT*>* elements, string name, string newManager)
{
	FindStudentByName(elements, name)->managerName = newManager;
}

ELEMENT * FindStudentByName(vector<ELEMENT*>* elements, string name)
{
	for (int i = 0; i < elements->size(); ++i)
		if ((*elements)[i]->name == name)
			return (*elements)[i];
}

bool WayToSort(ELEMENT* a, ELEMENT* b)
{
	return a->name < b->name;
}
void SortByName(vector<ELEMENT*>* elements)
{
	sort(elements->begin(), elements->end(), WayToSort);
}