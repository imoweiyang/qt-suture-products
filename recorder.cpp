#include "recorder.h"
#include "ui_recorder.h"
#include <QAudioRecorder>
#include <QDebug>
#include <QFileDialog>

Recorder::Recorder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Recorder)
{
    ui->setupUi(this);

    audioRecorder = new QAudioRecorder;
    QStringList inputs = audioRecorder->audioInputs();
    ui->comboBox->addItems(inputs);

    connect(audioRecorder, &QAudioRecorder::durationChanged, this,
            &Recorder::updateProgress);

    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/pcm");
    audioSettings.setQuality(QMultimedia::HighQuality);
    audioRecorder->setAudioSettings(audioSettings);
}

Recorder::~Recorder()
{
    delete ui;
}

// 选择按钮
void Recorder::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName();
    ui->lineEdit->setText(fileName);
}

// 开始按钮
void Recorder::on_pushButton_2_clicked()
{
    audioRecorder->setAudioInput(ui->comboBox->currentText());
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(ui->lineEdit->text()));
    audioRecorder->record();
}

// 停止按钮
void Recorder::on_pushButton_4_clicked()
{
    audioRecorder->stop();
}

void Recorder::updateProgress(qint64 duration)
{
    if (audioRecorder->error() != QMediaRecorder::NoError || duration < 1000)
        return;

    setWindowTitle(tr("Recorded %1 sec").arg(duration / 1000));
}
