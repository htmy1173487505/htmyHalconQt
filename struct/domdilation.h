#ifndef DOMDILATION_H
#define DOMDILATION_H

#include "superstruct.h"



class DomDilation : public SuperStruct
{
public:
    DomDilation();
    int value;
    int w;
    int h;
public:
    void action();
    void action2();
};

#endif // DOMDILATION_H
