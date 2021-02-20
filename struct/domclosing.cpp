#include "domclosing.h"

DomClosing::DomClosing()
{
    value = 0;
    w = 0;
    h = 0;
}

void DomClosing::action()
{
    ClosingCircle(image, &ImageOrReduced, value);
}

void DomClosing::action2()
{
    ClosingRectangle1(image, &ImageOrReduced, w, h);
}
