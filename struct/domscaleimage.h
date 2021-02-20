#ifndef DOMSCALEIMAGE_H
#define DOMSCALEIMAGE_H

#include "superstruct.h"



class DomScaleImage : public SuperStruct
{
public:
    DomScaleImage();
    int times;
    int number;
    void action();
};

#endif // DOMSCALEIMAGE_H
