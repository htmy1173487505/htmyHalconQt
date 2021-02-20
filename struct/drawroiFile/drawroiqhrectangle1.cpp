#include "drawroiqhrectangle1.h"

DrawRoiQhRectangle1::DrawRoiQhRectangle1()
{

}

void DrawRoiQhRectangle1::action()
{
    HalconCpp::DrawRectangle1(windowHandle, &row1, &column1, &row2, &column2);
    HalconCpp::GenRectangle1(&rectangle, row1, column1, row2, column2);
    HalconCpp::ReduceDomain(image, rectangle, &ImageOrReduced);
}
