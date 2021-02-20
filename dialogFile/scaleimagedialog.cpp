#include "scaleimagedialog.h"
#include "ui_scaleimagedialog.h"

ScaleimageDialog::ScaleimageDialog(MainWindowAtt* m,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScaleimageDialog)
{
    ui->setupUi(this);
    matt = m;
}

ScaleimageDialog::~ScaleimageDialog()
{
    delete ui;
}

void ScaleimageDialog::init()
{
    sDom = (DomScaleImage*)matt->domVector.at(matt->Index);
    sDomBackups = *sDom;
    ui->timesNumber->setValue(sDom->times);
    ui->times->setText(QString::number(sDom->times)+"倍");
    ui->scaleImageNumber->setValue(sDom->number+255);
    ui->number->setText(QString::number(sDom->number));
}

void ScaleimageDialog::on_pushButton_clicked()
{
    matt->updateImage = sDom->ImageOrReduced;
    close();
}

void ScaleimageDialog::on_pushButton_2_clicked()
{
    sDom->times = sDomBackups.times;
    sDom->number = sDomBackups.number;
    close();
}

void ScaleimageDialog::on_timesNumber_valueChanged(int age1)
{
    sDom->times= ui->timesNumber->value();
    sDom->image = matt->updateImage;
    sDom->action();
    ui->times->setText(QString::number( sDom->times)+"倍");
    DetachBackgroundFromWindow(matt->m_WindowHandle);
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(sDom->ImageOrReduced, matt->m_WindowHandle);
}

void ScaleimageDialog::on_scaleImageNumber_valueChanged(int value)
{
    sDom->number=value-255;
    sDom->image = matt->updateImage;
    sDom->action();
    ui->number->setText(QString::number(sDom->number));
    DetachBackgroundFromWindow(matt->m_WindowHandle);
    HalconCpp::ClearWindow(matt->m_WindowHandle);
    DispObj(sDom->ImageOrReduced, matt->m_WindowHandle);
}
