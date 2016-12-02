#ifndef CYLINDER_H
#define CYLINDER_H

#include "object.h"

class Cylinder : public Object
{
public:
    Cylinder();
    int isInside(Vec4 pos);
    Vec3 getMaximumCoords();
    Vec3 getMinimumCoords();

    vector<RCResult> checkIntersection(Ray ray);

    Vec4 *getVertices(int discretization);
private:
    vector<RCResult> sort(vector<RCResult> results);
    RCResult checkTopIntersect(Ray ray, Vec3 origin);
    RCResult checkBaseIntersect(Ray ray, Vec3 origin);
    std::pair<RCResult,RCResult> checkFoldIntersect(Ray ray, Vec3 origin, double a, double b, double c);
};

#endif // CYLINDER_H
