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
