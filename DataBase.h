#pragma once
#include <string>
#include <vector>
using namespace std;

struct STUDENT {
	string name;
	int group;
	string phone;
	string lessonName;
	string teacherName;
	string teacherEmail;
	string date;
	int mark;
};

STUDENT* InitStudent(string Data);
void AddStudent(vector<STUDENT*>* students);
void DeleteStudentByName(vector<STUDENT*>* students, string name);

void DeleteStudentByPhone(vector<STUDENT*>* students, string phone);

void ChangePhoneByName(vector<STUDENT*>* students, string name, string newPhone);

void ChangeGroupByName(vector<STUDENT*>* students, string name, int newGroup);

void ChangeMarkByName(vector<STUDENT*>* students, string name, int newMark);

STUDENT* FindStudentByName(vector<STUDENT*>* students, string name);

bool WayToSort(STUDENT* a, STUDENT* b);
void SortByName(vector<STUDENT*>* students);