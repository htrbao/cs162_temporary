#include "handling.h"

staffNode* headStaff;
studentNode* headStudent;

void printBirthday(long b)
{
	cout << b / 1000000;
	cout << '/' << (b / 10000) % 100;
	cout << '/' << b % 10000;
}

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

bool addFromCSV(string filename, studentNode* &pTH, studentNode*& pTE, staffNode* &pFH, staffNode* &pFE)
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
		addStudentNode(pTH, pTE, pItem);
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
		addStaffNode(pFH, pFE, pItem);
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
	fout << pItem->name << "," << pItem->id << "," << pItem->username << "," << pItem->password << "," << pItem->birthday;
	fout.close();
}

void addDataToStudentCsvFile(studentNode* pItem) {
	ofstream fout;
	fout.open("STUDENT.txt", ios::app);
	fout << pItem->name << "," << pItem->id << "," << pItem->username << "," << pItem->password << "," << pItem->birthday;
	fout.close();
}


void addFromKeyb(string name, string id, string username, string password, string birthday, string role, studentNode*& headT, studentNode*& endT, staffNode*& headF, staffNode*& endF)
{
	if (role == "student")
	{
		studentNode* pItemT = new studentNode;
		pItemT->name = name;
		pItemT->id = id;
		pItemT->username = username;
		pItemT->password = password;
		pItemT->birthday = stoi(birthday);
		pItemT->pNext = nullptr;
		addStudentNode(headT, endT, pItemT);
		addDataToStudentCsvFile(pItemT);
	}
	else
	{
		staffNode* pItemF = new staffNode;
		pItemF->name = name;
		pItemF->id = id;
		pItemF->username = username;
		pItemF->password = password;
		pItemF->birthday = stoi(birthday);
		pItemF->pNext = nullptr;
		addStaffNode(headF, endF, pItemF);
		addDataToStaffCsvFile(pItemF);
	}
}
bool checkLogin(string username, string password)
{
	if (username[0] == 'F')
	{
		staffNode* temp = headStaff;
		while (temp)
		{
			if (!temp->username.compare(username) && !temp->password.compare(password))
			{
				cout << "staff" << endl; //chinh sua sau
				return true;
			}
			temp = temp->pNext;
		}
	}
	else if (username[0] == 'T')
	{
		studentNode* temp = headStudent;
		while (temp)
		{
			if (!temp->username.compare(username) && !temp->password.compare(password))
			{
				cout << "student" << endl;
				return true;
			}
			temp = temp->pNext;
		}
	}
	return false;
}
