#include "handling.h"
using namespace std;
void addStudentNode(studentNode*& head, studentNode*& end, studentNode* pItem)
{
	if (!head)
	{
		head = pItem;
		end = pItem;
		return;
	}
	end->pNext = pItem;
	end = end->pNext;
}

void addStaffNode(staffNode*& head, staffNode*& end, staffNode* pItem)
{
	if (!head)
	{
		head = pItem;
		end = pItem;
		return;
	}
	end->pNext = pItem;
	end = end->pNext;
}

bool addFromCSV(string filename)
{
	ifstream f;
	f.open(filename);
	string role;
	getline(f, role, ',');
	if (role == "student") {
		studentNode* pItem = new studentNode;

		//char c;
		string name, id, username, password, birthday;
		getline(f, name, ',');
		//cin >> c;
		getline(f, id, ',');
		//cin >> c;
		getline(f, username, ',');
		//cin >> c;
		getline(f, password, ',');
		//cin >> c;
		getline(f, birthday, '\n');

		pItem->name = name;
		pItem->id = id;
		pItem->username = username;
		pItem->password = password;
		pItem->birthday = stoi(birthday);
		pItem->pNext = nullptr;
		addDataToStudentCsvFile(pItem);
	}
	else if (role == "staff") {
		staffNode* pItem = new staffNode;

		//char c;
		string name, id, username, password, birthday;
		getline(f, name, ',');
		//cin >> c;
		getline(f, id, ',');
		//cin >> c;
		getline(f, username, ',');
		//cin >> c;
		getline(f, password, ',');
		//cin >> c;
		getline(f, birthday, '\n');

		pItem->name = name;
		pItem->id = id;
		pItem->username = username;
		pItem->password = password;
		pItem->birthday = stoi(birthday);
		pItem->pNext = nullptr;
		addDataToStaffCsvFile(pItem);
	}
	else {
		return false;
	}
	f.close();
	return true;
}

void addDataToStaffCsvFile(staffNode* pItem)
{
	ofstream fout;
	fout.open("STAFF.txt", ios::app);
	fout << pItem->name << "," << pItem->id << "," << pItem->username << "," << pItem->password;
	fout.close();
}

void addDataToStudentCsvFile(studentNode* pItem) {
	ofstream fout;
	fout.open("STUDENT.txt", ios::app);
	fout << pItem->name << "," << pItem->id << "," << pItem->username << "," << pItem->password;
	fout.close();
}

void addFromKeyb(string name, string id, string username, string password, string role, studentNode*& headT, studentNode*& endT, studentNode* pItemT, staffNode*& headF, staffNode*& endF, staffNode* pItemF)
{
	if (role == "student")
	{
		addStudentNode(headT, endT, pItemT);
		addDataToStudentCsvFile(pItemT);
	}
	else
	{
		addStaffNode(headF, endF, pItemF);
		addDataToStaffCsvFile(staffNode * pItemF);
	}
}
