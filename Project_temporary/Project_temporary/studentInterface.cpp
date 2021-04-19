#include "studentInterface.h"


void initialStudentBackground(studentNode* pItem)
{
	avatar(2, 162, 1);
	setTextColor(7);
	gotoxy(167, 2); cout << pItem->name;

	gotoxy(0, 5);
	for (long i = 0; i <= 199; i++)
	{
		cout << char(254);
	}
	for (long i = 0; i <= 40; i++)
	{
		gotoxy(160, i);
		cout << char(219);
	}
}


