#include "ray.h"

Ray::Ray(Vec3 *origin, Vec3 *dir)
{
    this->origin = new Vec4(origin,1);

    Vec3 *nDir = dir->copy();
    nDir->normalize();
    this->dir = new Vec4(nDir,0);
    delete nDir;
}

Ray *Ray::transform(Mtx4x4 *transfMtx)
{
    return new Ray(transfMtx->prod(origin)->getVec3(),transfMtx->prod(dir)->getVec3());
}

Vec4 *Ray::getOrigin() const
{
    return origin;
}

Vec4 *Ray::getDir() const
{
    return dir;
}

Vec3 *Ray::getPoint(double t)
{
    return origin->sum(dir->prod(t))->getVec3();
}
