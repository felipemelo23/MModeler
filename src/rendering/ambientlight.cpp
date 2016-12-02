#include "ambientlight.h"

AmbientLight::AmbientLight()
{
    this->color = Color();
    this->intesity = 1;
}

AmbientLight::AmbientLight(Color color, double intesity)
{
    this->color = color;
    this->intesity = intesity;
}

Color AmbientLight::getColor() const
{
    return color;
}

double AmbientLight::getIntesity() const
{
    return intesity;
}
