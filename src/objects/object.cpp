#include <objects/object.h>

Material *Object::getMaterial() const
{
    return material;
}

void Object::setMaterial(Material *value)
{
    material = value;
}

Object::Object()
{
    ow = Mtx4x4::getIdentity_();
    wo = Mtx4x4::getIdentity_();
    material = new Material();
}

Vec3 Object::getOrigin()
{
    return (ow*Vec4(0,0,0,1)).getVec3_();
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
    ow = Mtx4x4::getRotateMtx_(degree,x,y,z)*ow;
    wo = wo*Mtx4x4::getRotateMtx_(-degree,x,y,z);
}

vector<RCResult> Object::checkIntersection(Ray ray)
{}

void Object::section(Vec2 *v, double radius) {}

void Object::scale(double x, double y, double z)
{
    ow = Mtx4x4::getScaleMtx_(x,y,z)*ow;
    wo = wo*Mtx4x4::getScaleMtx_(1/x,1/y,1/z);
}

int Object::getType()
{
    return type;
}

void Object::translate(double x, double y, double z)
{
    ow = Mtx4x4::getTranslateMtx_(x,y,z)*ow;
    wo = wo*Mtx4x4::getTranslateMtx_(-x,-y,-z);
}

