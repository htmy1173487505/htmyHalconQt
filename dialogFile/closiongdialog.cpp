#include "closiongdialog.h"
#include "ui_closiongdialog.h"

ClosiongDialog::ClosiongDialog(MainWindowAtt * m,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClosiongDialog)
{
    ui->setupUi(this);
    matt = m;
}

ClosiongDialog::~ClosiongDialog()
{
    delete ui;
}

void ClosiongDialog::init()
{
    cDom = (DomClosing*)matt->domVector.at(matt->Index);
    cDomBackups = *cDom;
    cDom->image = matt->updateregion;
}

void ClosiongDialog::updateImage()
{
    DetachBackgroundFromWindow(matt->m_WindowHandle);
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(cDom->ImageOrReduced, matt->m_WindowHandle);
}

void ClosiongDialog::on_comboBox_currentIndexChanged(int index)
{
    if(index==0){
        ui->stackedWidget->setCurrentIndex(0);
        cDom->value = ui->spinBox->value();
        cDom->action();
    }else{
        ui->stackedWidget->setCurrentIndex(1);
        cDom->w = ui->spinBox_2->value();
        cDom->h = ui->spinBox_3->value();
        cDom->action2();
    }
}

void ClosiongDialog::on_spinBox_valueChanged(int arg1)
{
    cDom->value = ui->spinBox->value();
    cDom->action();
    updateImage();
}

void ClosiongDialog::on_spinBox_2_valueChanged(int arg1)
{
    cDom->w = ui->spinBox_2->value();
    cDom->action2();
    updateImage();
}

void ClosiongDialog::on_spinBox_3_valueChanged(int arg1)
{
    cDom->h = ui->spinBox_3->value();
    cDom->action2();
    updateImage();
}

void ClosiongDialog::on_pushButton_clicked()
{
    matt->updateregion = cDom->ImageOrReduced;
    close();
}

void ClosiongDialog::on_pushButton_2_clicked()
{
    cDom->value = cDomBackups.value;
    cDom->w = cDomBackups.w;
    cDom->h = cDomBackups.h;
    close();
}
