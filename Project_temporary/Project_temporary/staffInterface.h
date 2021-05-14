#pragma once
#ifndef _STAFFINTERFACE_H_
#define _STAFFINTERFACE_H_

#include "handling.h"
#include "interface.h"

void clearStaffScreen();

void clearSettingScreen();

void viewProfile(staffNode* pItem);

void changePassword(staffNode*& pItem);

void creatNewClass();

void DrawAddNewCourse();

void addNewCourse();

void viewAllCourse();

void aboutCourse();

void viewStudent(Class* pClass);

void viewClass();

void aboutProfile(staffNode*& pItem, bool& isLogOut);

void initialStaffBackground(staffNode* pItem);

void staffMenu(staffNode*& pItem);

#endif // !_STAFFINTERFACE_H_
