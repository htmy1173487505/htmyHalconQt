#ifndef CREATESCALEDSHAPEMODELDIALOG_H
#define CREATESCALEDSHAPEMODELDIALOG_H

#include <QDialog>
#include "mainwindowatt.h"

namespace Ui {
class CreateScaledShapeModelDialog;
}

class CreateScaledShapeModelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateScaledShapeModelDialog(MainWindowAtt* m,QWidget *parent = nullptr);
    ~CreateScaledShapeModelDialog();
    void init();
    void updateImage();
    void action();

private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_comboBox_4_currentIndexChanged(int index);

    void on_comboBox_5_currentIndexChanged(int index);

    void on_comboBox_7_currentIndexChanged(int index);

    void on_comboBox_6_currentIndexChanged(int index);

    void on_comboBox_8_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreateScaledShapeModelDialog *ui;
    MainWindowAtt* matt;
    DomCreateScaledShapeModel* cssmDom;
    DomCreateScaledShapeModel cssmDomBackups;
};

#endif // CREATESCALEDSHAPEMODELDIALOG_H
