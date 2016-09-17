#include "scale.h"

Scale::Scale()
{
    this->command = "scale";
    this->shortcut = "scl";
}

void Scale::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() > 3) {
        if (objects->numOfSelected() > 0)
            for (int i=0;i<objects->numOfSelected();i++) {
                int objId = objects->getSelected(i);
                objects->getObject(objId)->scale(params.at(1).toDouble(),
                                                 params.at(2).toDouble(),
                                                 params.at(3).toDouble());
                objects->pushDirt(objId,0);
            }
    }
}
