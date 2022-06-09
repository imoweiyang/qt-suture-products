#include "vedio.h"
#include "ui_vedio.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QMessageBox>

vedio::vedio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vedio)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    videoWidget->resize(600, 300);
    player->setVideoOutput(videoWidget);
    player->setMedia(QUrl("qrc:/image/image/video.wmv"));
    player->play();
    // 亮度
    ui->brightnessSlider->setValue(videoWidget->brightness());
    connect(ui->brightnessSlider, &QSlider::sliderMoved,
            videoWidget, &QVideoWidget::setBrightness);
    connect(videoWidget, &QVideoWidget::brightnessChanged,
            ui->brightnessSlider, &QSlider::setValue);
    // 对比度
    ui->contrastSlider->setValue(videoWidget->contrast());
    connect(ui->contrastSlider, &QSlider::sliderMoved,
            videoWidget, &QVideoWidget::setContrast);
    connect(videoWidget, &QVideoWidget::contrastChanged,
            ui->contrastSlider, &QSlider::setValue);
    // 色相
    ui->hueSlider->setValue(videoWidget->hue());
    connect(ui->hueSlider, &QSlider::sliderMoved,
            videoWidget, &QVideoWidget::setHue);
    connect(videoWidget, &QVideoWidget::hueChanged,
            ui->hueSlider, &QSlider::setValue);
    // 饱和度
    ui->saturationSlider->setValue(videoWidget->saturation());
    connect(ui->saturationSlider, &QSlider::sliderMoved,
            videoWidget, &QVideoWidget::setSaturation);
    connect(videoWidget, &QVideoWidget::saturationChanged,
            ui->saturationSlider, &QSlider::setValue);
}

vedio::~vedio()
{
    delete ui;
}

void vedio::on_pushButton_clicked()
{
    QString s = QFileDialog::getOpenFileName(
                    this,"选择播放文件",
                    "/",
                    "视频文件（*.*）;;");
        player->setMedia(QUrl::fromLocalFile(s));
        player->play();
}
