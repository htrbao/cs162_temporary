#include "handling.h"
#include "interface.h"
#include "staffInterface.h"
#include "studentInterface.h"
#include "login.h"

HANDLE wHnd;
HANDLE rHnd;

int main()
{
	//setting all

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, 200, 40 };
	COORD bufferSize = { 200, 9001 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	updateCourse("COURSE.csv");
	updateStudent("STUDENT.csv");
	updateStaff("STAFF.csv");
	
	//welcome();
	//cout << headClass->headStudent->pNext->headSubject->subName;
	//end

	while (1)
	{
		studentNode* pStudent = nullptr;
		staffNode* pStaff = nullptr;
		loginScreen(pStudent, pStaff);

		ShowCur(0);
		if (pStudent) {
			studentMenu(pStudent);
		}
		else if (headStaff) {
			staffMenu(headStaff);
		}
		long n;
		cin >> n;
		if (n == 0) break;
	}

	//staffMenu(headStaff);

	cleanUpClass();
	cleanUpStaff();
	cleanUpCourse();

	return 0;
}