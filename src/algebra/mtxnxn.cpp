#include "mtxnxn.h"

MtxNxN::MtxNxN(double value) : Mtx(value) {}

MtxNxN::MtxNxN(int n, double value) : Mtx(n,n,value) {}

MtxNxN::MtxNxN(int n, double v1, double v2, ...)
{
    this->lines = n;
    this->columns = n;

    initializeMatrix(1);

    setValue(0,0,v1);
    setValue(0,1,v2);

    if (lines*columns > 2) {
        va_list vl;

        va_start(vl,v2);

        for (int column = 2; column < getColumns(); column++) {
            double value = va_arg(vl,double);
            setValue(0,column,value);
        }

        for (int line = 1; line < getLines(); line++) {
            for (int column = 0; column < getColumns(); column++) {
                double value = va_arg(vl,double);
                setValue(line,column,value);
            }
        }

        va_end(vl);
    }
}

MtxNxN::MtxNxN(Mtx mtx)
{
    this->lines = mtx.getLines();
    this->columns = mtx.getColumns();

    initializeMatrix(1);

    for (int column = 0; column < columns; column++) {
        for (int line = 0; line < lines; line++) {
            setValue(line,column,mtx.getValue(line,column));
        }
    }
}

int MtxNxN::getN()
{
    return lines;
}

void MtxNxN::loadIdentity()
{
    for (unsigned int line=0;line<lines;line++) {
        for (unsigned int column=0;column<columns;column++) {
            if (line!=column)
                setValue(line,column,0);
            else
                setValue(line,column,1);
        }
    }
}

MtxNxN *MtxNxN::sum(MtxNxN *mtx)
{
    return (MtxNxN*) Mtx::sum(mtx);
}

MtxNxN *MtxNxN::sub(MtxNxN *mtx)
{
    return (MtxNxN*) Mtx::sub(mtx);
}

MtxNxN *MtxNxN::prod(MtxNxN *mtx)
{
    return (MtxNxN*) Mtx::prod(mtx);
}

VecN *MtxNxN::prod(VecN *vec)
{
    if (vec->getColumns() > 1) vec->transpose();

    return (VecN*) Mtx::prod(vec);
}

MtxNxN *MtxNxN::prod(double lambda)
{
    return (MtxNxN*) Mtx::prod(lambda);
}

MtxNxN *MtxNxN::inverse()
{
    Mtx *mtx = this->copy();

    mtx = mtx->join(Mtx::RIGHT,MtxNxN::getIdentity(getN()));

    gaussElimination(mtx);

    MtxNxN *result = (MtxNxN*) mtx->getSubMatrix(0,mtx->getLines()-1,getN(),mtx->getColumns()-1);

    delete mtx;
    return result;
}

MtxNxN MtxNxN::operator+(MtxNxN mtx)
{
    return (MtxNxN) Mtx::operator+(mtx);
}

MtxNxN MtxNxN::operator-(MtxNxN mtx)
{
    return (MtxNxN) Mtx::operator-(mtx);
}

MtxNxN MtxNxN::operator*(MtxNxN mtx)
{
    return (MtxNxN) Mtx::operator*(mtx);
}

VecN MtxNxN::operator*(VecN vec)
{
    if (vec.getColumns() > 1) vec.transpose();

    return (VecN) Mtx::operator*(vec);
}

MtxNxN MtxNxN::operator*(double lambda)
{
    return (MtxNxN) Mtx::operator*(lambda);
}

MtxNxN MtxNxN::inverse_()
{
    Mtx mtx = this->copy_();

    mtx = mtx.join_(Mtx::RIGHT,MtxNxN::getIdentity_(getN()));

    gaussElimination(&mtx);

    return (MtxNxN) mtx.getSubMatrix_(0,mtx.getLines()-1,getN(),mtx.getColumns()-1);
}

MtxNxN *MtxNxN::copy()
{
    return (MtxNxN*) Mtx::copy();
}

MtxNxN MtxNxN::copy_()
{
    return (MtxNxN) Mtx::copy_();
}

MtxNxN *MtxNxN::getIdentity(int n)
{
    MtxNxN *I = new MtxNxN(n);
    I->loadIdentity();

    return I;
}

MtxNxN MtxNxN::getIdentity_(int n)
{
    MtxNxN I = MtxNxN(n);
    I.loadIdentity();

    return I;
}
