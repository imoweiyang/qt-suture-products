#include "form_zhong.h"
#include "ui_form_zhong.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
#include "clockwidget.h"


Form_zhong::Form_zhong(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_zhong)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);//设置窗体无边框

       setAttribute(Qt::WA_TranslucentBackground);//设置背景透明

    QPixmap pix;
    // 加载图片
    pix.load(":/image/image/clock.jpg");
    // 设置窗口大小为图片大小
    resize(pix.size());
    // 为窗口设置遮罩
    setMask(pix.mask());


    ui->setupUi(this);
    QCursor cursor;                      // 创建光标对象
    cursor.setShape(Qt::OpenHandCursor); // 设置光标形状
    setCursor(cursor);                   // 使用光标

    setGeometry(800,220,80,80);       //设置窗口位置和大小

      setToolTip("进入闹钟界面");
}

Form_zhong::~Form_zhong()
{
    delete ui;


}


//将图片绘制在窗口上，显示图片
void Form_zhong::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    // 从窗口左上角开始绘制图片
    painter.drawPixmap(0, 0, QPixmap(":/image/image/clock.jpg"));
}


//单击事件，左右单击
void Form_zhong::mousePressEvent(QMouseEvent * event)  //单击事件，左右单击
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
void Form_zhong::mouseReleaseEvent(QMouseEvent *event) // 鼠标释放事件
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();         // 恢复鼠标指针形状


}



// 鼠标移动事件
void Form_zhong::mouseMoveEvent(QMouseEvent *event) // 鼠标移动事件
{
    if(event->buttons() & Qt::LeftButton){      // 这里必须使用buttons()
        move(event->globalPos()+offset);
       event->accept();
    }
}


// 鼠标双击事件
void Form_zhong::mouseDoubleClickEvent(QMouseEvent *event) // 鼠标双击事件
{
    if(event->buttons()==Qt::LeftButton)
    {
       ClockWidget *c=new ClockWidget();
       c->show();                       //进入主界面
      // close();

    }
}

