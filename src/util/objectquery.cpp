#include "objectquery.h"

ObjectQuery::ObjectQuery() {}

double ObjectQuery::getVolume(Ocnode *octree)
{
    double volume = 0;

    switch (octree->getState()) {
    case 1:
        volume += pow(octree->getSize(),3);
        break;
    case 0:
        for (int i=0;i<8;i++)
            volume += getVolume(octree->getChild(i));
    default:
        break;
    }

    return volume;
}

double ObjectQuery::getVolume(Object *obj, int precision)
{
    double volume = 0;

    if (obj->getType() != Object::OCTREE) {
        Ocnode *rep = new Ocnode(true);

        rep->classify(obj,precision);

        volume = getVolume(rep);

        delete rep;
    } else {
        volume = getVolume((Ocnode*)obj);
    }

    return volume;
}
