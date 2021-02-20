#ifndef DILATIONDIALOG_H
#define DILATIONDIALOG_H

#include <QDialog>
#include "mainwindowatt.h"
namespace Ui {
class DilationDialog;
}

class DilationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DilationDialog(MainWindowAtt* m,QWidget *parent = nullptr);
    ~DilationDialog();
    void init();
    void updateImage();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DilationDialog *ui;
    MainWindowAtt* matt;
    DomDilation* dDom;
    DomDilation dDomBackups;
};

#endif // DILATIONDIALOG_H
