#ifndef SUPERSTRUCT_H
#define SUPERSTRUCT_H


#include"HalconCpp.h"
class SuperStruct
{
public:
    SuperStruct();
    HalconCpp::HObject ImageOrReduced,image;
    HalconCpp::HTuple windowHandle;
    virtual void action()=0;
};

#endif // SUPERSTRUCT_H
