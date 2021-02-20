#include "domselectshape.h"

DomSelectShape::DomSelectShape()
{
    type = "area";
    andOr = "and";
    min = 150;
    max = 10000;
}

void DomSelectShape::action()
{
    HalconCpp::SelectShape(image, &ImageOrReduced, type, andOr, min, max);
}
