#include "mtx3x3.h"

Mtx3x3::Mtx3x3(double value) : MtxNxN(value) {}

Mtx3x3::Mtx3x3(double v00, double v01, double v02, double v10, double v11, double v12, double v20, double v21, double v22) : MtxNxN(3,v00,v01,v02,v10,v11,v12,v20,v21,v22) {}

Mtx3x3::Mtx3x3(Mtx mtx) : MtxNxN(mtx) {}

Vec3 *Mtx3x3::getLine(unsigned int line)
{
    return (Vec3*) Mtx::getLine(line);
}

Vec3 *Mtx3x3::getColumn(unsigned int column)
{
    return (Vec3*) Mtx::getColumn(column);
}

void Mtx3x3::setLine(unsigned int line, Vec3 *value)
{
    Mtx::setLine(line,value);
}

void Mtx3x3::setColumn(unsigned int column, Vec3 *value)
{
    Mtx::setColumn(column,value);
}

Vec3 Mtx3x3::getLine_(unsigned int line)
{
    return (Vec3) Mtx::getLine_(line);
}

Vec3 Mtx3x3::getColumn_(unsigned int column)
{
    return (Vec3) Mtx::getColumn_(column);
}

void Mtx3x3::setLine_(unsigned int line, Vec3 value)
{
    Mtx::setLine_(line,value);
}

void Mtx3x3::setColumn_(unsigned int column, Vec3 value)
{
    Mtx::setColumn_(column,value);
}

Mtx3x3 *Mtx3x3::sum(Mtx3x3 *mtx)
{
    return (Mtx3x3*) MtxNxN::sum(mtx);
}

Mtx3x3 *Mtx3x3::sub(Mtx3x3 *mtx)
{
    return (Mtx3x3*) MtxNxN::sub(mtx);
}

Mtx3x3 *Mtx3x3::prod(Mtx3x3 *mtx)
{
    return (Mtx3x3*) MtxNxN::prod(mtx);
}

Vec3 *Mtx3x3::prod(Vec3 *vec)
{
    return (Vec3*) MtxNxN::prod(vec);
}

Mtx3x3 *Mtx3x3::prod(double lambda)
{
    return (Mtx3x3*) MtxNxN::prod(lambda);
}

Mtx3x3 *Mtx3x3::inverse()
{
    return (Mtx3x3*) MtxNxN::inverse();
}

Mtx3x3 Mtx3x3::operator+(Mtx3x3 mtx)
{
    return (Mtx3x3) MtxNxN::operator+(mtx);
}

Mtx3x3 Mtx3x3::operator-(Mtx3x3 mtx)
{
    return (Mtx3x3) MtxNxN::operator-(mtx);
}

Mtx3x3 Mtx3x3::operator*(Mtx3x3 mtx)
{
    return (Mtx3x3) MtxNxN::operator*(mtx);
}

Vec3 Mtx3x3::operator*(Vec3 vec)
{
    return (Vec3) MtxNxN::operator*(vec);
}

Mtx3x3 Mtx3x3::operator*(double lambda)
{
    return (Mtx3x3) MtxNxN::operator*(lambda);
}

Mtx3x3 Mtx3x3::inverse_()
{
    return (Mtx3x3) MtxNxN::inverse_();
}

Mtx3x3 *Mtx3x3::copy()
{
    return (Mtx3x3*) MtxNxN::copy();
}

Mtx3x3 Mtx3x3::copy_()
{
    return (Mtx3x3) MtxNxN::copy_();
}

Mtx3x3 *Mtx3x3::getIdentity()
{
    return (Mtx3x3*) MtxNxN::getIdentity(3);
}

Mtx3x3 *Mtx3x3::getRotateMtx(double degree, bool x, bool y, bool z)
{
    Mtx3x3 *R = getIdentity();

    if (x) {
        R->setValue(1,1,cos(degree));
        R->setValue(1,2,sin(degree));
        R->setValue(2,1,-sin(degree));
        R->setValue(2,2,cos(degree));
    } else if (y) {
        R->setValue(0,0,cos(degree));
        R->setValue(0,2,-sin(degree));
        R->setValue(2,0,sin(degree));
        R->setValue(2,2,cos(degree));
    } else if (z) {
        R->setValue(0,0,cos(degree));
        R->setValue(0,1,sin(degree));
        R->setValue(1,0,-sin(degree));
        R->setValue(1,1,cos(degree));
    }

    return R;
}

Mtx3x3 *Mtx3x3::getScaleMtx(double x, double y, double z)
{
    return new Mtx3x3(x,0,0,
                      0,y,0,
                      0,0,z);
}

Mtx3x3 Mtx3x3::getIdentity_()
{
    return (Mtx3x3) MtxNxN::getIdentity_(3);
}

Mtx3x3 Mtx3x3::getRotateMtx_(double degree, bool x, bool y, bool z)
{
    Mtx3x3 R = getIdentity_();

    if (x) {
        R.setValue(1,1,cos(degree));
        R.setValue(1,2,-sin(degree));
        R.setValue(2,1,sin(degree));
        R.setValue(2,2,cos(degree));
    } else if (y) {
        R.setValue(0,0,cos(degree));
        R.setValue(0,2,sin(degree));
        R.setValue(2,0,-sin(degree));
        R.setValue(2,2,cos(degree));
    } else if (z) {
        R.setValue(0,0,cos(degree));
        R.setValue(0,1,-sin(degree));
        R.setValue(1,0,sin(degree));
        R.setValue(1,1,cos(degree));
    }

    return R;
}

Mtx3x3 Mtx3x3::getScaleMtx_(double x, double y, double z)
{
    return Mtx3x3(x,0,0,
                  0,y,0,
                  0,0,z);
}
