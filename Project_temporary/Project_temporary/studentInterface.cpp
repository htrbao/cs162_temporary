#include "studentInterface.h"

void initialStudentBackground(studentNode* pItem)
{
	avatar(1, 1, 2, 1);
	gotoxy(8, 2); cout << pItem->name;

	gotoxy(0, 4);
	for (long i = 0; i <= 118; i++)
	{
		cout << char(254);
	}
	for (long i = 0; i <= 25; i++)
	{
		gotoxy(27, i);
		cout << char(219);
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
