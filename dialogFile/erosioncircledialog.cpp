#include "erosioncircledialog.h"
#include "ui_erosioncircledialog.h"

ErosionCircleDialog::ErosionCircleDialog(MainWindowAtt *m, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErosionCircleDialog)
{
    ui->setupUi(this);
    matt = m;
}

ErosionCircleDialog::~ErosionCircleDialog()
{
    delete ui;
}

void ErosionCircleDialog::init()
{
    ecDom = (DomErosionCircle*)matt->domVector.at(matt->Index);
    ecDomBackups = *ecDom;
    ecDom->image = matt->updateregion;
}

void ErosionCircleDialog::updateImage()
{
    DetachBackgroundFromWindow(matt->m_WindowHandle);
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(ecDom->ImageOrReduced, matt->m_WindowHandle);
}

void ErosionCircleDialog::on_comboBox_currentIndexChanged(int index)
{
    if(index==0){
        ui->stackedWidget->setCurrentIndex(0);
        ecDom->value = ui->spinBox->value();
        ecDom->action();
    }else{
        ui->stackedWidget->setCurrentIndex(1);
        ecDom->w = ui->spinBox_2->value();
        ecDom->h = ui->spinBox_3->value();
        ecDom->action2();
    }
    updateImage();
}

void ErosionCircleDialog::on_spinBox_valueChanged(int arg1)
{
    ecDom->value = ui->spinBox->value();
    ecDom->action();
    updateImage();
}

void ErosionCircleDialog::on_spinBox_2_valueChanged(int arg1)
{
    ecDom->w = ui->spinBox_2->value();
    ecDom->action();
    updateImage();
}

void ErosionCircleDialog::on_spinBox_3_valueChanged(int arg1)
{
    ecDom->h = ui->spinBox_3->value();
    ecDom->action();
    updateImage();
}

void ErosionCircleDialog::on_pushButton_clicked()
{
    matt->updateregion = ecDom->ImageOrReduced;
    close();
}

void ErosionCircleDialog::on_pushButton_2_clicked()
{
    ecDom->value = ecDomBackups.value;
    ecDom->w = ecDomBackups.w;
    ecDom->h = ecDomBackups.h;
    close();
}
