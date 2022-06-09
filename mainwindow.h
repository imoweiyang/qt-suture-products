#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
class QErrorMessage;
#include <QWizard>
#include <QTextEdit>


#include "dialog.h"
#include "dialog1.h"
#include "dialog2.h"

class QLineEdit;
class QDialog;
class QPrinter;

class QFile;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_N_triggered();

    void on_action_O_triggered();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_11_triggered();

    void on_action_12_triggered();

    void on_action_13_triggered(bool checked);

    void on_action_14_triggered();

    void on_action_15_triggered();

    void on_action_16_triggered();

    void findNext();
    void on_action_17_triggered();
    void printPreview(QPrinter *printer);

    void on_action_18_triggered();

    void on_action_19_triggered();

    void on_action_20_triggered();

    void on_action_21_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_action1_triggered();

    void on_action_22_triggered();

    void on_action_23_triggered();

    void on_action_24_triggered();

    void on_action_25_triggered();

    void on_action_26_triggered();

    void on_action3D_triggered();

    void on_action_27_triggered();

    void on_action_28_triggered();

    void on_action_29_triggered();

    void on_action_30_triggered();

    void on_action_31_triggered();

    void on_action_32_triggered();

    void on_action_33_triggered();

protected:
    void mousePressEvent(QMouseEvent *event);      // 鼠标按下事件
    void dragEnterEvent(QDragEnterEvent *event);   // 拖动进入事件
    void dragMoveEvent(QDragMoveEvent *event);     // 拖动事件
    void dropEvent(QDropEvent *event);             // 放下事件


private:
    Ui::MainWindow *ui;
    QErrorMessage *errordlg;

    QLineEdit *lineEdit;
    QDialog *findDialog;

    Dialog  *dialog;
    Dialog1 *dialog1;
    Dialog2 *dialog2;


    QWizardPage *createPage1();        // 新添加
    QWizardPage *createPage2();        // 新添加
    QWizardPage *createPage3();        // 新添加

    QFile *qssFile;

};

#endif // MAINWINDOW_H
