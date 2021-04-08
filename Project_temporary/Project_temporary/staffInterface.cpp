#include "staffInterface.h"

void initialStaffBackground(staffNode* pItem)
{
	avatar(1, 2, 1);
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