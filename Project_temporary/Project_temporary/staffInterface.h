#ifndef _STAFFINTERFACE_H_

#define _STAFFINTERFACE_H_

#include "handling.h"
#include "interface.h"

void clearStaffScreen();

void clearSettingScreen();

void viewProfile(staffNode* pItem);

void changePassword(staffNode*& pItem);

void aboutProfile(staffNode*& pItem, bool& isLogOut);

void initialStaffBackground(staffNode* pItem);

void staffMenu(staffNode*& pItem);

#endif // !_STAFFINTERFACE_H_
