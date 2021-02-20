#ifndef CLOSIONGDIALOG_H
#define CLOSIONGDIALOG_H

#include <QDialog>
#include "mainwindowatt.h"
namespace Ui {
class ClosiongDialog;
}

class ClosiongDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClosiongDialog(MainWindowAtt * m,QWidget *parent = nullptr);
    ~ClosiongDialog();
    void init();
    void updateImage();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ClosiongDialog *ui;
    MainWindowAtt* matt;
    DomClosing* cDom;
    DomClosing cDomBackups;
};

#endif // CLOSIONGDIALOG_H
