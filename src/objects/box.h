#ifndef BOX_H
#define BOX_H

#include "object.h"

class Box : public Object
{
public:
    Box();
    ~Box();

    Vec3 getMinimumCoords();
    Vec3 getMaximumCoords();
    int isInside(Vec4 pos);

    Vec4 *getVertices();

    vector<RCResult> checkIntersection(Ray ray);
private:
    vector<RCResult> sort(vector<RCResult> results);
};

#endif // BOX_H
