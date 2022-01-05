#pragma once
#include <Windows.h>
#include "Type.h"
enum  class ConsoledColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
};

class ConsoleHelper
{
public :
	static void SetCursorPosition(int32 x, int32 y);
	static void SetCursorColor(ConsoledColor color);
	static void ShowConsoleCursor(bool flag);
};

