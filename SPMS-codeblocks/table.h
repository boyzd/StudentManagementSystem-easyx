#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include "button.h"

#include "student.h"
#include<iostream>
using namespace std;


//*****************************//
extern int first_x;
extern int first_y;
struct Table{
    int row=13;   //行
    int col=8;   //列

    int width=100;
    int high=30;

	int m_curPage=0;	//当前页
	int m_maxPage=0;	//总页数
	int m_extraData;	//最后一页有多少条数据

	Button m_prevPageBtn;		//上一页
	Button m_nextPageBtn;		//下一页
	Button m_beginPageBtn;		//第一页
	Button m_endPageBtn;		//末尾页
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

#endif // TABLE_H_INCLUDED
