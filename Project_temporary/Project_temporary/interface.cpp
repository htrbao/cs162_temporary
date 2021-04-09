#include "interface.h"



void DisableCtrButton(bool Close, bool Min, bool Max)
{
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	if (Close == 1)
	{
		DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	}
	if (Min == 1)
	{
		DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
	}
	if (Max == 1)
	{
		DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	}
}

void gotoxy(short posX, short posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void setTextColor(long color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdout, color);
}

void drawRec(long x, long y, long posX, long posY)
{
	x = x + 2;
	y = y * 4 + 1;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(218);
		else if (i == y) cout << char(191);
		else cout << char(196);
	}
	for (long i = 2; i < x; i++)
	{
		posY++;
		gotoxy(posX, posY);
		for (long j = 1; j <= y; j++)
		{
			if (j == 1 || j == y) cout << char(179);
			else cout << ' ';
		}
	}
	posY++;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(192);
		else if (i == y) cout << char(217);
		else cout << char(196);
	}
}

void drawRec2(long x, long y, long posX, long posY)
{
	x = x + 2;
	y = y * 4 + 1;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == y) cout << char(187);
		else cout << char(205);
	}
	for (long i = 2; i < x; i++)
	{
		posY++;
		gotoxy(posX, posY);
		for (long j = 1; j <= y; j++)
		{
			if (j == 1 || j == y) cout << char(186);
			else cout << ' ';
		}
	}
	posY++;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(200);
		else if (i == y) cout << char(188);
		else cout << char(205);
	}
}

void avatar(bool i, short posX, short posY)
{
	if (i == 1)
	{
		drawRec(1, 1, posX, posY);
	}
	else
	{
		drawRec2(1, 1, posX, posY);
	}
}

void showInput(bool show, HANDLE hStdin, DWORD mode)
{


	if (show)
	{


		SetConsoleMode(hStdin, mode & (~ENABLE_INSERT_MODE));
	}
	else
	{

		SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	}
}

void welcome()
{
	cout << "			    __    __   _____   __      _____   _____   __  __   _____  \n";
	cout << "			   |  |/\\|  | |  ___| |  |    /     \\ /     \\\ |  \\/  | |  ___| \n";
	cout << "			   |        | |  ___| |  |__  | <---< |  |  | |      | |  ___| \n";
	cout << "			    \\__/\\__/  |_____| |_____| \\_____/ \\_____/ |_|\\/|_| |_____| \n";
	cout << endl;
	cout << endl;
	cout << "  	                            &&&&&&&&7                       $&&&&&$\n";
	cout << "                                    &&&&&&&&&c                   &&&&&&&$\n";
	cout << "                                     @&&&&&$&&&&                ¢&&&&&&&$\n";
	cout << "                                      &&&&&&&&&&&&             &&&&&&&&@\n";
	cout << "                                        &&&&&&&&&&&&c         &&&&&&&&&&\n";
	cout << "                                          &&&&&&&&&&&&       &&&&&&&&&\n";
	cout << "                                            c&&&&&&&&&&&    &&&&&&&&&\n";
	cout << "                                             &&&&&$&&&&&7   &&&&&&&&&7\n";
	cout << "                                              7&&&&&&&&&&  &&&&&&&&&\n";
	cout << "                                                &&&&&&&&  &&&&&&&\n";
	cout << "                                                      $&&&&&&&&&&&\n";
	cout << "                                                  &&&&&&&&&&&&&&&&\n";
	cout << "                                                &&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                              &&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                            &&&@    &&&&&&&&&&&&&&&&\n";
	cout << "                                           &&&&      &&&&&&&&&&&&&&&&\n";
	cout << "                                          &&&&&&    &&&&&&&&&&&&&&&&&\n";
	cout << "                                          &&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                          &&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                           &&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                             &&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                               7&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                  &&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                   &&&&&|-O-|&&&&&\n";
}

