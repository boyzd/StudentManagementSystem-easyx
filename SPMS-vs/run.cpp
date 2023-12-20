#include "run.h"

ExMessage s_message;
int opt = 66;		//当前所在页

bool hasMsg()
{
	return peekmessage(&s_message, EX_MOUSE | EX_KEY);
}

void run()
{
	readData1();
	BeginBatchDraw();

	while (true)
	{
		cleardevice();
		S_image1();

		//drawBackground();
		if (hasMsg())
		{
			switch (s_message.message)
			{
			case WM_KEYDOWN://按键
				switch (s_message.vkcode)
				{
				case VK_ESCAPE:		//ESC
					if (isfirst)isfirst = 0;
					opt = 66;
					break;
				}
				break;
			default:
				otherevent();
				break;
			}
		}

		switch (opt)
		{
		case 66:
			opt = mainMenu(s_message);
			break;
		case ShowAll:
			displayAll();
			break;
		case Insert:
			iinsert();
			break;
		case Erase:
			eerase();
			break;
		case Modify:
			modify();
			break;
		case Find:
			ffind();
			break;
		case Exit:
			writeData1();
			exit(666);
			break;
		default:
			break;
		}

		FlushBatchDraw();
	}

	EndBatchDraw();
}

void otherevent()
{
	if (opt == ShowAll)
	{
		eventLoop1();
	}
	else if (opt == Insert)
	{
		EdittLoop(s_message, insertEdit);
		Button_Loop1(s_message, insertBtn);
	}
	else if (opt == Erase)
	{
		Button_Loop1(s_message, delBtn);
		EdittLoop(s_message, delEdit);
	}
	else if (opt == Find)
	{
		Button_Loop1(s_message, FnameBtn);
		Button_Loop1(s_message, FnoBtn);
	}
	else if (opt == Modify)
	{
		EdittLoop(s_message, modifyEdit);
		if (haveStu)
		{
			for (int i = 0; i < 8; i++)
			{
				//			    modifys[i]=
				EdittLoop(s_message, modifys[i]);
			}
		}
	}
}
/** \brief 显示全部成绩页面
 *
 * \param
 * \param
 * \return
 *
 */
void eventLoop1()
{
	Button_Loop1(s_message, table1.m_prevPageBtn);
	Button_Loop1(s_message, table1.m_nextPageBtn);
	Button_Loop1(s_message, table1.m_beginPageBtn);
	Button_Loop1(s_message, table1.m_endPageBtn);
	Button_Loop1(s_message, SortNoBtn);
	Button_Loop1(s_message, SortSumBtn);

	if (BisClicked(s_message, table1.m_prevPageBtn))
	{
		if (table1.m_curPage != 0)
		{
			table1.m_curPage--;
		}
	}
	if (BisClicked(s_message, table1.m_nextPageBtn))
	{
		if (table1.m_curPage != table1.m_maxPage)
		{
			table1.m_curPage++;
		}
	}
	if (BisClicked(s_message, table1.m_beginPageBtn))
	{
		table1.m_curPage = 0;
	}
	if (BisClicked(s_message, table1.m_endPageBtn))
	{
		table1.m_curPage = table1.m_maxPage;
	}
}
/** \brief 延时
 *
 * \param
 * \param
 * \return
 *
 */

bool startTimer(int64_t ms, int id)
{
	static int64_t start[21] = { 0 };
	int64_t eend = clock();
	if (eend - start[id] >= ms)
	{
		start[id] = eend;
		return true;
	}
	return false;
}
