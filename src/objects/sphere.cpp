#include <objects/sphere.h>

#include <iostream>

using namespace std;

Sphere::Sphere() : Object() {
    type = Object::SPHERE;
    name = "Sphere";
}

Sphere::~Sphere()
{
    delete ow;
    delete wo;
}

Vec3 *Sphere::getMinimumCoords()
{
    Vec4 **v = new Vec4*[8];
    Vec4 *trash;

    v[0] = new Vec4(-0.5,-0.5,-0.5,1);
    v[1] = new Vec4(-0.5,-0.5,0.5,1);
    v[2] = new Vec4(-0.5,0.5,-0.5,1);
    v[3] = new Vec4(-0.5,0.5,0.5,1);
    v[4] = new Vec4(0.5,-0.5,-0.5,1);
    v[5] = new Vec4(0.5,-0.5,0.5,1);
    v[6] = new Vec4(0.5,0.5,-0.5,1);
    v[7] = new Vec4(0.5,0.5,0.5,1);

    for (int i=0;i<8;i++) {
        trash = v[i];
        v[i] = ow->prod(v[i]);
        delete trash;
    }

    double x = v[0]->getX();
    double y = v[0]->getY();
    double z = v[0]->getZ();

    for (int i=1;i<8;i++) {
        if (x > v[i]->getX()) x = v[i]->getX();
        if (y > v[i]->getY()) y = v[i]->getY();
        if (z > v[i]->getZ()) z = v[i]->getZ();
    }

    for (int i=0;i<8;i++) {
        delete v[i];
    }
    delete v;

    return new Vec3(x,y,z);
}

Vec3 *Sphere::getMaximumCoords()
{
    Vec4 **v = new Vec4*[8];
    Vec4 *trash;

    v[0] = new Vec4(-0.5,-0.5,-0.5,1);
    v[1] = new Vec4(-0.5,-0.5,0.5,1);
    v[2] = new Vec4(-0.5,0.5,-0.5,1);
    v[3] = new Vec4(-0.5,0.5,0.5,1);
    v[4] = new Vec4(0.5,-0.5,-0.5,1);
    v[5] = new Vec4(0.5,-0.5,0.5,1);
    v[6] = new Vec4(0.5,0.5,-0.5,1);
    v[7] = new Vec4(0.5,0.5,0.5,1);

    for (int i=0;i<8;i++)
    {
        trash = v[i];
        v[i] = ow->prod(v[i]);
        delete trash;
    }

    double x = v[0]->getX();
    double y = v[0]->getY();
    double z = v[0]->getZ();

    for (int i=1;i<8;i++)
    {
        if (x < v[i]->getX()) x = v[i]->getX();
        if (y < v[i]->getY()) y = v[i]->getY();
        if (z < v[i]->getZ()) z = v[i]->getZ();
    }

    for (int i=0;i<8;i++) {
        delete v[i];
    }
    delete v;

    return new Vec3(x,y,z);
}

bool Sphere::isInside(Vec4 *pos)
{
    Vec4 *canon = wo->prod(pos);

    double norm = canon->getVec3()->normColumn(0);

    delete canon;

    return norm <= 0.5;
}

Vec4 **Sphere::getVertices(int height, int width)
{
    Vec4 **v = new Vec4*[(height-1)*width + 2];

    Mtx4x4 *rotZ = Mtx4x4::getRotateMtx((3.141592)/height,false,false,true);
    Mtx4x4 *rotY = Mtx4x4::getRotateMtx((2*3.141592)/width,false,true,false);

    v[0] = new Vec4(0,0.5,0,1);
    v[1] = new Vec4(0,-0.5,0,1);

    for (int i=0;i<height-1;i++) {
        v[i+2] = rotZ->prod(v[i+1]);
    }

    for (int i=1;i<width;i++) {
        int currBase = 2+(height-1)*i;
        int prevBase = 2+(height-1)*(i-1);
        for (int j=0;j<height-1;j++) {
            v[currBase+j] = rotY->prod(v[prevBase+j]);
        }
    }

    Vec4 *trash;
    for (int i=0;i<(height-1)*width + 2;i++) {
        trash = v[i];
        v[i] = ow->prod(v[i]);
        delete trash;
    }

    delete rotZ;
    delete rotY;

    return v;
}

std::pair<RCResult, RCResult> Sphere::checkIntersection(Ray *ray)
{
    Ray *tRay = ray->transform(wo);

    double a = pow(tRay->getDir()->getX(),2) +
               pow(tRay->getDir()->getY(),2) +
               pow(tRay->getDir()->getZ(),2);
    double b = 2*(tRay->getOrigin()->getX()*tRay->getDir()->getX() +
                  tRay->getOrigin()->getY()*tRay->getDir()->getY() +
                  tRay->getOrigin()->getZ()*tRay->getDir()->getZ());
    double c = pow(tRay->getOrigin()->getX(),2) +
               pow(tRay->getOrigin()->getY(),2) +
               pow(tRay->getOrigin()->getZ(),2) - pow(0.5,2);

    double delta = (b*b) - (4*a*c);

    if (delta < 0) return std::make_pair(RCResult(),RCResult());

    if (delta == 0) {
        double t = -b/(2*a);
        Vec3 *point = ow->prod(tRay->getPoint(t),1);
        Vec3 *normal = point->sub(getOrigin());
        normal->normalize();

        delete tRay;
        return std::make_pair(RCResult(true,t,point,normal,material),RCResult());
    }

    double t1 = (-b + sqrt(delta))/(2*a);
    double t2 = (-b - sqrt(delta))/(2*a);

    Vec3 *nearestPoint = ow->prod(tRay->getPoint(min(t1,t2)),1);
    Vec3 *nearestNormal = nearestPoint->sub(getOrigin());
    nearestNormal->normalize();

    Vec3 *farthestPoint = ow->prod(tRay->getPoint(max(t1,t2)),1);
    Vec3 *farthestNormal = farthestPoint->sub(getOrigin());
    farthestNormal->normalize();

    return std::make_pair(RCResult(true,min(t1,t2),nearestPoint,nearestNormal,material),
                          RCResult(true,max(t1,t2),farthestPoint,farthestNormal,material));

}

















