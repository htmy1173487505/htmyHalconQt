#ifndef DOMTHRESHOLD_H
#define DOMTHRESHOLD_H

#include "superstruct.h"



class DomThreshold : public SuperStruct
{
public:
    DomThreshold();

    // SuperStruct interface
public:
    void action();
    int min;
    int max;
};

#endif // DOMTHRESHOLD_H
