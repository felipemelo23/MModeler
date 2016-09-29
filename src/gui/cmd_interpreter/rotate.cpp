#include "rotate.h"

Rotate::Rotate()
{
    this->command = "rotate";
    this->shortcut = "rot";
}

void Rotate::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() > 2) {
        if (objects->numOfSelected() > 0)
            for (int i=0;i<objects->numOfSelected();i++) {
                int objId = objects->getSelected(i);

                if (params.at(2) == "x") {
                    objects->getObject(objId)->rotate(params.at(1).toDouble(),true,false,false);
                } else if (params.at(2) == "y") {
                    objects->getObject(objId)->rotate(params.at(1).toDouble(),false,true,false);
                } else if (params.at(2) == "z") {
                    objects->getObject(objId)->rotate(params.at(1).toDouble(),false,false,true);
                }

                objects->pushDirt(objId,0);
            }
    }
}
