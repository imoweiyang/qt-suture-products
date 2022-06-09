#ifndef VEDIO_H
#define VEDIO_H

#include <QWidget>
class QMediaPlayer;
class QVideoWidget;

namespace Ui {
class vedio;
}

class vedio : public QWidget
{
    Q_OBJECT

public:
    explicit vedio(QWidget *parent = 0);
    ~vedio();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vedio *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};

#endif // VEDIO_H
