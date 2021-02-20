#include "domerosioncircle.h"

DomErosionCircle::DomErosionCircle()
{
    value=0;
    w=0;
    h=0;
}

void DomErosionCircle::action()
{
    HalconCpp::ErosionCircle(image, &ImageOrReduced, value);
}

void DomErosionCircle::action2()
{
    HalconCpp::ErosionRectangle1(image, &ImageOrReduced, w, h);
}
