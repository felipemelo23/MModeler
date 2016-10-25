#ifndef RCRESULT_H
#define RCRESULT_H

#include "material.h"
#include <algebra/vec3.h>

class RCResult
{
public:
    RCResult();
    RCResult(double t);
    RCResult(bool intersected, double t, Vec3 *point, Vec3 *normal, Material *material);

    bool getIntersected() const;
    double getT() const;
    Vec3 *getPoint() const;
    Vec3 *getNormal() const;
    Material *getMaterial() const;

private:
    bool intersected;
    double t;
    Vec3 *point;
    Vec3 *normal;
    Material *material;

};

#endif // RCRESULT_H
