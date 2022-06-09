#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QCompleter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // 新建验证器，指定范围为100-999
    //  QValidator *validator = new QIntValidator(100, 999, this);

    QRegExp rx("-?\\d{1,3}");
    QValidator *validator = new QRegExpValidator(rx, this);

    // 在行编辑器中使用验证器
    ui->lineEdit_3->setValidator(validator);


    QStringList wordList;
    wordList << "Qt" << "Qt Creator" << tr("你好");
    QCompleter *completer = new QCompleter(wordList, this);   // 新建自动完成器
    completer->setCaseSensitivity(Qt::CaseInsensitive);       // 设置大小写不敏感
    ui->lineEdit_4->setCompleter(completer);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_2_returnPressed()
{
    ui->lineEdit_3->setFocus();                    // 让lineEdit3获得焦点
    qDebug() << ui->lineEdit_2->text();            // 输出lineEdit2的内容
    qDebug() << ui->lineEdit_2->displayText();     // 输出lineEdit2显示的内容
}

void Dialog::on_lineEdit_3_returnPressed()
{
    qDebug() << ui->lineEdit_3->text();
}
