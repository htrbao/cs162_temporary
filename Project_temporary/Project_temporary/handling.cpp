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