#include "mainwindowatt.h"

HalconCpp::HTuple MainWindowAtt::QStringToHTuple(QString str)
{
    QByteArray ba   = str.toLatin1();
    char* data = ba.data();
    return (HalconCpp::HTuple)data;
}
