#ifndef FORM_CAMERA_H
#define FORM_CAMERA_H

#include <QWidget>

namespace Ui {
class Form_camera;
}

class Form_camera : public QWidget
{
    Q_OBJECT

public:
    explicit Form_camera(QWidget *parent = 0);
    ~Form_camera();

private:
    Ui::Form_camera *ui;
    QPoint offset;                       // 用来储存鼠标指针位置与窗口位置的差值

protected:
    void paintEvent(QPaintEvent *);        //显示图片

    void mousePressEvent(QMouseEvent *event);  //鼠标左单击和右单击

    void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放事件

    void mouseMoveEvent(QMouseEvent *event); //鼠标移动


    void mouseDoubleClickEvent(QMouseEvent *event);  //鼠标双击
};

#endif // FORM_CAMERA_H
