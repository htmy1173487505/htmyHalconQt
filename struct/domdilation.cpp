#include "domdilation.h"

DomDilation::DomDilation()
{
    value=0;
    w=0;
    h=0;
}

void DomDilation::action()
{
    DilationCircle(image, &ImageOrReduced, value);
}

void DomDilation::action2()
{
    DilationRectangle1(image, &ImageOrReduced, w, h);
}
