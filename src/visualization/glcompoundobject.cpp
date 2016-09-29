#include "glcompoundobject.h"

glCompoundObject::glCompoundObject() : glObject()
{
    subObjects = vector<glObject*>();
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
