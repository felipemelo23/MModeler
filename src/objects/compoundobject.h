#ifndef COMPOUNDOBJECT_H
#define COMPOUNDOBJECT_H

#include "object.h"
#include <cmath>

using std::max;
using std::min;

class CompoundObject : public Object
{
public:
    CompoundObject(Object *a, Object *b, int op);
    ~CompoundObject();

    int isInside(Vec4 *pos);
    vector<RCResult> checkIntersection(Ray *ray);
    Vec3 *getMaximumCoords();
    Vec3 *getMinimumCoords();

    Object *getObjectA();
    Object *getObjectB();

    Vec3 *getOrigin();

    void translate(double x, double y, double z);
    void scale(double x, double y, double z);
    void rotate(double degree, bool x=true, bool y=false, bool z=false);

    static const int UNION = 0;
    static const int INTERSECT = 1;
    static const int DIFFERENCE = 2;

    int getOperation() const;

private:
    int operation;
    Object *a;
    Object *b;

    vector<RCResult> merge(vector<RCResult> aResult,vector<RCResult> bResult);
};

#endif // COMPOUNDOBJECT_H
