#ifndef FORM_GAME_H
#define FORM_GAME_H

#include <QWidget>

namespace Ui {
class Form_game;
}

class Form_game : public QWidget
{
    Q_OBJECT

public:
    explicit Form_game(QWidget *parent = 0);
    ~Form_game();

private:
    Ui::Form_game *ui;
    QPoint offset;                       // 用来储存鼠标指针位置与窗口位置的差值

protected:
    void paintEvent(QPaintEvent *);        //显示图片

    void mousePressEvent(QMouseEvent *event);  //鼠标左单击和右单击

    void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放事件

    void mouseMoveEvent(QMouseEvent *event); //鼠标移动


    void mouseDoubleClickEvent(QMouseEvent *event);  //鼠标双击
};

#endif // FORM_GAME_H
