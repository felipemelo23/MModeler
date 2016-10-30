#include "face.h"
#include <iostream>

using namespace std;

Face::Face(int sides, Vec4 **v, Material *material)
{
    this->sides = sides;
    this->vertices = v;
    this->material = material;
}

Face::Face(int sides, Material *material, Vec4 *v1, Vec4 *v2, Vec4 *v3, ...)
{
    this->sides = sides;
    this->material = material;
    vertices = new Vec4*[sides];

    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;


    if (this->sides > 3) {
        va_list vl;

        va_start(vl,v3);

        for (int i=3;i<this->sides;i++) {
            Vec4* value = va_arg(vl,Vec4*);
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

Vec4 **Face::getVertices() const
{
    return vertices;
}

RCResult Face::checkIntersection(Ray *ray)
{
    Vec3 *normal = vertices[2]->sub(vertices[1])->cross(vertices[0]->sub(vertices[1]))->getVec3();
    normal->normalize();

    if (fabs(ray->getDir()->getVec3()->dot(normal)) > 0.00001) {
        double t = vertices[0]->sub(ray->getOrigin())->getVec3()->dot(normal)/ray->getDir()->getVec3()->dot(normal);

        Vec4 *point = new Vec4(ray->getPoint(t),1);

        if (isInside(point))
            return RCResult(true,t,point->getVec3(),normal,material);

    }

    return RCResult();
}

bool Face::isInside(Vec4 *pos) {
    double acc = 0;
    double area = 0;
    Vec4 *center = new Vec4();

    for (int i=0;i<sides;i++) {
        center->sum_(vertices[i]);
    }
    center = center->prod(1.0/sides);

    for (int i=0;i<sides;i++) {
        acc += vertices[i]->sub(pos)->cross(vertices[(i+1)%sides]->sub(pos))->getNorm();
        area += vertices[i]->sub(center)->cross(vertices[(i+1)%sides]->sub(center))->getNorm();
    }

    delete center;

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
