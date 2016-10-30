#include "box.h"
#include <iostream>

using namespace std;

Box::Box()
{
    type = Object::BOX;
    name = "Box";
}

Box::~Box()
{
    delete ow;
    delete wo;
}

Vec3 *Box::getMinimumCoords()
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

Vec3 *Box::getMaximumCoords()
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

int Box::isInside(Vec4 *pos)
{
    Vec4 *canon = wo->prod(pos);

    double x = canon->getX();
    double y = canon->getY();
    double z = canon->getZ();

    delete canon;

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

Vec4 **Box::getVertices()
{
    Vec4 **v = new Vec4*[8];
    Vec4 *trash;

    double size = 0.5;

    v[0] = new Vec4(size,-size,size,1);
    v[1] = new Vec4(-size,-size,size,1);
    v[2] = new Vec4(-size,-size,-size,1);
    v[3] = new Vec4(size,-size,-size,1);
    v[4] = new Vec4(size,size,-size,1);
    v[5] = new Vec4(-size,size,-size,1);
    v[6] = new Vec4(-size,size,size,1);
    v[7] = new Vec4(size,size,size,1);

    for (int i=0;i<8;i++)
    {
        trash = v[i];
        v[i] = ow->prod(v[i]);
        delete trash;
    }

    return v;
}

vector<RCResult> Box::checkIntersection(Ray *ray)
{
    Ray *tRay = ray->transform(wo);
    vector<RCResult> results = vector<RCResult>();

    if (tRay->getDir()->getX() != 0) {
        double t = (0.5 - tRay->getOrigin()->getX())/tRay->getDir()->getX();
        Vec3 *pT = ow->prod(tRay->getPoint(t),1);
        if ((pT->getY() >= -0.5)&&(pT->getY() <= 0.5)&&
            (pT->getZ() >= -0.5)&&(pT->getZ() <= 0.5)) {
            results.push_back(RCResult(true,ray->getOrigin()->getVec3()->sub(pT)->getNorm(),pT,ow->prod(new Vec3(1,0,0),0),material));
        }

        t = (-0.5 - tRay->getOrigin()->getX())/tRay->getDir()->getX();
        pT = ow->prod(tRay->getPoint(t),1);
        if ((pT->getY() >= -0.5)&&(pT->getY() <= 0.5)&&
            (pT->getZ() >= -0.5)&&(pT->getZ() <= 0.5)) {
            results.push_back(RCResult(true,ray->getOrigin()->getVec3()->sub(pT)->getNorm(),pT,ow->prod(new Vec3(-1,0,0),0),material));
        }
    }

    if (tRay->getDir()->getY() != 0) {
        double t = (0.5 - tRay->getOrigin()->getY())/tRay->getDir()->getY();
        Vec3 *pT = ow->prod(tRay->getPoint(t),1);
        if ((pT->getX() >= -0.5)&&(pT->getX() <= 0.5)&&
            (pT->getZ() >= -0.5)&&(pT->getZ() <= 0.5)) {
            results.push_back(RCResult(true,ray->getOrigin()->getVec3()->sub(pT)->getNorm(),pT,ow->prod(new Vec3(0,1,0),0),material));
        }

        t = (-0.5 - tRay->getOrigin()->getY())/tRay->getDir()->getY();
        pT = ow->prod(tRay->getPoint(t),1);
        if ((pT->getX() >= -0.5)&&(pT->getX() <= 0.5)&&
            (pT->getZ() >= -0.5)&&(pT->getZ() <= 0.5)) {
            results.push_back(RCResult(true,ray->getOrigin()->getVec3()->sub(pT)->getNorm(),pT,ow->prod(new Vec3(0,-1,0),0),material));
        }
    }

    if (tRay->getDir()->getZ() != 0) {
        double t = (0.5 - tRay->getOrigin()->getZ())/tRay->getDir()->getZ();
        Vec3 *pT = ow->prod(tRay->getPoint(t),1);
        if ((pT->getX() >= -0.5)&&(pT->getX() <= 0.5)&&
            (pT->getY() >= -0.5)&&(pT->getY() <= 0.5)) {
            results.push_back(RCResult(true,ray->getOrigin()->getVec3()->sub(pT)->getNorm(),pT,ow->prod(new Vec3(0,0,1),0),material));
        }

        t = (-0.5 - tRay->getOrigin()->getZ())/tRay->getDir()->getZ();
        pT = ow->prod(tRay->getPoint(t),1);
        if ((pT->getX() >= -0.5)&&(pT->getX() <= 0.5)&&
            (pT->getY() >= -0.5)&&(pT->getY() <= 0.5)) {
            results.push_back(RCResult(true,ray->getOrigin()->getVec3()->sub(pT)->getNorm(),pT,ow->prod(new Vec3(0,0,-1),0),material));
        }
    }

    delete tRay;

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





















