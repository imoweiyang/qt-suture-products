#include "sound.h"
#include "ui_sound.h"
#include <QSoundEffect>

sound::sound(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sound)
{
    ui->setupUi(this);

    effect = new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile(":/image/image/sound.wav"));
    effect->setVolume(0.25f);
}

sound::~sound()
{
    delete ui;
}

// 播放按钮
void sound::on_pushButton_clicked()
{
    effect->play();
}
// 停止按钮
void sound::on_pushButton_2_clicked()
{
    effect->stop();
}

void sound::on_spinBox_valueChanged(int arg1)
{
    effect->setLoopCount(arg1);
}
