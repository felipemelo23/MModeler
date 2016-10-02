#include "selfrotate.h"

SelfRotate::SelfRotate()
{
    this->command = "self_rotate";
    this->shortcut = "srot";
}

void SelfRotate::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() > 2) {
        if (objects->numOfSelected() > 0)
            for (int i=0;i<objects->numOfSelected();i++) {
                int objId = objects->getSelected(i);

                Vec3 *origin = objects->getObject(objId)->getOrigin();

                objects->getObject(objId)->translate(-origin->getX(),-origin->getY(),-origin->getZ());

                if (params.at(2) == "x") {
                    objects->getObject(objId)->rotate((params.at(1).toDouble()*3.141592)/180,true,false,false);
                } else if (params.at(2) == "y") {
                    objects->getObject(objId)->rotate((params.at(1).toDouble()*3.141592)/180,false,true,false);
                } else if (params.at(2) == "z") {
                    objects->getObject(objId)->rotate((params.at(1).toDouble()*3.141592)/180,false,false,true);
                }

                objects->getObject(objId)->translate(origin->getX(),origin->getY(),origin->getZ());

                objects->pushDirt(objId,0);
            }
    }
}
