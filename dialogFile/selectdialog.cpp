#include "selectdialog.h"
#include "ui_selectdialog.h"

SelectDialog::SelectDialog(MainWindowAtt * m,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDialog)
{
    ui->setupUi(this);
    matt = m;
}

SelectDialog::~SelectDialog()
{
    delete ui;
}

void SelectDialog::init()
{
    ssDom = (DomSelectShape*)matt->domVector.at(matt->Index);
    ssDomBackups = *ssDom;
    ssDom->image = matt->updateregion;
    ssDom->action();
    updateImage();
    ui->selectMin->setMaximum(10000);
    ui->selectMax->setMaximum(10000);
    ui->selectMax->setValue(10000);
}

void SelectDialog::updateImage()
{
    DetachBackgroundFromWindow(matt->m_WindowHandle);
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(ssDom->ImageOrReduced, matt->m_WindowHandle);
}

void SelectDialog::on_comboBox_currentIndexChanged(int index)
{
    QString comText = ui->comboBox->currentText();
    QStringList strList = comText.split("-");
    ssDom->type = matt->QStringToHTuple(strList[0]);
    if(index==0){
        ui->selectMin->setMaximum(10000);
        ui->selectMax->setMaximum(10000);
        ui->selectMax->setValue(10000);
    }else{
        ui->selectMin->setMaximum(100);
        ui->selectMax->setMaximum(100);
    }
}

void SelectDialog::on_selectMin_valueChanged(int value)
{
    int index = ui->comboBox->currentIndex();
    if(ui->selectMin->value()==ui->selectMax->maximum()-1){
    }else if(ui->selectMin->value()>ui->selectMax->value()){
        ui->selectMax->setValue(ui->selectMin->value()+1);
    }
    ssDom->min = ui->selectMin->value();
    ssDom->max = ui->selectMax->value();
    if(index == 0){
        ssDom->action();
    }else{
        ssDom->max = ssDom->max/100;
        ssDom->min = ssDom->min/100;
        ssDom->action();
    }
    updateImage();
}

void SelectDialog::on_selectMax_valueChanged(int value)
{
    int index = ui->comboBox->currentIndex();
    if(ui->selectMax->value()==1){
    }else if(ui->selectMax->value()<ui->selectMin->value()){
        if(index == 0){
            ui->selectMin->setValue(ui->selectMax->value()-1);
        }else{
            ui->selectMin->setValue(ui->selectMax->value()-1);
        }
    }
    ssDom->max = ui->selectMax->value();
    ssDom->max = ui->selectMax->value();
    if(index == 0){
        ssDom->action();
    }else{
        ssDom->max = ssDom->max/100;
        ssDom->min = ssDom->min/100;
        ssDom->action();
    }
    updateImage();
}

void SelectDialog::on_comboBox_2_currentIndexChanged(int index)
{
    QString comText = ui->comboBox->currentText();
    ssDom->andOr = matt->QStringToHTuple(comText);
}

void SelectDialog::on_pushButton_clicked()
{
    matt->updateregion = ssDom->ImageOrReduced;
    close();
}

void SelectDialog::on_pushButton_2_clicked()
{
    ssDom->max = ssDomBackups.max;
    ssDom->min = ssDomBackups.min;
    ssDom->type = ssDomBackups.type;
    close();
}
