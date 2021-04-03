#ifndef _HANDLING_H_

#define _HANGDLING_H_

#include <iostream>
#include <fstream>
#include <string>
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

void addStudentNode(studentNode*& head, studentNode*& end, studentNode* pItem);
void addStaffNode(staffNode*& head, staffNode*& end, staffNode* pItem);
void addDataToStaffCsvFile(staffNode* pHead);
void addDataToStudentCsvFile(studentNode* pHead);
bool checkLogInStaff(string username, string password);
bool checkLogInStudent(string username, string password);
bool checkLogin(string username, string password);

#endif // !_HANDLING_H_