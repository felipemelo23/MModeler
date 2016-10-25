#include "compoundobject.h"
#include "rbprism.h"
#include "rbpyramid.h"
#include "sphere.h"

CompoundObject::CompoundObject(Object *a, Object *b, , int op)
{
    this->a = a;
    this->b = b;
    this->name = "Compound Object";
    this->type = Object::COMPOUND;
    this->operation = op;
}

CompoundObject::~CompoundObject()
{
    delete ow;
    delete wo;
}

bool CompoundObject::isInside(Vec4 *pos)
{
    switch (operation) {
    case UNION:
        return a->isInside(pos)||b->isInside(pos);
        break;
    case INTERSECT:
        return a->isInside(pos)&&b->isInside(pos);
        break;
    case DIFFERENCE:
        return a->isInside(pos)&&(!b->isInside(pos));
        break;
    default:
        return false;
        break;
    }
}

Vec3 *CompoundObject::getMaximumCoords()
{
    Vec3 *maxA = a->getMaximumCoords();
    Vec3 *maxB = b->getMaximumCoords();

    Vec3 *maxCoords = new Vec3(max(maxA->getX(),maxB->getX()),
                               max(maxA->getY(),maxB->getY()),
                               max(maxA->getZ(),maxB->getZ()));

    delete maxA;
    delete maxB;

    return maxCoords;
}

Vec3 *CompoundObject::getMinimumCoords()
{
    Vec3 *minA = a->getMinimumCoords();
    Vec3 *minB = b->getMinimumCoords();

    Vec3 *minCoords = new Vec3(min(minA->getX(),minB->getX()),
                               min(minA->getY(),minB->getY()),
                               min(minA->getZ(),minB->getZ()));

    delete minA;
    delete minB;

    return minCoords;
}

Object *CompoundObject::getObjectA()
{
    return a;
}

Object *CompoundObject::getObjectB()
{
    return b;
}

Vec3 *CompoundObject::getOrigin()
{
    return a->getOrigin()->sum(b->getOrigin())->prod(0.5);
}

void CompoundObject::translate(double x, double y, double z)
{
    a->translate(x,y,z);
    b->translate(x,y,z);
}

void CompoundObject::scale(double x, double y, double z)
{
    a->scale(x,y,z);
    b->scale(x,y,z);
}

void CompoundObject::rotate(double degree, bool x, bool y, bool z)
{
    a->rotate(degree,x,y,z);
    b->rotate(degree,x,y,z);
}
