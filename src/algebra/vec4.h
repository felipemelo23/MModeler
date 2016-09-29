#ifndef VEC4_H
#define VEC4_H

#include "vec3.h"
#include "vecn.h"

class Vec4 : public VecN
{
public:
    Vec4(double value=0);
    Vec4(double x, double y, double z, double w);
    Vec4(Vec3 *vec, double w);
    ~Vec4();

    double getX();
    double getY();
    double getZ();
    double getW();

    void setX(double value);
    void setY(double value);
    void setZ(double value);
    void setW(double value);

    Vec4 *sum(Vec4 *vec);
    Vec4 *sub(Vec4 *vec);
    Vec4 *prod(double lambda);
    double dot(Vec4 *vec);
    Vec4 *cross(Vec4 *vec);

    bool isColumn();
    void normalize();
    double getNorm();

    Vec4 *copy();
};

#endif // VEC4_H
