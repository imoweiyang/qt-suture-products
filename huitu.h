#ifndef HUITU_H
#define HUITU_H

#include <QWidget>

namespace Ui {
class Huitu;
}

class Huitu : public QWidget
{
    Q_OBJECT

public:
    explicit Huitu(QWidget *parent = 0);
    ~Huitu();

private:
    Ui::Huitu *ui;
    QPoint offset;                       // 用来储存鼠标指针位置与窗口位置的差值

protected:
    void paintEvent(QPaintEvent *);        //显示图片

    void mousePressEvent(QMouseEvent *event);  //鼠标左单击和右单击

    void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放事件

    void mouseMoveEvent(QMouseEvent *event); //鼠标移动


    void mouseDoubleClickEvent(QMouseEvent *event);  //鼠标双击
};

#endif // HUITU_H
