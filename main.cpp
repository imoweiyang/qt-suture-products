#include "mainwindow.h"           //1，2，3行是头文件
#include <QApplication>
#include"widget.h"
int main(int argc, char *argv[])  //main（）函数，有2个参数，用来接收命令行参数
{
    QApplication a(argc, argv);   //新建QApplication类对象，用于管理应用程序的资源
    QApplication::addLibraryPath("./plugins");
    Widget m;
    m.show();
    return a.exec();
}


