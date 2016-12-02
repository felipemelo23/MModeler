#include "vec4.h"

Vec4::Vec4(double value) : VecN(4,value) {}

Vec4::Vec4(double x, double y, double z, double w) : VecN(4,x,y,z,w) {}

Vec4::Vec4(Vec3 *vec, double w) : VecN(4,vec->getX(),vec->getY(),vec->getZ(),w) {}

Vec4::Vec4(Vec3 vec, double w) : VecN(4,vec.getX(),vec.getY(),vec.getZ(),w) {}

Vec4::Vec4(Mtx mtx) : VecN(mtx) {}

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

Vec3 *Vec4::getVec3()
{
    return new Vec3(getX(),getY(),getZ());
}

Vec3 Vec4::getVec3_()
{
    return Vec3(getX(),getY(),getZ());
}

Vec4 *Vec4::sum(Vec4 *vec)
{
    Vec4 *result = (Vec4*) VecN::sum(vec);
    result->setW(0);

    return result;
}

Vec4 *Vec4::sum_(Vec4 *vec)
{
    setX(getX()+vec->getX());
    setY(getY()+vec->getY());
    setZ(getZ()+vec->getZ());
    setW(0);
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

Vec4 Vec4::operator+(Vec4 vec)
{
    Vec4 result = (Vec4) VecN::operator+(vec);
    result.setW(0);

    return result;
}

Vec4 Vec4::operator-(Vec4 vec)
{
    Vec4 result = (Vec4) VecN::operator-(vec);
    result.setW(0);

    return result;
}

Vec4 Vec4::operator*(double lambda)
{
    Vec4 result = (Vec4) VecN::operator*(lambda);
    if (result.getW() != 0) result.setW(1);

    return result;
}

double Vec4::dot_(Vec4 vec)
{
    return VecN::dot_(vec);
}

Vec4 Vec4::cross_(Vec4 vec)
{
    double x = (getY()*vec.getZ()) - (getZ()*vec.getY());
    double y = (getZ()*vec.getX()) - (getX()*vec.getZ());
    double z = (getX()*vec.getY()) - (getY()*vec.getX());
    double w = 0;

    return Vec4(x,y,z,w);
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

Vec4 Vec4::copy_()
{
    return (Vec4) VecN::copy_();
}

