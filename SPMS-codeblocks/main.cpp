#include <iostream>
using namespace std;
#include "UI.h"
#include "run.h"


int main()
{
    Show_window();
    SetWindowTitle("学生成绩管理系统");
    init_tb();
    ListInit(Student);
    run();
    closegraph();
    return 0;
}
