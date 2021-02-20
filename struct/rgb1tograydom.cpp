#include "rgb1tograydom.h"

Rgb1ToGrayDom::Rgb1ToGrayDom()
{

}

void Rgb1ToGrayDom::action()
{
    HalconCpp::Rgb1ToGray(image, &ImageOrReduced);
}
