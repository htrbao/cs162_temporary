#pragma once
#ifndef _HANDLING_H_

#define _HANGDLING_H_

#include <iostream>
#include <string>
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
	studentNode* pNext,* pPrev;
};

struct staffNode {
	string name, id, username, password;
	long birthday; //ddmmyyyy
	staffNode* pNext, * pPrev;
};

extern staffNode* headStaff, * endStaff;
extern studentNode* headStudent, * endStudent;

void printBirthday(long b);
void addStudentNode(studentNode*& head, studentNode*& end, studentNode* pItem);
void addStaffNode(staffNode*& head, staffNode*& end, staffNode* pItem);
bool addFromCSV(string filename);
void addDataToStaffCsvFile(staffNode* pHead);
void addDataToStudentCsvFile(studentNode* pHead);
void addFromKeyb(string name, string id, string username, string password, string birthday, string role, studentNode*& headT, studentNode*& endT, staffNode*& headF, staffNode*& endF);
bool checkLogin(string username, string password);
#endif // !_HANDLING_H_