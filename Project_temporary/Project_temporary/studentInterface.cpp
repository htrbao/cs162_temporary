#include "studentInterface.h"
#include"staffInterface.h"

void initialStudentBackground(studentNode* pItem)
{
	avatar(0, 1, 162, 1);
	setTextColor(7);
	gotoxy(167, 2); cout << pItem->name;
	setScreenSize(0, 0, 1471, 690);
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

void clearStudentScreen()
{
	for (long i = 0; i <= 159; i++)
	{
		for (long j = 9; j <= 40; j++)
		{
			gotoxy(i, j);
			cout << ' ';
		}
	}
}


void viewStudentProfile(studentNode* pItem)
{

}

void changeStudentPassword(studentNode*& pItem)
{

}

void aboutStudentProfile(studentNode*& pItem, bool& isLogOut)
{
	long numberSetting = 3, cnt = 0;
	roll* set = new roll[10];
	set[0].message = pItem->name + " 's profile";
	set[1].message = "Setting & Privacy";
	set[2].message = "Log out";

	for (long i = 0; i < numberSetting; i++)
	{
		set[i].x = 167;
		set[i].color = 8;
	}

	set[0].y = 9;
	set[1].y = 13;
	set[2].y = 15;

	set[0].color = 15;

	printSettingBox(set, numberSetting);

	while (1)
	{
		char c = _getch();

		if (c == char(72) || c == 'w' || c == 'W') cnt--;
		else if (c == char(80) || c == 's' || c == 'S') cnt++;

		if (cnt < 0) {
			break;
		}

		if (c == char(13))
		{
			if (cnt == 0) {
				viewStudentProfile(pItem);
			}
			if (cnt == 1) {
				changeStudentPassword(pItem);
			}
			if (cnt == 2) {
				isLogOut = true;
				break;
			}
		}

		if (cnt < 0) cnt = numberSetting - 1;
		if (cnt == numberSetting) cnt = 0;

		for (long i = 0; i < numberSetting; i++)
		{
			set[i].color = 8;
		}
		set[cnt].color = 15;

		if (cnt == numberSetting - 1) set[cnt].color = 9 * 16 + 15;
		printSettingBox(set, numberSetting);
	}

	clearSettingScreen();

	delete[] set;
}

void studentMenu(studentNode*& pItem)
{
	ShowCur(0);
	long numberSetting = 4;
	bool isLogOut = false;

	roll* setting;
	setting = new roll[10];

	setting[0].message = "VIEW COURSES";
	setting[1].message = "ENROLL COURSES";
	setting[2].message = "VIEW NOTE";
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
	initialStudentBackground(pItem);
	printSettingBox(setting, numberSetting);
	while (1) {
		char c = _getch();

		if (c == char(75) || c == 'a' || c == 'A') cnt--;
		else if (c == char(77) || c == 'd' || c == 'D') cnt++;

		if (c == char(13) || c == char(80)) {
			if (cnt == 3) {
				aboutStudentProfile(pItem, isLogOut);
				if (isLogOut) break;
			}
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
	delete[] setting;
}