#ifndef DOMOPENING_H
#define DOMOPENING_H

#include "superstruct.h"



class DomOpening : public SuperStruct
{
public:
    DomOpening();
    int value;
    int w;
    int h;
    // SuperStruct interface
public:
    void action();
    void action2();
};

#endif // DOMOPENING_H
