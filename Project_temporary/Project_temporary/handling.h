#pragma once
#ifndef _HANDLING_H_
#define _HANDLING_H_

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>


using namespace std;

struct course {
	string subName, subID, teacher;
	double midterm, final, lab;
	course* pNext, * pPrev;
};

struct studentNode {
	string name, id, classname, username, password;
	long birthday; //ddmmyyyy
	course* headSubject,* endSubject;
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

extern course* headCourse, * endCourse;
extern Class* headClass,* endClass;
extern staffNode* headStaff, * endStaff;

#include "staffInterface.h"
long random(long n);

Class* findClass(string classname, bool doAdd);

void updateStudent(string filename);
void updateStaff(string filename);
void updateCourse(string filename);

void printBirthday(long b);

void addClassNode(string classname);
void addStudentNode(Class*& pClass, studentNode* pItem);
void addStaffNode(staffNode* pItem);
void addCourseNode(course* pItem);

bool addFromCSV(string filename);

void addDataToStaffCsvFile(staffNode* pHead);
void addDataToStudentCsvFile(Class* pHead);

void addFromKeyb(string name, string id, string cl, string username, string password, string birthday, string role, studentNode*& headStudent, studentNode*& endStudent);

void displayClassList();
void displayStudentList(Class* pClass);
bool checkLogin(string username, string password, studentNode*& headStudent, studentNode*& endStudent, studentNode*& pSt, staffNode*& pStf);

void cleanUpClass();
void cleanUpStaff();
void cleanUpCourse();

bool checkk(string username, string password, studentNode*& pSt, staffNode*& pStf);
#endif // !_HANDLING_H_