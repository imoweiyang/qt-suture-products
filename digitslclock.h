#ifndef DIGITSLCLOCK_H
#define DIGITSLCLOCK_H

#include <QLCDNumber>

namespace Ui {
class DigitslClock;
}

class DigitslClock : public QLCDNumber
{
    Q_OBJECT

public:
    explicit DigitslClock(QWidget *parent = 0);
    ~DigitslClock();

private:
    Ui::DigitslClock *ui;

private slots:
    void showTime();
};

#endif // DIGITSLCLOCK_H
