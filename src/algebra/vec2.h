#ifndef VEC2_H
#define VEC2_H

#include "vecn.h"

class Vec2 : public VecN
{
public:
    Vec2(double value=0);
    Vec2(double x, double y);
    Vec2(Mtx mtx);

    double getX();
    double getY();

    void setX(double value);
    void setY(double value);

    Vec2 *sum(Vec2 *vec);
    Vec2 *sub(Vec2 *vec);
    Vec2 *prod(double lambda);
    double dot(Vec2 *vec);
    double cross(Vec2 *vec);

    Vec2 operator+(Vec2 vec);
    Vec2 operator-(Vec2 vec);
    Vec2 operator*(double lambda);
    double dot_(Vec2 vec);
    double cross_(Vec2 vec);

    bool isColumn();
    void normalize();
    double getNorm();

    Vec2 *copy();
    Vec2 copy_();
};

#endif // VEC2_H
