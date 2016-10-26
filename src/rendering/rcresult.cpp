#include "rcresult.h"

RCResult::RCResult()
{
    this->intersected = false;
    this->t = 0;
    this->point = NULL;
    this->normal = NULL;
    this->material = NULL;
}

RCResult::RCResult(double t)
{
    this->intersected = false;
    this->t = t;
    this->point = NULL;
    this->normal = NULL;
    this->material = NULL;
}

RCResult::RCResult(bool intersected, double t, Vec3 *point, Vec3 *normal, Material *material)
{
    this->intersected = intersected;
    this->t = t;
    this->point = point;
    this->normal = normal;
    this->material = material;
}

bool RCResult::getIntersected() const
{
    return intersected;
}

double RCResult::getT() const
{
    return t;
}

Vec3 *RCResult::getPoint() const
{
    return point;
}

Vec3 *RCResult::getNormal() const
{
    return normal;
}

Material *RCResult::getMaterial() const
{
    return material;
}

void RCResult::setMaterial(Material *value)
{
    material = value;
}

void RCResult::setNormal(Vec3 *value)
{
    normal = value;
}
