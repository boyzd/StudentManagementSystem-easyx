
#include "table.h"

int first_x = 50;
int first_y = 100;

Table table1;

string tableh[8] =
{
	"学号",
	"姓名",
	"性别",
	"年级",
	"成绩1",
	"成绩2",
	"成绩3",
	"总分",
};
string TEMP[8] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
};

int ssort = 0;
/** \brief 显示完整表格画面，实现排序等按钮效果
 *
 * \param
 * \param
 * \return
 *
 */

void displayAll()
{
	//T_Table(table1,SL_length(Student),8);
	drawTableGrid(table1);
	drawTableText(table1);

	if (BisClicked(s_message, SortNoBtn) && startTimer(200, 0))
	{
		ssort++;
		if (ssort % 2 == 0)SortList1(Student);
		else SortList2(Student);
	}
	if (BisClicked(s_message, SortSumBtn) && startTimer(200, 0))
	{
		ssort++;
		if (ssort % 2 == 0)SortList3(Student);
		else SortList4(Student);
	}
}
/** \brief 绘制线条
 *
 * \param
 * \param
 * \return
 *
 */

void drawTableGrid(Table& ttt)
{

	drawHeader(ttt);
	setlinestyle(PS_SOLID, 1);
	//横线
	int linexlen = ttt.col * ttt.width;
	for (int i = 0; i < ttt.row + 1; i++)
	{

		int resy = first_y + ttt.high * i;
		line(first_x, resy, first_x + linexlen, resy);
	}
	//竖线
	for (int k = 0; k < ttt.col + 1; k++)
	{
		line(first_x + k * ttt.width, first_y, first_x + k * ttt.width, first_y + ttt.high * ttt.row);
	}

	if (ttt.m_maxPage > 0)
	{
		initPageBtnPos(ttt);
	}
	S_button(SortNoBtn);
	S_button(SortSumBtn);

}
/** \brief 	绘制表头
 *
 * \param
 * \param
 * \return
 *
 */

void drawHeader(Table& ttt)
{
	setlinestyle(PS_SOLID, 2);
	rectangle(first_x, first_y - 30, first_x + ttt.width * ttt.col, first_y);
	RECT r;

	settextstyle(18, 0, "宋体");
	settextcolor(BLACK);

	for (int i = 0; i < ttt.col; i++)
	{
		line(first_x + i * ttt.width, first_y - 30, first_x + i * ttt.width, first_y);
		r = { first_x + i * ttt.width, first_y - 30, first_x + (i + 1) * ttt.width, first_y };
		drawtext(static_cast<LPCTSTR>(tableh[i].c_str()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}
/** \brief 绘制表格中内容
 *
 * \param
 * \param
 * \return
 *
 */

void drawTableText(Table ttt)
{
	int begPos = ttt.m_curPage * ttt.row;
	int endPos = ttt.row + ttt.m_curPage * ttt.row;
	//cout<<endPos<<endl;
	if (ttt.m_curPage == ttt.m_maxPage)
	{
		endPos = begPos + ttt.m_extraData;
	}
	if (SL_length(Student) == 0)
	{
		endPos = 0;
	}
	//cout<<endPos<<endl;

	student temp;
	for (int beg = begPos, i = 0; beg < endPos; beg++, i++)
	{
		temp = seach_NUM(Student, beg);
		TEMP[0] = to_string(temp.no);
		TEMP[1] = temp.name;
		TEMP[2] = temp.sex;
		TEMP[3] = temp.grade;
		TEMP[4] = to_string(temp.scores[0]);
		TEMP[5] = to_string(temp.scores[1]);
		TEMP[6] = to_string(temp.scores[2]);
		TEMP[7] = to_string(temp.sum);
		//cout<<TEMP[7]<<endl;
		for (int k = 0; k < ttt.col; k++)
		{
			RECT r = { first_x + k * ttt.width, first_y + i * ttt.high, first_x + (k + 1) * ttt.width, first_y + (i + 1) * ttt.high };
			drawtext(TEMP[k].data(), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
	}
}

/** \brief 页数相关按钮
 *
 * \param
 * \param
 * \return
 *
 */

void initPageBtnPos(Table& bbb)
{
	bbb.m_prevPageBtn.area = { 50,530,130,560 };
	bbb.m_prevPageBtn.text = "上一页";
	bbb.m_nextPageBtn.area = { 150,530,230,560 };
	bbb.m_nextPageBtn.text = "下一页";
	bbb.m_beginPageBtn.area = { 250,530,330,560 };
	bbb.m_beginPageBtn.text = "第一页";
	bbb.m_endPageBtn.area = { 350,530,430,560 };
	bbb.m_endPageBtn.text = "结尾页";

	settextstyle(16, 0, "宋体");
	settextcolor(BLACK);
	S_button(bbb.m_prevPageBtn);
	S_button(bbb.m_nextPageBtn);
	S_button(bbb.m_beginPageBtn);
	S_button(bbb.m_endPageBtn);

	string pageInfo("共" + std::to_string(bbb.m_maxPage + 1) + "页,第" + to_string(bbb.m_curPage + 1) + "页");

	//drawtext(pageInfo.c_str(), {750,530,850,560} , DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

/** \brief 更新页数相关
 *
 * \param
 * \param
 * \return
 *
 */

void updateData(Table& bbb)
{
	if (bbb.row >= SL_length(Student)) //计算最大页数
	{
		bbb.m_maxPage = 0;
		bbb.m_extraData = SL_length(Student);
	}
	else
	{
		bbb.m_extraData = SL_length(Student) % bbb.row;	//余下多少条
		bbb.m_maxPage = SL_length(Student) / bbb.row;
	}

}
