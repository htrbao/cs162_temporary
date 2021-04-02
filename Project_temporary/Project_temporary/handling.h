#ifndef _HANDLING_H_

#define _HANGDLING_H_

#include <iostream>
#include <fstream>

using namespace std;

struct subject {
	string subName, subID;
};

struct marks {
	double midterm, final, lab;
};

struct studentNode {
	string name, id, username, password;
	long birthday; //ddmmyyyy
	marks Maths, Physics, CS; //initialization value is -1;
	studentNode* pNext;
};

struct staffNode {
	string name, id, username, password;
	long birthday; //ddmmyyyy
	staffNode* pNext;
};

#endif // !_HANDLING_H_
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

void addDataToStaffCsvFile(ofstream fout, staffNode* pHead) {
	staffNode* pCur = pHead;
	fout.open("STAFF.txt", ios::app);
	fout << "name,id,username,password";
	while (pCur != nullptr) {
		fout << pCur->name << "," << pCur->id << "," << pCur->username << "," << pCur->password;
		pCur = pCur->pNext;
	}

	fout.close();
}

void addDataToStudentCsvFile(ofstream fout, studentNode* pHead) {
	studentNode* pCur = pHead;
	fout.open("STUDENT.txt", ios::app);
	fout << "name,id,username,password";
	while (pCur != nullptr) {
		fout << pCur->name << "," << pCur->id << "," << pCur->username << "," << pCur->password;
		pCur = pCur->pNext;
	}

	fout.close();
}
void addStudentNode(studentNode*& head, studentNode*& end, studentNode* pItem);
void addStaffNode(staffNode*& head, staffNode*& end, staffNode* pItem);