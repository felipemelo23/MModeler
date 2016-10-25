#ifndef RBPYRAMID_H
#define RBPYRAMID_H

#include <objects/object.h>

class RBPyramid : public Object
{
private:
    int numOfSides;

public:
    RBPyramid(int numOfSides=3);
    ~RBPyramid();
    void section(Vec2 **v, double radius);
    bool isInside(Vec4 *pos);
    Vec3 *getMaximumCoords();
    Vec3 *getMinimumCoords();
    int getNumOfSides() const;

    std::pair<RCResult,RCResult> checkIntersection(Ray *ray);

    Vec4 **getVertices();
};

#endif // RBPYRAMID_H
