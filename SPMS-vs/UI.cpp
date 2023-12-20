#include "UI.h"

#pragma comment(lib,"Winmm.lib")


HWND handle;//��ǰ���ھ��
IMAGE img1;

void Show_window()
{
    handle = initgraph(900, 600, 1);
    setbkmode(TRANSPARENT);
}
void SetWindowTitle(const std::string& title)
{
    SetWindowText(handle, title.c_str());
}
void S_image1()
{
    loadimage(&img1, "./img04.jpg", 900, 600);
    putimage(0, 0, &img1);
}
/** \brief ���˵�
 *
 * \param
 * \param
 * \return
 *
 */

int mainMenu(const ExMessage& msg)
{
    settextstyle(60, 0, "����");
    settextcolor(RGB(49, 112, 167));
    RECT r = { 0, 0, 900, 200 };

    drawtext("ѧ���ɼ�����ϵͳ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    int i;
    settextstyle(20, 0, "����");
    settextcolor(BLACK);
    for (i = 0; i < 6; i++)
    {
        Button_Loop1(s_message, button[i]);
        //        Button_Loop(s_message,button,i);
        S_button(button[i]);
        if (BisClicked(s_message, button[i]))
            return i;

    }
    return 66;
}
/** \brief ��
 *
 * \param
 * \param
 * \return
 *
 */

void iinsert()
{
    settextstyle(50, 0, "����");
    //char title[50] = "���ѧ��";
    RECT r = { 0, 0, 900, 250 };
    drawtext("���ѧ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    settextstyle(30, 0, "����");
    r = { 0, 0, 900, 400 };
    drawtext("����������<ѧ�� ���� �Ա� �༶ �ɼ�1 �ɼ�2 �ɼ�3>", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    settextstyle(20, 0, "����");
    S_button(insertBtn);
    Editshow(insertEdit);

    if (BisClicked(s_message, insertBtn) && startTimer(200, 0))
    {
        if (insertEdit.text.empty())
        {
            printf("����ʧ�ܣ��ַ���Ϊ��\n");
            return;
        }
        char* s = new char[insertEdit.text.size() + 1];
        strcpy(s, insertEdit.text.c_str());
        char* sstt = strtok(s, " ");
        vector<string> words;
        vector<string>::iterator it;
        int n = 0;
        while (sstt)
        {
            words.push_back(sstt);
            cout << sstt << " ";
            sstt = strtok(NULL, " ");
            n++;
        }
        cout << endl;
        if (n != 7)
        {
            printf("����ʧ�ܣ���ʽ������\n");
            return;
        }
        it = words.begin();
        temp.no = stoi(*it);
        it++; temp.name = *it;
        it++; temp.sex = *it;
        it++; temp.grade = *it;
        it++; temp.scores[0] = stoi(*it);
        it++; temp.scores[1] = stoi(*it);
        it++; temp.scores[2] = stoi(*it);
        insertEdit.text = "";
        TailInsert(Student, temp);
        updateData(table1);
    }
}
/** \brief ɾ
 *
 * \param
 * \param
 * \return
 *
 */

void eerase()
{
    settextstyle(50, 0, "����");
    RECT r = { 0, 0, 900, 200 };
    drawtext("ɾ��ѧ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(30, 0, "����");
    r = { 0, 150, 900, 250 };
    drawtext("��������Ҫɾ����ѧ��ѧ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    Editshow(delEdit);
    S_button(delBtn);

    int no=-1;
    if (TextChanged(delEdit))
    {
        isfirst++;
        if (delEdit.text.empty())return;
        no = stoi(delEdit.text);
        delEdit.pos = seach_No(Student, no);
        if (delEdit.pos == -1)
            cout << no << _T("������") << endl;
        else
        {
            temp = seach_NUM(Student, delEdit.pos);
            TEMP[0] = to_string(temp.no);
            TEMP[1] = temp.name;
            TEMP[2] = temp.sex;
            TEMP[3] = temp.grade;
        }
    }
    //	cout<<pos<<endl;
    //	cout<<m_pretext<<m_text<<endl;

    if (delEdit.pos != -1)
    {
        r = { 100 + 150, 300, 100 + 150 + 100, 400 };
        drawtext("ѧ����Ϣ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        settextstyle(20, 0, "����");
        setfillcolor(RGB(232, 232, 236));
        fillrectangle(250, 400, 650, 440);
        for (int k = 0; k < 4; k++)
        {
            r = { 100 + 150 + k * 100, 360, 100 + 150 + (k + 1) * 100, 400 };
            drawtext(tableh[k].data(), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            r = { 100 + 150 + k * 100, 400, 100 + 150 + (k + 1) * 100, 440 };
            drawtext(TEMP[k].data(), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        }
    }
    else
    {
        r = { 250, 300, 650, 500 };
        if (isfirst)drawtext("�����ڸ�ѧ����Ϣ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    //ɾ����ť����
    if (BisClicked(s_message, delBtn) && startTimer(200, 1))
    {
        delete_No(Student, no);
        cout << "ѧ��Ϊ" << no << "��ѧ����ɾ������������:" << SL_length(Student) << endl;
        delEdit.text = "";
        updateData(table1);
    }
}
int isfirst = 0;
bool haveStu = false;
/** \brief ��
 *
 * \param
 * \param
 * \return
 *
 */

void modify()
{
    settextstyle(50, 0, "����");
    RECT r = { 0, 0, 900, 200 };
    drawtext("�޸�ѧ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //    for (int i = 0; i < 8; i++)
    //	{
    //		S_Edit(modifys[i]);
    //	}
    settextstyle(30, 0, "����");
    r = { 0, 150, 900, 250 };
    drawtext("��������Ҫ�޸ĵ�ѧ��ѧ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    Editshow(modifyEdit);

    int no;
    if (TextChanged(modifyEdit))
    {
        isfirst++;
        if (modifyEdit.text.empty())return;
        no = stoi(modifyEdit.text);
        modifyEdit.pos = seach_No(Student, no);
        if (modifyEdit.pos == -1)cout << no << " ������" << endl;
        else
        {
            temp = seach_NUM(Student, modifyEdit.pos);
            cout << "�ҵ���~ " << endl;
            modifys[0].text = to_string(temp.no);
            modifys[1].text = temp.name;
            modifys[2].text = temp.sex;
            modifys[3].text = temp.grade;
            modifys[4].text = to_string(temp.scores[0]);
            modifys[5].text = to_string(temp.scores[1]);
            modifys[6].text = to_string(temp.scores[2]);
            modifys[7].text = to_string(temp.sum);

            modifys[0].pretext = modifys[0].text;
            modifys[1].pretext = modifys[1].text;
            modifys[2].pretext = modifys[2].text;
            modifys[3].pretext = modifys[3].text;
            modifys[4].pretext = modifys[4].text;
            modifys[5].pretext = modifys[5].text;
            modifys[6].pretext = modifys[6].text;
            modifys[7].pretext = modifys[7].text;
        }
    }

    if (modifyEdit.pos != -1)
    {
        haveStu = true;
        //        settextstyle(20, 0, _T("����"));
        //        for (int k = 0; k < 8; k++)
        //            drawtext(modifys[k].text.data(), &(modifys[k].area), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    else haveStu = false;
    if (haveStu)
    {
        for (int i = 0; i < 8; i++)
        {
            if (TextChanged(modifys[i]))
            {
                switch (i)
                {
                case 0:
                    no = stoi(modifys[i].text);
                    if (seach_No(Student, no) != -1)
                    {
                        cout << no << " ѧ�ų�ͻ!!" << endl;
                        modifys[0].text = to_string(temp.no);
                        modifys[0].pretext = modifys[0].text;
                        break;
                    }
                    temp.no = no;
                    cout << "�޸���ѧ�� " << temp.no << endl;
                    break;
                case 1:
                    temp.name = modifys[i].text;
                    cout << "�޸������� " << temp.name << endl;
                    break;
                case 2:
                    temp.sex = modifys[i].text;
                    cout << "�޸����Ա� " << temp.sex << endl;
                    break;
                case 3:
                    temp.grade = modifys[i].text;
                    cout << "�޸��˰༶ " << temp.grade << endl;
                    break;
                case 4:
                    temp.scores[0] = stoi(modifys[i].text);
                    cout << "�޸��˳ɼ�1 " << temp.scores[0] << endl;
                    break;
                case 5:		//�޸���Ӣ��
                    temp.scores[1] = stoi(modifys[i].text);
                    cout << "�޸��˳ɼ�2 " << temp.scores[1] << endl;
                    break;
                case 6:
                    temp.scores[2] = stoi(modifys[i].text);
                    cout << "�޸��˳ɼ�3 " << temp.scores[2] << endl;
                    break;
                case 7:
                    //                    modifys[i].text=to_string(temp.sum);
                    //                    modifys[7].pretext=modifys[7].text;
                    cout << "!!�ܳɼ�����ֱ���޸�!! " << endl;
                }
                temp.sum = temp.scores[0] + temp.scores[1] + temp.scores[2];
                modifys[7].text = to_string(temp.sum);
                modifys[7].pretext = modifys[7].text;
                modify_NUM(Student, modifyEdit.pos, temp);

            }
            Editshow(modifys[i]);
            RECT r = { 50 + i * 100,320,150 + i * 100,360 };
            drawtext(tableh[i].c_str(), &(r), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }
    else
    {
        setfillcolor(RGB(232, 232, 236));
        fillrectangle(50, 360, 850, 390);
        settextstyle(20, 0, "����");
        r = { 50, 360, 850, 390 };
        if (isfirst)
            drawtext("δ�ҵ���Ҫ�޸ĵ�ѧ�������֤�����ԣ�", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        else
            drawtext("�����Ϸ������������Ҫ���ҵ�ѧ��ѧ�ţ�Ȼ�����˴���Ϣֱ�ӱ༭��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
}
/** \brief ��
 *
 * \param
 * \param
 * \return
 *
 */

void ffind()
{
    settextstyle(50, 0, "����");
    RECT r = { 0, 0, 900, 200 };
    drawtext("����ѧ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(20, 0, "����");

    S_button(FnoBtn);
    S_button(FnameBtn);

    int where = -1;		//��¼ʱ��ѧ�Ų��һ��ǰ�����
    if (BisClicked(s_message, FnoBtn))
    {
        SetEditTitle(searchEdit, "������ѧ��");
        popInput(searchEdit);
        where = 0;
    }
    if (BisClicked(s_message, FnameBtn))
    {
        SetEditTitle(searchEdit, "����������");
        popInput(searchEdit);
        where = 1;
    }
    if (where == 0)
    {
        if (searchEdit.text.empty())return;
        int no = stoi(searchEdit.text);
        searchEdit.pos = seach_No(Student, no);
        if (searchEdit.pos == -1)cout << no << " ������" << endl;
        isfirst++;
    }
    else if (where == 1)
    {
        if (searchEdit.text.empty())return;
        searchEdit.pos = seach_Name(Student, searchEdit.text);
        if (searchEdit.pos == -1)cout << searchEdit.text << " ������" << endl;
        else cout << "�ҵ���~ " << endl;
        isfirst++;
    }

    if (searchEdit.pos != -1)
    {
        temp = seach_NUM(Student, searchEdit.pos);
        TEMP[0] = to_string(temp.no);
        TEMP[1] = temp.name;
        TEMP[2] = temp.sex;
        TEMP[3] = temp.grade;
        TEMP[4] = to_string(temp.scores[0]);
        TEMP[5] = to_string(temp.scores[1]);
        TEMP[6] = to_string(temp.scores[2]);
        TEMP[7] = to_string(temp.sum);
        settextstyle(20, 0, "����");
        for (int i = 0; i < 8; i++)
        {
            RECT r = { 50 + i * 100,350,150 + i * 100,390 };
            drawtext(tableh[i].c_str(), &(r), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            r = { 50 + i * 100,390,150 + i * 100,430 };
            drawtext(TEMP[i].data(), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }
    else {
        r = { 250, 300, 650, 500 };
        if (isfirst)drawtext("�����ڸ�ѧ����Ϣ��", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
}


