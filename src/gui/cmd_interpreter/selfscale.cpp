#include "selfscale.h"

SelfScale::SelfScale()
{
    this->command = "self_scale";
    this->shortcut = "sscl";
}

void SelfScale::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() > 3) {
        if (objects->numOfSelected() > 0)
            for (int i=0;i<objects->numOfSelected();i++) {
                int objId = objects->getSelected(i);
                Vec3 origin = objects->getObject(objId)->getOrigin();

                objects->getObject(objId)->translate(-origin.getX(),-origin.getY(),-origin.getZ());

                objects->getObject(objId)->scale(params.at(1).toDouble(),
                                                 params.at(2).toDouble(),
                                                 params.at(3).toDouble());

                objects->getObject(objId)->translate(origin.getX(),origin.getY(),origin.getZ());

                objects->pushDirt(objId,0);
            }
    }
}
