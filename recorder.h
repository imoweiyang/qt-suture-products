#ifndef RECORDER_H
#define RECORDER_H

#include <QWidget>
class QAudioRecorder;

namespace Ui {
class Recorder;
}

class Recorder : public QWidget
{
    Q_OBJECT

public:
    explicit Recorder(QWidget *parent = 0);
    ~Recorder();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void updateProgress(qint64 duration);

private:
    Ui::Recorder *ui;
    QAudioRecorder *audioRecorder;
};

#endif // RECORDER_H
