#include "initwidget.h"
#include "ui_initwidget.h"
#include <QBitmap>
#include <QMouseEvent>
#include <QPainter>
#include <qDebug>
#include <QPixmap>

#include <QStandardPaths>
#include <QDir>
#include <QMimeDatabase>
#include <QImageReader>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>

InitWidget::InitWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InitWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    setMouseTracking(true);
    img=":/images/logo.jpg";
    QPixmap pix;
    pix.load(img);
    //QBitmap bg(":/image/image/hd.jpg");
    resize(pix.size());

    QCursor cursor;                      // 创建光标对象
    cursor.setShape(Qt::OpenHandCursor); // 设置光标形状
    setCursor(cursor);                   // 使用光标
}

InitWidget::~InitWidget()
{
    delete ui;
}

void InitWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix=QPixmap(img);
    setMask(pix.mask());
    update();
    painter.drawPixmap(0,0,pix);
}

void InitWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {

        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor); // 使鼠标指针暂时改变形状

        offset=event->globalPos()-pos();   //globalPos()获取根窗口的相对路径，frameGeometry().topLeft()获取主窗口左上角的位置

    }
    else if(event->button()==Qt::RightButton)
    {
        close();
    }
}

void InitWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        QPoint temp;
        temp=event->globalPos()-offset;
        move(temp);
    }
    QPoint p1=this->pos();
    QPoint p2=event->globalPos();
    int xp=p2.x()-p1.x();
    int yp=p2.y()-p1.y();
    if(xp>0 && yp>0 && xp<64 && yp<64){
        if(img!=":/images/logo2.jpg"){
            img=":/images/logo2.jpg";
            this->repaint();
            qDebug()<<xp<<yp;
        }
        else{
            img=":/images/logo2.jpg";
        }
    }
    else{
        if(img!=":/images/logo.jpg"){
            img=":/images/logo.jpg";
            this->repaint();
            qDebug()<<xp<<yp;
        }
        else{
            img=":/images/logo.jpg";
    }
    }
}

void InitWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();
}

void InitWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
     if(event->button()==Qt::LeftButton)
     {
         if(img==":/images/logo.jpg"){
             //close();
             qDebug()<<"dong dong dong";
             wg=new Widget1();
             wg->show();

         }else{
             //close();
             qDebug()<<"miao~";

             QQuickView *view=new QQuickView;
             view->setSource(QUrl(QStringLiteral("qrc:///photosurface.qml")));

//             QQuickWindow::setDefaultAlphaBuffer(true);
//             QQmlApplicationEngine engine(QUrl("qrc:///photosurface.qml"));
             //dealWithQQuickView(view);
             //view->setSource(QUrl(QStringLiteral("qrc:///photosurface.qml")));
         }
         //close();
     }
}

QStringList InitWidget::imageNameFilters()
{
    QStringList result;
    QMimeDatabase mimeDatabase;
    foreach (const QByteArray &m, QImageReader::supportedMimeTypes()) {
        foreach (const QString &suffix, mimeDatabase.mimeTypeForName(m).suffixes()) {
            result.append(QStringLiteral("*.") + suffix);
        }
    }
    return result;
}

void InitWidget::dealWithQQuickView(QQuickView *view)
{
     const QStringList nameFilters = imageNameFilters();
     const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);

     view->rootContext()->setContextProperty(QStringLiteral("contextPicturesLocation"), picturesLocations);
     view->rootContext()->setContextProperty(QStringLiteral("contextInitialUrl"), QUrl("qrc:///photosurface.qml"));
     view->rootContext()->setContextProperty(QStringLiteral("contextImageNameFilters"), nameFilters);

}
