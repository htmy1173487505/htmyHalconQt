#ifndef DOMEROSIONCIRCLE_H
#define DOMEROSIONCIRCLE_H

#include "superstruct.h"



class DomErosionCircle : public SuperStruct
{
public:
    DomErosionCircle();
    int value;
    int w;
    int h;
    // SuperStruct interface
public:
    void action();
    void action2();
};

#endif // DOMEROSIONCIRCLE_H
