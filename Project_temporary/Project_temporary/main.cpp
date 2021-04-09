#include "handling.h"
#include "interface.h"
#include "staffInterface.h"
#include "studentInterface.h"

HANDLE wHnd;
HANDLE rHnd;

int main()
{	
	//setting screen
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, 200, 40 };
	COORD bufferSize = { 200, 9001 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	//end

	return 0;
}