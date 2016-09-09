#ifndef MTXNXN_H
#define MTXNXN_H

#include "mtx.h"
#include "vecn.h"

class MtxNxN : public Mtx
{
public:
    MtxNxN(double value=0);
    MtxNxN(int n, double value=0);
    ~MtxNxN();

    int getN();
    void loadIdentity();

    MtxNxN *sum(MtxNxN *mtx);
    MtxNxN *sub(MtxNxN *mtx);
    MtxNxN *prod(MtxNxN *mtx);
    VecN *prod(VecN *vec);
    MtxNxN *prod(double lambda);
    MtxNxN *inverse();

    MtxNxN *copy();

    static MtxNxN *getIdentity(int n);
};

#endif // MTXNXN_H
