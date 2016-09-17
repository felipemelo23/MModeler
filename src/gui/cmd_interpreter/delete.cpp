#include "delete.h"

Delete::Delete()
{
    this->command = "delete";
    this->shortcut = "del";
}

void Delete::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() == 1) {
        if (objects->numOfSelected() > 0)
            for (int i=0;i<objects->numOfSelected();i++) {
                int objId = objects->getSelected(i);
                objects->removeSelected(objId);
                objects->removeObject(objId);
                objects->pushDirt(objId,-1);
            }
    } else {
        for (int i=1;i<params.size();i++) {
            objects->removeSelected(params.at(i).toInt());
            objects->removeObject(params.at(i).toInt());
            objects->pushDirt(params.at(i),-1);
        }
    }
}