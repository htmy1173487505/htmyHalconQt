#include "domscaleimage.h"

DomScaleImage::DomScaleImage()
{
    times=1;
    number=0;
}

void DomScaleImage::action()
{
    ScaleImage(image, &ImageOrReduced, times, number);
}
