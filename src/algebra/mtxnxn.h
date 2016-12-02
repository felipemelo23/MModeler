#ifndef MTXNXN_H
#define MTXNXN_H

#include "mtx.h"
#include "vecn.h"
#include <stdarg.h>

class MtxNxN : public Mtx
{
public:
    MtxNxN(double value=0);
    MtxNxN(int n, double value=0);
    MtxNxN(int n, double v1, double v2, ...);
    MtxNxN(Mtx mtx);

    int getN();
    void loadIdentity();

    MtxNxN *sum(MtxNxN *mtx);
    MtxNxN *sub(MtxNxN *mtx);
    MtxNxN *prod(MtxNxN *mtx);
    VecN *prod(VecN *vec);
    MtxNxN *prod(double lambda);
    MtxNxN *inverse();

    MtxNxN operator+(MtxNxN mtx);
    MtxNxN operator-(MtxNxN mtx);
    MtxNxN operator*(MtxNxN mtx);
    VecN operator*(VecN mtx);
    MtxNxN operator*(double lambda);
    MtxNxN inverse_();

    MtxNxN *copy();
    MtxNxN copy_();

    static MtxNxN *getIdentity(int n);
    static MtxNxN getIdentity_(int n);
};

#endif // MTXNXN_H
