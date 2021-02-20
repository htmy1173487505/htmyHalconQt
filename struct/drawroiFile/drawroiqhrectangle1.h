#ifndef DRAWROIQHRECTANGLE1_H
#define DRAWROIQHRECTANGLE1_H

#include "drawroiqh.h"



class DrawRoiQhRectangle1 : public DrawRoiQh
{
public:
    DrawRoiQhRectangle1();
    HalconCpp::HTuple row2,column2;//矩形的
    void action();
};

#endif // DRAWROIQHRECTANGLE1_H
