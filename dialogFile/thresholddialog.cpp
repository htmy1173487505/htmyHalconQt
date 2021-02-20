#include "thresholddialog.h"
#include "ui_thresholddialog.h"

ThresholdDialog::ThresholdDialog(MainWindowAtt *m, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThresholdDialog)
{
    ui->setupUi(this);
    matt = m;
}

ThresholdDialog::~ThresholdDialog()
{
    delete ui;
}

void ThresholdDialog::init()
{
    tDom = (DomThreshold*)matt->domVector.at(matt->Index);
    tDomBackups = *tDom;
    ui->thresholdMin->setValue(tDom->min);
    ui->thresholdMax->setValue(tDom->max);
    ui->min->setText(QString::number(tDom->min));
    ui->max->setText(QString::number(tDom->max));
}

void ThresholdDialog::on_thresholdMin_valueChanged(int value)
{
    if(value>=tDom->max){
        tDom->max = 255;
        ui->thresholdMax->setValue(255);
        ui->max->setText(QString::number(255));
    }
    tDom->min = value;
    ui->min->setText(QString::number(value));
    tDom->image =  matt->updateImage;
    tDom->action();
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(tDom->ImageOrReduced, matt->m_WindowHandle);
    DispObj(tDom->ImageOrReduced, matt->m_WindowHandle);
}

void ThresholdDialog::on_thresholdMax_valueChanged(int value)
{
    if(value<=tDom->min){
        tDom->max = 255;
        ui->thresholdMax->setValue(255);
    }else{
        tDom->max = value;
    }
    ui->max->setText(QString::number(tDom->max));
    tDom->image = matt->updateImage;
    tDom->action();
    DetachBackgroundFromWindow(matt->m_WindowHandle);
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(tDom->ImageOrReduced, matt->m_WindowHandle);
    DispObj(tDom->ImageOrReduced, matt->m_WindowHandle);
}

void ThresholdDialog::on_pushButton_clicked()
{
    matt->updateregion = tDom->ImageOrReduced;
    close();
}

void ThresholdDialog::on_pushButton_2_clicked()
{
    tDom->min = tDomBackups.min;
    tDom->max = tDomBackups.max;
    close();
}
