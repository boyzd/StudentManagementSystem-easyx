#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS

//头文件
#include <graphics.h>
#include <conio.h>
#include <string>
#include "button.h"
#include "run.h"
#include "string.h"
#include <time.h>
#include <vector>
#include <string>
#include "student.h"

//变量
extern  HWND handle;

extern int isfirst;


//************函数***************//
void Show_window();
void SetWindowTitle(const std::string& title);
void S_image1();

int mainMenu(const ExMessage& msg);
void iinsert();
void eerase();
void modify();
void ffind();



#endif // UI_H_INCLUDED
