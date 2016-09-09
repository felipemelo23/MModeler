#include "vecn.h"

#include <iostream>

using namespace std;

VecN::VecN(double value) : Mtx(value) {}

VecN::VecN(int size, double value) : Mtx(size,1,value) {}

VecN::VecN(int size, double v1, double v2, ...)
{
    this->lines = size;
    this->columns = 1;

    initializeMatrix(1);

    setValue(0,v1);
    setValue(1,v2);

    if (size > 2) {
        va_list vl;

        va_start(vl,v2);

        for (int pos=2;pos<getSize();pos++) {
            double value = va_arg(vl,double);
            setValue(pos,value);
        }

        va_end(vl);
    }
}

VecN::~VecN() {}

int VecN::getSize()
{
    if (columns > 1) return columns;
    return lines;
}

double VecN::getValue(int pos)
{
    if (columns > 1) return Mtx::getValue(0,pos);
    return Mtx::getValue(pos,0);
}

void VecN::setValue(int pos, double value)
{
    if (columns > 1) Mtx::setValue(0,pos,value);
    Mtx::setValue(pos,0,value);
}

VecN *VecN::sum(VecN *vec)
{
    if (columns > 1) transpose();
    if (!vec->isColumn()) vec->transpose();

    return (VecN*) Mtx::sum(vec);
}

VecN *VecN::sub(VecN *vec)
{
    if (columns > 1) transpose();
    if (!vec->isColumn()) vec->transpose();

    return (VecN*) Mtx::sub(vec);
}

VecN *VecN::prod(double lambda)
{
    return (VecN*) Mtx::prod(lambda);
}

Mtx *VecN::prod(VecN *vec)
{
    return (Mtx*)Mtx::prod(vec);
}

double VecN::dot(VecN *vec)
{
    if (isColumn()) transpose();
    if (!vec->isColumn()) vec->transpose();

    return Mtx::prod(vec)->getValue(0,0);
}

bool VecN::isColumn()
{
    return !(columns>1);
}

void VecN::normalize()
{
    if (!isColumn()) transpose();

    normalizeColumn(0);
}

double VecN::getNorm()
{
    if (!isColumn()) transpose();

    return normColumn(0);
}

VecN *VecN::getSubVec(int initialPos, int finalPos)
{
    if (!isColumn()) transpose();

    if (finalPos < 0) {
        return (VecN*)Mtx::getSubMatrix(initialPos,getSize()-1,0,0);
    }
    return (VecN*)Mtx::getSubMatrix(initialPos,finalPos,0,0);
}

void VecN::setSubVec(int initialPos, VecN *vec)
{
    if (!isColumn()) transpose();

    Mtx::setSubMatrix(initialPos,0,vec);
}

VecN *VecN::copy()
{
    return (VecN*)Mtx::copy();
}
