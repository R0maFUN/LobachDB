
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
	if (!Data)
		return 0;

	vector<ELEMENT*> AllElements;
	for (int i = 0; i < Data->size(); ++i)
	{
		ELEMENT* test = InitElement((*Data)[i]);
		AllElements.push_back(test);
	}

	for (int i = 0; i < AllElements.size(); ++i)
		PrintElement(AllElements[i]);

	int a;
	cin >> a;
	system("cls");
	AddElement(&AllElements);
	PrintIntoFile(filename, &AllElements);

	for (int i = 0; i < AllElements.size(); ++i)
		PrintElement(AllElements[i]);
	string name;
	cout << "Enter the name to delete" << endl;
	cin >> name;
	system("cls");
	DeleteElementByName(&AllElements, name);

	for (int i = 0; i < AllElements.size(); ++i)
		PrintElement(AllElements[i]);

	cout << "Enter the name to change phone" << endl;
	cin >> name;
	system("cls");
	ChangePhoneByName(&AllElements, name, string("70000000000"));
	for (int i = 0; i < AllElements.size(); ++i)
		PrintElement(AllElements[i]);

	cout << "Enter the name to find element" << endl;
	cin >> name;
	system("cls");
	ELEMENT* element = FindStudentByName(&AllElements, name);

	PrintElement(element);

	cout << "Enter something to sort table by name" << endl;
	cin >> name;
	system("cls");
	SortByName(&AllElements);
	for (int i = 0; i < AllElements.size(); ++i)
		PrintElement(AllElements[i]);



	return 0;
}