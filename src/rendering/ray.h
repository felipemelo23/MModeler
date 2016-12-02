#ifndef RAY_H
#define RAY_H

#include <algebra/mtx4x4.h>
#include <algebra/vec4.h>



class Ray
{
public:
    Ray(Vec3 origin, Vec3 dir);

    Ray transform(Mtx4x4 transfMtx);

    Vec4 getOrigin() const;
    Vec4 getDir() const;
    Vec3 getPoint(double t);

private:
    Vec4 origin;
    Vec4 dir;
};

#endif // RAY_H
