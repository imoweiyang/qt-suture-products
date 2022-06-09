#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include <QToolButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QLabel>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>
#include <QTextFrame>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QFileInfo>

#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPainter>
#include <QMimeData>
#include <QDrag>

#include <QFile>

#include "tetrixwindow.h"
#include "mainwidget.h"
#include "initwidget.h"
#include "digitslclock.h"
#include "clockwidget.h"
#include "camera.h"
#include "recorder.h"
#include "vedio.h"
#include "sound.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    errordlg=new QErrorMessage(this);

    QTextDocument *document = ui->textEdit->document();   // 获取文档对象
    QTextFrame *rootFrame = document->rootFrame();        // 获取根框架
    QTextFrameFormat format;                              // 创建框架格式
    format.setBorderBrush(Qt::red);                       // 边界颜色
    format.setBorder(3);                                  // 边界宽度
    rootFrame->setFrameFormat(format);                    // 框架使用格式

    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::lightGray);                  // 设置背景颜色
    frameFormat.setMargin(10);                                 // 设置边距
    frameFormat.setPadding(5);                                 // 设置填衬
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted); // 设置边框样式
    QTextCursor cursor = ui->textEdit->textCursor();                  // 获取光标
    cursor.insertFrame(frameFormat);                                  // 在光标处插入框架

    findDialog = new QDialog(this);         // 创建对话框
    lineEdit = new QLineEdit(findDialog);            // 创建行编辑器
    QPushButton *btn = new QPushButton(findDialog);  // 创建按钮
    btn->setText(tr("查找下一个"));
    connect(btn, &QPushButton::clicked, this, &MainWindow::findNext); // 关联信号和槽
    QVBoxLayout *layout = new QVBoxLayout;    // 创建垂直布局管理器
    layout->addWidget(lineEdit);              // 添加部件
    layout->addWidget(btn);
    findDialog->setLayout(layout);                   // 在对话框中使用布局管理器

    qssFile = new QFile(":/qss/my.qss", this);
    // 只读方式打开该文件
    qssFile->open(QFile::ReadOnly);
    // 读取文件全部内容，使用tr()函数将其转换为QString类型
    QString styleSheet = tr(qssFile->readAll());
    // 为QApplication设置样式表
    qApp->setStyleSheet(styleSheet);
    qssFile->close();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_N_triggered()
{
    // 新建文本编辑器部件
    QTextEdit *edit = new QTextEdit(this);
    // 使用QMdiArea类的addSubWindow()函数创建子窗口，以文本编辑器为中心部件
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();

}

void MainWindow::on_action_O_triggered()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("文件对话框"),
                                                              "D:", tr("图片文件(*png *jpg)"));
    qDebug()<< "fileNames:" << fileNames;
}

void MainWindow::on_action_triggered()
{
    QColorDialog dialog(Qt::red, this);                // 创建对象
    dialog.setOption(QColorDialog::ShowAlphaChannel); // 显示alpha选项
    dialog.exec();                                    // 以模态方式运行对话框
    QColor color = dialog.currentColor();             // 获取当前颜色
    qDebug() << "color: " << color;
}

void MainWindow::on_action_2_triggered()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("文件对话框"),
                                                              "D:", tr("图片文件(*png *jpg)"));
    qDebug()<< "fileNames:" << fileNames;
}

void MainWindow::on_action_3_triggered()
{
    // ok用于标记是否按下了“OK”按钮
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);

    // 如果按下“OK”按钮，那么让“字体对话框”按钮使用新字体
    // 如果按下“Cancel”按钮，那么输出信息

    //if (ok) ui->pushButton_3->setFont(font);
    //else
        qDebug() << tr("没有选择字体！");
}

void MainWindow::on_action_4_triggered()
{
    bool ok;
    // 获取字符串
    QString string = QInputDialog::getText(this, tr("输入字符串对话框"),
                                           tr("请输入用户名："), QLineEdit::Normal,tr("admin"), &ok);
    if(ok) qDebug() << "string:" << string;
    // 获取整数
    int value1 = QInputDialog::getInt(this, tr("输入整数对话框"),
                                      tr("请输入-1000到1000之间的数值"), 100, -1000, 1000, 10, &ok);
    if(ok) qDebug() << "value1:" << value1;
    // 获取浮点数
    double value2 = QInputDialog::getDouble(this, tr("输入浮点数对话框"),
                                            tr("请输入-1000到1000之间的数值"), 0.00, -1000, 1000, 2, &ok);
    if(ok) qDebug() << "value2:" << value2;
    QStringList items;
    items << tr("条目1") << tr("条目2");
    // 获取条目
    QString item = QInputDialog::getItem(this, tr("输入条目对话框"),
                                         tr("请选择或输入一个条目"), items, 0, true, &ok);
    if(ok) qDebug() << "item:" << item;
}

void MainWindow::on_action_5_triggered()
{
    // 问题对话框
    int ret1 = QMessageBox::question(this, tr("问题对话框"),
                                     tr("你了解Qt吗？"), QMessageBox::Yes, QMessageBox::No);
    if(ret1 == QMessageBox::Yes) qDebug() << tr("问题！");
    // 提示对话框
    int ret2 = QMessageBox::information(this, tr("提示对话框"),
                                        tr("这是Qt书籍！"), QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok) qDebug() << tr("提示！");
    // 警告对话框
    int ret3 = QMessageBox::warning(this, tr("警告对话框"),
                                    tr("不能提前结束！"), QMessageBox::Abort);
    if(ret3 == QMessageBox::Abort) qDebug() << tr("警告！");
    // 错误对话框
    int ret4 = QMessageBox::critical(this, tr("严重错误对话框"),
                                     tr("发现一个严重错误！现在要关闭所有文件！"), QMessageBox::YesAll);
    if(ret4 == QMessageBox::YesAll) qDebug() << tr("错误");
    // 关于对话框
    QMessageBox::about(this, tr("关于对话框"),
                       tr("yafeilinux致力于Qt及Qt Creator的普及工作！"));
}

void MainWindow::on_action_6_triggered()
{
    QProgressDialog dialog(tr("文件复制进度"), tr("取消"), 0, 50000, this);
        dialog.setWindowTitle(tr("进度对话框"));     // 设置窗口标题
        dialog.setWindowModality(Qt::WindowModal);  // 将对话框设置为模态
        dialog.show();
        for(int i=0; i<50000; i++) {                // 演示复制进度
            dialog.setValue(i);                     // 设置进度条的当前值
            QCoreApplication::processEvents();      // 避免界面冻结
            if(dialog.wasCanceled()) break;         // 按下取消按钮则中断
        }
        dialog.setValue(50000);    // 这样才能显示100%，因为for循环中少加了一个数
        qDebug() << tr("复制结束！");
}

QWizardPage * MainWindow::createPage1()  // 向导页面1
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("介绍"));
    return page;
}
QWizardPage * MainWindow::createPage2()  // 向导页面2
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("用户选择信息"));
    return page;
}
QWizardPage * MainWindow::createPage3()  // 向导页面3
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}

void MainWindow::on_action_7_triggered()
{
    errordlg->setWindowTitle(tr("错误信息对话框"));
    errordlg->showMessage(tr("这里是出错信息！"));
}

void MainWindow::on_action_8_triggered()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(createPage1());     // 添加向导页面
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}





void MainWindow::on_action_11_triggered()
{
    QTextDocument *document = ui->textEdit->document();
    QTextFrame *frame = document->rootFrame();
    QTextFrame::iterator it;                          // 建立QTextFrame类的迭代器
    for (it = frame->begin(); !(it.atEnd()); ++it) {
        QTextFrame *childFrame = it.currentFrame();  // 获取当前框架的指针
        QTextBlock childBlock = it.currentBlock();   // 获取当前文本块
        if (childFrame)
            qDebug() << "frame";
        else if (childBlock.isValid())
            qDebug() << "block:" << childBlock.text();
    }
}

void MainWindow::on_action_12_triggered()
{
    QTextDocument *document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();         // 获取文档的第一个文本块
    for (int i = 0; i < document->blockCount(); i++) {
        qDebug() << tr("文本块%1，文本块首行行号为:%2，长度为:%3,内容为：")
                    .arg(i).arg(block.firstLineNumber()).arg(block.length())
                 << block.text();
        block = block.next();                         // 获取下一个文本块
    }
}

void MainWindow::on_action_13_triggered(bool checked)
{
    if(checked){                                   // 如果处于选中状态
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextBlockFormat blockFormat;              // 文本块格式
        blockFormat.setAlignment(Qt::AlignCenter); // 水平居中
        cursor.insertBlock(blockFormat);           // 使用文本块格式
        QTextCharFormat charFormat;                // 字符格式
        charFormat.setBackground(Qt::lightGray);   // 背景色
        charFormat.setForeground(Qt::blue);        // 字体颜色
        // 使用宋体，12号，加粗，倾斜
        charFormat.setFont(QFont(tr("宋体"), 12, QFont::Bold, true));
        charFormat.setFontUnderline(true);         // 使用下划线
        cursor.setCharFormat(charFormat);          // 使用字符格式
        cursor.insertText(tr("测试字体"));         // 插入文本
    }
    else{/*恢复默认的字体格式*/}        // 如果处于非选中状态，可以进行其他操作
}

void MainWindow::on_action_14_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;          // 表格格式
    format.setCellSpacing(2);         // 表格外边白
    format.setCellPadding(10);        // 表格内边白
    cursor.insertTable(2, 2, format); // 插入2行2列表格
}

void MainWindow::on_action_15_triggered()
{
    QTextListFormat format;           // 列表格式
    format.setStyle(QTextListFormat::ListDecimal);   // 数字编号
    ui->textEdit->textCursor().insertList(format);
}

void MainWindow::on_action_16_triggered()
{
    QTextImageFormat format;          // 图片格式
    format.setName(":/image/image/add.jpg");       // 图片路径
    ui->textEdit->textCursor().insertImage(format);
}

void MainWindow::on_action_17_triggered()
{
    findDialog->show();
}

void MainWindow::findNext()     // 查找下一个
{
    QString string = lineEdit->text();
    // 使用查找函数查找指定字符串，查找方式为向后查找
    bool isfind = ui->textEdit->find(string, QTextDocument::FindBackward);
    if(isfind){                // 如果查找成功，输出字符串所在行和列的编号
        qDebug() << tr("行号:%1 列号:%2")
                    .arg(ui->textEdit->textCursor().blockNumber())
                    .arg(ui->textEdit->textCursor().columnNumber());
    }
}

void MainWindow::on_action_18_triggered()
{
    QPrinter printer;                         // 创建打印机对象
    QPrintDialog dlg(&printer, this);         // 创建打印对话框
    // 如果编辑器中有选中区域，则打印选中区域
    if (ui->textEdit->textCursor().hasSelection())
        dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (dlg.exec() == QDialog::Accepted) {    // 如果在对话框中按下了打印按钮
        ui->textEdit->print(&printer);        // 则执行打印操作
    }
}

void MainWindow::on_action_19_triggered()
{
    QPrinter printer;
    QPrintPreviewDialog preview(&printer, this);     // 创建打印预览对话框
    // 当要生成预览页面时，发射paintRequested()信号
    connect(&preview, &QPrintPreviewDialog::paintRequested,
            this, &MainWindow::printPreview);
    preview.exec();
}

void MainWindow::printPreview(QPrinter *printer)
{
    ui->textEdit->print(printer);
}

void MainWindow::on_action_20_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("导出PDF文件"),
                                                    QString(), "*.pdf");
    if (!fileName.isEmpty()) {
        if (QFileInfo(fileName).suffix().isEmpty())
            fileName.append(".pdf");        // 如果文件后缀为空，则默认使用.pdf
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);    // 指定输出格式为pdf
        printer.setOutputFileName(fileName);
        ui->textEdit->print(&printer);
    }
}

void MainWindow::on_action_21_triggered()
{
    setAcceptDrops(true);                      // 设置窗口部件可以接收拖入
    QLabel *label = new QLabel(this);          // 创建标签
    QPixmap pix(":/image/image/add.jpg");
    label->setPixmap(pix);                     // 添加图片
    label->resize(pix.size());                 // 设置标签大小为图片的大小
    label->move(30,30);
    label->setAttribute(Qt::WA_DeleteOnClose); // 当窗口关闭时销毁图片
    label->show();
}

void MainWindow::mousePressEvent(QMouseEvent *event)   //鼠标按下事件
{
    // 第一步：获取图片
    // 将鼠标指针所在位置的部件强制转换为QLabel类型
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if(!child->inherits("QLabel")) return; // 如果部件不是QLabel则直接返回
    QPixmap pixmap = *child->pixmap();     // 获取QLabel中的图片

    // 第二步：自定义MIME类型
    QByteArray itemData;                                     // 创建字节数组
    QDataStream dataStream(&itemData, QIODevice::WriteOnly); // 创建数据流
    // 将图片信息，位置信息输入到字节数组中
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    // 第三步：将数据放入QMimeData中
    QMimeData *mimeData = new QMimeData;  // 创建QMimeData用来存放要移动的数据
    // 将字节数组放入QMimeData中，这里的MIME类型是我们自己定义的
    mimeData->setData("myimage/png", itemData);

    // 第四步：将QMimeData数据放入QDrag中
    QDrag *drag = new QDrag(this);      // 创建QDrag，它用来移动数据
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);//在移动过程中显示图片，若不设置则默认显示一个小矩形
    drag->setHotSpot(event->pos() - child->pos()); // 拖动时鼠标指针的位置不变

    // 第五步：给原图片添加阴影
    QPixmap tempPixmap = pixmap; // 使原图片添加阴影
    QPainter painter;            // 创建QPainter，用来绘制QPixmap
    painter.begin(&tempPixmap);
    // 在图片的外接矩形中添加一层透明的淡黑色形成阴影效果
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();
    child->setPixmap(tempPixmap); // 在移动图片过程中，让原图片添加一层黑色阴影

    // 第六步：执行拖放操作
    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction)
            == Qt::MoveAction)  // 设置拖放可以是移动和复制操作，默认是复制操作
        child->close();         // 如果是移动操作，那么拖放完成后关闭原标签
    else {
        child->show();            // 如果是复制操作，那么拖放完成后显示标签
        child->setPixmap(pixmap); // 显示原图片，不再使用阴影
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) // 拖动进入事件
{
      // 如果有我们定义的MIME类型数据，则进行移动操作
     if (event->mimeData()->hasFormat("myimage/png")) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
     } else {
         event->ignore();
     }
}
void MainWindow::dragMoveEvent(QDragMoveEvent *event)   // 拖动事件
{
     if (event->mimeData()->hasFormat("myimage/png")) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
     } else {
         event->ignore();
     }
}

void MainWindow::dropEvent(QDropEvent *event) // 放下事件
{
    if (event->mimeData()->hasFormat("myimage/png")) {
         QByteArray itemData = event->mimeData()->data("myimage/png");
         QDataStream dataStream(&itemData, QIODevice::ReadOnly);
         QPixmap pixmap;
         QPoint offset;
         // 使用数据流将字节数组中的数据读入到QPixmap和QPoint变量中
         dataStream >> pixmap >> offset;
         // 新建标签，为其添加图片，并根据图片大小设置标签的大小
         QLabel *newLabel = new QLabel(this);
         newLabel->setPixmap(pixmap);
         newLabel->resize(pixmap.size());
   // 让图片移动到放下的位置，不设置的话，图片会默认显示在(0,0)点即窗口左上角
         newLabel->move(event->pos() - offset);
         newLabel->show();
         newLabel->setAttribute(Qt::WA_DeleteOnClose);
         event->setDropAction(Qt::MoveAction);
         event->accept();
     } else {
         event->ignore();
     }
}


//重新登录返回界面
void MainWindow::on_pushButton_clicked()
{
    close();
    LoginDialog lg;
    if(lg.exec()==QDialog::Accepted)
        show();
}

//直接退出界面
void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_action1_triggered()
{
    if(qssFile->fileName() == ":/qss/my.qss")
            qssFile->setFileName(":/qss/my1.qss");    //转换到my1.qss
        else if(qssFile->fileName() == ":/qss/my1.qss")
            qssFile->setFileName(":/qss/my2.qss");      //转换到my2.qss
        else if(qssFile->fileName() == ":/qss/my2.qss")
            qssFile->setFileName(":/qss/my3.qss");       //转换到my3.qss
        else if(qssFile->fileName() == ":/qss/my3.qss")
            qssFile->setFileName(":/qss/my.qss");        //转换到my.qss
        else qssFile->setFileName(":/qss/my.qss");     //默认样式my.qss

        qssFile->open(QFile::ReadOnly);
        QString styleSheet = tr(qssFile->readAll());
        qApp->setStyleSheet(styleSheet);
        qssFile->close();
}

void MainWindow::on_action_22_triggered()
{
    dialog1=new Dialog1(this);
    dialog1->setModal(this);
    dialog1->show();
}

void MainWindow::on_action_23_triggered()
{
    dialog=new Dialog(this);
    dialog->setModal(this);
    dialog->show();
}

void MainWindow::on_action_24_triggered()
{
    dialog2=new Dialog2(this);
    dialog2->setModal(this);
    dialog2->show();
}

void MainWindow::on_action_25_triggered()
{
    TetrixWindow *t=new TetrixWindow();
    t->show();
}

void MainWindow::on_action3D_triggered()
{
    MainWidget *m=new MainWidget();
            m->show();
}

void MainWindow::on_action_27_triggered()
{
    InitWidget *time=new InitWidget();
            time->show();
}

void MainWindow::on_action_28_triggered()
{
    DigitslClock *d=new DigitslClock();
           d->show();
}

void MainWindow::on_action_29_triggered()
{
    ClockWidget *c=new ClockWidget();
           c->show();
}

void MainWindow::on_action_30_triggered()
{
    Camera *b=new Camera();
            b->show();
}

void MainWindow::on_action_31_triggered()
{
    Recorder *w=new Recorder();
            w->show();
}

void MainWindow::on_action_33_triggered()
{
    sound *l=new sound();
            l->show();
}
