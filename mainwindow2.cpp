#include "mainwindow2.h"
#include "ui_mainwindow2.h"

#include<QLCDNumber>
#include<QDateTime>
#include<QFont>

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    QDateTime currenttime =QDateTime::currentDateTime();
    ui->lcd->display(currenttime.toString("yyyy-MM-dd HH:mm:ss"));


    QFont font;
    font.setPointSize(15);
    ui->velocity_2->setFont(font);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
