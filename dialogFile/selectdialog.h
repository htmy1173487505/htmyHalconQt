#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>
#include "mainwindowatt.h"
namespace Ui {
class SelectDialog;
}

class SelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDialog(MainWindowAtt * m,QWidget *parent = nullptr);
    ~SelectDialog();
    void init();
    void updateImage();

private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_selectMin_valueChanged(int value);

    void on_selectMax_valueChanged(int value);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SelectDialog *ui;
    MainWindowAtt * matt;
    DomSelectShape* ssDom;
    DomSelectShape ssDomBackups;
};

#endif // SELECTDIALOG_H
