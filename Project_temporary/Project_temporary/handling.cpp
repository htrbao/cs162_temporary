#include "handling.h"
using namespace std;
void addStudentNode(studentNode*& head, studentNode*& end, studentNode* pItem)
{
	if (!head)
	{
		head = pItem;
		end = pItem;
		return;
	}
	end->pNext = pItem;
	end = end->pNext;
}

void addStaffNode(staffNode*& head, staffNode*& end, staffNode* pItem)
{
	if (!head)
	{
		head = pItem;
		end = pItem;
		return;
	}
	end->pNext = pItem;
	end = end->pNext;
}

bool addFromCSV(string filename)
{
	ifstream f;
	f.open(filename);
	string role;
	getline(f, role, ',');
	if (role == "student") {
		studentNode* pItem = new studentNode;

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
		addDataToStudentCsvFile(pItem);
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
		addDataToStaffCsvFile(pItem);
	}
	else {
		return false;
	}
	f.close();
	return true;
}

void addDataToStaffCsvFile(staffNode* pItem)
{
	ofstream fout;
	fout.open("STAFF.txt", ios::app);
	fout << pItem->name << "," << pItem->id << "," << pItem->username << "," << pItem->password;
	fout.close();
}

void addDataToStudentCsvFile(studentNode* pItem) {
	ofstream fout;
	fout.open("STUDENT.txt", ios::app);
	fout << pItem->name << "," << pItem->id << "," << pItem->username << "," << pItem->password;
	fout.close();
}

bool checkLogInStudent(string username, string password)
{
    ifstream in;
    int start, end;
    string u, p;
    in.open("STUDENT.txt");
    string input;
    
    u = "";
    while (!in.eof())
    {
        getline(in, input);
        if (in.eof()) break;
        //split string by ","

        end = input.find(',');
        start = end + 1;
        
        end = input.find(",", start);
        start = end + 1;
        end = input.find(",", start);
        u = input.substr(start, end - start);
        start = end + 1;
        p = input.substr(start, end - start);
       //if username and password matches goto another interface
        if (u.compare(username)) {
            in.close();
            studentInterface(); }
        // if there is no match return false
    }
   
    in.close();
    return false;
}
bool checkLogInStaff(string username, string password)
{
    ifstream in;
    int start, end;
    string u, p;
    in.open("STAFF.txt");
    string input;

    u = "";
    while (!in.eof())
    {
        getline(in, input);
        if (in.eof()) break;
        //split string by ","

        end = input.find(',');
        start = end + 1;

        end = input.find(",", start);
        start = end + 1;
        end = input.find(",", start);
        u = input.substr(start, end - start);
        start = end + 1;
        p = input.substr(start, end - start);
        //if username and password matches goto another interface
        if (u.compare(username)) {
            in.close();
            staffInterface();
        }

    }
	// if there is no match return false
    in.close();
    return false;
}

bool checkLogin(string username, string password)
{
    if (!checkLogInStudent(username, password) && !checkLogInStaff(username, password)) return false;
}

void addFromKeyb(int no, int StudentID, string Firstname, string Lastname, string gender, long DateofBirth, int SocialID, int role)
{
	if (role == T)
		addDataToStaffCsvFile(ofstream fout, staffNode * pHead);
	else
		addDataToStudentCsvFile(ofstream fout, studentNode * pHead);
}
