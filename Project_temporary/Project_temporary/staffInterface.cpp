#include "staffInterface.h"

void clearStaffScreen()
{
	for (long i = 0; i <= 159; i++)
	{
		for (long j = 6; j <= 40; j++)
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
	setScreenSize(0, 0, 1471, 690);
	avatar(0, 1, 162, 1);
	setTextColor(15);
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

void aboutProfile(staffNode*& pItem, bool& isLogOut)
{
	ShowCur(0);
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

void creatNewClass()
{
	long* sizeClass = new long[3];
	for (int i = 0; i < 3; i++)
		sizeClass[i] = 0;
	gotoxy(2, 6); setTextColor(15); cout << "Write School Year: ";
	long inp = -1, length = 0;
	string schoolY;
	while (!(((inp = inputKey()) == 13 && length == 4 ) || (inp == 9 && length == 4)))
	{
		if (char('0') <= inp && inp <= char('9') && length < 4)
		{
			length++;
			schoolY.push_back(inp);
			cout << char(inp);
		}
		else
			if (inp == 8 && length > 0)
			{

				schoolY.pop_back();
				gotoxy(19 + length + 1, 6);
				cout << " ";
				gotoxy(19 + length + 1, 6);
				length--;
			}
	}

	roll* selection = new roll[4];

	for (long i = 0; i < 4; i++)
	{
		selection[i].message = char(248);
		selection[i].color = 0;
		selection[i].x = 29;
		selection[i].y = 12 + i * 3;
	}

	selection[3].message = "Ok.";
	selection[3].color = 15;
	selection[3].x = 63;
	selection[3].y = 21;

	drawRec(1, 1, 30, 11); gotoxy(36, 12); setTextColor(7); cout << "CLC Class";
	drawRec(1, 1, 30, 14); gotoxy(36, 15); setTextColor(7); cout << "CTT Class";
	drawRec(1, 1, 30, 17); gotoxy(36, 18); setTextColor(7); cout << "VP  Class";
	drawRec2(1, 2, 61, 21); drawRec(1, 2, 60, 20);

	selection[0].color = 15;

	printSettingBox(selection, 4);
	
	long cnt = 0;


	while (1)
	{
		char c = _getch();
		if (c == char(72) || c == 'w' || c == 'W') cnt--;
		else if (c == char(80) || c == 's' || c == 'S') cnt++;

		if (cnt < 0) cnt = 4 - 1;
		if (cnt == 4) cnt = 0;

		if (c == char(13))
		{
			if (cnt < 3) {
				if (sizeClass[cnt] == 0) {
					setTextColor(15);
					gotoxy(selection[cnt].x + 20, selection[cnt].y); ShowCur(1);  cin >> sizeClass[cnt];
					ShowCur(0);
				}
				else {
					gotoxy(selection[cnt].x + 20, selection[cnt].y); cout << "     ";
					sizeClass[cnt] = 0;
				}
			}

			if (cnt == 3) {
				if (isOK(10, 36, 45, 17))
				{
					if (sizeClass[0]) {
						gotoxy(47, 19);  cout << "Creat " << sizeClass[0] << " CLC Class" << endl;
						for (int i = 1; i <= sizeClass[0]; i++)
						{
							string s;
							s.push_back(schoolY[schoolY.size() - 2]);
							s.push_back(schoolY[schoolY.size() - 1]);
							s = s + "CLC";
							s = s + to_string(i);
							findClass(s, 1);
						}
					}

					if (sizeClass[1]) {
						gotoxy(47, 21); cout << "Creat " << sizeClass[1] << " CTT Class" << endl;
						for (int i = 1; i <= sizeClass[1]; i++)
						{
							string s;
							s.push_back(schoolY[schoolY.size() - 2]);
							s.push_back(schoolY[schoolY.size() - 1]);
							s = s + "CTT";
							s = s + to_string(i);
							findClass(s, 1);
						}
					}

					if (sizeClass[2]) {
						gotoxy(47, 23); cout << "Creat " << sizeClass[2] << " VP Class";
						for (int i = 1; i <= sizeClass[2]; i++)
						{
							string s;
							s.push_back(schoolY[schoolY.size() - 2]);
							s.push_back(schoolY[schoolY.size() - 1]);
							s = s + "VP";
							s = s + to_string(i);
							findClass(s, 1);
						}
					}
				}
				else
				{
					clearStaffScreen();
					creatNewClass();
				}
				//system("pause");
				break;
			}
		}

		for (long i = 0; i < 4; i++)
		{
			if (i < 3 && sizeClass[i] != 0) {
				setTextColor(7 * 16); gotoxy(32, selection[i].y); cout << ' ';
				setTextColor(7);
			}
			else if ((i < 3 && sizeClass[i] == 0))
			{
				setTextColor(7); gotoxy(32, selection[i].y); cout << ' ';
			}
			selection[i].color = 0;
		}
		selection[3].color = 15;
		selection[cnt].color = (cnt == 3 ? 15 * 16 : 15);

		printSettingBox(selection, 4);
	}
	delete[] sizeClass;
	delete[] selection;
	setTextColor(7);
	clearStaffScreen();
}

void viewStudent()
{
	displayClassList();
	system("pause");
	clearStaffScreen();

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
	ShowCur(0);
	printSettingBox(setting, numberSetting);
	while (1) {
		char c = _getch();
		if (c == char(75) || c == 'a' || c == 'A') cnt--;
		else if (c == char(77) || c == 'd' || c == 'D') cnt++;

		if (cnt < 0) cnt = numberSetting - 1;
		if (cnt == numberSetting) cnt = 0;

		if (c == char(13) || c == char(80) || c == 's' || c == 'S') {

			//gotoxy(10, 10); setTextColor(15); cout << long(c) << ' ' << cnt;
			if (cnt == 0) {
				creatNewClass();
			}
			if (cnt == 2) {
				setTextColor(7);
				viewStudent();
			}
			if (cnt == 3) {
				aboutProfile(pItem, isLogOut);
				if(isLogOut) break;
			}
		}


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