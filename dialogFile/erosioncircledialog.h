#ifndef EROSIONCIRCLEDIALOG_H
#define EROSIONCIRCLEDIALOG_H

#include <QDialog>
#include "mainwindowatt.h"
namespace Ui {
class ErosionCircleDialog;
}

class ErosionCircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ErosionCircleDialog(MainWindowAtt* m,QWidget *parent = nullptr);
    ~ErosionCircleDialog();
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
    Ui::ErosionCircleDialog *ui;
    MainWindowAtt* matt;
    DomErosionCircle* ecDom;
    DomErosionCircle ecDomBackups;
};

#endif // EROSIONCIRCLEDIALOG_H
