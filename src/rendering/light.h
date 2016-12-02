#ifndef LIGHT_H
#define LIGHT_H

#include "color.h"
#include <algebra/vec3.h>

class Light
{
public:
    Light();
    Light(Vec3 origin, Color color, double intensity, double radius=0);

    Vec3 getOrigin() const;
    Color getColor() const;
    double getIntensity() const;

private:
    Vec3 origin;
    Color color;
    double intensity;
    double radius;
};

#endif // LIGHT_H
