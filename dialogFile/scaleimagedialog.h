#ifndef SCALEIMAGEDIALOG_H
#define SCALEIMAGEDIALOG_H

#include <QDialog>
#include "mainwindowatt.h"
namespace Ui {
class ScaleimageDialog;
}

class ScaleimageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScaleimageDialog(MainWindowAtt* m,QWidget *parent = nullptr);
    ~ScaleimageDialog();
    void init();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_timesNumber_valueChanged(int arg1);

    void on_scaleImageNumber_valueChanged(int value);

private:
    Ui::ScaleimageDialog *ui;
    MainWindowAtt* matt;
    DomScaleImage* sDom;
    DomScaleImage sDomBackups;
};

#endif // SCALEIMAGEDIALOG_H
