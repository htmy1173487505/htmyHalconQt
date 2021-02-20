#ifndef DRAWROIQHROTATE_H
#define DRAWROIQHROTATE_H

#include "drawroiqh.h"

class DrawRoiQhRotate : public DrawRoiQh
{
public:
    DrawRoiQhRotate();
    HalconCpp::HTuple phi,length1, length2;//旋转矩形,椭圆的
    virtual void action()=0;
};

#endif // DRAWROIQHROTATE_H
