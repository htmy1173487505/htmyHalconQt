#include "createscaledshapemodeldialog.h"
#include "ui_createscaledshapemodeldialog.h"

CreateScaledShapeModelDialog::CreateScaledShapeModelDialog(MainWindowAtt* m,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateScaledShapeModelDialog)
{
    ui->setupUi(this);
    matt = m;
}

CreateScaledShapeModelDialog::~CreateScaledShapeModelDialog()
{
    delete ui;
}

void CreateScaledShapeModelDialog::init()
{
    cssmDom = (DomCreateScaledShapeModel*)matt->domVector.at(matt->Index);
    cssmDomBackups = *cssmDom;
    cssmDom->image = matt->updateImage;
    cssmDom->action();
}

void CreateScaledShapeModelDialog::updateImage()
{
    DetachBackgroundFromWindow(matt->m_WindowHandle);
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(cssmDom->ImageOrReduced, matt->m_WindowHandle);
}

void CreateScaledShapeModelDialog::action()
{
    cssmDom->NumLevels = matt->QStringToHTuple(ui->comboBox->currentText());
    cssmDom->AngleStart = ui->doubleSpinBox->value();
    cssmDom->AngleExtent = ui->doubleSpinBox_3->value();
    cssmDom->AngleStep = matt->QStringToHTuple(ui->comboBox_3->currentText());
    cssmDom->ScaleMin = ui->doubleSpinBox_4->value();
    cssmDom->ScaleMax = ui->doubleSpinBox_5->value();
    cssmDom->ScaleStep = matt->QStringToHTuple(ui->comboBox_4->currentText());
    cssmDom->Optimization = matt->QStringToHTuple(ui->comboBox_5->currentText());
    cssmDom->Metric = matt->QStringToHTuple(ui->comboBox_6->currentText());
    cssmDom->Contrast = matt->QStringToHTuple(ui->comboBox_7->currentText());
    cssmDom->MinContrast = matt->QStringToHTuple(ui->comboBox_8->currentText());
}

void CreateScaledShapeModelDialog::on_comboBox_currentIndexChanged(int index)
{
    action();
}

void CreateScaledShapeModelDialog::on_doubleSpinBox_valueChanged(double arg1)
{
    action();
}

void CreateScaledShapeModelDialog::on_doubleSpinBox_3_valueChanged(double arg1)
{
    action();
}

void CreateScaledShapeModelDialog::on_comboBox_3_currentIndexChanged(int index)
{
    action();
}

void CreateScaledShapeModelDialog::on_doubleSpinBox_4_valueChanged(double arg1)
{
    action();
}

void CreateScaledShapeModelDialog::on_doubleSpinBox_5_valueChanged(double arg1)
{
    action();
}

void CreateScaledShapeModelDialog::on_comboBox_4_currentIndexChanged(int index)
{
    action();
}

void CreateScaledShapeModelDialog::on_comboBox_5_currentIndexChanged(int index)
{
    action();
}

void CreateScaledShapeModelDialog::on_comboBox_7_currentIndexChanged(int index)
{
    action();
}

void CreateScaledShapeModelDialog::on_comboBox_6_currentIndexChanged(int index)
{
    action();
}

void CreateScaledShapeModelDialog::on_comboBox_8_currentIndexChanged(int index)
{
    action();
}

void CreateScaledShapeModelDialog::on_pushButton_clicked()
{
    cssmDom->action();
    matt->updateModelID = cssmDom->ModelID;;
    close();
}

void CreateScaledShapeModelDialog::on_pushButton_2_clicked()
{
    cssmDom->NumLevels = cssmDomBackups.NumLevels;
    cssmDom->AngleStart = cssmDomBackups.AngleStart;
    cssmDom->AngleExtent = cssmDomBackups.AngleExtent;
    cssmDom->AngleStep = cssmDomBackups.AngleStep;
    cssmDom->ScaleMin = cssmDomBackups.ScaleMin;
    cssmDom->ScaleMax = cssmDomBackups.ScaleMax;
    cssmDom->ScaleStep = cssmDomBackups.ScaleStep;
    cssmDom->Optimization = cssmDomBackups.Optimization;
    cssmDom->Metric = cssmDomBackups.Metric;
    cssmDom->Contrast = cssmDomBackups.Contrast;
    cssmDom->MinContrast = cssmDomBackups.MinContrast;
    close();
}
