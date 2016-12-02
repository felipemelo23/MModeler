#ifndef CAMERA_H
#define CAMERA_H

#include <algebra/mtx4x4.h>
#include <algebra/vec2.h>



class Camera
{
public:
    Camera();
    Camera(Vec3 origin, Vec3 lookAt, Vec3 viewUp);

    Mtx4x4 getCW() const;
    Mtx4x4 getWC() const;

    Vec2 getMaxPP() const;
    void setMaxPP(Vec2 value);

    Vec2 getMinPP() const;
    void setMinPP(Vec2 value);

    double getProjectionPlane() const;
    void setProjectionPlane(double value);

    Vec3 getOrigin() const;

private:
    Mtx4x4 cw;
    Mtx4x4 wc;
    Vec3 origin;

    Vec2 maxPP;
    Vec2 minPP;
    double projectionPlane;
};

#endif // CAMERA_H
