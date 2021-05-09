#include "staffInterface.h"

void clearStaffScreen()
{
	for (long i = 0; i <= 159; i++)
	{
		for (long j = 7; j <= 40; j++)
		{
			gotoxy(i, j);
			cout << ' ';
		}
	}
}

void clearSettingScreen()
{
	for (long i = 161; i <= 199; i++)
	{
		for (long j = 6; j <= 40; j++)
		{
			gotoxy(i, j);
			cout << ' ';
		}
	}
}


void initialStaffBackground(staffNode* pItem)
{
	ShowCur(0);
	setScreenSize(0, 0, 1471, 690);
	avatar(0, 1, 162, 1);
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

void viewProfile(staffNode* pItem)
{
	avatar(0, 5, 2, 7);
	setTextColor(11);
	gotoxy(30, 7); cout << "Full name: " << pItem->name;
	gotoxy(30, 9); cout << "User name: " << pItem->username;
	gotoxy(30, 11); cout << "ID: " << pItem->id;
	gotoxy(30, 13); cout << "Role: " << "Staff";
	gotoxy(30, 15); cout << "Birthday: "; printBirthday(pItem->birthday);

	setTextColor(7);
	if(_getch())clearStaffScreen();
}

void changePassword(staffNode*& pItem)
{

}

void creatNewClass()
{
	setTextColor(7);

	gotoxy(2, 7); setTextColor(15); cout << "Write the new school year: ";
	ShowCur(1);
	long inp, length = 0;
	string scYear;
	while (!((inp = inputKey()) == 13 && length == 4) || (inp == 9 && length == 4))
	{
		if ('0' <= inp && inp <= '9'  && length < 4)
		{
			length++;
			scYear.push_back(inp);
			gotoxy(28 + length, 7);
			cout << char(inp);
		}
		else
			if (inp == 8 && length > 0)
			{

				scYear.pop_back(); 
				gotoxy(28 + length, 7);
				cout << " "; 
				gotoxy(28 + length, 7);
				length--;
			}
	}

	ShowCur(0);

	int* sizeClass = new int[5];

	roll* selection = new roll[5];

	drawRec(1, 1, 40, 13); gotoxy(45, 14); setTextColor(7); cout << "CLC Class";
	drawRec(1, 1, 40, 16); gotoxy(45, 17); setTextColor(7); cout << "CTT Class";
	drawRec(1, 1, 40, 19); gotoxy(45, 20); setTextColor(7); cout << "VP  Class";
	drawRec2(1, 3, 79, 22);
	drawRec(1, 3, 78, 21);

	for (long i = 0; i < 3; i++)
	{
		sizeClass[i] = 0;
		selection[i].message = char(16);
		selection[i].color = 0;
		selection[i].x = 39;
		selection[i].y = 14 + i * 3;
	}

	selection[3].message = "Ok.";
	selection[3].color = 15;
	selection[3].x = 83;
	selection[3].y = 22;

	selection[0].color = 12;

	printSettingBox(selection, 4);

	long cnt = 0;

	while (1)
	{
		char c = _getch();

		if (c == char(72) || c == 'w' || c == 'W') cnt--;
		else if (c == char(80) || c == 's' || c == 'S') cnt++;

		if (cnt < 0) cnt = 3;
		if (cnt == 4) cnt = 0;

		if (c == char(13))
		{
			ShowCur(1);
			if (cnt < 3) {
				gotoxy(56, 14 + cnt * 3);
				cin >> sizeClass[cnt];
			}
			ShowCur(0);
			if (cnt == 3)
			{
				if (isOK())
				{
					setTextColor(10);
					drawRec3(7, 25, 50, 18);
					gotoxy(52, 19); setTextColor(7); cout << "Creat New Class...";
					if (sizeClass[0])
					{
						gotoxy(52, 20); cout << "Creat " << sizeClass[0] <<" CLC class"; ellipses(69, 20);
						for (long i = 1; i <= sizeClass[0]; i++)
						{
							string s;
							s.push_back(scYear[scYear.size() - 2]);
							s.push_back(scYear[scYear.size() - 1]);
							s = s + "CLC";
							s = s + to_string(i);
							findClass(s, 1);
						}
					}
					if (sizeClass[1])
					{
						gotoxy(52, 21); cout << "Creat " << sizeClass[1] << " CTT class"; ellipses(69 , 21);
						for (long i = 1; i <= sizeClass[1]; i++)
						{
							string s;
							s.push_back(scYear[scYear.size() - 2]);
							s.push_back(scYear[scYear.size() - 1]);
							s = s + "CTT";
							s = s + to_string(i);
							findClass(s, 1);
						}
					}
					if (sizeClass[2])
					{
						gotoxy(52, 22); cout << "Creat " << sizeClass[2] << " VP class"; ellipses(69, 22);
						for (long i = 1; i <= sizeClass[2]; i++)
						{
							string s;
							s.push_back(scYear[scYear.size() - 2]);
							s.push_back(scYear[scYear.size() - 1]);
							s = s + "VP";
							s = s + to_string(i);
							findClass(s, 1);
						}
					}
					break;
				}
				else
				{
					clearStaffScreen();
					delete[] sizeClass;
					delete[] selection;
					creatNewClass();
				}
			}
		}

		for (long i = 0; i < 4; i++)
		{
			selection[i].color = 0;
			if (i < 3 && sizeClass[i] > 0)
			{
				gotoxy(selection[i].x + 3, selection[i].y);
				setTextColor(11 * 16);
				cout << " ";
				setTextColor(7);
			}
		}
		selection[3].color = 7;
		selection[cnt].color = (cnt == 3 ? 15 * 16 : 12);
		printSettingBox(selection, 4);
	}

	setTextColor(7);
	clearStaffScreen();
	delete[] sizeClass;
	delete[] selection;
}

void viewStudent(Class* pClass)
{

}

void viewClass()
{

	clearStaffScreen();
}

void aboutProfile(staffNode*& pItem, bool& isLogOut)
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

	while(1)
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
				viewProfile(pItem);
			}
			if (cnt == 1) {
				changePassword(pItem);
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



void staffMenu(staffNode*& pItem)
{

	//setScreenSize(30, 30, 1100, 1011);

	long numberSetting = 4;
	bool isLogOut = false;

	roll* setting;
	setting = new roll[10];

	setting[0].message = "CREAT NEW CLASS";
	setting[1].message = "ADD NEW STUDENT";
	setting[2].message = "VIEW STUDENT";
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

	ShowCur(0);
	while (1) {
		char c = _getch();

		if (c == char(75) || c == 'a' || c == 'A') cnt--;
		else if (c == char(77) || c == 'd' || c == 'D') cnt++;
		
		if (c == char(13) || c == char(80)) {
			if (cnt == 0) {
				creatNewClass();
			}
			if (cnt == 2) {
				viewClass();
			}
			if (cnt == 3) {
				aboutProfile(pItem, isLogOut);
				if(isLogOut) break;
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
	system("cls");
	delete[] setting;
}