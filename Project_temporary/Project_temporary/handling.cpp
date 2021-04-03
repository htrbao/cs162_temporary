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
