#include "handling.h"

int main()
{
	string user, pass;
	studentNode* newnode = new studentNode;
	newnode->username = "Thtbao";
	newnode->password = "baone";
	addStudentNode(headStudent, endStudent, newnode);
	cin >> user >> pass;
	checkLogin(user, pass);
	return 0;
}