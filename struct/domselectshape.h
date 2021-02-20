#ifndef DOMSELECTSHAPE_H
#define DOMSELECTSHAPE_H

#include "superstruct.h"
#include "QString"
class DomSelectShape : public SuperStruct
{
public:
    DomSelectShape();
    HalconCpp::HTuple QStringToHTuple(QString str);
    HalconCpp::HTuple type;
    HalconCpp::HTuple andOr;
    double min;
    double max;
    // SuperStruct interface
public:
    void action();
};

#endif // DOMSELECTSHAPE_H
