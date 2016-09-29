#include "insertcmd.h"

InsertCmd::InsertCmd()
{
    this->command = "insert";
    this->shortcut = "ins";
}

void InsertCmd::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() > 1) {
        QString objType = params.at(1);

//        switch (objType) {
//        case "sphere":
//            objects->addObject(new Sphere());
//            objects->pushDirt(objects->numOfObjects()-1,+1);
//            break;
//        case "rbprism":
//            if (params.size() > 2) {
//                objects->addObject(new RBPrism(params.at(2).toInt()));
//                objects->pushDirt(objects->numOfObjects()-1,+1);
//            }
//            break;
//        case "rbpyramid":
//            if (params.size() > 2) {
//                objects->addObject(new RBPyramid(params.at(2).toInt()));
//                objects->pushDirt(objects->numOfObjects()-1,+1);
//            }
//            break;
//        case "octree":
//            if (params.size() > 3) {
//                Ocnode *o = new Ocnode();
//                o->classify(objects->getObject(params.at(2).toInt()),params.at(3).toInt());
//                objects->addObject(o);
//                objects->pushDirt(objects->numOfObjects()-1,+1);
//            }
//            break;
//        default:
//            break;
//        }
    }
}
