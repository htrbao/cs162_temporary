#include "studentInterface.h"
#include"staffInterface.h"

void initialStudentBackground(studentNode* pItem)
{
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

	ShowCur(0);
}

void clearStudentScreen()
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


void viewStudentProfile(studentNode* pItem)
{
	avatar(0, 5, 2, 7);
	setTextColor(11);
	gotoxy(30, 7); cout << "Full name: " << pItem->name;
	gotoxy(30, 9); cout << "User name: " << pItem->username;
	gotoxy(30, 11); cout << "ID: " << pItem->id;
	gotoxy(30, 13); cout << "Role: " << "Student";
	gotoxy(30, 15); cout << "Birthday: "; printBirthday(pItem->birthday);
	gotoxy(30, 17); cout << "Class: " << pItem->classname;
	setTextColor(7);
	if (_getch())clearStaffScreen();
}

void changeStudentPassword(studentNode*& pItem)
{
	string password = "";
	setColor(7);
	gotoxy(32, 7); cout << "Enter your current password";
	int length = 0;
	char inp;
	gotoxy(32, 8);
	while ((inp = inputKey()) != 13)
	{
		if (inp != 8 && length < 20)
		{
			length++;
			password.push_back(inp);
			gotoxy(32 + length, 8);
			cout << "*";
		}
		else
			if (inp == 8 && length > 0)
			{

				password.pop_back();
				gotoxy(32 + length, 8);
				cout << " ";
				gotoxy(32 + length, 8);
				length--;
			}
	}
	if (pItem->password.compare(password)){
		gotoxy(32,9); cout << "Current password is incorrect";
		if (_getch())clearStaffScreen();
	}
	else
	{
		gotoxy(32, 9);
		length = 0;
		password = "";
		cout << "Enter your new  password";
		gotoxy(32, 10);
		while ((inp = inputKey()) != 13)
		{
			if (inp != 8 && length < 20)
			{
				length++;
				password.push_back(inp);
				gotoxy(32 + length, 10);
				cout << "*";
			}
			else
				if (inp == 8 && length > 0)
				{

					password.pop_back();
					gotoxy(32 + length, 10);
					cout << " ";
					gotoxy(32 + length, 10);
					length--;
				}
		}
		pItem->password = password;
		gotoxy(32, 11);
		cout << "Your password is updated " << endl;
		if (_getch())clearStaffScreen();
	}

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
	while (1) 
	{
		char c = _getch();

		if (c == char(75) || c == 'a' || c == 'A') cnt--;
		else if (c == char(77) || c == 'd' || c == 'D') cnt++;

		if (c == char(13) || c == char(80)) {
			if (cnt == 3) {
				aboutStudentProfile(pItem, isLogOut);
				if (isLogOut) break;
			}
			if (!cnt)
			{
				viewCourses(pItem);
			}
			if (cnt == 1)
			{
				enrollCourse(pItem);
			}
			if (pItem->headSubject)
			{ }

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
int courseEnrolled(studentNode* pItem)
{
	int count = 0;
	course* cur = pItem->headSubject;
	while (cur)
	{
		count++;
		cur = cur->pNext;
	}
	return count;
}
void printCourse()
{	
	setTextColor(7);
	int n;
	n = 6;
	gotoxy(30, n); cout << "Available courses";
	course* cur = headCourse;
	while (cur)
	{
		n += 2;
		gotoxy(30, n); cout << cur->subName << ", lecturer: " << cur->teacher;
		cur = cur->pNext;
	}
}
void enrollCourse(studentNode*& pItem)
{	
	
	
	int cnt = 1;
	course* cur = nullptr;
	printCourse();
	setTextColor(11);
	cur = headCourse;
	for (int i = 1; i < cnt; i++)
		cur = cur->pNext;
	gotoxy(30, 6 + 2 * cnt); cout << cur->subName << ", lecturer: " << cur->teacher;
		
	while (1)
	{
		char c = _getch();

		if (c == char(8)) break;

		if (c == char(72) || c == 'w' || c == 'W') cnt--;
		else if (c == char(80) || c == 's' || c == 'S') cnt++;
		if (cnt == 0) cnt = 1;
		//cout << cnt;
		if (cnt > numOfCourse()) cnt = numOfCourse();
		printCourse();
		setTextColor(11);
		cur = headCourse;
		for (int i = 1; i < cnt; i++)
			cur = cur->pNext;
		gotoxy(30, 6 + 2 * cnt); cout << cur->subName << ", lecturer: " << cur->teacher;
		if (c == char(13))// || c == char(80))
		{
			cur = headCourse;
			for (int i = 1; i < cnt; i++)
				cur = cur->pNext;
			bool check = true;
			if (courseEnrolled(pItem) == 5) check = false;
			course* cur2 = pItem->headSubject;
			while (cur2)
			{
				if (!cur2->subName.compare(cur->subName))
				{
					check = false;
					break;
				}
				cur2 = cur2->pNext;
			}
			if (pItem->headSubject)
			{

			}
			if (check)
			{
				cout << pItem->headSubject->subName;
				course* pNew = new course;
				pNew->subName = cur->subName;
				pNew->subID = cur->subID;
				pNew->teacher = cur->teacher;
				pNew->pNext = nullptr;
				addStudentCourse(pItem, pNew);
				/*updateStudent("STUDENT.csv");*/
				gotoxy(30, 18); cout << "You've enrolled for this course successfully";
				break;
			}
			else
			{
				gotoxy(30, 18); cout << "You can't enrol for this course";
				break;
			}
		}
	}
	if (_getch())clearStaffScreen();
	clearStaffScreen();
}

void viewCourses(studentNode* pItem)
{	
	
	setTextColor(11);
	int n = 7;
	gotoxy(30, n); cout << "You enrolled for " << courseEnrolled(pItem) << " courses(s)";
	if (!pItem->headSubject)
	{
		if (_getch())clearStaffScreen();
		return;
	}
	gotoxy(30, n + 2); cout <<  pItem->headSubject->subName;
	pItem->headSubject = pItem->headSubject->pNext;
	n += 2;
	while (pItem->headSubject != nullptr) {
		n += 2;
		gotoxy(30, n); cout << pItem->headSubject->subName;
		pItem->headSubject = pItem->headSubject->pNext;
	}

	setTextColor(7);
	if (_getch())clearStaffScreen();
}

void viewNote(studentNode* pItem){
	setTextColor(11);
	int n = 7;
	gotoxy(30, n); cout << "Courses";
	gotoxy(60, n); cout << "Midterm";
	gotoxy(90, n); cout << "Final";
	gotoxy(120, n); cout << "Lab";
	
	while (pItem->headSubject != nullptr) {
		n += 2;
		gotoxy(30, n); cout << pItem->headSubject->subName;
		gotoxy(60, n); cout << pItem->headSubject->midterm;
		gotoxy(90, n); cout << pItem->headSubject->final;
		gotoxy(120, n); cout << pItem->headSubject->lab;
		pItem->headSubject = pItem->headSubject->pNext;
	}

	setTextColor(7);
	if (_getch())clearStudentScreen();
}
