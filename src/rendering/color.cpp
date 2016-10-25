#include "color.h"

Color::Color() : Vec3(1,1,1) {}

Color::Color(double red, double green, double blue) : Vec3(red,green,blue) {}

double Color::getRed()
{
    return Vec3::getX();
}

double Color::getGreen()
{
    return Vec3::getY();
}

double Color::getBlue()
{
    return Vec3::getZ();
}

void Color::setRed(double value)
{
    Vec3::setX(value);
}

void Color::setGreen(double value)
{
    Vec3::setY(value);
}

void Color::setBlue(double value)
{
    Vec3::setZ(value);
}

Color *Color::sum(Color *color)
{
    return (Color*) Vec3::sum(color);
}

void Color::sum_(Color *color)
{
    setRed(getRed()+color->getRed());
    setGreen(getGreen()+color->getGreen());
    setBlue(getBlue()+color->getBlue());
}

Color *Color::sub(Color *color)
{
    return (Color*) Vec3::sub(color);
}

Color *Color::prod(double lambda)
{
    return (Color*) Vec3::prod(lambda);
}

Color *Color::prod(Color *color)
{
    return new Color(getRed()*color->getRed(),getGreen()*color->getGreen(),getBlue()*color->getBlue());
}
