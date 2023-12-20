#include "button.h"

COLORREF nor_color = RGB(232, 232, 236);  //浅灰
COLORREF h_color = RGB(194, 195, 201);  //深灰
COLORREF R_color = RGB(124, 24, 35);  //枣红

/**< 显示按钮 */
void S_button(Button tttt)
{
    setlinecolor(BLACK);
    setfillcolor(tttt.color);
    solidroundrect(tttt.area.left,tttt.area.top,tttt.area.right,tttt.area.bottom,9,9);
	drawtext(tttt.text.data(), &(tttt.area), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
/**< 显示编辑框 */
void S_Edit(Edit tttt)
{
    settextstyle(20, 0, _T("宋体"));
    settextcolor(BLACK);
	setfillcolor(RGB(232, 232, 236));
    fillrectangle(tttt.area.left,tttt.area.top,tttt.area.right,tttt.area.bottom);
    drawtext(tttt.text.data(), &(tttt.area), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
/** \brief 鼠标是否在上面
 *
 * \param
 * \param
 * \return
 *
// */
/**< 鼠标是否在编辑框上面 */
bool Bisin(const ExMessage& msg,Edit tttt)
{
	if (msg.x >= tttt.area.left && msg.x <= tttt.area.right&& msg.y >= tttt.area.top && msg.y <= tttt.area.bottom)
		return true;
	return false;
}
/**< 鼠标是否在按钮上面 */
bool Bisin(const ExMessage& msg,Button tttt)
{
	if (msg.x >= tttt.area.left && msg.x <= tttt.area.right&& msg.y >= tttt.area.top && msg.y <= tttt.area.bottom)
		return true;
	return false;
}
/** \brief 鼠标是否点击了
 *
 * \param
 * \param
 * \return
 *
 */
/**< 鼠标是否点击了按钮 */
bool BisClicked(const ExMessage& msg,Edit tttt)
{
	if (Bisin(msg,tttt)&&msg.message==WM_LBUTTONDOWN)
    {
        PlayEditM();return true;
    }

	return false;
}
/**< 鼠标是否点击了编辑框 */
bool BisClicked(const ExMessage& msg,Button tttt)
{
	if (Bisin(msg,tttt)&&msg.message==WM_LBUTTONDOWN)
    {
        PlayButtonM();return true;
    }
	return false;
}
/** \brief 弹出输入框
 *
 * \param
 * \param
 * \return
 *
 */
void popInput(Edit &tttt)
{
	char str[128] = { 0 };
	InputBox(str, 128, nullptr,tttt.title.c_str(),tttt.text.c_str());
	tttt.text = str;
}

/** \brief 文字是否更新
 *
 * \param
 * \param
 * \return
 *
 */
bool TextChanged(Edit &tttt)
{
	if (tttt.pretext == tttt.text)
	{
		return false;
	}
	tttt.pretext = tttt.text;	//更新
	return true;
}

/**< 按钮改色 */
void Button_Loop1(const ExMessage& msg,Button &tttt)
{
	if (Bisin(msg,tttt))
	{
		if (!tttt.isint)
		{
		    tttt.isint = true;
			tttt.color = h_color;
		}
	}
	else
	{
		if (tttt.isint)
		{
			tttt.isint = 0;
			tttt.color=nor_color;
		}
	}
}
/** \brief 音效播放
 *
 * \param
 * \param
 * \return
 *
 */

void PlayButtonM()
{
    mciSendString("close button ", NULL, 0, NULL);
    mciSendString("open button.mp3 alias button",NULL, 0, NULL);
    mciSendString("play button", NULL, 0, NULL);
}
void PlayEditM()
{
    mciSendString("close edit ", NULL, 0, NULL);
    mciSendString("open edit.mp3 alias edit",NULL, 0, NULL);
    mciSendString("play edit", NULL, 0, NULL);
}


/** \brief 输入框显示
 *
 * \param
 * \param
 * \return
 *
 */

void Editshow(Edit& tttt)
{
	S_Edit(tttt);
	if (tttt.isshow)
	{
		tttt.pretext = tttt.text;
		popInput(tttt);
		tttt.isshow = false;
	}

}
/**< 输入框标题 */
void SetEditTitle(Edit& tttt,string title)
{
    tttt.title=title;
}
/** \brief 判断是否需要弹出输入框
 *
 * \param
 * \param
 * \return
 *
 */

Edit EdittLoop(const ExMessage& msg,Edit& tttt)
{
	if(BisClicked(msg,tttt))
        tttt.isshow = true;
    return tttt;
}


bool m_isPopUp=0;	//是否弹出
string m_pretext="";	//上一次的文字
string m_text="";		//行编辑器中的文字
string m_title;	//行编辑器弹出窗标题

//首页
Button button[6];
//增加
Edit insertEdit;
Button insertBtn;
//删除
Edit delEdit;
Button delBtn;
//修改
Edit modifyEdit;
Edit modifys[8];
//查找
Button FnameBtn;
Button FnoBtn;
Edit searchEdit;
//排序
Button SortNoBtn;
Button SortSumBtn;

void init_tb()
{

    int i;
    button[0].text="查看学生成绩";
    button[1].text="添加学生成绩";
    button[2].text="删除学生成绩";
    button[3].text="修改学生成绩";
    button[4].text="查找学生成绩";
    button[5].text=_T("退出");

    for(i=0;i<6;i++)
    {
        button[i].area={300,200+50*i,600,240+50*i};
    }

    insertEdit.area={300,320,600,360};

    insertBtn.text="确定";
    insertBtn.area={700-30,320,780-30,360};

    delEdit.area={300,280,600,320};
    delBtn.area={700,280,780,320};
    delBtn.text="确定";

    modifyEdit.area={300,250,600,285};
    for(i=0;i<8;i++)
    {
        modifys[i].area={50+i*100,360,150+i*100,390};
    }

    FnoBtn.area={300,210,600,250};
    FnoBtn.text="按学号查找";
    FnameBtn.area={300,280,600,320};
    FnameBtn.text = "按姓名查找";

    SortNoBtn.area={520,530,600,560};
    SortNoBtn.text="学号排序";

    SortSumBtn.area={620,530,700,560};
    SortSumBtn.text="总分排序";
}
