#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;


namespace Ui {
class Camera;
}

class Camera : public QWidget
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Camera *ui;

    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
};

#endif // CAMERA_H
