#pragma once
#pragma comment(lib,"Imm32.lib")
#define _CRT_SECURE_NO_WARNINGS
#ifdef  UNICODE
#undef UNICODE
#endif //  UNICODE
//ͷ�ļ�
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

//����
extern  HWND handle;

extern int isfirst;


//************����***************//
void Show_window();
void SetWindowTitle(const std::string& title);
void S_image1();

int mainMenu(const ExMessage& msg);
void iinsert();
void eerase();
void modify();
void ffind();

