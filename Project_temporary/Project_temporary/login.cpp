#include "login.h"

void loginScreen(studentNode*& pSt, staffNode*& pStf)
{	
	system("cls");
	setBackgroundColor(0);
	setScreenSize(360, 120, 760, 580);
	DisableResizeWindow();
	DisableCtrButton(0, 0, 1);
	ShowScrollbar(false);
	string username = "";
	int length;
	string password = "";
	ifstream in;
	in.open("logo.txt");
	int input;
	//in >> input;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 61; j++)
		{
			in >> input;
			gotoxy(3 + j, 4 + i);
			cout << char(input);
		}
		//cout << endl;
	}
	in.close();
	in.open("moodle.txt");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 37; j++)
		{
			in >> input;
			gotoxy(15 + j, 20 + i);
			cout << char(input);
		}
		//cout << endl;
	}
	in.close();
	in.open("login.txt");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			in >> input;
			gotoxy(71 + j, 7 + i);
			cout << char(input);
		}
		//cout << endl;
	}
	for (int i = 0; i < 32; i++)
	{
		gotoxy(69 , i);
		cout << (char)179;
	}
	gotoxy(71, 16); 
	cout << "Username";
	gotoxy(71, 18);
	cout << "Password";
	char inp;

	length = 0;
	gotoxy(71, 17);
	while ((inp = inputKey()) != 13 && inp != 9)
	{
		if (inp != 8 && length < 20)
		{
			length++;
			username.push_back(inp);
			gotoxy(70 + length, 17);
			cout << inp;
		}
		else
			if (inp == 8 && length > 0)
			{
				
				username.pop_back();
				gotoxy(70 + length, 17);
				cout << " ";
				gotoxy(70 + length, 17);
				length--;
			}
	}
	length = 0;
	gotoxy(71, 19);
	while ((inp = inputKey()) != 13)
	{
		if (inp != 8 && length < 20)
		{
			length++;
			password.push_back(inp);
			gotoxy(70 + length, 19);
			cout << "*";
		}
		else
			if (inp == 8 && length > 0)
			{

				password.pop_back();
				gotoxy(70 + length, 19);
				cout << " ";
				gotoxy(70 + length, 19);
				length--;
			}
	}
	//cout << password;
	while (!checkk(username, password, pSt, pStf))
	{
		reLogin(username, password);
	}

	gotoxy(0, 0);
	in.close();
}

void reLogin(string &username, string &password)
{
	int length;
	username = "";
	password = "";
	char inp;
	gotoxy(71, 17);
	cout << ("                    ");

	gotoxy(71, 19);
	cout << ("                    ");
	setColor(12);
	gotoxy(71, 23);
	cout << "wrong password or username";
	setColor(7);
	length = 0;
	gotoxy(71, 17);
	while ((inp = inputKey()) != 13 && inp != 9)
	{
		if (inp != 8 && length < 20)
		{
			length++;
			username.push_back(inp);
			gotoxy(70 + length, 17);
			cout << inp;
		}
		else
			if (inp == 8 && length > 0)
			{

				username.pop_back();
				gotoxy(70 + length, 17);
				cout << " ";
				gotoxy(70 + length, 17);
				length--;
			}
	}
	length = 0;
	gotoxy(71, 19);
	while ((inp = inputKey()) != 13)
	{
		if (inp != 8 && length < 20)
		{
			length++;
			password.push_back(inp);
			gotoxy(70 + length, 19);
			cout << "*";
		}
		else
			if (inp == 8 && length > 0)
			{

				password.pop_back();
				gotoxy(70 + length, 19);
				cout << " ";
				gotoxy(70 + length, 19);
				length--;
			}
	}
}
