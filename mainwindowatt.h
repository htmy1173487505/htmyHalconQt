#ifndef MAINWINDOWATT_H
#define MAINWINDOWATT_H

#include    "struct/superstruct.h"
#include    "struct/rgb1tograydom.h"
#include    "struct/domthreshold.h"
#include    "struct/drawroiFile/drawroiqhrectangle1.h"
#include    "struct/drawroiFile/drawroiqhrectangle2.h"
#include    "struct/drawroiFile/drawroiqhcircle.h"
#include    "struct/drawroiFile/drawroiqhellipse.h"
#include    "struct/domscaleimage.h"
#include    "struct/domerosioncircle.h"
#include    "struct/domdilation.h"
#include    "struct/domclosing.h"
#include    "struct/domopening.h"
#include    "struct/domconnection.h"
#include    "struct/domselectshape.h"
#include    "struct/domcreatescaledshapemodel.h"
#include <QMap>
#include <QVector>
# pragma execution_character_set("utf-8")
class MainWindowAtt{
public:
    //显示图像的控件id
    HalconCpp::HTuple m_hLabelID;			//QLabel控件句柄
    //Halcon显示窗口句柄
    HalconCpp::HTuple m_WindowHandle;
    //原始图像的尺寸
    HalconCpp::HTuple m_imgWidth, m_imgHeight;
    //图片路径列表
    HalconCpp::HTuple m_imgFiles;
    //当前图像
    HalconCpp::HObject m_image;
    //当前图像的下标
    HalconCpp::HTuple index;
    //是否等比缩放
    bool m_bIsEqualScale;
    //是否居中显示
    bool m_bIsShowCenter;
    //缩放后的图像
    HalconCpp::HObject m_hResizedImg;
    //缩放系数
    HalconCpp::HTuple m_hvScaledRate;
    //缩放后图像的大小
    HalconCpp::HTuple m_scaledHeight, m_scaledWidth;
    HalconCpp::HObject updateregion;//操作后展示的图片或者region
    HalconCpp::HObject updateImage;//操作后展示的图片或者image
    HalconCpp::HTuple updateModelID;//创建模板后的modelId;
public:
    int domCount;
    QVector<SuperStruct*> domVector;
    int Index;
    HalconCpp::HTuple QStringToHTuple(QString str);
};
#endif // MAINWINDOWATT_H
