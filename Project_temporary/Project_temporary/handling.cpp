	#include "handling.h"

course* headCourse, * endCourse;
Class* headClass,* endClass;
staffNode* headStaff,* endStaff;

void printBirthday(long b)
{
	cout << b / 1000000;
	cout << '/' << (b / 10000) % 100;
	cout << '/' << b % 10000;
}

long random(long n)
{
	srand(time(NULL));
	return rand() % n + 1;
}

Class* findClass(string classname, bool doAdd)
{
	Class* pClass = headClass;
	while (pClass)
	{
		if (pClass->name == classname) return pClass;
		pClass = pClass->pNext;
	}

	if (doAdd) {
		addClassNode(classname);
		return endClass;
	}
	else return nullptr;
}


void updateStudent(string filename)
{
	ifstream f;
	f.open(filename);
	string role;
	getline(f, role, '\n');
	while (!f.eof())
	{
		studentNode* pItem = new studentNode;
		//char c;
		string name, id, cl, username, password, birthday;
		int numofsub;
		
		getline(f, name, ',');
		//cout << name << endl;
		//cin >> c;
		getline(f, id, ',');
		char comma;
		
		getline(f, cl, ',');
		//cin >> c;
		getline(f, username, ',');
		//cin >> c;
		getline(f, password, ',');
		//cin >> c

		getline(f, birthday, ',');
		f >> numofsub;
		pItem->name = name;
		pItem->id = id;
		pItem->classname = cl;
		pItem->username = username;
		pItem->password = password;
		pItem->birthday = stoi(birthday);
		pItem->numOfSub = (numofsub);

		Class* pClass = findClass(cl, 1);
		if (!numofsub) {
			addStudentNode(pClass, pItem);
			f.ignore(); continue;
		}
		f >> comma;
		pItem->numOfSub = (numofsub);
		string courseID, courseName, Cteacher;
		for (int i = 0; i < (numofsub); i++)
		{
			getline(f, courseName, ',');
			getline(f, courseID, ',');
			if (i != (numofsub)-1)
			{
				getline(f, Cteacher, ',');
			}
			else getline(f, Cteacher, '\n');
			//cout << courseID;

			course* pNew = new course;
			pNew->subName = courseName;
			pNew->subID = courseID;
			pNew->teacher = Cteacher;
			addStudentCourse(pItem, pNew);
			//cout << cur->subName;
		}
		

		
		addStudentNode(pClass, pItem);

		//f.ignore();
	}
	f.close();
}

void updateStaff(string filename)
{
	ifstream f;
	f.open(filename);
	string role;
	getline(f, role, '\n');
	while (!f.eof())
	{
		staffNode* pItem = new staffNode;
		//char c;
		string name, id, username, password, birthday;
		getline(f, name, ',');
		//cin >> c;
		getline(f, id, ',');
		//cin >> c;
		getline(f, username, ',');
		//cin >> c;
		getline(f, password, ',');
		//cin >> c;
		getline(f, birthday, '\n');

		pItem->name = name;
		pItem->id = id;
		pItem->username = username;
		pItem->password = password;
		pItem->birthday = stoi(birthday);
		addStaffNode(pItem);
	}
	f.close();
}

void updateCourse(string filename)
{
	ifstream f;
	f.open(filename);
	string role;
	getline(f, role, '\n');
	while (!f.eof())
	{
		course* pItem = new course;
		//char c;
		string subName, subID, teacher;
		getline(f, subName, ',');
		//cin >> c;
		getline(f, subID, ',');
		//cin >> c;
		getline(f, teacher, '\n');
		//cin >> c;

		pItem->subName = subName;
		pItem->subID = subID;
		pItem->teacher = teacher;
		addCourseNode(pItem);
	}
	f.close();
}

void addClassNode(string classname)
{
	Class* pItem = new Class;
	pItem->name = classname;
	pItem->headStudent = nullptr;
	pItem->endStudent = nullptr;
	pItem->pNext = nullptr;
	pItem->pPrev = endClass;
	if (!headClass)
	{
		headClass = pItem;
		endClass = pItem;
		return;
	}
	endClass->pNext = pItem;
	endClass = endClass->pNext;
}

void addStudentNode(Class*& pClass, studentNode* pItem)
{
	pItem->pNext = nullptr;
	pItem->pPrev = pClass->endStudent;
	if (!pClass->headStudent)
	{
		pClass->headStudent = pItem;
		pClass->endStudent = pItem;
		return;
	}
	pClass->endStudent->pNext = pItem;
	pClass->endStudent = pClass->endStudent->pNext;
}

void addStaffNode(staffNode* pItem)
{
	pItem->pNext = nullptr;
	pItem->pPrev = endStaff;
	if (!headStaff)
	{
		headStaff = pItem;
		endStaff = pItem;
		return;
	}
	endStaff->pNext = pItem;
	endStaff = endStaff->pNext;
}

void addCourseNode(course* pItem)
{
	pItem->pNext = nullptr;
	pItem->pPrev = endCourse;
	if (!headCourse)
	{
		headCourse = pItem;
		endCourse = pItem;
		return;
	}
	endCourse->pNext = pItem;
	endCourse = endCourse->pNext;
}

void addStudentCourse(studentNode* &pNode, course* pCourse)
{	
	
	course* pItem = new course;
	//copy the info
	pItem->midterm = pCourse->midterm;
	pItem->final = pCourse->final;
	pItem->lab = pCourse->lab;
	pItem->subName = pCourse->subName;
	pItem->subID = pCourse->subID;
	pItem->teacher = pCourse->teacher;
	pItem->pNext = nullptr;
	if (!pNode->headSubject)
	{
		pNode->headSubject = pItem;
		pNode->endSubject = pItem;
		return;
	}
	pItem->pPrev = pNode->endSubject;
	pNode->endSubject->pNext = pItem;
	pNode->endSubject = pItem;
}

int numOfCourse()
{
	int count = 0;
	course* cur = headCourse;
	while (cur)
	{
		cur = cur->pNext;
		count++;
	}
	return count;
}

bool addFromCSV(string filename)
{
	ifstream f;
	f.open(filename);
	string role;
	getline(f, role, '\n');
	while (!f.eof())
	{
		getline(f, role, ',');
		cout << role;
		if (role == "student") {
			studentNode* pItem = new studentNode;

			//char c;
			string name, id, cl, username, password, birthday;
			getline(f, name, ',');
			//cin >> c;
			getline(f, id, ',');

			getline(f, cl, ',');
			//cin >> c;
			getline(f, username, ',');
			//cin >> c;
			getline(f, password, ',');
			//cin >> c;
			getline(f, birthday, '\n');

			pItem->name = name;
			pItem->id = id;
			pItem->classname = cl;
			pItem->username = username;
			pItem->password = password;
			pItem->birthday = stoi(birthday);
			pItem->pNext = nullptr;

			Class* pClass = findClass(cl, 0);

			if (!pClass) return false;

			addStudentNode(pClass, pItem);
		}
		else if (role == "staff") {
			staffNode* pItem = new staffNode;

			//char c;
			string name, id, username, password, birthday;
			getline(f, name, ',');
			//cin >> c;
			getline(f, id, ',');
			//cin >> c;
			getline(f, username, ',');
			//cin >> c;
			getline(f, password, ',');
			//cin >> c;
			getline(f, birthday, '\n');

			pItem->name = name;
			pItem->id = id;
			pItem->username = username;
			pItem->password = password;
			pItem->birthday = stoi(birthday);
			pItem->pNext = nullptr;
			addStaffNode(pItem);
		}
		else {
			f.close();
			return false;
		}
	}
	f.close();
	return true;
}

void addDataToStaffCsvFile()
{
	staffNode* pItem = headStaff;
	ofstream fout;
	fout.open("STAFF.csv", ios::trunc);
	fout << "Name" << "," << "id" << "," << "username" << "," << "password" << "," << "birthday" ;
	while (pItem != nullptr) {
		fout << '\n' << pItem->name << "," << pItem->id << "," << pItem->username << "," << pItem->password << "," << pItem->birthday;
		pItem = pItem->pNext;
	}
	fout.close();

}

void addDataToStudentCsvFile() {
	ofstream fout;
	fout.open("STUDENT.csv", ios::trunc);
	fout << "Name" << "," << "id" << ",class," << "username" << "," << "password" << "," << "birthday" << "," << "num of sub";
	Class* pItem = headClass;
	while (pItem) 
	{
		while (pItem->headStudent != nullptr) 
		{
			fout << '\n' << pItem->headStudent->name << "," << pItem->headStudent->id << "," << pItem->headStudent->classname << "," << pItem->headStudent->username  << "," << pItem->headStudent->password << "," << pItem->headStudent->birthday<<"," << courseEnrolled(pItem->headStudent);
			while (pItem->headStudent->headSubject)
			{
				fout << "," << pItem->headStudent->headSubject->subID;
				pItem->headStudent->headSubject = pItem->headStudent->headSubject->pNext;
			}
			pItem->headStudent = pItem->headStudent->pNext;
		}
		pItem = pItem->pNext;
	}
		fout.close();
	
}

void addDataToCourseCsvFile()
{
	course* pItem = headCourse;
	ofstream fout;
	fout.open("COURSE.csv", ios::trunc);
	fout << "subName" << "," << "subID" << "," << "Teacher";
	while (pItem != nullptr) {
		fout << '\n' << pItem->subName << "," << pItem->subID << "," << pItem->teacher;
		pItem = pItem->pNext;
	}
	fout.close();
}

void addFromKeyb(string name, string id, string cl, string username, string password, string birthday, string role, studentNode*& headStudent, studentNode*& endStudent)
{
	if (role == "student")
	{
		studentNode* pItemT = new studentNode;
		pItemT->name = name;
		pItemT->id = id;
		pItemT->classname = cl;
		pItemT->username = username;
		pItemT->password = password;
		pItemT->birthday = stoi(birthday);
		pItemT->pNext = nullptr;
		Class* pClass = findClass(cl, 0);
		addStudentNode(pClass, pItemT);
	}
	else if (role == "staff")
	{
		staffNode* pItemF = new staffNode;
		pItemF->name = name;
		pItemF->id = id;
		pItemF->username = username;
		pItemF->password = password;
		pItemF->birthday = stoi(birthday);
		pItemF->pNext = nullptr;
		addStaffNode(pItemF);
	}
}

void displayClassList()
{
	Class* pClass = headClass;
	while (pClass)
	{
		cout << pClass->name << endl;
		pClass = pClass->pNext;
	}
}

void displayStudentList(Class* pClass)
{
	studentNode* pStudent = pClass->headStudent;
	while (pStudent)
	{
		cout << pStudent->name << endl;
		pStudent = pStudent->pNext;
	}
}


bool checkk(string username, string password, studentNode*& pSt, staffNode*& pStf)
{
	bool temp = false;
	Class* curClass = headClass;
	while (curClass && !temp)
	{
		temp = checkLogin(username, password, curClass->headStudent, curClass->endStudent, pSt, pStf);
		curClass = curClass->pNext;
	}
	return temp;
}

bool checkLogin(string username, string password, studentNode*& headStudent, studentNode*& endStudent, studentNode* &pSt, staffNode* &pStf)
{
	if (username[0] == 'F')
	{
		staffNode* temp = headStaff;
		while (temp)
		{
			if (temp->username == username && temp->password == password)
			{
				//invoke staffInterface funtion here with temp as a argument
				pStf = temp;
				pSt = nullptr;
				return true;
			}
			temp = temp->pNext;
		}
	}
	else if (username[0] == 'T')
	{
		studentNode* temp = headStudent;
		while (temp)
		{
			if (!temp->username.compare(username) && !temp->password.compare(password))
			{
				//invoke studentInterface funtion here with temp as a argument
				pStf = nullptr;
				pSt = temp;
				return true;
			}
			temp = temp->pNext;
		}
	}
	return false;
}

void cleanUpClass()
{
	Class* pClass = headClass;
	while (pClass)
	{
		studentNode* pCur = pClass->headStudent;
		while (pCur)
		{
			if (!pClass->headStudent) break;
			pClass->headStudent = pClass->headStudent->pNext;
			delete pCur;
			pCur = pClass->headStudent;
		}
		headClass = headClass->pNext;
		delete pClass;
		pClass = headClass;
	}
}

void cleanUpStaff()
{
	staffNode* pStaff = headStaff;
	while (pStaff)
	{
		headStaff = headStaff->pNext;
		delete pStaff;
		pStaff = headStaff;
	}
}

void cleanUpCourse()
{
	course* pCourse = headCourse;
	while (pCourse)
	{
		headCourse = headCourse->pNext;
		delete pCourse;
		pCourse = headCourse;
	}
}


