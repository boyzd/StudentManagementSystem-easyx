#pragma once

#pragma comment(lib,"Imm32.lib")
#ifdef  UNICODE
#undef UNICODE
#endif //  UNICODE
#include "button.h"

#include "student.h"
#include<iostream>
using namespace std;


//*****************************//
extern int first_x;
extern int first_y;
struct Table {
	int row = 13;   //��
	int col = 8;   //��

	int width = 100;
	int high = 30;

	int m_curPage = 0;	//��ǰҳ
	int m_maxPage = 0;	//��ҳ��
	int m_extraData;	//���һҳ�ж���������

	Button m_prevPageBtn;		//��һҳ
	Button m_nextPageBtn;		//��һҳ
	Button m_beginPageBtn;		//��һҳ
	Button m_endPageBtn;		//ĩβҳ
};
extern string tableh[8];
extern string TEMP[8];
extern Table table1;


//*****************************//

void drawHeader();
void drawTableGrid(Table& ttt);
void displayAll();
void drawTableText(Table ttt);
void drawHeader(Table& ttt);
void initPageBtnPos(Table& bbb);
void updateData(Table& bbb);


//*****************************//
