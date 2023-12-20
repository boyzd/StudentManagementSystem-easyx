#pragma once

#pragma comment(lib,"Imm32.lib")
#ifdef  UNICODE
#undef UNICODE
#endif //  UNICODE

#include <iostream>
#include <string>
#include <graphics.h>
#include <conio.h>

using namespace std;

struct Button {
    RECT area;
    string text;  //��ť����
    bool isint = false;
    COLORREF color = RGB(232, 232, 236);  //ǳ��
};

struct Edit
{
    RECT area;
    string title;	            //����������
    string text;
    string pretext;
    bool isshow = false;		//��ʾ״̬
    bool isint = false;
    int pos = -1;
};


/******************************/

extern bool haveStu;

extern Button button[6];
//��
extern Edit insertEdit;
extern Button insertBtn;
//ɾ
extern Edit delEdit;
extern Button delBtn;
//��
extern Edit modifyEdit;
extern Edit modifys[8];
//��
extern Button FnameBtn;
extern Button FnoBtn;
extern Edit searchEdit;
//����
extern Button SortNoBtn;
extern Button SortSumBtn;

/**<  **************************** */
void init_tb();
void S_button(Button tttt);
void S_Edit(Edit tttt);
bool BisClicked(const ExMessage& msg, Button tttt);//����Ƿ����˰�ť
bool BisClicked(const ExMessage& msg, Edit tttt);
bool Bisin(const ExMessage& msg, Button tttt);//����Ƿ��ڰ�ť����
bool Bisin(const ExMessage& msg, Edit tttt);
void Button_Loop1(const ExMessage& msg, Button& tttt);
void PlayEditM();
void PlayButtonM();

void popInput(Edit& tttt);
void SetEditTitle(Edit& tttt, string title);
void Editshow(Button& tttt);
bool TextChanged(Edit& tttt);
Edit EdittLoop(const ExMessage& msg, Edit& tttt);
void Editshow(Edit& tttt);