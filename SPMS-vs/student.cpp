#include "student.h"

SList* Student;

student temp;
/** \brief �����ʼ��
 *
 * \param
 * \param
 * \return
 *
 */

int ListInit(SList*& L)
{
    //L=(SList*)malloc(sizeof(SList));
    L = new SList;
    L->next = NULL;
    return 1;
}
/** \brief ������
 *
 * \param
 * \param
 * \return ����ֵ
 *
 */

int SL_length(SList* stuL)
{
    if (stuL->next == NULL) return 0;
    int len = 0;
    SList* r = stuL->next;
    while (r)
    {
        r = r->next;
        len++;
    }
    return len;
}

/** \brief β��
 *
 * \param
 * \param
 * \return
 *
 */

void TailInsert(SList*& L, student nnnn)
{
    SList* p;
    SList* r = L;
    while (r->next)
    {
        r = r->next;
        if (r->data.no == nnnn.no)
        {
            cout << "ѧ����Ϣ����ѧ�ų�ͻn" << endl;
            return;
        }
    }
    nnnn.sum = (nnnn.scores[0] + nnnn.scores[1] + nnnn.scores[2]);
    p = new SList;;
    p->data = nnnn;
    p->next = NULL;
    r->next = p;
    cout << "����ɹ���������������:" << SL_length(Student) << endl;
    updateData(table1);

}
/** \brief ɾ����ѧ�Žڵ�
 *
 * \param
 * \param
 * \return
 *
 */

int delete_No(SList* L, int e)
{
    SList* r = L, * p = L->next;
    while (p)
    {
        if (p->data.no == e)break;//��
        r = p;
        p = p->next;
    }
    if (p->data.no != e)cout << "��ѧ��������";
    r->next = p->next;

    free(p);//�ͷ�ɾ���ڵ�
    return 1;
}
/** \brief �޸ĸ�ѧ��ѧ��
 *
 * \param
 * \param
 * \return �������޸���Ϣ
 *
 */

int modify_No(SList*& L, int e, student data)
{
    SList* p = L->next;
    while (p)
    {
        if (p->data.no == e)break;//��
        p = p->next;
    }
    if (p->data.no != e) { cout << "��ѧ��������"; return -1; }

    p->data = data;
    return 1;
}
/** \brief �޸�ָ��λ��ѧ����Ϣ
 *
 * \param
 * \param
 * \return �������޸���Ϣ
 *
 */

student modify_NUM(SList* L, int e, student data)
{
    int pos = 0;
    SList* r = L->next;
    while (r)
    {
        if (pos == e) break; //
        r = r->next;
        pos++;
    }
    r->data = data;
    return r->data;
}
/** \brief ɾ����ѧ����Ϣ
 *
 * \param
 * \param
 * \return
 *
 */

int deleteLinkList(SList* L, int e, student& ttt)
{
    SList* r = L, * p = L->next;
    while (p)
    {
        if (p->data.no == e)break;//��
        r = p;
        p = p->next;
    }
    ttt = p->data;
    r->next = p->next;
    free(p);//�ͷ�ɾ���ڵ�
    return 1;
}
/** \brief ���� ��ѧ�� ����
 *
 * \param
 * \param
 * \return
 *
 */

void SortList1(SList*& L)
{
    SList* p, * q;
    for (p = L->next; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data.no > q->data.no)
            {
                student x;
                x = p->data;
                p->data = q->data;
                q->data = x;

            }
        }
    }
}
/** \brief ���� ��ѧ�� ����
 *
 * \param
 * \param
 * \return
 *
 */

void SortList2(SList*& L)
{
    SList* p, * q;
    for (p = L->next; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data.no < q->data.no)
            {
                student x;
                x = p->data;
                p->data = q->data;
                q->data = x;

            }
        }
    }
}
/** \brief ���� ���ܷ� ����
 *
 * \param
 * \param
 * \return
 *
 */

void SortList3(SList*& L)
{
    SList* p, * q;
    for (p = L->next; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data.sum < q->data.sum)
            {
                student x;
                x = p->data;
                p->data = q->data;
                q->data = x;

            }
        }
    }
}
/** \brief ���� ���ܷ� ����
 *
 * \param
 * \param
 * \return
 *
 */

void SortList4(SList*& L)
{
    SList* p, * q;
    for (p = L->next; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data.sum > q->data.sum)
            {
                student x;
                x = p->data;
                p->data = q->data;
                q->data = x;

            }
        }
    }
}

/** \brief ����ָ��Ԫ�� ��ѧ��
 *
 * \param
 * \param
 * \return ����λ��
 *
 */

int seach_No(SList* L, int e)
{
    int pos = 0;
    SList* r = L->next;
    while (r)
    {
        if (r->data.no == e) return pos;
        r = r->next;
        pos++;
    }
    return -1;
}
/** \brief ����ָ��Ԫ�� ������
 *
 * \param
 * \param
 * \return ����λ��
 *
 */

int seach_Name(SList* L, string e)
{
    int pos = 0;
    SList* r = L->next;
    while (r)
    {
        if (r->data.name == e) return pos;
        r = r->next;
        pos++;
    }
    return -1;
}
/** \brief ��λ�����
 *
 * \param
 * \param
 * \return ������Ϣ
 *
 */

student seach_NUM(SList* L, int e)
{
    int pos = 0;
    SList* r = L->next;
    while (r)
    {
        if (pos == e) return r->data;
        r = r->next;
        pos++;
    }
    return L->data;
}

/** \brief д��
 *
 * \param
 * \param
 * \return
 *
 */

void writeData1()
{
    cout << "д���ļ�" << endl;
    fstream write("student.dat", ios::trunc | ios::out);
    if (!write.is_open())
    {
        cout << "���ļ�ʧ��";
        return;
    }

    SList* p;
    p = Student->next;

    while (p)
    {
        string info = formatInfo(p->data);
        write.write(info.c_str(), info.size());
        p = p->next;
    }
    write.close();
}
/** \brief ��ȡ
 *
 * \param
 * \param
 * \return
 *
 */

void readData1()
{
    cout << "��ȡ" << endl;
    fstream stream("student.dat", ios::in);
    if (!stream.is_open())
    {
        cerr << " ���ļ�ʧ��" << endl;
        return;
    }
    student stu;
    char buf[1024] = { 0 };
    //��ȡ����
    while (!stream.eof())
    {
        memset(buf, 0, sizeof(buf));
        stream.getline(buf, 1024);
        //��������
        if (strlen(buf) == 0)
            break;
        //��ʽ����ȡ
        stringstream ss(buf);
        ss >> stu.no >> stu.name >> stu.sex >> stu.grade >> stu.scores[0]
            >> stu.scores[1] >> stu.scores[2] >> stu.sum;
        TailInsert(Student, stu);
    }
    stream.close();
}

string formatInfo(student ssss)
{
    stringstream ss;
    ss << ssss.no << "\t" << ssss.name << "\t" << ssss.sex << "\t" << ssss.grade << "\t"
        << ssss.scores[0] << "\t" << ssss.scores[1] << "\t" << ssss.scores[2] << "\t" << ssss.sum << endl;
    return ss.str();
}
