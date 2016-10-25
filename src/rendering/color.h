#ifndef COLOR_H
#define COLOR_H

#include <algebra/vec3.h>

class Color : public Vec3
{
public:
    Color();
    Color(double red, double green, double blue);

    double getRed();
    double getGreen();
    double getBlue();

    void setRed(double value);
    void setGreen(double value);
    void setBlue(double value);

    Color *sum(Color *color);
    void sum_(Color *color);
    Color *sub(Color *color);
    Color *prod(double lambda);
    Color *prod(Color *color);
};

#endif // COLOR_H
