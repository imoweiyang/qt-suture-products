#ifndef FORM_HOME_H
#define FORM_HOME_H

#include <QWidget>

namespace Ui {
class Form_home;
}

class Form_home : public QWidget
{
    Q_OBJECT

public:
    explicit Form_home(QWidget *parent = 0);
    ~Form_home();


private:
    Ui::Form_home *ui;
    QPoint offset;                       // 用来储存鼠标指针位置与窗口位置的差值

protected:
    void paintEvent(QPaintEvent *);        //显示图片

    void mousePressEvent(QMouseEvent *event);  //鼠标左单击和右单击

    void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放事件

    void mouseMoveEvent(QMouseEvent *event); //鼠标移动


    void mouseDoubleClickEvent(QMouseEvent *event);  //鼠标双击
};

#endif // FORM_H
