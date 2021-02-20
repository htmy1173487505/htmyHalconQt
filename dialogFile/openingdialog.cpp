#include "openingdialog.h"
#include "ui_openingdialog.h"

OpeningDialog::OpeningDialog(MainWindowAtt* m,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpeningDialog)
{
    ui->setupUi(this);
    matt = m;
}

OpeningDialog::~OpeningDialog()
{
    delete ui;
}

void OpeningDialog::init()
{
    oDom = (DomOpening*)matt->domVector.at(matt->Index);
    oDomBackups = *oDom;
    oDom->image = matt->updateregion;
}

void OpeningDialog::updateImage()
{
    DetachBackgroundFromWindow(matt->m_WindowHandle);
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(oDom->ImageOrReduced, matt->m_WindowHandle);
}

void OpeningDialog::on_comboBox_currentIndexChanged(int index)
{
    if(index==0){
        ui->stackedWidget->setCurrentIndex(0);
        oDom->value = ui->spinBox->value();
        oDom->action();
    }else{
        ui->stackedWidget->setCurrentIndex(1);
        oDom->w = ui->spinBox_2->value();
        oDom->h = ui->spinBox_3->value();
        oDom->action2();
    }
}

void OpeningDialog::on_spinBox_valueChanged(int arg1)
{
    oDom->value = ui->spinBox->value();
    oDom->action();
    updateImage();
}

void OpeningDialog::on_spinBox_2_valueChanged(int arg1)
{
    oDom->w = ui->spinBox_2->value();
    oDom->action2();
    updateImage();
}

void OpeningDialog::on_spinBox_3_valueChanged(int arg1)
{
    oDom->h = ui->spinBox_3->value();
    oDom->action2();
    updateImage();
}

void OpeningDialog::on_pushButton_clicked()
{
    matt->updateregion = oDom->ImageOrReduced;
    close();
}

void OpeningDialog::on_pushButton_2_clicked()
{
    oDom->value = oDomBackups.value;
    oDom->w = oDomBackups.w;
    oDom->h = oDomBackups.h;
    close();
}
