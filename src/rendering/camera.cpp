#include "camera.h"
#include <iostream>

using namespace std;

Camera::Camera() {}

Camera::Camera(Vec3 origin, Vec3 lookAt, Vec3 viewUp)
{
    Vec3 x;
    Vec3 y;
    Vec3 z;

    z = origin - lookAt;
    z.normalize();

    viewUp.normalize();
    x = viewUp.cross_(z);
    x.normalize();

    y = z.cross_(x);
    y.normalize();

    cw = Mtx4x4();
    cw.setColumn_(0,Vec4(x,0));
    cw.setColumn_(1,Vec4(y,0));
    cw.setColumn_(2,Vec4(z,0));
    cw.setColumn_(3,Vec4(origin,1));

    wc = Mtx4x4();
    wc.loadIdentity();
    Vec4 line = Vec4(x,-x.dot_(origin));
    line.transpose();
    wc.setLine_(0,line);
    line = Vec4(y,-y.dot_(origin));
    line.transpose();
    wc.setLine_(1,line);
    line = Vec4(z,-z.dot_(origin));
    line.transpose();
    wc.setLine_(2,line);

    this->origin = origin;
    minPP = Vec2(-0.5,-0.5);
    maxPP = Vec2(0.5,0.5);
    projectionPlane = -1;
}

Mtx4x4 Camera::getCW() const
{
    return cw;
}

Mtx4x4 Camera::getWC() const
{
    return wc;
}

Vec2 Camera::getMaxPP() const
{
    return maxPP;
}

void Camera::setMaxPP(Vec2 value)
{
    maxPP = value;
}

Vec2 Camera::getMinPP() const
{
    return minPP;
}

void Camera::setMinPP(Vec2 value)
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

Vec3 Camera::getOrigin() const
{
    return origin;
}
