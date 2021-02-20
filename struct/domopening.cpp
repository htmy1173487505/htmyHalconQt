#include "domopening.h"

DomOpening::DomOpening()
{
    value = 0;
    w = 0;
    h = 0;
}

void DomOpening::action()
{
    OpeningCircle(image, &ImageOrReduced, value);
}

void DomOpening::action2()
{
    OpeningRectangle1(image, &ImageOrReduced, w, h);
}
