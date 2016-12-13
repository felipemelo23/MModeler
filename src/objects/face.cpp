#include "face.h"
#include <iostream>

using namespace std;

Face::Face()
{
    this->sides = 0;
    this->material = NULL;
    this->vertices = NULL;
}

Face::Face(int sides, Material *material, Vec4 *v)
{
    this->sides = sides;
    this->vertices = v;
    this->material = material;
}

Face::Face(int sides, Material *material, Vec4 v1, Vec4 v2, Vec4 v3, ...)
{
    this->sides = sides;
    this->material = material;
    vertices = new Vec4[sides];

    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;


    if (this->sides > 3) {
        va_list vl;

        va_start(vl,v3);

        for (int i=3;i<this->sides;i++) {
            Vec4 value = va_arg(vl,Vec4);
            vertices[i] = value;
        }

        va_end(vl);
    }
}

Face::~Face()
{
    //delete vertices;
}

int Face::getSides() const
{
    return sides;
}

Vec4 *Face::getVertices() const
{
    return vertices;
}

RCResult Face::checkIntersection(Ray ray)
{
    Vec3 normal = (vertices[2] - vertices[1]).cross_(vertices[0] - vertices[1]).getVec3_();
    normal.normalize();

    if (fabs(ray.getDir().getVec3_().dot_(normal)) > 0.00001) {
        double t = (vertices[0] - ray.getOrigin()).getVec3_().dot_(normal)/ray.getDir().getVec3_().dot_(normal);

        Vec4 point = Vec4(ray.getPoint(t),1);

        if (isInside(point))
            return RCResult(true,t,point.getVec3_(),normal,material);

    }

    return RCResult();
}

bool Face::isInside(Vec4 pos) {
    double acc = 0;
    double area = 0;
    Vec4 center = Vec4();

    for (int i=0;i<sides;i++) {
        center = center + vertices[i];
    }
    center = center * (1.0/sides);

    for (int i=0;i<sides;i++) {
        acc += (vertices[i] - pos).cross_(vertices[(i+1)%sides] - pos).getNorm();
        area += (vertices[i] - center).cross_(vertices[(i+1)%sides] - center).getNorm();
    }

    if (fabs((acc/area)-1) <= 0.00001) return true;

    return false;
}

Material *Face::getMaterial() const
{
    return material;
}

void Face::setMaterial(Material *value)
{
    material = value;
}

vector<pair<Vec3, Vec3> > Face::getEdges()
{
    vector< pair<Vec3, Vec3> > edges;

    for(int i=0; i<sides-1; i++)
    {
        edges.push_back(pair<Vec3,Vec3>(vertices[i].getVec3_(),vertices[i+1].getVec3_()));
    }
    edges.push_back(pair<Vec3,Vec3>(vertices[sides-1].getVec3_(),vertices[0].getVec3_()));
}

