#include "deselect.h"

Deselect::Deselect()
{
    this->command = "deselect";
    this->shortcut = "d";
}

void Deselect::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() > 1) {
        for (int i=1;i<params.size();i++) {
            objects->removeSelected(params.at(i).toInt());
        }
    }
}
