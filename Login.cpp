#include <iostream>
#include <windows.h>
#include <string>

using namespace std;



// void gotoxy(int x, int y)
// {
//     static HANDLE  h = NULL;
//     if(!h)
//         h = GetStdHandle(STD_OUTPUT_HANDLE);
//     COORD c = {x,y};
//     SetConsoleCursorPosition(h,c);
// }
void gotoxy(short posX, short posY)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

    SetConsoleCursorPosition(hStdout, Position);
}
enum colors { BLACK = 0, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, GREY,
                 LIGHTGREY, LIGHTRED, LIGHTGREEN, LIGHTYELLOW, LIGHTBLUE,
                 LIGHTPURPLE, LIGHTCYAN, WHITE, DEFAULT };

int getColor(){
        CONSOLE_SCREEN_BUFFER_INFO info;
        if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
            return false;
        SHORT ret = info.wAttributes;
        return ret;
}

 void setBackgroundColor(int BackC)
 {

    WORD wColor = ((BackC & 0x0F) << 4) + (getColor() & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hStdOut, wColor);
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          SetConsoleCursorPosition(hStdOut, coord);
     }
    return;
}

void showCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
    SetConsoleCursorInfo(handle, &cursor);
}

void hideInput()
{
     HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);

}
void showInput(bool show, HANDLE hStdin, DWORD mode)
{


    if (show)
    {


    SetConsoleMode(hStdin, mode & (~ENABLE_INSERT_MODE));
    }
    else
    {

        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    }
}

void drawRec(long x, long y, long posX, long posY)
{
    x = x + 2;
    y = y * 4 + 1;
    gotoxy(posX, posY);
    for (long i = 1; i <= y; i++)
    {
        if (i == 1) cout << char(218);
        else if (i == y) cout << char(191);
        else cout << char(196);
    }
    for (long i = 2; i < x; i++)
    {
        posY++;
        gotoxy(posX, posY);
        for (long j = 1; j <= y; j++)
        {
            if (j == 1 || j == y) cout << char(179);
            else cout << ' ';
        }
    }
    posY++;
    gotoxy(posX, posY);
    for (long i = 1; i <= y; i++)
    {
        if (i == 1) cout << char(192);
        else if (i == y) cout << char(217);
        else cout << char(196);
    }
}

void drawRec2(long x, long y, long posX, long posY)
{
    x = x + 2;
    y = y * 4 + 1;
    gotoxy(posX, posY);
    for (long i = 1; i <= y; i++)
    {
        if (i == 1) cout << char(201);
        else if (i == y) cout << char(187);
        else cout << char(205);
    }
    for (long i = 2; i < x; i++)
    {
        posY++;
        gotoxy(posX, posY);
        for (long j = 1; j <= y; j++)
        {
            if (j == 1 || j == y) cout << char(186);
            else cout << ' ';
        }
    }
    posY++;
    gotoxy(posX, posY);
    for (long i = 1; i <= y; i++)
    {
        if (i == 1) cout << char(200);
        else if (i == y) cout << char(188);
        else cout << char(205);
    }
}

int main()
{

    string s;


   drawRec2(28,29, 0 , 0);
   drawRec(20, 22, 16, 5);
   drawRec(8, 8, 20, 15);
   drawRec(1,2, 32, 20);
   int hcmus_x = 42;
   int hcmus_y = 6;
     gotoxy(hcmus_x,hcmus_y);  cout << "  _    _  _____ __  __ _    _  _____";
gotoxy(hcmus_x,hcmus_y + 1);   cout << " | |  | |/ ____|  \\/  | |  | |/ ____|";
gotoxy(hcmus_x,hcmus_y + 2);   cout << " | |__| | |    | \\  / | |  | | (___";
gotoxy(hcmus_x,hcmus_y + 3);   cout << " |  __  | |    | |\\/| | |  | |\\___ \\";
gotoxy(hcmus_x,hcmus_y + 4);   cout << " | |  | | |____| |  | | |__| |____) | ";
gotoxy(hcmus_x,hcmus_y + 5);   cout << " |_|  |_|\\_____|_|  |_|\\____/|_____/ ";
gotoxy(22, 16); cout << "username:";
gotoxy(22, 18); cout << "password";
gotoxy(62, 16); cout << "Forgotten your username or password?";
gotoxy(62, 17); cout <<"Cookies must be enabled in your browser";
gotoxy(6, 1); cout << "Call us : (028) 3835 4266 E-mail : info@fit.hcmus.edu.vn";
gotoxy(10,3); cout << "fit@HCMUS";
gotoxy(33, 21); cout << " LOGIN";
gotoxy(90,1); cout << "You are not logged in";
gotoxy(95, 3); cout << "English  (en)";
gotoxy(32,16); cin >> s;
   return 0;
}
