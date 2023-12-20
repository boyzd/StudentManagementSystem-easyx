#include "button.h"

COLORREF nor_color = RGB(232, 232, 236);  //ǳ��
COLORREF h_color = RGB(194, 195, 201);  //���
COLORREF R_color = RGB(124, 24, 35);  //���

/**< ��ʾ��ť */
void S_button(Button tttt)
{
    setlinecolor(BLACK);
    setfillcolor(tttt.color);
    solidroundrect(tttt.area.left, tttt.area.top, tttt.area.right, tttt.area.bottom, 9, 9);
    drawtext(tttt.text.data(), &(tttt.area), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
/**< ��ʾ�༭�� */
void S_Edit(Edit tttt)
{
    settextstyle(20, 0, "����");
    settextcolor(BLACK);
    setfillcolor(RGB(232, 232, 236));
    fillrectangle(tttt.area.left, tttt.area.top, tttt.area.right, tttt.area.bottom);
    drawtext(tttt.text.data(), &(tttt.area), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
/** \brief ����Ƿ�������
 *
 * \param
 * \param
 * \return
 *
// */
/**< ����Ƿ��ڱ༭������ */
bool Bisin(const ExMessage& msg, Edit tttt)
{
    if (msg.x >= tttt.area.left && msg.x <= tttt.area.right && msg.y >= tttt.area.top && msg.y <= tttt.area.bottom)
        return true;
    return false;
}
/**< ����Ƿ��ڰ�ť���� */
bool Bisin(const ExMessage& msg, Button tttt)
{
    if (msg.x >= tttt.area.left && msg.x <= tttt.area.right && msg.y >= tttt.area.top && msg.y <= tttt.area.bottom)
        return true;
    return false;
}
/** \brief ����Ƿ�����
 *
 * \param
 * \param
 * \return
 *
 */
 /**< ����Ƿ����˰�ť */
bool BisClicked(const ExMessage& msg, Edit tttt)
{
    if (Bisin(msg, tttt) && msg.message == WM_LBUTTONDOWN)
    {
        PlayEditM(); return true;
    }

    return false;
}
/**< ����Ƿ����˱༭�� */
bool BisClicked(const ExMessage& msg, Button tttt)
{
    if (Bisin(msg, tttt) && msg.message == WM_LBUTTONDOWN)
    {
        PlayButtonM(); return true;
    }
    return false;
}
/** \brief ���������
 *
 * \param
 * \param
 * \return
 *
 */
void popInput(Edit& tttt)
{
    char str[128] = { 0 };
    InputBox(str, 128, nullptr, tttt.title.c_str(), tttt.text.c_str());
    tttt.text = str;
}

/** \brief �����Ƿ����
 *
 * \param
 * \param
 * \return
 *
 */
bool TextChanged(Edit& tttt)
{
    if (tttt.pretext == tttt.text)
    {
        return false;
    }
    tttt.pretext = tttt.text;	//����
    return true;
}

/**< ��ť��ɫ */
void Button_Loop1(const ExMessage& msg, Button& tttt)
{
    if (Bisin(msg, tttt))
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
            tttt.color = nor_color;
        }
    }
}
/** \brief ��Ч����
 *
 * \param
 * \param
 * \return
 *
 */

void PlayButtonM()
{
    mciSendString("close button", NULL, 0, NULL);
    mciSendString("open button.mp3 alias button", NULL, 0, NULL);
    mciSendString("play button", NULL, 0, NULL);
}
void PlayEditM()
{
    mciSendString("close edit ", NULL, 0, NULL);
    mciSendString("open edit.mp3 alias edit", NULL, 0, NULL);
    mciSendString("play edit", NULL, 0, NULL);
}


/** \brief �������ʾ
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
/**< �������� */
void SetEditTitle(Edit& tttt, string title)
{
    tttt.title = title;
}
/** \brief �ж��Ƿ���Ҫ���������
 *
 * \param
 * \param
 * \return
 *
 */

Edit EdittLoop(const ExMessage& msg, Edit& tttt)
{
    if (BisClicked(msg, tttt))
        tttt.isshow = true;
    return tttt;
}


bool m_isPopUp = 0;	//�Ƿ񵯳�
string m_pretext = "";	//��һ�ε�����
string m_text = "";		//�б༭���е�����
string m_title;	//�б༭������������

//��ҳ
Button button[6];
//����
Edit insertEdit;
Button insertBtn;
//ɾ��
Edit delEdit;
Button delBtn;
//�޸�
Edit modifyEdit;
Edit modifys[8];
//����
Button FnameBtn;
Button FnoBtn;
Edit searchEdit;
//����
Button SortNoBtn;
Button SortSumBtn;

void init_tb()
{

    int i;
    button[0].text = "�鿴ѧ���ɼ�";
    button[1].text = "���ѧ���ɼ�";
    button[2].text = "ɾ��ѧ���ɼ�";
    button[3].text = "�޸�ѧ���ɼ�";
    button[4].text = "����ѧ���ɼ�";
    button[5].text = "�˳�";

    for (i = 0; i < 6; i++)
    {
        button[i].area = { 300,200 + 50 * i,600,240 + 50 * i };
    }

    insertEdit.area = { 300,320,600,360 };

    insertBtn.text = "ȷ��";
    insertBtn.area = { 700 - 30,320,780 - 30,360 };

    delEdit.area = { 300,280,600,320 };
    delBtn.area = { 700,280,780,320 };
    delBtn.text = "ȷ��";

    modifyEdit.area = { 300,250,600,285 };
    for (i = 0; i < 8; i++)
    {
        modifys[i].area = { 50 + i * 100,360,150 + i * 100,390 };
    }

    FnoBtn.area = { 300,210,600,250 };
    FnoBtn.text = "��ѧ�Ų���";
    FnameBtn.area = { 300,280,600,320 };
    FnameBtn.text = "����������";

    SortNoBtn.area = { 520,530,600,560 };
    SortNoBtn.text = "ѧ������";

    SortSumBtn.area = { 620,530,700,560 };
    SortSumBtn.text = "�ܷ�����";
}
