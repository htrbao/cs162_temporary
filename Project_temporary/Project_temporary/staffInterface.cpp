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

		if (c == char(8)) break;

		if (c == char(13))
		{
			if (cnt < 3 && sizeClass[cnt] != 0) {
				gotoxy(56, 14 + cnt * 3);
				cout << " ";
				sizeClass[cnt] = 0;
			}
			else if (cnt < 3 && sizeClass[cnt] == 0) {
				ShowCur(1);
				gotoxy(56, 14 + cnt * 3);
				cin >> sizeClass[cnt];
			}
			ShowCur(0);
			if (cnt == 3)
			{
				if (isOK(""))
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
			if (i < 3 && sizeClass[i] == 0)
			{
				gotoxy(selection[i].x + 3, selection[i].y);
				setTextColor(7);
				cout << " ";
				
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

void DrawAddNewCourse()
{
	gotoxy(2, 9);  cout << "	.-----.-----.--.--.--.   .----.-----.--.--.----.-----.-----.";
	gotoxy(2, 10); cout << "	|     |  -__|  |  |  |   |  __|  _  |  |  |   _|__-- |  -__I";
	gotoxy(2, 11); cout << "	|__|__|_____|________|   |____|_____|_____|__| |_____|_____|";
}

void addNewCourse()
{
	setTextColor(15);
	DrawAddNewCourse();
	setTextColor(7);
	course* pItem = new course;

	roll* selection = new roll[4];

	gotoxy(41, 14); setTextColor(7); cout << "Write course name";
	gotoxy(41, 17); setTextColor(7); cout << "Write course ID";
	gotoxy(41, 20); setTextColor(7); cout << "Write name of teacher";
	drawRec2(1, 3, 79, 22);
	drawRec(1, 3, 78, 21);


	for (long i = 0; i < 3; i++)
	{
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

		if (c == char(8)) break;

		if (c == char(13))
		{
			if (cnt < 3) {
				gotoxy(62, 14 + cnt * 3);
				cout << "                                       ";
				ShowCur(1);
				
				gotoxy(62, 14 + cnt * 3);
				if (cnt == 0) getline(cin, pItem->subName, '\n');
				if (cnt == 1) getline(cin, pItem->subID, '\n');
				if (cnt == 2) getline(cin, pItem->teacher, '\n');
			}
			ShowCur(0);
			if (cnt == 3)
			{
				if (pItem->subName == "" || pItem->subID == "" || pItem->teacher == "") 
				{
					gotoxy(71, 24); setTextColor(12); cout << "Please fill all the blank";
				}
				else
				{
					if (isOK(""))
					{
						addCourseNode(pItem);
						break;
					}
					else
					{
						clearStaffScreen();
						delete pItem;
						delete[] selection;
						addNewCourse();
					}
				}
			}
		}

		for (long i = 0; i < 4; i++)
		{
			selection[i].color = 0;
		}
		selection[3].color = 7;
		selection[cnt].color = (cnt == 3 ? 15 * 16 : 12);
		printSettingBox(selection, 4);
	}

	setTextColor(7);
	clearStaffScreen(); 
	delete[] selection;
}

void viewAllCourse()
{
	if (!headCourse) {
		gotoxy(45, 12); setTextColor(12); cout << "No course are created";
		setTextColor(7);
	}
	course* pCourse = headCourse;

	setTextColor(7);

	long i = 0;
	while (pCourse)
	{
		gotoxy(3, 9 + 2 * i);
		cout << pCourse->subName << (pCourse->subName.size() < 13 ? "\t\t" : "\t") << pCourse->subID << "\t\t" << pCourse->teacher;
		i++;
		pCourse = pCourse->pNext;
	}
	setTextColor(15 * 16);
	pCourse = headCourse;

	gotoxy(3, 10); setTextColor(15); for (long j = 1; j <= pCourse->subName.size(); j++) cout << char(22);
	
	long cnt = 0;

	while (1)
	{
		char c = _getch();
		
		if (c == char(72) || c == 'w' || c == 'W')
		{
			cnt--;
			if (pCourse != headCourse) pCourse = pCourse->pPrev;
			else
			{
				pCourse = endCourse;
				cnt = i - 1;
			}
		}
		else if (c == char(80) || c == 's' || c == 'S')
		{
			cnt++;
			if (pCourse != endCourse)
			{
				pCourse = pCourse->pNext;
			}
			else
			{
				cnt = 0;
				pCourse = headCourse;
			}
		}

		if (c == char(83) || c == char(13))
		{
			for (long k = 0; k <= 80; k++)
			{
				for (long j = 9; j <= 9 + i * 2; j++)
				{
					gotoxy(k, j);
					cout << ' ';
				}
			}
			course* pTmp = headCourse;

			if (headCourse == endCourse)
			{ 
				delete headCourse;
				headCourse = endCourse = nullptr;
				return;
			}
			else if (cnt == i - 1)
			{
				cnt = i - 2;
				pTmp = endCourse;
				endCourse = endCourse->pPrev;
				delete pTmp;
				endCourse->pNext = nullptr;
				pCourse = endCourse;
			}
			else if (cnt == 0)
			{
				pTmp = headCourse->pNext;
				pTmp->pPrev = headCourse->pPrev;
				delete headCourse;
				headCourse = pTmp;
				pCourse = headCourse;
			}
			else
			{
				pTmp = pCourse->pNext;
				pCourse->pNext->pPrev = pCourse->pPrev;
				pCourse->pPrev->pNext = pCourse->pNext;
				delete pCourse;
				pCourse = pTmp;
			}

			if (!headCourse) return;

			pTmp = headCourse;

			i = 0;
			while (pTmp)
			{
				gotoxy(3, 9 + 2 * i);
				cout << pTmp->subName << (pTmp->subName.size() < 13 ? "\t\t" : "\t") << pTmp->subID << "\t\t" << pTmp->teacher;
				i++;
				pTmp = pTmp->pNext;
			}
		}

		if (c == char(8)) break;

		
		if (cnt != i - 1) {
			gotoxy(3, 9 + (cnt + 1) * 2 + 1); setTextColor(15); for (long j = 1; j <= pCourse->pNext->subName.size(); j++) cout << " ";
		}
		else
		{
			gotoxy(3, 9 + (0) * 2 + 1); setTextColor(15); for (long j = 1; j <= headCourse->subName.size(); j++) cout << " ";
		}
		if (cnt != 0) {
			gotoxy(3, 9 + (cnt - 1) * 2 + 1); setTextColor(15); for (long j = 1; j <= pCourse->pPrev->subName.size(); j++) cout << " ";
		} 
		else
		{
			gotoxy(3, 9 + (i - 1) * 2 + 1); setTextColor(15); for (long j = 1; j <= endCourse->subName.size(); j++) cout << " ";
		}
		gotoxy(3, 9 + cnt * 2 + 1); setTextColor(15); for (long j = 1; j <= pCourse->subName.size(); j++) cout << char(22);
	}

}

void aboutCourse()
{
	gotoxy(1, 7); setTextColor(11); cout << "ADD NEW COURSE";
	

	gotoxy(81, 7); setTextColor(7); cout << "VIEW AVAILABLE COURSE";
	

	long cnt = 1;
	while (1)
	{
		char c = _getch();

		if (c == char(75) || c == 'a' || c == 'A' || c == char(77) || c == 'd' || c == 'D') cnt = !cnt;

		if (c == 'N' || c == 'n')
		{
			gotoxy(1, 7); setTextColor(7); cout << "ADD NEW COURSE";

			gotoxy(81, 7); setTextColor(11); cout << "VIEW AVAILABLE COURSE";
		}
		else if (c == 'Y' || c == 'y')
		{
			gotoxy(1, 7); setTextColor(11); cout << "ADD NEW COURSE";
			gotoxy(81, 7); cout << char(22);

			gotoxy(1, 7); setTextColor(7); cout << "VIEW AVAILABLE COURSE";
			gotoxy(81, 7); cout << char(22);
		}

		if (c == char(8)) break;

		if (c == char(13))
		{
			if (cnt == 1) addNewCourse();
			else
			{
				viewAllCourse();
			}

		}

		if (cnt == 1)
		{
			gotoxy(1, 7); setTextColor(11); cout << "ADD NEW COURSE";

			gotoxy(81, 7); setTextColor(7); cout << "VIEW AVAILABLE COURSE";
		}
		if (cnt == 0)
		{
			gotoxy(1, 7); setTextColor(7); cout << "ADD NEW COURSE";

			gotoxy(81, 7); setTextColor(11); cout << "VIEW AVAILABLE COURSE";
		}
	}
	clearStaffScreen();
}

void viewStudent(Class* pClass)
{
	setTextColor(7);
	gotoxy(2, 7); cout << "Class " << pClass->name;
	studentNode* pCurClass = pClass->headStudent;
	long i = 1;
	while (pCurClass)
	{
		gotoxy(2, 7 + i * 2); cout << pCurClass->name << (pCurClass->name.size() < 14 ? "\t\t\t" : "\t\t") << pCurClass->id <<"\t\t" << pCurClass->classname;
		pCurClass = pCurClass->pNext;
		i++;
	}
	pCurClass = pClass->headStudent;

	if (!pCurClass)
	{
		warning("No student here", 9, 20, 59, 19);
		system("pause");
		return;
	}

	gotoxy(2, 10); setTextColor(15); for (long j = 1; j <= pCurClass->name.size(); j++) cout << char(22);

	long cnt = 1;

	while (1)
	{
		char c = _getch();

		if (c == char(72) || c == 'w' || c == 'W')
		{
			cnt--;
			if (pCurClass != pClass->headStudent) pCurClass = pCurClass->pPrev;
			else
			{
				pCurClass = pClass->endStudent;
				cnt = i - 1;
			}
		}
		else if (c == char(80) || c == 's' || c == 'S')
		{
			cnt++;
			if (pCurClass != pClass->endStudent)
			{
				pCurClass = pCurClass->pNext;
			}
			else
			{
				cnt = 1;
				pCurClass = pClass->headStudent;
			}
		}

		if (c == char(13))
		{
			clearStaffScreen();
			break;
		}

		if (c == char(8)) break;

		gotoxy(2, 7 + cnt * 2 + 1); setTextColor(15); for (long j = 1; j <= pCurClass->name.size(); j++) cout << char(22);
		if (cnt != i - 1) {
			gotoxy(2, 7 + (cnt + 1) * 2 + 1); setTextColor(15); for (long j = 1; j <= pCurClass->pNext->name.size(); j++) cout << " ";
		}
		else
		{
			gotoxy(2, 7 + (1) * 2 + 1); setTextColor(15); for (long j = 1; j <= pClass->headStudent->name.size(); j++) cout << " ";
		}
		if (cnt != 1) {
			gotoxy(2, 7 + (cnt - 1) * 2 + 1); setTextColor(15); for (long j = 1; j <= pCurClass->pPrev->name.size(); j++) cout << " ";
		}
		else
		{
			gotoxy(2, 7 + (i - 1) * 2 + 1); setTextColor(15); for (long j = 1; j <= pClass->endStudent->name.size(); j++) cout << " ";
		}
	}

}

void viewClass()
{
	setTextColor(7);

	gotoxy(2, 7); setTextColor(15); cout << "Write the available school year (2 digit): ";
	ShowCur(1);
	long inp, length = 0;
	string scYear;
	while (!((inp = inputKey()) == 13 && length == 2) || (inp == 9 && length == 2))
	{
		if ('0' <= inp && inp <= '9' && length < 2)
		{
			length++;
			scYear.push_back(inp);
			gotoxy(44 + length, 7);
			cout << char(inp);
		}
		else
			if (inp == 8 && length > 0)
			{
				scYear.pop_back();
				gotoxy(44 + length, 7);
				cout << " ";
				gotoxy(44 + length, 7);
				length--;
			}
	}
	Class* pCur = headClass, *head = nullptr, *end = nullptr;
	while (pCur)
	{
		if (pCur->name[0] == scYear[0] && pCur->name[1] == scYear[1])
		{
			head = pCur;
			break;
		}
		pCur = pCur->pNext;
	}
	ShowCur(0);
	long i = 1;
	setTextColor(7);

	if (!head) {
		string str = "Do you want to creat this new school year?";
		if (isOK(str)) {
			clearStaffScreen();
			gotoxy(2, 6); setTextColor(8); cout << "<creat new class> page";
			creatNewClass();
		}
		gotoxy(2, 6); cout << "                          ";
		clearStaffScreen();
		return;
		
	}

	while (pCur)
	{
		gotoxy(2, 7 + i * 2); cout << pCur->name;
		if (pCur->name[0] == scYear[0] && pCur->name[1] == scYear[1] && pCur->pNext->name[0] != scYear[0] && pCur->pNext->name[1] != scYear[1])
		{
			gotoxy(2, 7 + i * 2); cout << pCur->name;
			end = pCur;
			break;
		}
		i++;
		pCur = pCur->pNext;
		if (pCur->name[0] == scYear[0] && pCur->name[1] == scYear[1] && pCur->pNext == nullptr)
		{
			gotoxy(2, 7 + i * 2); cout << pCur->name;
			end = pCur;
			break;
		}
	}

	pCur = head;
	setTextColor(7 * 16);
	gotoxy(2, 9); cout << pCur->name;
	setTextColor(7);
	long cnt = 1;

	while (1)
	{
		char c = _getch();

		if (c == char(72) || c == 'w' || c == 'W')
		{
			cnt--;
			if(pCur != head) pCur = pCur->pPrev;
			else
			{
				pCur = end;
				cnt = i;
			}
		}
		else if (c == char(80) || c == 's' || c == 'S')
		{
			cnt++;
			if (pCur != end)
			{
				pCur = pCur->pNext;
			}
			else
			{
				cnt = 1;
				pCur = head;
			}
		}

		if (c == char(13))
		{
			clearStaffScreen(); 
			viewStudent(pCur);
			break;
		}

		if (c == char(8)) break;

		gotoxy(2, 7 + cnt * 2); setTextColor(7 * 16); cout << pCur->name;
		if (pCur != end) {
			gotoxy(2, 7 + (cnt + 1) * 2); setTextColor(7); cout << pCur->pNext->name;
			gotoxy(2, 7 + (i) * 2); setTextColor(7); cout << end->name;
		}
		if (pCur != head) {
			gotoxy(2, 7 + (cnt - 1) * 2); setTextColor(7); cout << pCur->pPrev->name;
			gotoxy(2, 7 + (1) * 2); setTextColor(7); cout << head->name;
		}
	}

	ShowCur(0);
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

	long numberSetting = 5;
	bool isLogOut = false;

	roll* setting;
	setting = new roll[10];

	setting[0].message = "CREAT NEW CLASS";
	setting[1].message = "ADD NEW STUDENT";
	setting[2].message = "VIEW STUDENT";
	setting[3].message = "ABOUT COURSE";
	setting[4].message = "...";

	for (long i = 0; i < numberSetting; i++)
	{
		setting[i].x = i * 40;
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
			if (cnt == 1) {

			}
			if (cnt == 2) {
				viewClass();
			}
			if (cnt == 3) {
				aboutCourse();
			}
			if (cnt == 4) {
				aboutProfile(pItem, isLogOut);
			}
			if (isLogOut) break;
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