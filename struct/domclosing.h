#ifndef DOMCLOSING_H
#define DOMCLOSING_H

#include "superstruct.h"



class DomClosing : public SuperStruct
{
public:
    DomClosing();
    int value;
    int w,h;
public:
    void action();
    void action2();
};

#endif // DOMCLOSING_H
