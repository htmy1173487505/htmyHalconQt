#ifndef THRESHOLDDIALOG_H
#define THRESHOLDDIALOG_H

#include <QDialog>
#include"mainwindowatt.h"
namespace Ui {
class ThresholdDialog;
}

class ThresholdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThresholdDialog(MainWindowAtt* m,QWidget *parent = nullptr);
    ~ThresholdDialog();
    void init();
public slots:
    void on_thresholdMin_valueChanged(int value);
    void on_thresholdMax_valueChanged(int value);
public:
    Ui::ThresholdDialog *ui;
    MainWindowAtt* matt;
    DomThreshold* tDom;
    DomThreshold tDomBackups;
    HalconCpp::HObject updateRegionImage;//region的截图
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // THRESHOLDDIALOG_H
