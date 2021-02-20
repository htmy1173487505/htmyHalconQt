#include "domcreatescaledshapemodel.h"

DomCreateScaledShapeModel::DomCreateScaledShapeModel()
{
    NumLevels = "auto";
    AngleStart = -1.57;
    AngleExtent = 3.14;
    AngleStep = "auto";
    ScaleMin = 0.9;
    ScaleMax = 1.1;
    ScaleStep = "auto";
    Optimization = "auto";
    Metric = "use_polarity";
    Contrast = "auto";
    MinContrast = "auto";
}

void DomCreateScaledShapeModel::action()
{
    CreateScaledShapeModel(image, NumLevels, AngleStart, AngleExtent,AngleStep,ScaleMin,ScaleMax, ScaleStep,Optimization,
                           Metric, Contrast, MinContrast, &ModelID);
}
