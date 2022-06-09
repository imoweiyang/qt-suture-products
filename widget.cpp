#include "widget.h"
#include "ui_widget.h"

#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QPalette>

#include <QMouseEvent>
#include"logindialog.h"
#include "mainwindow.h"
#include <QApplication>
//#include "choose.h"
//#include "form_home.h"
//#include "form_nine.h"
#include "form_zhong.h"
#include "form_dianzi.h"
#include "form_game.h"
#include "huitu.h"
#include "form_camera.h"
#include "form_luyin.h"
#include "form_video.h"
#include "form_sound.h"
//#include "form_time.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pix;
    // 加载图片
    pix.load(":/image/image/add1.jpg");
    // 设置窗口大小为图片大小
    resize(pix.size());
    // 为窗口设置遮罩
    setMask(pix.mask());

    ui->setupUi(this);
    QCursor cursor;                      // 创建光标对象
    cursor.setShape(Qt::OpenHandCursor); // 设置光标形状
    setCursor(cursor);                   // 使用光标

    setWindowFlags(Qt::FramelessWindowHint);      //实现外部框架透明
    setAttribute(Qt::WA_TranslucentBackground);
    setToolTip("点按左键可以拖移，双击左键登录，点击右键退出");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    // 从窗口左上角开始绘制图片
    painter.drawPixmap(0, 0, QPixmap(":/image/image/add1.jpg"));
}

void Widget::mousePressEvent(QMouseEvent * event)  //单击事件，左右单击
{   // 关闭窗口
    //close();
    if(event->button()==Qt::LeftButton){           //左单击
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor); // 使鼠标指针暂时改变形状


        offset=frameGeometry().topLeft()-event->globalPos();   //globalPos()获取根窗口的相对路径，frameGeometry().topLeft()获取主窗口左上角的位置
        event->accept();                   //鼠标事件被系统接收
    }
    else if (event->button()==Qt::RightButton)   //右键单击退出
    {
        close();
    }
}

// 鼠标释放事件
void Widget::mouseReleaseEvent(QMouseEvent *event) // 鼠标释放事件
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();         // 恢复鼠标指针形状
}



// 鼠标移动事件
void Widget::mouseMoveEvent(QMouseEvent *event) // 鼠标移动事件
{
    if(event->buttons() & Qt::LeftButton){      // 这里必须使用buttons()
        move(event->globalPos()+offset);
       event->accept();
    }
}


// 鼠标双击事件
void Widget::mouseDoubleClickEvent(QMouseEvent *event) // 鼠标双击事件
{
//    if(event->buttons()==Qt::LeftButton)
//    {
//        close();         //将图标关闭
//        LoginDialog dlg;   //创建一个登录窗口
//        dlg.show();         //显示登录的窗口

//        MainWindow *w=new MainWindow();         //new一个主界面窗口
//        if(dlg.exec()==QDialog::Accepted)   //判断dlg执行结果
//        {
//        w->show();                    //如果按下了”登录“，让主页面显示出来
//        }
//    }

    if(event->buttons()==Qt::LeftButton)
        {
            close();         //将图标关闭
            LoginDialog dlg;   //创建一个登录窗口
            dlg.show();         //显示登录的窗口

            //MainWindow *w=new MainWindow();         //new一个主界面窗口
            //Form_home *f=new Form_home();
            Form_zhong *c=new Form_zhong();
            Form_dianzi *a=new Form_dianzi();
            Form_game *g=new Form_game();
            Huitu *h=new Huitu();
            Form_camera *k=new Form_camera();
            Form_luyin *j=new Form_luyin();
            Form_video *u=new Form_video();
            Form_sound *t=new Form_sound();
            //Form_time *ft=new Form_time();
            //Form_nine *fn=new Form_nine();

            if(dlg.exec()==QDialog::Accepted)   //判断dlg执行结果
            {
            //w->show();                    //如果按下了”登录“，让主页面显示出来
                //f->show();
                c->show();
                a->show();
                g->show();
                h->show();
                k->show();
                j->show();
                u->show();
                t->show();
                //ft->show();
               // fn->show();

            }
    }

//    if(event->buttons()==Qt::LeftButton){
//        choose *ch=new choose();
//        ch->show();

//     }


    close();
}
