#ifndef OPENINGDIALOG_H
#define OPENINGDIALOG_H

#include <QDialog>
#include "mainwindowatt.h"
namespace Ui {
class OpeningDialog;
}

class OpeningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpeningDialog(MainWindowAtt* m,QWidget *parent = nullptr);
    ~OpeningDialog();
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
    Ui::OpeningDialog *ui;
    MainWindowAtt* matt;
    DomOpening* oDom;
    DomOpening oDomBackups;
};

#endif // OPENINGDIALOG_H
