#ifndef RBPRISM_H
#define RBPRISM_H

#include <objects/object.h>
#include <algebra/mtx3x3.h>

class RBPrism : public Object
{
private:
    int numOfSides;

public:
    RBPrism(int numOfSides=3);
    ~RBPrism();
    void section(Vec2 **v, double radius=0.5);
    bool isInside(Vec4 *pos);
    Vec3 *getMaximumCoords();
    Vec3 *getMinimumCoords();
};

#endif // RBPRISM_H
