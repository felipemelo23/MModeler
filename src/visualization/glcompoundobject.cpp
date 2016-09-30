#include "glcompoundobject.h"

glCompoundObject::glCompoundObject() : glObject()
{
    subObjects = vector<glObject*>();
}

glCompoundObject::~glCompoundObject()
{
    for (int i=0;i<subObjects.size();i++) {
        delete subObjects.at(i);
    }
}

void glCompoundObject::addSubObject(glObject *obj)
{
    this->subObjects.push_back(obj);
}

glObject *glCompoundObject::getSubObject(int index)
{
    return subObjects.at(index);
}

int glCompoundObject::numOfSubObjects()
{
    return subObjects.size();
}

void glCompoundObject::draw()
{
    glObject::draw();

    for (int i=0;i<subObjects.size();i++) {
        subObjects.at(i)->draw();
    }
}

void glCompoundObject::setColor(double color[])
{
    glObject::setColor(color);

    for (int i=0;i<subObjects.size();i++) {
        subObjects.at(i)->setColor(color);
    }
}
