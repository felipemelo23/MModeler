#include "ray.h"

Ray::Ray(Vec3 origin, Vec3 dir)
{
    this->origin = Vec4(origin,1);

    Vec3 nDir = dir.copy_();
    nDir.normalize();
    this->dir = Vec4(nDir,0);
}

Ray Ray::transform(Mtx4x4 transfMtx)
{
    return Ray((transfMtx*origin).getVec3_(),(transfMtx*dir).getVec3_());
}

Vec4 Ray::getOrigin() const
{
    return origin;
}

Vec4 Ray::getDir() const
{
    return dir;
}

Vec3 Ray::getPoint(double t)
{
    return origin.getVec3_() + (dir*t).getVec3_();
}
