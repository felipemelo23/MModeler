#ifndef MTX3X3_H
#define MTX3X3_H

#include "mtxnxn.h"
#include "vec3.h"

class Mtx3x3 : public MtxNxN
{
public:
    Mtx3x3(double value=0);
    Mtx3x3(double v00,double v01,double v02,double v10,double v11, double v12,double v20,double v21, double v22);
    Mtx3x3(Mtx mtx);

    Vec3 *getLine(unsigned int line);
    Vec3 *getColumn(unsigned int column);
    void setLine(unsigned int line, Vec3 *value);
    void setColumn(unsigned int column, Vec3 *value);

    Vec3 getLine_(unsigned int line);
    Vec3 getColumn_(unsigned int column);
    void setLine_(unsigned int line, Vec3 value);
    void setColumn_(unsigned int column, Vec3 value);

    Mtx3x3 *sum(Mtx3x3 *mtx);
    Mtx3x3 *sub(Mtx3x3 *mtx);
    Mtx3x3 *prod(Mtx3x3 *mtx);
    Vec3 *prod(Vec3 *vec);
    Mtx3x3 *prod(double lambda);
    Mtx3x3 *inverse();

    Mtx3x3 operator+(Mtx3x3 mtx);
    Mtx3x3 operator-(Mtx3x3 mtx);
    Mtx3x3 operator*(Mtx3x3 mtx);
    Vec3 operator*(Vec3 vec);
    Mtx3x3 operator*(double lambda);
    Mtx3x3 inverse_();

    Mtx3x3 *copy();
    Mtx3x3 copy_();

    static Mtx3x3 *getIdentity();
    static Mtx3x3 *getRotateMtx(double degree, bool x=true, bool y=false, bool z=false);
    static Mtx3x3 *getScaleMtx(double x, double y, double z);

    static Mtx3x3 getIdentity_();
    static Mtx3x3 getRotateMtx_(double degree, bool x, bool y, bool z);
    static Mtx3x3 getScaleMtx_(double x, double y, double z);
};

#endif // MTX3X3_H
