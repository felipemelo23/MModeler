#ifndef MTX2X2_H
#define MTX2X2_H

#include "mtxnxn.h"
#include "vec2.h"

class Mtx2x2 : public MtxNxN
{
public:
    Mtx2x2(double value=0);
    Mtx2x2(double v00,double v01,double v10,double v11);
    Mtx2x2(Mtx mtx);
    ~Mtx2x2();

    Vec2 *getLine(unsigned int line);
    Vec2 *getColumn(unsigned int column);
    void setLine(unsigned int line, Vec2 *value);
    void setColumn(unsigned int column, Vec2 *value);

    Vec2 getLine_(unsigned int line);
    Vec2 getColumn_(unsigned int column);
    void setLine_(unsigned int line, Vec2 value);
    void setColumn_(unsigned int column, Vec2 value);

    Mtx2x2 *sum(Mtx2x2 *mtx);
    Mtx2x2 *sub(Mtx2x2 *mtx);
    Mtx2x2 *prod(Mtx2x2 *mtx);
    Vec2 *prod(Vec2 *vec);
    Mtx2x2 *prod(double lambda);
    Mtx2x2 *inverse();

    Mtx2x2 operator+(Mtx2x2 mtx);
    Mtx2x2 operator-(Mtx2x2 mtx);
    Mtx2x2 operator*(Mtx2x2 mtx);
    Vec2 operator*(Vec2 vec);
    Mtx2x2 operator*(double lambda);
    Mtx2x2 inverse_();

    Mtx2x2 *copy();
    Mtx2x2 copy_();

    static Mtx2x2 *getIdentity();
    static Mtx2x2 *getRotateMtx(double degree);
    static Mtx2x2 *getScaleMtx(double x, double y);

    static Mtx2x2 getIdentity_();
    static Mtx2x2 getRotateMtx_(double degree, bool x, bool y, bool z);
    static Mtx2x2 getScaleMtx_(double x, double y, double z);
};

#endif // MTX2X2_H
