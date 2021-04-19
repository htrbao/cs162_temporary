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
	setTextColor(random(15));
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
	setTextColor(8);
}

void drawRec2(long x, long y, long posX, long posY)
{
	x = x + 2;
	y = y * 4 + 1;
	setTextColor(9);
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
	setTextColor(8);
}

void avatar(bool i, long length, short posX, short posY)
{
	if (i == 1)
	{
		drawRec(length, length, posX, posY);
	}
	else
	{
		drawRec2(length, length, posX, posY);
	}
	setTextColor(random(15) * 16);
	for (long k = posX + 2; k <= posX + (length * 4 + 1) - 3; k++)
	{
		for (long e = posY + 1; e <= posY + length; e++)
		{
			gotoxy(k, e);  cout << ' ';
		}
	}
	
	setTextColor(8);
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
	cout << "                                     	               		    __    __   _____   __      _____   _____   __  __   _____  \n";
	cout << "                                     	               		   |  |/\\|  | |  ___| |  |    /     \\ /     \\\ |  \\/  | |  ___| \n";
	cout << "                                                      		   |        | |  ___| |  |__  | <---< |  |  | |      | |  ___| \n";
	cout << "                                      			            \\__/\\__/  |_____| |_____| \\_____/ \\_____/ |_|\\/|_| |_____| \n";
	cout << endl;
	cout << endl;
	cout << "                                      	                               &&&&&&&&7                       $&&&&&$\n";
	cout << "                                                                         &&&&&&&&&c                   &&&&&&&$\n";
	cout << "                                                                          @&&&&&$&&&&                ¢&&&&&&&$\n";
	cout << "                                                                           &&&&&&&&&&&&             &&&&&&&&@\n";
	cout << "                                                                             &&&&&&&&&&&&c         &&&&&&&&&&\n";
	cout << "                                                                               &&&&&&&&&&&&       &&&&&&&&&\n";
	cout << "                                                                                 c&&&&&&&&&&&    &&&&&&&&&\n";
	cout << "                                                                                  &&&&&$&&&&&7   &&&&&&&&&7\n";
	cout << "                                                                                   7&&&&&&&&&&  &&&&&&&&&\n";
	cout << "                                                                                     &&&&&&&&  &&&&&&&\n";
	cout << "                                                                                           $&&&&&&&&&&&\n";
	cout << "                                                                                       &&&&&&&&&&&&&&&&\n";
	cout << "                                                                                     &&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                                                   &&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                                                 &&&@    &&&&&&&&&&&&&&&&\n";
	cout << "                                                                                &&&&      &&&&&&&&&&&&&&&&\n";
	cout << "                                                                               &&&&&&    &&&&&&&&&&&&&&&&&\n";
	cout << "                                                                               &&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                                               &&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                                                &&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                                                  &&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                                                    7&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                                                       &&&&&&&&&&&&&&&&&&&\n";
	cout << "                                                                                        &&&&&|-O-|&&&&&\n";
}

//warning(a, 9, 20, 59, 19);
void warning(string warningText, long x, long y, long posX, long posY) {

	x = x + 2;
	y = y * 4 + 1;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == y) cout << char(187);
		else cout << char(205);
	}

	for (long i = 2; i <= x; i++)
	{
		posY++;
		gotoxy(posX, posY);
		for (long j = 1; j <= y; j++)
		{
			if (j == 1 || j == y) cout << char(186);
			else if (i >= 2 && i <= 7 && j <= 6 && j >= 3) cout << char(219);
			else if ((i == 2 && j == 7) || (i == 9 && j == 7)) cout << char(187);
			else if ((i > 2 && i <= 7 && j == 7) || (i == 10 && j == 7)) cout << char(186);
			else if ((i == 8 && j == 7) || (i == 11 && j == 7)) cout << char(188);
			else if ((i == 8 && j > 4 && j < 7) || (i == 11 && j > 4 && j < 7)) cout << char(205);
			else if ((i == 8 && j == 4) || (i == 11 && j == 4)) cout << char(200);
			else if (i > 8 && i <= x - 1 && j <= 6 && j >= 3) cout << char(219);

			else cout << ' ';
		}
	}
	gotoxy(posX + 38, posY - 4);
	cout << warningText;
	posY++;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(200);
		else if (i == y) cout << char(188);
		else cout << char(205);
	}
}

void printSettingBox(roll* setting, long n)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	for (long i = 0; i < n; i++)
	{
		SetConsoleTextAttribute(hStdout, 7);
		gotoxy(setting[i].x, setting[i].y);
		cout << "               ";

		SetConsoleTextAttribute(hStdout, setting[i].color);
		gotoxy(setting[i].x, setting[i].y);
		cout << setting[i].message;
	}
}
