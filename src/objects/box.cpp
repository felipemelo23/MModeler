#include "box.h"
#include <iostream>

using namespace std;

Box::Box()
{
    type = Object::BOX;
    name = "Box";
}

Box::~Box() {}

Vec3 Box::getMinimumCoords()
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

Vec3 Box::getMaximumCoords()
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
        if (x < v[i].getX()) x = v[i].getX();
        if (y < v[i].getY()) y = v[i].getY();
        if (z < v[i].getZ()) z = v[i].getZ();
    }

    delete[] v;

    return Vec3(x,y,z);
}

int Box::isInside(Vec4 pos)
{
    Vec4 canon = wo*pos;

    double x = canon.getX();
    double y = canon.getY();
    double z = canon.getZ();

    if ((fabs(fabs(x)-0.5) <= 0.0001)&&
        (fabs(fabs(y)-0.5) <= 0.0001)&&
        (fabs(fabs(z)-0.5) <= 0.0001))
        return -1;

    if ((fabs(x) <= 0.5)&&
        (fabs(y) <= 0.5)&&
        (fabs(z) <= 0.5))
        return 1;

    return 0;
}

Vec4 *Box::getVertices()
{
    Vec4 *v = new Vec4[8];

    double size = 0.5;

    v[0] = Vec4(size,-size,size,1);
    v[1] = Vec4(-size,-size,size,1);
    v[2] = Vec4(-size,-size,-size,1);
    v[3] = Vec4(size,-size,-size,1);
    v[4] = Vec4(size,size,-size,1);
    v[5] = Vec4(-size,size,-size,1);
    v[6] = Vec4(-size,size,size,1);
    v[7] = Vec4(size,size,size,1);

    for (int i=0;i<8;i++)
    {
        v[i] = ow*v[i];
    }

    return v;
}

vector<RCResult> Box::checkIntersection(Ray ray)
{
    Ray tRay = ray.transform(wo);
    vector<RCResult> results = vector<RCResult>();

    if (tRay.getDir().getX() != 0) {
        double t = (0.5 - tRay.getOrigin().getX())/tRay.getDir().getX();
        Vec3 pT = tRay.getPoint(t);
        if ((fabs(pT.getY()) <= 0.5)&&(fabs(pT.getZ()) <= 0.5)) {
            pT = ow.prod_(pT,1);
            results.push_back(RCResult(true,(ray.getOrigin().getVec3_() - pT).getNorm(),pT,ow.prod_(Vec3(1,0,0),0),material));
        }

        t = (-0.5 - tRay.getOrigin().getX())/tRay.getDir().getX();
        pT = tRay.getPoint(t);
        if ((fabs(pT.getY()) <= 0.5)&&(fabs(pT.getZ()) <= 0.5)) {
            pT = ow.prod_(pT,1);
            results.push_back(RCResult(true,(ray.getOrigin().getVec3_() - pT).getNorm(),pT,ow.prod_(Vec3(-1,0,0),0),material));
        }
    }

    if (tRay.getDir().getY() != 0) {
        double t = (0.5 - tRay.getOrigin().getY())/tRay.getDir().getY();
        Vec3 pT = tRay.getPoint(t);
        if ((fabs(pT.getX()) <= 0.5)&&(fabs(pT.getZ()) <= 0.5)) {
            pT = ow.prod_(pT,1);
            results.push_back(RCResult(true,(ray.getOrigin().getVec3_() - pT).getNorm(),pT,ow.prod_(Vec3(0,1,0),0),material));
        }

        t = (-0.5 - tRay.getOrigin().getY())/tRay.getDir().getY();
        pT = tRay.getPoint(t);
        if ((fabs(pT.getX()) <= 0.5)&&(fabs(pT.getZ()) <= 0.5)) {
            pT = ow.prod_(pT,1);
            results.push_back(RCResult(true,(ray.getOrigin().getVec3_() - pT).getNorm(),pT,ow.prod_(Vec3(0,-1,0),0),material));
        }
    }

    if (tRay.getDir().getZ() != 0) {
        double t = (0.5 - tRay.getOrigin().getZ())/tRay.getDir().getZ();
        Vec3 pT = tRay.getPoint(t);
        if ((fabs(pT.getX()) <= 0.5)&&(fabs(pT.getY()) <= 0.5)) {
            pT = ow.prod_(pT,1);
            results.push_back(RCResult(true,(ray.getOrigin().getVec3_() - pT).getNorm(),pT,ow.prod_(Vec3(0,0,1),0),material));
        }

        t = (-0.5 - tRay.getOrigin().getZ())/tRay.getDir().getZ();
        pT = tRay.getPoint(t);
        if ((fabs(pT.getX()) <= 0.5)&&(fabs(pT.getY()) <= 0.5)) {
            pT = ow.prod_(pT,1);
            results.push_back(RCResult(true,(ray.getOrigin().getVec3_() - pT).getNorm(),pT,ow.prod_(Vec3(0,0,-1),0),material));
        }
    }

    return sort(results);
}

vector<RCResult> Box::sort(vector<RCResult> results) {
    if (results.size() > 0) {
        for (int i=0;i<results.size()-1;i++) {
            for (int j=i;j<results.size();j++) {
                if (results.at(i).getT() > results.at(j).getT()) {
                    RCResult aux = results.at(i);
                    results.at(i) = results.at(j);
                    results.at(j) = aux;
                }
            }
        }
    }

    return results;
}





















