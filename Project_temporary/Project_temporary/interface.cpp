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

void avatar(bool i,long length, short posX, short posY)
{
	if (i == 1)
	{
		drawRec(length, length - (length == 1 ? 0 : 1), posX, posY);
	}
	else
	{
		drawRec2(length, length - (length == 1 ? 0 : 1), posX, posY);
	}
	setTextColor(random(15) * 16);
	for (long k = posX + 2; k <= posX + (length * 4 + 1) - 3; k++)
	{
		for (long e = posY + 1; e <= posY + length; e++)
		{
			gotoxy(k, e);  cout << ' ';
		}
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

void wait(int seconds)
{
	clock_t ew;
	ew = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < ew) {}
}

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

void clrscr()
{
	COORD origin = { 0, 0 };
	unsigned long len;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	unsigned long size;
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);


	GetConsoleScreenBufferInfo(handle, &csbi);
	size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(handle, TEXT(' '), size, origin, &len);
	FillConsoleOutputAttribute(handle, csbi.wAttributes, size, origin, &len);
	SetConsoleCursorPosition(handle, origin);
}
void gotoxy(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void welcome()
{
	setTextColor(2);
	cout << "			    __    __   _____   __      _____   _____   __  __   _____  \n";
	cout << "			   |  |/\\|  | |  ___| |  |    /     \\ /     \\\ |  \\/  | |  ___| \n";
	cout << "			   |        | |  ___| |  |__  | <---< |  |  | |      | |  ___| \n";
	cout << "			    \\__/\\__/  |_____| |_____| \\_____/ \\_____/ |_|\\/|_| |_____| \n";
	cout << "                             |###########33%                   |";
	cout << endl;
	setTextColor(0);
	cout << "  	                            &&&&&&&&7                       $&&&&&$\n";
	cout << "                                    &&&&&&&&&c                   &&&&&&&$\n";
	cout << "                                     @&&&&&$&&&&                �&&&&&&&$\n";
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

	gotoxy(15, 15);
	gotoxy(15, 5);
	cout << ",-._.-. ";
	gotoxy(14, 6);
	cout << "/_,._,._\\ ";
	gotoxy(14, 7);
	cout << "\\`-._.' / ";
	gotoxy(15, 8);
	cout << "\\_____/ ";

	gotoxy(25, 19);
	cout << "'.----'`v'`----.'";
	gotoxy(26, 20);
	cout << "\\`----._.----'/";
	gotoxy(27, 21);
	cout << "`.--.___.--.'";
	gotoxy(28, 22);
	cout << " `-.___.-'";

	gotoxy(91, 13);
	cout << ".. ..";
	gotoxy(89, 14);
	cout << ".'  `  `.";
	gotoxy(87, 15);
	cout << ".'_.-...-._`.";
	gotoxy(88, 16);
	cout << "`.       .'";
	gotoxy(90, 17);
	cout << "`-...-'";

	gotoxy(101, 22);
	cout << "***     ***";
	gotoxy(99, 23);
	cout << "**   ** **   **";
	gotoxy(98, 24);
	cout << "*       *       *";
	gotoxy(98, 25);
	cout << "*               *";
	gotoxy(99, 26);
	cout << "*             *";
	gotoxy(99, 27);
	cout << " **         **";
	gotoxy(102, 28);
	cout << "**     **";
	gotoxy(103, 29);
	cout << " ** **";
	gotoxy(106, 30);
	cout << "*";

	gotoxy(102, 8);
	cout << " |";
	gotoxy(102, 9);
	cout << "-o-";
	gotoxy(102, 10);
	cout << " |";

	gotoxy(80, 15);
	cout << " |";
	gotoxy(80, 16);
	cout << "-o-";
	gotoxy(80, 17);
	cout << " |";

	gotoxy(87, 25);
	cout << " |";
	gotoxy(87, 26);
	cout << "-o-";
	gotoxy(87, 27);
	cout << " |";

	gotoxy(102, 8);
	cout << " |";
	gotoxy(102, 9);
	cout << "-o-";
	gotoxy(102, 10);
	cout << " |";

	gotoxy(33, 12);
	cout << " |";
	gotoxy(33, 13);
	cout << "-o-";
	gotoxy(33, 14);
	cout << " |";

	gotoxy(5, 22);
	cout << " |";
	gotoxy(5, 23);
	cout << "-o-";
	gotoxy(5, 24);
	cout << " |";

	wait(1);
	clrscr();
	setTextColor(2);
	cout << "			    __    __   _____   __      _____   _____   __  __   _____  \n";
	cout << "			   |  |/\\|  | |  ___| |  |    /     \\ /     \\\ |  \\/  | |  ___| \n";
	cout << "			   |        | |  ___| |  |__  | <---< |  |  | |      | |  ___| \n";
	cout << "			    \\__/\\__/  |_____| |_____| \\_____/ \\_____/ |_|\\/|_| |_____| \n";
	cout << "                             |######################66%        |";
	cout << endl;
	setTextColor(0);
	cout << "  	                            &&&&&&&&7                       $&&&&&$\n";
	cout << "                                    &&&&&&&&&c                   &&&&&&&$\n";
	cout << "                                     @&&&&&$&&&&                �&&&&&&&$\n";
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

	gotoxy(13, 7);
	cout << ",-._.-. ";
	gotoxy(12, 8);
	cout << "/_,._,._\\ ";
	gotoxy(12, 9);
	cout << "\\`-._.' / ";
	gotoxy(13, 10);
	cout << "\\_____/ ";

	gotoxy(25, 19);
	cout << "'.----'`v'`----.'";
	gotoxy(26, 20);
	cout << "\\`----._.----'/";
	gotoxy(27, 21);
	cout << "`.--.___.--.'";
	gotoxy(28, 22);
	cout << " `-.___.-'";

	gotoxy(91, 13);
	cout << ".. ..";
	gotoxy(89, 14);
	cout << ".'  `  `.";
	gotoxy(87, 15);
	cout << ".'_.-...-._`.";
	gotoxy(88, 16);
	cout << "`.       .'";
	gotoxy(90, 17);
	cout << "`-...-'";

	gotoxy(101, 22);
	cout << "***     ***";
	gotoxy(99, 23);
	cout << "**   ** **   **";
	gotoxy(98, 24);
	cout << "*       *       *";
	gotoxy(98, 25);
	cout << "*               *";
	gotoxy(99, 26);
	cout << "*             *";
	gotoxy(99, 27);
	cout << " **         **";
	gotoxy(102, 28);
	cout << "**     **";
	gotoxy(103, 29);
	cout << " ** **";
	gotoxy(106, 30);
	cout << "*";

	gotoxy(10, 24);
	cout << " |";
	gotoxy(10, 25);
	cout << "-o-";
	gotoxy(10, 26);
	cout << " |";

	gotoxy(56, 7);
	cout << " |";
	gotoxy(56, 8);
	cout << "-o-";
	gotoxy(56, 9);
	cout << " |";

	gotoxy(23, 12);
	cout << " |";
	gotoxy(23, 13);
	cout << "-o-";
	gotoxy(23, 14);
	cout << " |";

	gotoxy(77, 22);
	cout << " |";
	gotoxy(77, 23);
	cout << "-o-";
	gotoxy(77, 24);
	cout << " |";

	gotoxy(107, 14);
	cout << " |";
	gotoxy(107, 15);
	cout << "-o-";
	gotoxy(107, 16);
	cout << " |";

	wait(1);
	clrscr();
	setTextColor(2);
	cout << "			    __    __   _____   __      _____   _____   __  __   _____  \n";
	cout << "			   |  |/\\|  | |  ___| |  |    /     \\ /     \\\ |  \\/  | |  ___| \n";
	cout << "			   |        | |  ___| |  |__  | <---< |  |  | |      | |  ___| \n";
	cout << "			    \\__/\\__/  |_____| |_____| \\_____/ \\_____/ |_|\\/|_| |_____| \n";
	cout << "                             |###############99,99%############|";
	cout << endl;
	setTextColor(0);
	cout << "  	                            &&&&&&&&7                       $&&&&&$\n";
	cout << "                                    &&&&&&&&&c                   &&&&&&&$\n";
	cout << "                                     @&&&&&$&&&&                �&&&&&&&$\n";
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

	gotoxy(82, 8);
	cout << "    ,(())),";
	gotoxy(82, 9);
	cout << "   '(('''))'";
	gotoxy(82, 10);
	cout << "   '(|o_o|)'";
	gotoxy(82, 11);
	cout << "     : = :";
	gotoxy(82, 12);
	cout << "     _) (_";
	gotoxy(82, 13);
	cout << "   /`_ V _`\\ ";
	gotoxy(82, 14);
	cout << "  / (_   _) \\ ";
	gotoxy(82, 15);
	cout << " / / )   ( \\ \\ ";
	gotoxy(82, 16);
	cout << " \\ \\/_____\\/ /";
	gotoxy(82, 17);
	cout << "  \\_)__.__(_/";
	gotoxy(82, 18);
	cout << "   |  \\_/  )";
	gotoxy(82, 19);
	cout << "    \\ _/__/";
	gotoxy(82, 20);
	cout << "     \/   /";
	gotoxy(82, 21);
	cout << "     (  ;";
	gotoxy(82, 22);
	cout << "      \\  \\ ";
	gotoxy(82, 23);
	cout << "       \\  \\";
	gotoxy(82, 24);
	cout << "        ))"")-)";
	gotoxy(82, 25);
	cout << "        ((__/| * ";

	gotoxy(27, 8);
	cout << "\\|";

	gotoxy(17, 8);
	cout << "   .&&&&&& / )";
	gotoxy(17, 9);
	cout << "   .&&&/ \\ |/";
	gotoxy(17, 10);
	cout << "   .&& <,( |\\";
	gotoxy(17, 11);
	cout << "    &&  _/ | )";
	gotoxy(17, 12);
	cout << "   _ ) &._/ /";
	gotoxy(17, 13);
	cout << "  /  )__| .'";
	gotoxy(17, 14);
	cout << " /./| _)_)";
	gotoxy(17, 15);
	cout << "( | \\.--|";
	gotoxy(17, 16);
	cout << " \\|  ) !|";
	gotoxy(17, 17);
	cout << " /| /.__|";
	gotoxy(17, 18);
	cout << "(_// _\\_/______";
	gotoxy(17, 19);
	cout << "  (            )";
	gotoxy(17, 20);
	cout << "   '..____.-'/ |";
	gotoxy(17, 21);
	cout << "    \\  |    (  |";
	gotoxy(17, 22);
	cout << "     \\ /     \\ |";
	gotoxy(17, 23);
	cout << "     / |      )|";
	gotoxy(17, 24);
	cout << "    (  |     / |";
	gotoxy(17, 25);
	cout << "     \\ |      \\|";
	gotoxy(17, 26);
	cout << "      )|";
	gotoxy(17, 27);
	cout << "     / |";
	gotoxy(17, 28);
	cout << "     \\ |";
	wait(1);
}

void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

void setScreenSize(SHORT x, SHORT y, SHORT width, SHORT height)
{
	HWND consoleWindow = GetConsoleWindow();
	MoveWindow(GetConsoleWindow(), x, y, width, height, TRUE);
}

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int inputKey()
{

	int key = _getch();

	if (key == 224)
	{
		key = _getch();
		return key;
	}

	return key;

}