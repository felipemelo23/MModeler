#ifndef MTX4X4_H
#define MTX4X4_H

#include "mtxnxn.h"
#include "vec4.h"

class Mtx4x4 : public MtxNxN
{
public:
    Mtx4x4(double value=0);
    Mtx4x4(double v00,double v01,double v02,double v03,
           double v10,double v11,double v12,double v13,
           double v20,double v21,double v22,double v23,
           double v30,double v31,double v32,double v33);
    Mtx4x4(Mtx mtx);
    ~Mtx4x4();

    Vec4 *getLine(unsigned int line);    
    Vec4 *getColumn(unsigned int column);
    void setLine(unsigned int line, Vec4 *value);
    void setColumn(unsigned int column, Vec4 *value);

    Vec4 getLine_(unsigned int line);
    Vec4 getColumn_(unsigned int column);
    void setLine_(unsigned int line, Vec4 value);
    void setColumn_(unsigned int column, Vec4 value);

    Mtx4x4 *sum(Mtx4x4 *mtx);
    Mtx4x4 *sub(Mtx4x4 *mtx);
    Mtx4x4 *prod(Mtx4x4 *mtx);
    Vec4 *prod(Vec4 *vec);
    Vec3 *prod(Vec3 *vec, double w);
    Mtx4x4 *prod(double lambda);
    Mtx4x4 *inverse();

    Mtx4x4 operator+(Mtx4x4 mtx);
    Mtx4x4 operator-(Mtx4x4 mtx);
    Mtx4x4 operator*(Mtx4x4 mtx);
    Vec4 operator*(Vec4 vec);
    Vec3 prod_(Vec3 vec, double w);
    Mtx4x4 operator*(double lambda);
    Mtx4x4 inverse_();

    Mtx4x4 *copy();
    Mtx4x4 copy_();

    static Mtx4x4 *getIdentity();
    static Mtx4x4 *getTranslateMtx(double x, double y, double z);
    static Mtx4x4 *getRotateMtx(double degree, bool x, bool y, bool z);
    static Mtx4x4 *getScaleMtx(double x, double y, double z);

    static Mtx4x4 getIdentity_();
    static Mtx4x4 getTranslateMtx_(double x, double y, double z);
    static Mtx4x4 getRotateMtx_(double degree, bool x, bool y, bool z);
    static Mtx4x4 getScaleMtx_(double x, double y, double z);
};

#endif // MTX4X4_H
