#ifndef DRAWROI_H
#define DRAWROI_H


#include "struct/superstruct.h"
class DrawRoiQh : public SuperStruct
{
public:
    DrawRoiQh();
    HalconCpp::HObject rectangle;//公共的参数
    HalconCpp::HTuple row1,column1;//公共的参数
    virtual void action()=0;
};

#endif // DRAWROI_H
