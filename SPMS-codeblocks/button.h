#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED


#include <iostream>
#include <string>
#include <graphics.h>
#include <conio.h>

using namespace std;

struct Button{
    RECT area;
    string text;  //按钮文字
	bool isint=false;
	COLORREF color = RGB(232, 232, 236);  //浅灰
};

struct Edit
{
    RECT area;
    string title;	            //弹出窗标题
    string text;
    string pretext;
    bool isshow = false;		//显示状态
	bool isint=false;
	int pos=-1;
};


/******************************/

extern bool haveStu;

extern Button button[6];
//增
extern Edit insertEdit;
extern Button insertBtn;
//删
extern Edit delEdit;
extern Button delBtn;
//改
extern Edit modifyEdit;
extern Edit modifys[8];
//查
extern Button FnameBtn;
extern Button FnoBtn;
extern Edit searchEdit;
//排序
extern Button SortNoBtn;
extern Button SortSumBtn;

/**<  **************************** */
void init_tb();
void S_button(Button tttt);
void S_Edit(Edit tttt);
bool BisClicked(const ExMessage& msg,Button tttt);//鼠标是否点击了按钮
bool BisClicked(const ExMessage& msg,Edit tttt);
bool Bisin(const ExMessage& msg,Button tttt);//鼠标是否在按钮上面
bool Bisin(const ExMessage& msg,Edit tttt);
void Button_Loop1(const ExMessage& msg,Button& tttt);
void PlayEditM();
void PlayButtonM();

void popInput(Edit &tttt);
void SetEditTitle(Edit& tttt,string title);
void Editshow(Button &tttt);
bool TextChanged(Edit &tttt);
Edit EdittLoop(const ExMessage& msg,Edit& tttt);
void Editshow(Edit& tttt);

#endif // BUTTON_H_INCLUDED
