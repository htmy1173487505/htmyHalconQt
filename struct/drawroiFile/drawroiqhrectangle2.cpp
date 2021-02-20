#include "drawroiqhrectangle2.h"

DrawRoiQhRectangle2::DrawRoiQhRectangle2()
{

}

void DrawRoiQhRectangle2::action()
{
    HalconCpp::DrawRectangle2(windowHandle, &row1, &column1, &phi, &length1, &length2);
    HalconCpp::GenRectangle2(&rectangle, row1, column1, phi, length1, length2);
    HalconCpp::ReduceDomain(image, rectangle, &ImageOrReduced);
}
