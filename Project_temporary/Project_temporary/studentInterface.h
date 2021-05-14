#ifndef _STUDENTINTERFACE_H_

#define _STUDENTINTERFACE_H_

#include "handling.h"
#include "interface.h"

void initialStudentBackground(studentNode* pItem);

void clearStudentScreen();

void viewStudentProfile(studentNode* pItem);

void changeStudentPassword(studentNode*& pItem);

void aboutStudentProfile(studentNode*& pItem, bool& isLogOut);

void studentMenu(studentNode*& pItem);

void viewCourses(studentNode* pItem);

void viewNote(studentNode* pItem);

#endif // !_STUDENTINTERFACE_H_