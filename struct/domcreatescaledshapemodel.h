#ifndef DOMCREATESCALEDSHAPEMODEL_H
#define DOMCREATESCALEDSHAPEMODEL_H

#include "superstruct.h"

class DomCreateScaledShapeModel : public SuperStruct
{
public:
    DomCreateScaledShapeModel();
    HalconCpp::HTuple NumLevels;//金字塔的层数，可设为“auto”或0—10的整数
    double AngleStart,AngleExtent;//模板旋转的起始角度,//模板旋转角度范围, >=0
    HalconCpp::HTuple AngleStep;//旋转角度的步长， >=0 and <=pi/16
    double ScaleMin,ScaleMax;
    HalconCpp::HTuple ScaleStep;
    HalconCpp::HTuple Optimization;//设置模板优化和模板创建方法
    HalconCpp::HTuple Metric;//匹配方法设置
    HalconCpp::HTuple Contrast;//设置对比度
    HalconCpp::HTuple MinContrast;//设置最小对比度
    HalconCpp::HTuple ModelID;//输出模板句柄
    void action();
};

#endif // DOMCREATESCALEDSHAPEMODEL_H
