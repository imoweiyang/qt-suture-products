#include "clockwidget.h"
#include "ui_clockwidget.h"
#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>
#include <QTimer>
#include <QPoint>
#include <QTime>

ClockWidget::ClockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClockWidget)
{
    ui->setupUi(this);

    setMouseTracking(true);

        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);
        angle = 0;

       setWindowTitle(tr("时钟"));
    resize(400,400);
}

ClockWidget::~ClockWidget()
{
    delete ui;
}

void ClockWidget::paintEvent(QPaintEvent *)
{
    angle += 10;
    if(angle == 360)
        angle = 0;
    int side = qMin(width(), height());

    static const QPoint hourHand[3] = {   //时针
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -60)
    };
    static const QPoint minuteHand[3] = {  //分针
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };

    static const QPoint secondHand[3] = {  //秒针
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -90)
    };

    //设置样式
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(0, 0, 0, 150);

    QRect* rect=new QRect(-30,-90,60,20);

     QTime time = QTime::currentTime();    //获取当前时间
     QPainter painter(this);

     painter.setRenderHint(QPainter::Antialiasing);
     QTransform transform;
     transform.translate(width() / 2, height() / 2);
     transform.scale(side / 300.0, side / 300.0);
     painter.translate(200,200);     //圆心位置


     painter.setBrush(hourColor);

     painter.save();
     painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
     painter.drawConvexPolygon(hourHand, 3);
     painter.restore();

     painter.setPen(hourColor);

     for (int i = 1; i < 13; ++i) {          //时钟&时刻显示
         painter.drawLine(88, 0, 96, 0);
         painter.rotate(30.0);

         transform.rotate(30);
         painter.setTransform(transform);
         //绘制数字刻度，垂直最上，水平居中
         painter.drawText(*rect,Qt::AlignHCenter,QString::number(i));
         //绘制线条刻度
         painter.drawLine(0,-100,0,-92);
     }


     painter.setBrush(minuteColor);

     painter.save();
     painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
     painter.drawConvexPolygon(minuteHand, 3);
     painter.restore();

     painter.setPen(minuteColor);

     for (int j = 0; j < 60; ++j) {   //分针设置
         if ((j % 5) != 0)
             painter.drawLine(92, 0, 96, 0);
         painter.rotate(30.0);
     }


     painter.setBrush(secondColor);

     painter.save();
     painter.rotate(time.minute()*60.0+time.second());
     painter.drawConvexPolygon(secondHand, 3);
     painter.restore();

     painter.setPen(secondColor);


     for(int k=0;k<360;k++){    //秒针设置
         if((k%5)!=0)
             painter.drawLine(95,0,96,0);
         painter.rotate(6.0/5.0);
     }

}

void ClockWidget::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);
}
