#include "form.h"
#include "ui_form.h"
#include"mainwindow.h"
#include"clockwidget.h"
#include"digitslclock.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);//设置窗体无边框

       setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    //close();
        MainWindow *m=new MainWindow();
        m->show();
}

void Form::on_pushButton_2_clicked()
{
   // close();
        ClockWidget *c=new ClockWidget();
        c->show();
}

void Form::on_pushButton_3_clicked()
{
    //跳转到电子时间
     //  close();
       DigitslClock *d=new DigitslClock();
   d->show();
}
