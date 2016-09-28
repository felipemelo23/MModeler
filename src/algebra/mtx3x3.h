#ifndef MTX3X3_H
#define MTX3X3_H

#include "mtxnxn.h"
#include "vec3.h"

class Mtx3x3 : public MtxNxN
{
public:
    Mtx3x3(double value=0);
    Mtx3x3(double v00,double v01,double v02,double v10,double v11, double v12,double v20,double v21, double v22);
    ~Mtx3x3();

    Vec3 *getLine(unsigned int line);
    Vec3 *getColumn(unsigned int column);
    void setLine(unsigned int line, Vec3 *value);
    void setColumn(unsigned int column, Vec3 *value);

    Mtx3x3 *sum(Mtx3x3 *mtx);
    Mtx3x3 *sub(Mtx3x3 *mtx);
    Mtx3x3 *prod(Mtx3x3 *mtx);
    Vec3 *prod(Vec3 *vec);
    Mtx3x3 *prod(double lambda);
    Mtx3x3 *inverse();

    Mtx3x3 *copy();

    static Mtx3x3 *getIdentity();
    static Mtx3x3 *getRotateMtx(double degree, bool x=true, bool y=false, bool z=false);
    static Mtx3x3 *getScaleMtx(double x, double y, double z);
};

#endif // MTX3X3_H
