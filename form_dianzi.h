#ifndef FORM_DIANZI_H
#define FORM_DIANZI_H

#include <QWidget>

namespace Ui {
class Form_dianzi;
}

class Form_dianzi : public QWidget
{
    Q_OBJECT

public:
    explicit Form_dianzi(QWidget *parent = 0);
    ~Form_dianzi();

private:
    Ui::Form_dianzi *ui;
    QPoint offset;                       // 用来储存鼠标指针位置与窗口位置的差值

protected:
    void paintEvent(QPaintEvent *);        //显示图片

    void mousePressEvent(QMouseEvent *event);  //鼠标左单击和右单击

    void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放事件

    void mouseMoveEvent(QMouseEvent *event); //鼠标移动


    void mouseDoubleClickEvent(QMouseEvent *event);  //鼠标双击
};

#endif // FORM_DIANZI_H