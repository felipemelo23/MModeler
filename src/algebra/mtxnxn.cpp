#include "mtxnxn.h"

MtxNxN::MtxNxN(double value) : Mtx(value) {}

MtxNxN::MtxNxN(int n, double value) : Mtx(n,n,value) {}

MtxNxN::~MtxNxN() {}

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

MtxNxN *MtxNxN::copy()
{
    return (MtxNxN*) Mtx::copy();
}

MtxNxN *MtxNxN::getIdentity(int n)
{
    MtxNxN *I = new MtxNxN(n);
    I->loadIdentity();

    return I;
}
