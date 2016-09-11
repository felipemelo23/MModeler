#ifndef MTX4X4_H
#define MTX4X4_H

#include "mtxnxn.h"
#include "vec4.h"

class Mtx4x4 : public MtxNxN
{
public:
    Mtx4x4(double value=0);
    ~Mtx4x4();

    Vec4 *getLine(unsigned int line);
    Vec4 *getColumn(unsigned int column);
    void setLine(unsigned int line, Vec4 *value);
    void setColumn(unsigned int column, Vec4 *value);

    Mtx4x4 *sum(Mtx4x4 *mtx);
    Mtx4x4 *sub(Mtx4x4 *mtx);
    Mtx4x4 *prod(Mtx4x4 *mtx);
    Vec4 *prod(Vec4 *vec);
    Mtx4x4 *prod(double lambda);
    Mtx4x4 *inverse();

    Mtx4x4 *copy();

    static Mtx4x4 *getIdentity();
    static Mtx4x4 *getTranslateMtx(double x, double y, double z);
    static Mtx4x4 *getRotateMtx(double degree, bool x, bool y, bool z);
    static Mtx4x4 *getScaleMtx(double x, double y, double z);
};

#endif // MTX4X4_H
