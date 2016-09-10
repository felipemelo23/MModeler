#ifndef VEC3_H
#define VEC3_H

#include "vecn.h"

class Vec3 : public VecN
{
public:
    Vec3(double value=0);
    Vec3(double x, double y, double z);
    ~Vec3();

    double getX();
    double getY();
    double getZ();

    void setX(double value);
    void setY(double value);
    void setZ(double value);

    Vec3 *sum(Vec3 *vec);
    Vec3 *sub(Vec3 *vec);
    Vec3 *prod(double lambda);
    double dot(Vec3 *vec);
    Vec3 *cross(Vec3 *vec);

    bool isColumn();
    void normalize();
    double getNorm();

    Vec3 *copy();
};

#endif // VEC3_H
