#include "light.h"

Light::Light()
{
    this->origin = new Vec3();
    this->color = new Color();
    this->intensity = 1;
    this->radius = 0;
}

Light::Light(Vec3 *origin, Color *color, double intensity, double radius)
{
    this->origin = origin;
    this->color = color;
    this->intensity = intensity;
    this->radius = radius;
}

Vec3 *Light::getOrigin() const
{
    return origin;
}

Color *Light::getColor() const
{
    return color;
}

double Light::getIntensity() const
{
    return intensity;
}
