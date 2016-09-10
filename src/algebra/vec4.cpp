#include "vec4.h"

Vec4::Vec4(double value) : VecN(4,value) {}

Vec4::Vec4(double x, double y, double z, double w) : VecN(4,x,y,z,w) {}

Vec4::~Vec4() {}

double Vec4::getX()
{
    return VecN::getValue(0);
}

double Vec4::getY()
{
    return VecN::getValue(1);
}

double Vec4::getZ()
{
    return VecN::getValue(2);
}

double Vec4::getW()
{
    return VecN::getValue(3);
}

void Vec4::setX(double value)
{
    VecN::setValue(0,value);
}

void Vec4::setY(double value)
{
    VecN::setValue(1,value);
}

void Vec4::setZ(double value)
{
    VecN::setValue(2,value);
}

void Vec4::setW(double value)
{
    VecN::setValue(3,value);
}

Vec4 *Vec4::sum(Vec4 *vec)
{
    Vec4 *result = (Vec4*) VecN::sum(vec);
    result->setW(0);

    return result;
}

Vec4 *Vec4::sub(Vec4 *vec)
{
    Vec4 *result = (Vec4*) VecN::sub(vec);
    result->setW(0);

    return result;
}

Vec4 *Vec4::prod(double lambda)
{
    Vec4 *result = (Vec4*) VecN::prod(lambda);
    if (result->getW() != 0) result->setW(1);

    return result;
}

double Vec4::dot(Vec4 *vec)
{
    return VecN::dot(vec);
}

Vec4 *Vec4::cross(Vec4 *vec)
{
    double x = (getY()*vec->getZ()) - (getZ()*vec->getY());
    double y = (getZ()*vec->getX()) - (getX()*vec->getZ());
    double z = (getX()*vec->getY()) - (getY()*vec->getX());
    double w = 0;

    return new Vec4(x,y,z,w);
}

bool Vec4::isColumn()
{
    return VecN::isColumn();
}

void Vec4::normalize()
{
    VecN::normalize();
}

double Vec4::getNorm()
{
    return VecN::getNorm();
}

Vec4 *Vec4::copy()
{
    return (Vec4*) VecN::copy();
}

