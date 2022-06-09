#ifndef SOUND_H
#define SOUND_H

#include <QWidget>
class QSoundEffect;

namespace Ui {
class sound;
}

class sound : public QWidget
{
    Q_OBJECT

public:
    explicit sound(QWidget *parent = 0);
    ~sound();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::sound *ui;
    QSoundEffect *effect;
};

#endif // SOUND_H
