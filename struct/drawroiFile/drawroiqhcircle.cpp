#include "drawroiqhcircle.h"

DrawRoiQhCircle::DrawRoiQhCircle()
{

}

void DrawRoiQhCircle::action()
{
    HalconCpp::DrawCircle(windowHandle, &row1, &column1, &radius);
    HalconCpp::GenCircle(&rectangle, row1, column1, radius);
    HalconCpp::ReduceDomain(image, rectangle, &ImageOrReduced);
}
