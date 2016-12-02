#include "vec2.h"

Vec2::Vec2(double value) : VecN(2,value) {}

Vec2::Vec2(double x, double y) : VecN(2,x,y) {}

Vec2::Vec2(Mtx mtx) : VecN(mtx) {}

double Vec2::getX()
{
    return VecN::getValue(0);
}

double Vec2::getY()
{
    return VecN::getValue(1);
}

void Vec2::setX(double value)
{
    VecN::setValue(0,value);
}

void Vec2::setY(double value)
{
    VecN::setValue(1,value);
}

Vec2 *Vec2::sum(Vec2 *vec)
{
    return (Vec2*) VecN::sum(vec);
}

Vec2 *Vec2::sub(Vec2 *vec)
{
    return (Vec2*) VecN::sub(vec);
}

Vec2 *Vec2::prod(double lambda)
{
    return (Vec2*) VecN::prod(lambda);
}

double Vec2::dot(Vec2 *vec)
{
    return VecN::dot(vec);
}

double Vec2::cross(Vec2 *vec)
{
    return (getX()*vec->getY()) - (getY()*vec->getX());
}

Vec2 Vec2::operator+(Vec2 vec)
{
    return (Vec2) VecN::operator+(vec);
}

Vec2 Vec2::operator-(Vec2 vec)
{
    return (Vec2) VecN::operator-(vec);
}

Vec2 Vec2::operator*(double lambda)
{
    return (Vec2) VecN::operator*(lambda);
}

double Vec2::dot_(Vec2 vec)
{
    return VecN::dot_(vec);
}

double Vec2::cross_(Vec2 vec)
{
    return (getX()*vec.getY()) - (getY()*vec.getX());
}

bool Vec2::isColumn()
{
    return VecN::isColumn();
}

void Vec2::normalize()
{
    VecN::normalize();
}

double Vec2::getNorm()
{
    return VecN::getNorm();
}

Vec2 *Vec2::copy()
{
    return (Vec2*) VecN::copy();
}

Vec2 Vec2::copy_()
{
    return (Vec2) VecN::copy_();
}
