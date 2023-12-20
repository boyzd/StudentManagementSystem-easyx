#include "student.h"

SList *Student;

student temp;
/** \brief 链表初始化
 *
 * \param
 * \param
 * \return
 *
 */

int ListInit(SList* &L)
{
    //L=(SList*)malloc(sizeof(SList));
    L=new SList;
    L->next=NULL;
    return 1;
}
/** \brief 链表长度
 *
 * \param
 * \param
 * \return 长度值
 *
 */

int SL_length(SList* stuL)
{
    if(stuL->next == NULL) return 0;
    int len = 0;
    SList *r = stuL->next;
    while(r)
    {
        r = r->next;
        len++;
    }
    return len;
}

/** \brief 尾插
 *
 * \param
 * \param
 * \return
 *
 */

void TailInsert(SList* &L,student nnnn)
{
    SList *p;
    SList *r = L;
    while(r->next)
    {
        r = r->next;
        if(r->data.no==nnnn.no)
        {
            cout<<"学生信息有误：学号冲突n"<<endl;
            return;
        }
    }
    nnnn.sum=(nnnn.scores[0]+nnnn.scores[1]+nnnn.scores[2]);
    p=new SList;;
    p->data=nnnn;
    p->next=NULL;
    r->next=p;
    cout<<"插入成功啦！！数据条数:"<<SL_length(Student)<<endl;
    updateData(table1);

}
/** \brief 删除该学号节点
 *
 * \param
 * \param
 * \return
 *
 */

int delete_No(SList *L,int e)
{
    SList *r =L, *p=L->next;
    while(p)
    {
        if(p->data.no==e)break;//找
        r=p;
        p = p->next;
    }
    if(p->data.no!=e)cout<<"该学生不存在";
    r->next = p->next;

    free(p);//释放删除节点
    return 1;
}
/** \brief 修改该学号学生
 *
 * \param
 * \param
 * \return 返回已修改信息
 *
 */

int modify_No(SList*&L,int e,student data)
{
    SList  *p=L->next;
    while(p)
    {
        if(p->data.no==e)break;//找
        p = p->next;
    }
    if(p->data.no!=e){cout<<"该学生不存在";return -1;}

    p->data=data;
    return 1;
}
/** \brief 修改指定位置学生信息
 *
 * \param
 * \param
 * \return 返回已修改信息
 *
 */

student modify_NUM(SList *L, int e,student data)
{
    int pos = 0;
    SList *r = L->next;
    while(r)
    {
        if( pos == e) break; //
        r = r->next;
        pos ++;
    }
    r->data=data;
    return r->data;
}
/** \brief 删除该学号信息
 *
 * \param
 * \param
 * \return
 *
 */

int deleteLinkList(SList *L, int e, student &ttt)
{
    SList *r =L, *p=L->next;
    while(p)
    {
        if(p->data.no==e)break;//找
        r=p;
        p = p->next;
    }
    ttt=p->data;
    r->next = p->next;
    free(p);//释放删除节点
    return 1;
}
/** \brief 排序 按学号 升序
 *
 * \param
 * \param
 * \return
 *
 */

void SortList1(SList*&L)
{
    SList *p,*q;
    for(p=L->next;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
         {
           if(p->data.no>q->data.no)
            {
                student x;
                x=p->data;
                p->data=q->data;
                q->data=x;

            }
        }
    }
}
/** \brief 排序 按学号 降序
 *
 * \param
 * \param
 * \return
 *
 */

void SortList2(SList*&L)
{
    SList *p,*q;
    for(p=L->next;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
         {
           if(p->data.no<q->data.no)
            {
                student x;
                x=p->data;
                p->data=q->data;
                q->data=x;

            }
        }
    }
}
/** \brief 排序 按总分 降序
 *
 * \param
 * \param
 * \return
 *
 */

void SortList3(SList*&L)
{
    SList *p,*q;
    for(p=L->next;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
         {
           if(p->data.sum<q->data.sum )
            {
                student x;
                x=p->data;
                p->data=q->data;
                q->data=x;

            }
        }
    }
}
/** \brief 排序 按总分 升序
 *
 * \param
 * \param
 * \return
 *
 */

void SortList4(SList*&L)
{
    SList *p,*q;
    for(p=L->next;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
         {
           if(p->data.sum>q->data.sum)
            {
                student x;
                x=p->data;
                p->data=q->data;
                q->data=x;

            }
        }
    }
}

/** \brief 查找指定元素 按学号
 *
 * \param
 * \param
 * \return 返回位序
 *
 */

int seach_No(SList *L, int e)
{
    int pos = 0;
    SList *r = L->next;
    while(r)
    {
        if(r->data.no == e) return pos;
        r = r->next;
        pos ++;
    }
    return -1;
}
/** \brief 查找指定元素 按姓名
 *
 * \param
 * \param
 * \return 返回位序
 *
 */

int seach_Name(SList *L, string e)
{
    int pos = 0;
    SList *r = L->next;
    while(r)
    {
        if(r->data.name == e) return pos;
        r = r->next;
        pos ++;
    }
    return -1;
}
/** \brief 按位序查找
 *
 * \param
 * \param
 * \return 返回信息
 *
 */

student seach_NUM(SList *L, int e)
{
    int pos = 0;
    SList *r = L->next;
    while(r)
    {
        if( pos == e) return r->data;
        r = r->next;
        pos ++;
    }
    return L->data;
}

/** \brief 写入
 *
 * \param
 * \param
 * \return
 *
 */

void writeData1()
{
    cout<<"写入文件"<<endl;
	fstream write("student.dat", ios::trunc | ios::out);
	if (!write.is_open())
	{
		cout<< "打开文件失败";
		return;
	}

	SList* p;
    p=Student->next;

    while(p)
    {
        string info = formatInfo(p->data);
        write.write(info.c_str(),info.size());
        p=p->next;
    }
	write.close();
}
/** \brief 读取
 *
 * \param
 * \param
 * \return
 *
 */

void readData1()
{
    cout<<"读取"<<endl;
	fstream stream("student.dat", ios::in);
	if (!stream.is_open())
	{
		cerr << " 打开文件失败" << endl;
		return;
	}
	student stu;
	char buf[1024] = { 0 };
	//读取数据
	while (!stream.eof())
	{
		memset(buf, 0, sizeof(buf));
		stream.getline(buf, 1024);
		//跳过空行
		if (strlen(buf) == 0)
			break;
		//格式化读取
		stringstream ss(buf);
		ss >> stu.no >> stu.name >> stu.sex >> stu.grade >> stu.scores[0]
		 >> stu.scores[1]>> stu.scores[2]>> stu.sum;
		TailInsert(Student,stu);
	}
	stream.close();
}

string formatInfo(student ssss)
{
	stringstream ss;
	ss<< ssss.no << "\t" << ssss.name << "\t" << ssss.sex <<"\t" << ssss.grade << "\t"
	<< ssss.scores[0] << "\t" << ssss.scores[1] << "\t" << ssss.scores[2] << "\t"<<ssss.sum<< endl;
	return ss.str();
}
