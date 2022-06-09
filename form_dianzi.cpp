#include "form_dianzi.h"
#include "ui_form_dianzi.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
#include "digitslclock.h"


Form_dianzi::Form_dianzi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_dianzi)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);//设置窗体无边框

       setAttribute(Qt::WA_TranslucentBackground);//设置背景透明

    QPixmap pix;
    // 加载图片
    pix.load(":/image/image/eleclock.jpg");
    // 设置窗口大小为图片大小
    resize(pix.size());
    // 为窗口设置遮罩
    setMask(pix.mask());


    ui->setupUi(this);
    QCursor cursor;                      // 创建光标对象
    cursor.setShape(Qt::OpenHandCursor); // 设置光标形状
    setCursor(cursor);                   // 使用光标

    setGeometry(800,320,80,80);       //设置窗口位置和大小

     setToolTip("进入电子时钟界面");
}

Form_dianzi::~Form_dianzi()
{
    delete ui;
}


//将图片绘制在窗口上，显示图片
void Form_dianzi::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    // 从窗口左上角开始绘制图片
    painter.drawPixmap(0, 0, QPixmap(":/image/image/eleclock.jpg"));
}


//单击事件，左右单击
void Form_dianzi::mousePressEvent(QMouseEvent * event)  //单击事件，左右单击
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
void Form_dianzi::mouseReleaseEvent(QMouseEvent *event) // 鼠标释放事件
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();         // 恢复鼠标指针形状


}



// 鼠标移动事件
void Form_dianzi::mouseMoveEvent(QMouseEvent *event) // 鼠标移动事件
{
    if(event->buttons() & Qt::LeftButton){      // 这里必须使用buttons()
        move(event->globalPos()+offset);
       event->accept();
    }
}


// 鼠标双击事件
void Form_dianzi::mouseDoubleClickEvent(QMouseEvent *event) // 鼠标双击事件
{
    if(event->buttons()==Qt::LeftButton)
    {
       DigitslClock *d=new DigitslClock();
       d->show();                       //进入电子时间
      // close();

    }
}

