#ifndef RBPRISM_H
#define RBPRISM_H

#include <objects/object.h>
#include <algebra/mtx3x3.h>

class RBPrism : public Object
{
private:
    int numOfSides;

    vector<RCResult> sort(vector<RCResult> results);
public:
    RBPrism(int numOfSides=3);
    ~RBPrism();
    void section(Vec2 **v, double radius=0.5);
    int isInside(Vec4 *pos);
    Vec3 *getMaximumCoords();
    Vec3 *getMinimumCoords();
    int getNumOfSides() const;

    vector<RCResult> checkIntersection(Ray *ray);

    Vec4 **getVertices();
};

#endif // RBPRISM_H
