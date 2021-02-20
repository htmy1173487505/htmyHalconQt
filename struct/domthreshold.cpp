#include "domthreshold.h"

DomThreshold::DomThreshold()
{
    min=0;
    max=255;
}

void DomThreshold::action()
{
    Threshold(image, &ImageOrReduced, min, max);
}
