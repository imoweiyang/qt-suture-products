#ifndef TETRIXWINDOW_H
#define TETRIXWINDOW_H

#include <QWidget>
#include <QFrame>

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
QT_END_NAMESPACE
class TetrixBoard;


class TetrixWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TetrixWindow(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *createLabel(const QString &text);

    TetrixBoard *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;

    QPushButton *Skinpeeler;  //换肤按钮
    int count=1;  //皮肤图片后缀名称


   protected slots:
    void skinpeeler();             //更换皮肤图片事件
    void paintEvent(QPaintEvent *);    //皮肤事件
    void quit(); //仅关闭游戏
};

#endif // TETRIXWINDOW_H
