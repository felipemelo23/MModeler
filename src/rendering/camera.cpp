#include "camera.h"
#include <iostream>

using namespace std;

Camera::Camera(Vec3 *origin, Vec3 *lookAt, Vec3 *viewUp)
{
    Vec3 *x;
    Vec3 *y;
    Vec3 *z;

    z = origin->sub(lookAt);
    z->normalize();

    viewUp->normalize();
    x = viewUp->cross(z);
    x->normalize();

    y = z->cross(x);
    y->normalize();

    cw = new Mtx4x4();
    cw->setColumn(0,new Vec4(x,0));
    cw->setColumn(1,new Vec4(y,0));
    cw->setColumn(2,new Vec4(z,0));
    cw->setColumn(3,new Vec4(origin,1));

    wc = new Mtx4x4();
    wc->loadIdentity();
    Vec4 *line = new Vec4(x,-x->dot(origin));
    line->transpose();
    wc->setLine(0,line);
    line = new Vec4(y,-y->dot(origin));
    line->transpose();
    wc->setLine(1,line);
    line = new Vec4(z,-z->dot(origin));
    line->transpose();
    wc->setLine(2,line);

    this->origin = origin;
    minPP = new Vec2(-0.5,-0.5);
    maxPP = new Vec2(0.5,0.5);
    projectionPlane = -1;
}

Mtx4x4 *Camera::getCW() const
{
    return cw;
}

Mtx4x4 *Camera::getWC() const
{
    return wc;
}

Vec2 *Camera::getMaxPP() const
{
    return maxPP;
}

void Camera::setMaxPP(Vec2 *value)
{
    maxPP = value;
}

Vec2 *Camera::getMinPP() const
{
    return minPP;
}

void Camera::setMinPP(Vec2 *value)
{
    minPP = value;
}

double Camera::getProjectionPlane() const
{
    return projectionPlane;
}

void Camera::setProjectionPlane(double value)
{
    projectionPlane = value;
}

Vec3 *Camera::getOrigin() const
{
    return origin;
}
