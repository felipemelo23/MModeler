#include <objects/sphere.h>

#include <iostream>

using namespace std;

Sphere::Sphere() : Object() {
    type = Object::SPHERE;
    name = "Sphere";
}

Sphere::~Sphere() {}

Vec3 Sphere::getMinimumCoords()
{
    Vec4 *v = new Vec4[8];

    v[0] = Vec4(-0.5,-0.5,-0.5,1);
    v[1] = Vec4(-0.5,-0.5,0.5,1);
    v[2] = Vec4(-0.5,0.5,-0.5,1);
    v[3] = Vec4(-0.5,0.5,0.5,1);
    v[4] = Vec4(0.5,-0.5,-0.5,1);
    v[5] = Vec4(0.5,-0.5,0.5,1);
    v[6] = Vec4(0.5,0.5,-0.5,1);
    v[7] = Vec4(0.5,0.5,0.5,1);

    for (int i=0;i<8;i++) {
        v[i] = ow*v[i];
    }

    double x = v[0].getX();
    double y = v[0].getY();
    double z = v[0].getZ();

    for (int i=1;i<8;i++) {
        if (x > v[i].getX()) x = v[i].getX();
        if (y > v[i].getY()) y = v[i].getY();
        if (z > v[i].getZ()) z = v[i].getZ();
    }

    delete[] v;

    return Vec3(x,y,z);
}

Vec3 Sphere::getMaximumCoords()
{
    Vec4 *v = new Vec4[8];

    v[0] = Vec4(-0.5,-0.5,-0.5,1);
    v[1] = Vec4(-0.5,-0.5,0.5,1);
    v[2] = Vec4(-0.5,0.5,-0.5,1);
    v[3] = Vec4(-0.5,0.5,0.5,1);
    v[4] = Vec4(0.5,-0.5,-0.5,1);
    v[5] = Vec4(0.5,-0.5,0.5,1);
    v[6] = Vec4(0.5,0.5,-0.5,1);
    v[7] = Vec4(0.5,0.5,0.5,1);

    for (int i=0;i<8;i++)
    {
        v[i] = ow*v[i];
    }

    double x = v[0].getX();
    double y = v[0].getY();
    double z = v[0].getZ();

    for (int i=1;i<8;i++)
    {
        if (x < v[i].getX()) x = v[i].getX();
        if (y < v[i].getY()) y = v[i].getY();
        if (z < v[i].getZ()) z = v[i].getZ();
    }

    delete[] v;

    return Vec3(x,y,z);
}

int Sphere::isInside(Vec4 pos)
{
    Vec4 canon = wo*pos;

    double norm = canon.getVec3_().normColumn(0);

    if (fabs(norm - 0.5) <= 0.00001)
        return -1;

    return norm < 0.5;
}

Vec4 *Sphere::getVertices(int height, int width)
{
    Vec4 *v = new Vec4[(height-1)*width + 2];

    Mtx4x4 rotZ = Mtx4x4::getRotateMtx_((3.141592)/height,false,false,true);
    Mtx4x4 rotY = Mtx4x4::getRotateMtx_((2*3.141592)/width,false,true,false);

    v[0] = Vec4(0,0.5,0,1);
    v[1] = Vec4(0,-0.5,0,1);

    for (int i=0;i<height-1;i++) {
        v[i+2] = rotZ*v[i+1];
    }

    for (int i=1;i<width;i++) {
        int currBase = 2+(height-1)*i;
        int prevBase = 2+(height-1)*(i-1);
        for (int j=0;j<height-1;j++) {
            v[currBase+j] = rotY*v[prevBase+j];
        }
    }

    for (int i=0;i<(height-1)*width + 2;i++) {
        v[i] = ow*v[i];
    }

    return v;
}

vector<RCResult> Sphere::checkIntersection(Ray ray)
{
    Ray tRay = ray.transform(wo);

    vector<RCResult> results = vector<RCResult>();

    double a = pow(tRay.getDir().getX(),2) +
               pow(tRay.getDir().getY(),2) +
               pow(tRay.getDir().getZ(),2);
    double b = 2*(tRay.getOrigin().getX()*tRay.getDir().getX() +
                  tRay.getOrigin().getY()*tRay.getDir().getY() +
                  tRay.getOrigin().getZ()*tRay.getDir().getZ());
    double c = pow(tRay.getOrigin().getX(),2) +
               pow(tRay.getOrigin().getY(),2) +
               pow(tRay.getOrigin().getZ(),2) - pow(0.5,2);

    double delta = (b*b) - (4*a*c);

    if (delta < 0) return results;

    if (delta == 0) {
        double t = -b/(2*a);
        Vec3 point = ow.prod_(tRay.getPoint(t),1);
        Vec3 normal = point - getOrigin();
        normal.normalize();

        results.push_back(RCResult(true,t,point,normal,material));
        return results;
    }

    double t1 = min((-b + sqrt(delta))/(2*a),(-b - sqrt(delta))/(2*a));
    double t2 = max((-b + sqrt(delta))/(2*a),(-b - sqrt(delta))/(2*a));

    Vec3 nearestPoint = ow.prod_(tRay.getPoint(t1),1);
    Vec3 nearestNormal = nearestPoint - getOrigin();
    t1 = (ray.getOrigin().getVec3_() - nearestPoint).getNorm();
    nearestNormal.normalize();

    Vec3 farthestPoint = ow.prod_(tRay.getPoint(t2),1);
    Vec3 farthestNormal = farthestPoint - getOrigin();
    t2 = (ray.getOrigin().getVec3_() - farthestPoint).getNorm();
    farthestNormal.normalize();

    results.push_back(RCResult(true,t1,nearestPoint,nearestNormal,material));
    results.push_back(RCResult(true,t2,farthestPoint,farthestNormal,material));

    return results;
}

















