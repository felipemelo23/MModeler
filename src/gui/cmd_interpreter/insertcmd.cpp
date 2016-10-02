#include "insertcmd.h"
#include <iostream>

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
        if (objType == "rbprism") {
            if ((params.size() > 2) && (params.at(2).toInt() > 2)){
                objects->addObject(new RBPrism(params.at(2).toInt()));
            }
        }
        if (objType == "rbpyramid") {
            if ((params.size() > 2) && (params.at(2).toInt() > 2)) {
                objects->addObject(new RBPyramid(params.at(2).toInt()));
            }
        }
        if (objType == "octree") {
            if ((params.size() > 3) && (objects->numOfObjects() > params.at(2).toInt())) {
                Ocnode *o = new Ocnode(true);
                o->classify(objects->getObject(params.at(2).toInt()),params.at(3).toInt());
                objects->addObject(o);
            }
        }
    }
}
