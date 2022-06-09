#include "kuan.h"
#include "ui_kuan.h"
#include <QDebug>
#include <QCompleter>

kuan::kuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kuan)
{
    ui->setupUi(this);

    // 新建验证器，指定范围为100-999
    //  QValidator *validator = new QIntValidator(100, 999, this);

    QRegExp rx("-?\\d{1,3}");
    QValidator *validator = new QRegExpValidator(rx, this);

    // 在行编辑器中使用验证器
    ui->lineEdit3->setValidator(validator);


    QStringList wordList;
    wordList << "Qt" << "Qt Creator" << tr("你好");
    QCompleter *completer = new QCompleter(wordList, this);   // 新建自动完成器
    completer->setCaseSensitivity(Qt::CaseInsensitive);       // 设置大小写不敏感
    ui->lineEdit4->setCompleter(completer);
}

kuan::~kuan()
{
    delete ui;
}

void kuan::on_lineEdit2_returnPressed()
{
    ui->lineEdit3->setFocus();                    // 让lineEdit3获得焦点
    qDebug() << ui->lineEdit2->text();            // 输出lineEdit2的内容
    qDebug() << ui->lineEdit2->displayText();     // 输出lineEdit2显示的内容
}

void kuan::on_lineEdit3_returnPressed()
{
    qDebug() << ui->lineEdit3->text();
}
