#include "digitslclock.h"
#include "ui_digitslclock.h"
#include <QtWidgets>

DigitslClock::DigitslClock(QWidget *parent) :
    QLCDNumber(parent),
    ui(new Ui::DigitslClock)
{
    ui->setupUi(this);

    setSegmentStyle(Filled);

    QTimer *timer = new QTimer(this);       //创建一个新的定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));//关联定时器的溢出信号到槽上
    timer->start(1000);                //设置溢出时间为1s，并启动定时器

    showTime();

    setWindowTitle(tr("电子时钟"));
    resize(150, 60);
}

DigitslClock::~DigitslClock()
{
    delete ui;
}

void DigitslClock::showTime()
{
    QTime time = QTime::currentTime();           //获取当前时间
    QString text = time.toString("hh:mm");     //转换为字符串
    if ((time.second() % 2) == 0)            //每隔一秒就将“：”显示为空格
        text[2] = ' ';
    display(text);
}
