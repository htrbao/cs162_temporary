#pragma once
#ifndef _INTERFACE_H_

#define _INTERFACE_H_

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "handling.h"


using namespace std;

struct roll{
	long x, y;
	short color;
	string message;
};

void DisableCtrButton(bool Close, bool Min, bool Max); // disable buttons with windows

void gotoxy(short posX, short posY); // move cursor to position[X, Y] X : column Y : row countedFromZero

void ShowCur(bool CursorVisibility); // hidden || show cursor

void drawRec(long x, long y, long posX, long posY);

void drawRec2(long x, long y, long posX, long posY);

void drawRec3(long x, long y, long posX, long posY);

void avatar(bool i, long length, short posX, short posY); // draw avatar randomly at position[X, Y]

void ellipses(int posX, int posY);

bool isOK(string str);

void setTextColor(long color);

void showInput(bool show, HANDLE hStdin, DWORD mode);

void welcome();

void warning(string warningText, long x, long y, long posX, long posY);

void printSettingBox(roll* setting, long n);

void DisableResizeWindow();

void ShowScrollbar(BOOL Show);

void setScreenSize(SHORT x, SHORT y, SHORT width, SHORT height);

void setColor(int color);

int inputKey();

void setBackgroundColor(int BackC);

void ellipses(int posX, int posY);

#endif // !_INTERFACE_H_
