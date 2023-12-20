#pragma once

#pragma comment(lib,"Imm32.lib")
#ifdef  UNICODE
#undef UNICODE
#endif //  UNICODE
#include <stdio.h>
#include <iostream>
#include<sstream>
#include <fstream>
#include <string>
#include "table.h"
#include "run.h"
using namespace std;

struct student {

    int no;
    string name;
    string sex;
    string grade;
    int scores[3];
    int sum = 0;
};
struct SList
{
    student data;
    SList* next;
};

extern SList* Student;
extern student temp;


//*****************************//
int ListInit(SList*& L);
int SL_length(SList* stuL);
student seach_NUM(SList* L, int e);
void TailInsert(SList*& L, student nnnn);
int delete_No(SList* L, int e);
int deleteLinkList(SList* L, int e, student& ttt);
int seach_No(SList* L, int e);
int seach_Name(SList* L, string e);
int modify_No(SList*& L, int e, student data);
student modify_NUM(SList* L, int e, student data);
void SortList4(SList*& L);
void SortList3(SList*& L);
void SortList2(SList*& L);
void SortList1(SList*& L);
string formatInfo(student ssss);
void readData1();
void writeData1();

//*****************************//