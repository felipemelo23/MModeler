#include "cylinder.h"

Cylinder::Cylinder()
{
    this->type = Object::CYLINDER;
    this->name = "Cylinder";
}

int Cylinder::isInside(Vec4 pos)
{
    Vec4 canon = wo*pos;

    if ((canon.getY() > 0.5)||(canon.getY() < -0.5))
        return false;

    Vec2 v = Vec2(canon.getX(),canon.getZ());
    double norm = v.getNorm();

    if (fabs(norm - 0.5) <= 0.00001)
        return -1;

    return norm < 0.5;
}

Vec3 Cylinder::getMaximumCoords()
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

Vec3 Cylinder::getMinimumCoords()
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
        if (x > v[i].getX()) x = v[i].getX();
        if (y > v[i].getY()) y = v[i].getY();
        if (z > v[i].getZ()) z = v[i].getZ();
    }

    delete[] v;

    return Vec3(x,y,z);
}

vector<RCResult> Cylinder::checkIntersection(Ray ray)
{
    Ray tRay = ray.transform(wo);
    vector<RCResult> results = vector<RCResult>();

    double a = pow(tRay.getDir().getX(),2) +
               pow(tRay.getDir().getZ(),2);
    double b = 2*(tRay.getOrigin().getX()*tRay.getDir().getX() +
                  tRay.getOrigin().getZ()*tRay.getDir().getZ());
    double c = pow(tRay.getOrigin().getX(),2) +
               pow(tRay.getOrigin().getZ(),2) - pow(0.5,2);

    double delta = b*b - 4*a*c;

    if (delta < 0) return results;

    Vec3 origin = ray.getOrigin().getVec3_();
    RCResult top = checkTopIntersect(tRay,origin);
    RCResult base = checkBaseIntersect(tRay,origin);
    std::pair<RCResult,RCResult> fold = checkFoldIntersect(tRay,origin,a,b,c);

    if (top.getIntersected()) results.push_back(top);
    if (base.getIntersected()) results.push_back(base);
    if (fold.first.getIntersected()) results.push_back(fold.first);
    if (fold.second.getIntersected()) results.push_back(fold.second);

    return sort(results);
}

vector<RCResult> Cylinder::sort(vector<RCResult> results) {
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

RCResult Cylinder::checkTopIntersect(Ray ray, Vec3 origin)
{
    if (ray.getDir().getY() != 0) {
        double t = (0.5 - ray.getOrigin().getY())/ray.getDir().getY();

        if (t < 0) return RCResult();

        Vec3 r = ray.getPoint(t);

        if (pow(r.getX(),2) + pow(r.getZ(),2) <= pow(0.5,2)) {
            r = ow.prod_(r,1);

            return RCResult(true,(origin-r).getNorm(),r,ow.prod_(Vec3(0,1,0),0),material);
        }

        return RCResult();
    }
    return RCResult();
}

RCResult Cylinder::checkBaseIntersect(Ray ray, Vec3 origin)
{
    if (ray.getDir().getY() != 0) {
        double t = (-0.5 - ray.getOrigin().getY())/ray.getDir().getY();

        if (t < 0) return RCResult();

        Vec3 r = ray.getPoint(t);

        if (pow(r.getX(),2) + pow(r.getZ(),2) <= pow(0.5,2)) {
            r = ow.prod_(r,1);

            return RCResult(true,(origin - r).getNorm(),r,ow.prod_(Vec3(0,-1,0),0),material);
        }

        return RCResult();
    }
    return RCResult();
}

std::pair<RCResult, RCResult> Cylinder::checkFoldIntersect(Ray ray, Vec3 origin, double a, double b, double c)
{
    double delta = b*b - 4*a*c;
    double t1 = (-b + sqrt(delta))/(2*a);
    double t2 = (-b - sqrt(delta))/(2*a);

    Vec3 p1 = ray.getPoint(t1);
    RCResult r1 = RCResult();

    if ((p1.getY() < 0.5) && (p1.getY() > -0.5)) {
        Vec3 n1 = ow.prod_(Vec3(p1.getX(),0,p1.getZ()),0);
        p1 = ow.prod_(p1,1);

        r1 = RCResult(true,(origin - p1).getNorm(),p1,n1,material);
    }

    Vec3 p2 = ray.getPoint(t2);
    RCResult r2 = RCResult();

    if ((p2.getY() < 0.5) && (p2.getY() > -0.5)) {
        Vec3 n2 = ow.prod_(Vec3(p2.getX(),0,p2.getZ()),0);
        p2 = ow.prod_(p2,1);

        r2 = RCResult(true,(origin - p2).getNorm(),p2,n2,material);
    }

    return std::make_pair(r1,r2);
}

Vec4 *Cylinder::getVertices(int discretization)
{
    Vec4 *v = new Vec4[2*discretization];

    Mtx4x4 rot = Mtx4x4::getRotateMtx_((2*3.141592)/discretization,false,true,false);

    v[0] = Vec4(0,-0.5,0.5,1);
    v[discretization] = Vec4(0,0.5,0.5,1);

    for (int i=1;i<discretization;i++)
    {
        v[i] = rot*v[i-1];
        v[discretization+i] = rot*v[discretization+i-1];
    }

    for (int i=0;i<discretization;i++)
    {
        v[i] = ow*v[i];
        v[discretization+i] = ow*v[discretization+i];
    }

    return v;
}
