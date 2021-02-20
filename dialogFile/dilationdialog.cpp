#include "dilationdialog.h"
#include "ui_dilationdialog.h"

DilationDialog::DilationDialog(MainWindowAtt* m,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DilationDialog)
{
    ui->setupUi(this);
    matt = m;
}

DilationDialog::~DilationDialog()
{
    delete ui;
}

void DilationDialog::init()
{
    dDom = (DomDilation*)matt->domVector.at(matt->Index);
    dDomBackups = *dDom;
    dDom->image = matt->updateregion;
}

void DilationDialog::updateImage()
{
    DetachBackgroundFromWindow(matt->m_WindowHandle);
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(dDom->ImageOrReduced, matt->m_WindowHandle);
}

void DilationDialog::on_comboBox_currentIndexChanged(int index)
{
    if(index==0){
        ui->stackedWidget->setCurrentIndex(0);
        dDom->value = ui->spinBox->value();
        dDom->action();
    }else{
        ui->stackedWidget->setCurrentIndex(1);
        dDom->w = ui->spinBox_2->value();
        dDom->h = ui->spinBox_3->value();
        dDom->action2();
    }
}

void DilationDialog::on_spinBox_2_valueChanged(int arg1)
{
    dDom->w = ui->spinBox_2->value();
    dDom->action();
    updateImage();
}

void DilationDialog::on_spinBox_valueChanged(int arg1)
{
    dDom->value = ui->spinBox->value();
    dDom->action();
    updateImage();
}

void DilationDialog::on_spinBox_3_valueChanged(int arg1)
{
    dDom->h = ui->spinBox_3->value();
    dDom->action();
    updateImage();
}

void DilationDialog::on_pushButton_clicked()
{
    matt->updateregion = dDom->ImageOrReduced;
    close();
}

void DilationDialog::on_pushButton_2_clicked()
{
    dDom->value = dDomBackups.value;
    dDom->w = dDomBackups.w;
    dDom->h = dDomBackups.h;
    close();
}
