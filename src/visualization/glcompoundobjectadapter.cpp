#include "glcompoundobject.h"
#include "glcompoundobjectadapter.h"
#include "glrbprismadapter.h"
#include "glrbpyramidadapter.h"
#include "glsphereadapter.h"

#include <objects/rbpyramid.h>

glObject *glCompoundObjectAdapter::adapt(CompoundObject *obj)
{
    glCompoundObject *cObj = new glCompoundObject();

    cObj->addSubObject(adaptSubObject(obj->getObjectA()));
    cObj->addSubObject(adaptSubObject(obj->getObjectB()));

    return cObj;
}

glObject *glCompoundObjectAdapter::adaptSubObject(Object *obj)
{
    int type = obj->getType();

    glObject *o = NULL;

    switch (type) {
    case Object::SPHERE:
        o = glSphereAdapter::adapt((Sphere*)obj);
        break;
    case Object::RBPRISM:
        o = glRBPrismAdapter::adapt((RBPrism*)obj);
        break;
    case Object::RBPYRAMID:
        o = glRBPyramidAdapter::adapt((RBPyramid*)obj);
        break;
    case Object::COMPOUND:
        o = glCompoundObjectAdapter::adapt((CompoundObject*)obj);
        break;
    default:
        break;
    }

    return o;
}
