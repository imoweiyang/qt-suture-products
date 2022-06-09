#include "tetrixwindow.h"
#include <QtWidgets>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QObject>
#include <QPropertyAnimation>
#include "tetrixboard.h"


TetrixWindow::TetrixWindow(QWidget *parent) : QWidget(parent)
{

    board = new TetrixBoard;


    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    board->setNextPieceLabel(nextPieceLabel);


    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);

    levelLcd = new QLCDNumber(2);
    levelLcd->setSegmentStyle(QLCDNumber::Filled);
    linesLcd = new QLCDNumber(5);
    linesLcd->setSegmentStyle(QLCDNumber::Filled);


    startButton = new QPushButton(tr("&开始游戏"));  //开始按钮
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&退出游戏"));   //退出按钮
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&暂停游戏"));   //暂停按钮

    pauseButton->setFocusPolicy(Qt::NoFocus);


    connect(startButton, SIGNAL(clicked()), board, SLOT(start()));   //开始按钮点击事件

    connect(quitButton , SIGNAL(clicked()), this, SLOT(quit()));      //退出按钮点击事件
    connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));    //暂停事件
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));
    connect(board, SIGNAL(linesRemovedChanged(int)),
            linesLcd, SLOT(display(int)));


    //创建换肤按钮
    Skinpeeler=new QPushButton(tr("&换肤"));
    Skinpeeler->setFocusPolicy(Qt::NoFocus);
    connect(Skinpeeler,SIGNAL(clicked()),this,SLOT(skinpeeler()));




    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("下一个方块")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("提示：上键变形，空格键下降")), 1.5, 0);
    layout->addWidget(createLabel(tr("等级")), 2, 0);
    layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 4, 0);
    layout->addWidget(board, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("您获得分数")), 0, 2);
    layout->addWidget(scoreLcd, 1, 2);
    layout->addWidget(createLabel(tr("消除行数")), 2, 2);
    layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);
    layout->addWidget(Skinpeeler,5,0);    //换肤位置
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);
}


QLabel *TetrixWindow::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}

void TetrixWindow::paintEvent(QPaintEvent *)
{
    //设置背景图片
    this->setAutoFillBackground(true);  //不加可能显示不出背景图片
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(QString(":/image/image/beijing%1.jpg").arg(count)).scaled(
                                //缩放背景图
                                this->size(),
                                Qt::IgnoreAspectRatio,
                                Qt::SmoothTransformation)));  //使用平滑缩放方式
    this->setPalette(palette);   //给widget加上背景图

}

void TetrixWindow::skinpeeler()
{
    //点击一次更换下一个皮肤
    if(count == 1)
        count = 2;
    else if(count == 2)
       count = 3;
    else if(count == 3)
        count = 4;
    else
        count = 1;
    qDebug("okay");

}

void TetrixWindow::quit()
{
    close();   //关闭游戏窗口
}
