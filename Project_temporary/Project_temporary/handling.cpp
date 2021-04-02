#include "handling.h"

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

void addDataToStaffCsvFile(ofstream fout, staffNode* pHead)
{
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