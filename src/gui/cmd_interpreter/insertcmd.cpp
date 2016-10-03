#include "insertcmd.h"
#include <iostream>
#include <objects/compoundobject.h>

using namespace std;

InsertCmd::InsertCmd()
{
    this->command = "insert";
    this->shortcut = "ins";
}

void InsertCmd::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() > 1) {
        QString objType = params.at(1);

        if (objType == "sphere") {
            objects->addObject(new Sphere());
        }
        if (objType == "prism") {
            if ((params.size() > 2) && (params.at(2).toInt() > 2)){
                objects->addObject(new RBPrism(params.at(2).toInt()));
            }
        }
        if (objType == "pyramid") {
            if ((params.size() > 2) && (params.at(2).toInt() > 2)) {
                objects->addObject(new RBPyramid(params.at(2).toInt()));
            }
        }
        if (objType == "octree") {
            if (params.size() == 3) {
                Ocnode *o = new Ocnode(true);
                o->setState(-1);
                o->setSize(params.at(2).toDouble());
                objects->addObject(o);
            } else if ((params.size() > 3) && (objects->numOfObjects() > params.at(2).toInt())) {
                Ocnode *o = new Ocnode(true);
                o->classify(objects->getObject(params.at(2).toInt()),params.at(3).toInt());
                objects->addObject(o);
            }
        }
        if (objType == "compound") {
            if ((params.size() == 4)&&
                (params.at(2).toInt() < objects->numOfObjects())&&
                (params.at(3).toInt() < objects->numOfObjects())) {
                CompoundObject *co = new CompoundObject(objects->getObject(params.at(2).toInt()),
                                                        objects->getObject(params.at(3).toInt()));
                objects->addObject(co);
            }
        }
    }
}
