#include "vec3.h"

Vec3::Vec3(double value) : VecN(3,value) {}

Vec3::Vec3(double x, double y, double z) : VecN(3,x,y,z) {}

Vec3::Vec3(Mtx mtx) : VecN(mtx) {}

double Vec3::getX()
{
    return VecN::getValue(0);
}

double Vec3::getY()
{
    return VecN::getValue(1);
}

double Vec3::getZ()
{
    return VecN::getValue(2);
}

void Vec3::setX(double value)
{
    VecN::setValue(0,value);
}

void Vec3::setY(double value)
{
    VecN::setValue(1,value);
}

void Vec3::setZ(double value)
{
    VecN::setValue(2,value);
}

Vec3 *Vec3::sum(Vec3 *vec)
{
    return (Vec3*) VecN::sum(vec);
}

Vec3 *Vec3::sub(Vec3 *vec)
{
    return (Vec3*) VecN::sub(vec);
}

Vec3 *Vec3::prod(double lambda)
{
    return (Vec3*) VecN::prod(lambda);
}

double Vec3::dot(Vec3 *vec)
{
    return VecN::dot(vec);
}

Vec3 *Vec3::cross(Vec3 *vec)
{
    double x = (getY()*vec->getZ()) - (getZ()*vec->getY());
    double y = (getZ()*vec->getX()) - (getX()*vec->getZ());
    double z = (getX()*vec->getY()) - (getY()*vec->getX());

    return new Vec3(x,y,z);
}

Vec3 Vec3::operator+(Vec3 vec)
{
    return (Vec3) VecN::operator+(vec);
}

Vec3 Vec3::operator-(Vec3 vec)
{
    return (Vec3) VecN::operator-(vec);
}

Vec3 Vec3::operator*(double lambda)
{
    return (Vec3) VecN::operator*(lambda);
}

double Vec3::dot_(Vec3 vec)
{
    return VecN::dot_(vec);
}

Vec3 Vec3::cross_(Vec3 vec)
{
    double x = (getY()*vec.getZ()) - (getZ()*vec.getY());
    double y = (getZ()*vec.getX()) - (getX()*vec.getZ());
    double z = (getX()*vec.getY()) - (getY()*vec.getX());

    return Vec3(x,y,z);
}

bool Vec3::isColumn()
{
    return VecN::isColumn();
}

void Vec3::normalize()
{
    VecN::normalize();
}

double Vec3::getNorm()
{
    return VecN::getNorm();
}

Vec3 *Vec3::copy()
{
    return (Vec3*) VecN::copy();
}

Vec3 Vec3::copy_()
{
    return (Vec3) VecN::copy_();
}
