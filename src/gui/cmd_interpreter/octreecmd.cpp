#include "octreecmd.h"

#include <objects/ocnode.h>

OctreeCMD::OctreeCMD()
{
    this->command = "octree";
    this->shortcut = "oct";
}

void OctreeCMD::execute(QStringList params, ObjectsManager *objects)
{
    if ((params.size() == 5)&&(params.at(1) == "classify")) {
        if ((params.at(2).toInt() < objects->numOfObjects()) && (params.at(3).toInt() < objects->numOfObjects())) {
            if ((objects->getObject(params.at(2).toInt())->getType() == Object::OCTREE)&&
                (objects->getObject(params.at(3).toInt())->getType() != Object::OCTREE)) {
                ((Ocnode*)objects->getObject(params.at(2).toInt()))->classify(objects->getObject(params.at(3).toInt()),params.at(4).toInt(),true);
                objects->pushDirt(params.at(2).toInt(),0);
            }
        }
    } else if ((params.size() == 4)&&(params.at(1) == "intersect")) {
        if ((params.at(2).toInt() < objects->numOfObjects()) && (params.at(3).toInt() < objects->numOfObjects())) {
            if ((objects->getObject(params.at(2).toInt())->getType() == Object::OCTREE)&&
                (objects->getObject(params.at(3).toInt())->getType() == Object::OCTREE)) {
                objects->addObject(Ocnode::intersection((Ocnode*)objects->getObject(params.at(2).toInt()),
                                                        (Ocnode*)objects->getObject(params.at(3).toInt())));
            }
        }
    }
}
