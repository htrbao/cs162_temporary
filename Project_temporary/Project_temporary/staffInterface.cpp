#include "staffInterface.h"

roll* setting;

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

void initialStaffBackground(staffNode* pItem)
{
	avatar(2, 162, 1);
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

void staffMenu(staffNode* pItem)
{
	ShowCur(0);
	long numberSetting = 4;
	setting = new roll[10];
	setting[0].message = "CREAT NEW CLASS";
	setting[1].message = "ADD NEW STUDENT";
	setting[2].message = "STUDENT";
	setting[3].message = "...";

	for (long i = 0; i < numberSetting; i++)
	{
		setting[i].x = i * 53;
		setting[i].y = 2;
		setting[i].color = 8;
	}

	setting[numberSetting - 1].x = 195;
	setting[numberSetting - 1].y = 2;

	setting[0].color = 15;
	int cnt = 0;
	system("cls");
	initialStaffBackground(pItem);
	printSettingBox(setting, numberSetting);
	while (1) {
		char c = _getch();
		if (c == char(75) || c == 'a' || c == 'A') cnt--;
		else if (c == char(77) || c == 'd' || c == 'D') cnt++;
		else if (c == char(13)) {
			delete[] setting;
			return;
		}
		if (cnt < 0) cnt = numberSetting - 1;
		if (cnt == numberSetting) cnt = 0;

		for (long i = 0; i < 5; i++)
		{
			setting[i].color = 8;
		}
		setting[cnt].color = 15;
		if (cnt == numberSetting - 1) setting[cnt].color = 100;
		printSettingBox(setting, numberSetting);
	}
}