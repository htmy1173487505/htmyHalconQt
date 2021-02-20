#ifndef DRAWROIQHCIRCLE_H
#define DRAWROIQHCIRCLE_H

#include "drawroiqh.h"



class DrawRoiQhCircle : public DrawRoiQh
{
public:
    DrawRoiQhCircle();
    HalconCpp::HTuple radius;//圆形的
    void action();
};

#endif // DRAWROIQHCIRCLE_H
