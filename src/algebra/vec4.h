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
    Vec4(Vec3 vec, double w);
    Vec4(Mtx mtx);

    double getX();
    double getY();
    double getZ();
    double getW();

    void setX(double value);
    void setY(double value);
    void setZ(double value);
    void setW(double value);

    Vec3 *getVec3();
    Vec3 getVec3_();

    Vec4 *sum(Vec4 *vec);
    Vec4 *sum_(Vec4 *vec);
    Vec4 *sub(Vec4 *vec);
    Vec4 *prod(double lambda);
    double dot(Vec4 *vec);
    Vec4 *cross(Vec4 *vec);

    Vec4 operator+(Vec4 vec);
    Vec4 operator-(Vec4 vec);
    Vec4 operator*(double lambda);
    double dot_(Vec4 vec);
    Vec4 cross_(Vec4 vec);

    bool isColumn();
    void normalize();
    double getNorm();

    Vec4 *copy();
    Vec4 copy_();
};

#endif // VEC4_H
