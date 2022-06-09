#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>
class QTimer;

namespace Ui {
class ClockWidget;
}

class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClockWidget(QWidget *parent = 0);
    ~ClockWidget();

private:
    Ui::ClockWidget *ui;
    QTimer *timer;
    int angle;
    int i;

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // CLOCKWIDGET_H
