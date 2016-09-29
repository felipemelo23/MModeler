#ifndef SPHERE_H
#define SPHERE_H

#include <objects/object.h>

class Sphere : public Object
{
public:
    Sphere();
    ~Sphere();

    Vec3 *getMinimumCoords();
    Vec3 *getMaximumCoords();
    bool isInside(Vec4 *pos);

    Vec4 **getVertices(int height, int width);

};

#endif // SPHERE_H
