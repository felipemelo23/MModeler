#include "mtx4x4.h"

Mtx4x4::Mtx4x4(double value) : MtxNxN(4,value) {}

Mtx4x4::Mtx4x4(double v00, double v01, double v02, double v03, double v10, double v11, double v12, double v13, double v20, double v21, double v22, double v23, double v30, double v31, double v32, double v33) : MtxNxN(4,v00,v01,v02,v03,v10,v11,v12,v13,v20,v21,v22,v23,v30,v31,v32,v33) {}

Mtx4x4::Mtx4x4(Mtx mtx) : MtxNxN(mtx) {}

Vec4 *Mtx4x4::getLine(unsigned int line)
{
    return (Vec4*) Mtx::getLine(line);
}

Vec4 *Mtx4x4::getColumn(unsigned int column)
{
    return (Vec4*) Mtx::getColumn(column);
}

void Mtx4x4::setLine(unsigned int line, Vec4 *value)
{
    Mtx::setLine(line,value);
}

void Mtx4x4::setColumn(unsigned int column, Vec4 *value)
{
    Mtx::setColumn(column,value);
}

Vec4 Mtx4x4::getLine_(unsigned int line)
{
    return (Vec4) Mtx::getLine_(line);
}

Vec4 Mtx4x4::getColumn_(unsigned int column)
{
    return (Vec4) Mtx::getColumn_(column);
}

void Mtx4x4::setLine_(unsigned int line, Vec4 value)
{
    Mtx::setLine_(line,value);
}

void Mtx4x4::setColumn_(unsigned int column, Vec4 value)
{
    Mtx::setColumn_(column,value);
}

Mtx4x4 *Mtx4x4::sum(Mtx4x4 *mtx)
{
    return (Mtx4x4*) MtxNxN::sum(mtx);
}

Mtx4x4 *Mtx4x4::sub(Mtx4x4 *mtx)
{
    return (Mtx4x4*) MtxNxN::sub(mtx);
}

Mtx4x4 *Mtx4x4::prod(Mtx4x4 *mtx)
{
    return (Mtx4x4*) MtxNxN::prod(mtx);
}

Vec4 *Mtx4x4::prod(Vec4 *vec)
{
    return (Vec4*) MtxNxN::prod(vec);
}

Vec3 *Mtx4x4::prod(Vec3 *vec, double w)
{
    Vec4 *temp = new Vec4(vec,w);

    Vec3 *result = prod(temp)->getVec3();

    delete temp;

    return result;
}

Mtx4x4 *Mtx4x4::prod(double lambda)
{
    return (Mtx4x4*) MtxNxN::prod(lambda);
}

Mtx4x4 *Mtx4x4::inverse()
{
    return (Mtx4x4*) MtxNxN::inverse();
}

Mtx4x4 Mtx4x4::operator+(Mtx4x4 mtx)
{
    return (Mtx4x4) MtxNxN::operator+(mtx);
}

Mtx4x4 Mtx4x4::operator-(Mtx4x4 mtx)
{
    return (Mtx4x4) MtxNxN::operator-(mtx);
}

Mtx4x4 Mtx4x4::operator*(Mtx4x4 mtx)
{
    return (Mtx4x4) MtxNxN::operator*(mtx);
}

Vec4 Mtx4x4::operator*(Vec4 vec)
{
    return (Vec4) MtxNxN::operator*(vec);
}

Vec3 Mtx4x4::prod_(Vec3 vec, double w)
{
    return operator*(Vec4(&vec,w)).getVec3_();
}

Mtx4x4 Mtx4x4::operator*(double lambda)
{
    return (Mtx4x4) MtxNxN::operator*(lambda);
}

Mtx4x4 Mtx4x4::inverse_()
{
    return (Mtx4x4) MtxNxN::inverse_();
}

Mtx4x4 *Mtx4x4::copy()
{
    return (Mtx4x4*) MtxNxN::copy();
}

Mtx4x4 Mtx4x4::copy_()
{
    return (Mtx4x4) MtxNxN::copy_();
}

Mtx4x4 *Mtx4x4::getIdentity()
{
    return (Mtx4x4*) MtxNxN::getIdentity(4);
}

Mtx4x4 *Mtx4x4::getTranslateMtx(double x, double y, double z)
{
    Mtx4x4 *T = new Mtx4x4();

    T = getIdentity();
    T->setValue(0,3,x);
    T->setValue(1,3,y);
    T->setValue(2,3,z);

    return T;
}

Mtx4x4 *Mtx4x4::getRotateMtx(double degree, bool x, bool y, bool z)
{
    Mtx4x4 *R = getIdentity();

    if (x) {
        R->setValue(1,1,cos(degree));
        R->setValue(1,2,-sin(degree));
        R->setValue(2,1,sin(degree));
        R->setValue(2,2,cos(degree));
    } else if (y) {
        R->setValue(0,0,cos(degree));
        R->setValue(0,2,sin(degree));
        R->setValue(2,0,-sin(degree));
        R->setValue(2,2,cos(degree));
    } else if (z) {
        R->setValue(0,0,cos(degree));
        R->setValue(0,1,-sin(degree));
        R->setValue(1,0,sin(degree));
        R->setValue(1,1,cos(degree));
    }

    return R;
}

Mtx4x4 *Mtx4x4::getScaleMtx(double x, double y, double z)
{
    Mtx4x4 *S = new Mtx4x4();

    S = getIdentity();
    S->setValue(0,0,x);
    S->setValue(1,1,y);
    S->setValue(2,2,z);

    return S;
}

Mtx4x4 Mtx4x4::getIdentity_()
{
    return (Mtx4x4) MtxNxN::getIdentity_(4);
}

Mtx4x4 Mtx4x4::getTranslateMtx_(double x, double y, double z)
{
    Mtx4x4 T = getIdentity_();

    T.setValue(0,3,x);
    T.setValue(1,3,y);
    T.setValue(2,3,z);

    return T;
}

Mtx4x4 Mtx4x4::getRotateMtx_(double degree, bool x, bool y, bool z)
{
    Mtx4x4 R = getIdentity_();

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

Mtx4x4 Mtx4x4::getScaleMtx_(double x, double y, double z)
{
    Mtx4x4 S = getIdentity_();

    S.setValue(0,0,x);
    S.setValue(1,1,y);
    S.setValue(2,2,z);

    return S;
}
