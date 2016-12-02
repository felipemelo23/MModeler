#ifndef SPHERE_H
#define SPHERE_H

#include <objects/object.h>

class Sphere : public Object
{
public:
    Sphere();
    ~Sphere();

    Vec3 getMinimumCoords();
    Vec3 getMaximumCoords();
    int isInside(Vec4 pos);

    Vec4 *getVertices(int height, int width);

    vector<RCResult> checkIntersection(Ray ray);

};

#endif // SPHERE_H
