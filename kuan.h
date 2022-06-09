#ifndef KUAN_H
#define KUAN_H

#include <QWidget>

namespace Ui {
class kuan;
}

class kuan : public QWidget
{
    Q_OBJECT

public:
    explicit kuan(QWidget *parent = 0);
    ~kuan();

private slots:
    void on_lineEdit2_returnPressed();

    void on_lineEdit3_returnPressed();

private:
    Ui::kuan *ui;

};

#endif // KUAN_H
