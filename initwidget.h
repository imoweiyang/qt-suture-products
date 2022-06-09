#ifndef INITWIDGET_H
#define INITWIDGET_H
#include "widget1.h"
#include <QWidget>
#include <QQuickView>
#include <QWidget>


namespace Ui {
class InitWidget;
}

class InitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InitWidget(QWidget *parent = 0);
    ~InitWidget();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

    QStringList imageNameFilters();
    void dealWithQQuickView(QQuickView *view);

private:
    Ui::InitWidget *ui;
    QString img;
    QPoint offset;
    Widget1 *wg;
};

#endif // INITWIDGET_H
