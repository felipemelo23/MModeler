#ifndef COMPOUNDOBJECT_H
#define COMPOUNDOBJECT_H

#include "object.h"
#include <cmath>

using std::max;
using std::min;

class CompoundObject : public Object
{
public:
    CompoundObject(Object *a, Object *b);
    ~CompoundObject();

    bool isInside(Vec4 *pos);
    Vec3 *getMaximumCoords();
    Vec3 *getMinimumCoords();

    Object *getObjectA();
    Object *getObjectB();

    Vec3 *getOrigin();

    void translate(double x, double y, double z);
    void scale(double x, double y, double z);
    void rotate(double degree, bool x=true, bool y=false, bool z=false);

private:
    Object *a;
    Object *b;
};

#endif // COMPOUNDOBJECT_H
