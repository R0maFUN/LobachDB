#pragma once
#include <string>
#include <vector>
using namespace std;

struct ELEMENT {

	string name;
	string phone;
	string email;
	int salary;
	string managerName;
	string managerPhone;
	string date;

};

ELEMENT* InitElement(string Data);
void AddElement(vector<ELEMENT*>* elements);

//template <typename T>
//void ChangeSmthByName(vector<ELEMENT*>* elements, string name, T newVal);

void DeleteElementByName(vector<ELEMENT*>* elements, string name);

void DeleteElementByPhone(vector<ELEMENT*>* elements, string phone);

void ChangePhoneByName(vector<ELEMENT*>* elements, string name, string newPhone);

void ChangeEmailByName(vector<ELEMENT*>* elements, string name, string newEmail);

void ChangeSalaryByName(vector<ELEMENT*>* elements, string name, int newSalary);

void ChangeManagerByName(vector<ELEMENT*>* elements, string name, string newManager);

ELEMENT* FindStudentByName(vector<ELEMENT*>* elements, string name);

bool WayToSort(ELEMENT* a, ELEMENT* b);
void SortByName(vector<ELEMENT*>* elements);