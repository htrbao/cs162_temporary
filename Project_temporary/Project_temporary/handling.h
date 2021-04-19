#pragma once
#ifndef _HANDLING_H_

#define _HANGDLING_H_

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

struct subject {
	string subName, subID;
	double midterm, final, lab;
	subject* pNext, * pPrev;
};

struct studentNode {
	string name, id, classname, username, password;
	long birthday; //ddmmyyyy
	subject* headSubject;
	studentNode* pNext,* pPrev;
};

struct Class {
	string name;
	studentNode* headStudent,* endStudent;
	Class* pNext, *pPrev;
};

struct staffNode {
	string name, id, username, password;
	long birthday; //ddmmyyyy
	staffNode* pNext, * pPrev;
};

extern Class* headClass,* endClass;
extern staffNode* headStaff, * endStaff;
extern studentNode* headStudent, * endStudent;

long random(long n);
Class* findClass(string classname, bool doAdd);
void updateStudent(string filename);
void updateStaff(string filename);
void addClassNode(string classname);
void printBirthday(long b);
void addStudentNode(Class*& pClass, studentNode* pItem);
void addStaffNode(staffNode* pItem);
bool addFromCSV(string filename);
void addDataToStaffCsvFile(staffNode* pHead);
void addDataToStudentCsvFile(studentNode* pHead);
void addFromKeyb(string name, string id, string cl, string username, string password, string birthday, string role, studentNode*& headStudent, studentNode*& endStudent);
void displayClassList();
void displayStudentList(Class* pClass);
bool checkLogin(string username, string password, studentNode*& headStudent, studentNode*& endStudent);
void cleanUpClass();
void cleanUpStaff();
#endif // !_HANDLING_H_