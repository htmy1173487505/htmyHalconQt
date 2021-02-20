#include "drawroiqhellipse.h"

DrawRoiQhEllipse::DrawRoiQhEllipse()
{

}

void DrawRoiQhEllipse::action()
{
    HalconCpp::DrawEllipse(windowHandle, &row1, &column1, &phi, &length1, &length2);
    HalconCpp::GenEllipse(&rectangle, row1, column1, phi, length1, length2);
    HalconCpp::ReduceDomain(image, rectangle, &ImageOrReduced);
}
