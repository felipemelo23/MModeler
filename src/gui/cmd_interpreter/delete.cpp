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
                if ((objects->numOfObjects() > 0)&&(objId < objects->numOfObjects())) {
                    objects->removeSelected(objId);
                    objects->removeObject(objId);
                }

            }
    } else {
        for (int i=1;i<params.size();i++) {
            if ((objects->numOfObjects() > 0)&&(params.at(i).toInt() < objects->numOfObjects())) {
                objects->removeSelected(params.at(i).toInt());
                objects->removeObject(params.at(i).toInt());
            }
        }
    }
}
