#pragma once

#pragma comment(lib,"Imm32.lib")
#ifdef  UNICODE
#undef UNICODE
#endif //  UNICODE
//********************//
#include "UI.h"
#include <graphics.h>
#include <conio.h>
#include "table.h"
#include "button.h"


//*********************//

extern  ExMessage s_message;
extern int opt;

enum menu
{
	one,
	two,
	three,
};

enum Operator
{
	ShowAll,
	Insert,
	Erase,
	Modify,
	Find,
	Exit,
};


//*********************//
void run();
void otherevent();
void eventLoop1();
bool startTimer(int64_t ms, int id);


//*********************//