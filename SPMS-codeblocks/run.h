#ifndef RUN_H_INCLUDED
#define RUN_H_INCLUDED
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
#endif // RUN_H_INCLUDED
