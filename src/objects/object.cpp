#include <objects/object.h>

Object::Object()
{
    ow = Mtx4x4::getIdentity();
    wo = Mtx4x4::getIdentity();
}

Vec3 *Object::getOrigin()
{
    Vec4 *o = new Vec4(0,0,0,1);
    Vec4 *o4 = ow->prod(o);
    Vec3 *origin = new Vec3(o4->getX(), o4->getY(), o4->getZ());

    delete o;
    delete o4;

    return origin;
}

QString Object::getName()
{
    return name;
}

void Object::setName(QString name)
{
    this->name = name;
}

void Object::rotate(double degree, bool x, bool y, bool z)
{
    Mtx4x4 *trash = ow;
    ow = Mtx4x4::getRotateMtx(degree,x,y,z)->prod(ow);
    delete trash;

    trash = wo;
    wo = wo->prod(Mtx4x4::getRotateMtx(-degree,x,y,z));
    delete trash;
}

void Object::section(Vec2 **v, double radius) {}

void Object::scale(double x, double y, double z)
{
    Mtx4x4 *trash = ow;
    ow = Mtx4x4::getScaleMtx(x,y,z)->prod(ow);
    delete trash;

    trash = wo;
    wo = wo->prod(Mtx4x4::getScaleMtx(1/x,1/y,1/z));
    delete trash;
}

int Object::getType()
{
    return type;
}

void Object::translate(double x, double y, double z)
{
    Mtx4x4 *trash = ow;
    ow = Mtx4x4::getTranslateMtx(x,y,z)->prod(ow);
    delete trash;

    trash = wo;
    wo = wo->prod(Mtx4x4::getTranslateMtx(-x,-y,-z));
    delete trash;
}

