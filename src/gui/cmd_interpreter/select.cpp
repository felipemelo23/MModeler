#include "select.h"

Select::Select()
{
    this->command = "select";
    this->shortcut = "s";
}

void Select::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() > 1) {
        for (int i=1;i<params.size();i++) {
            objects->addSelected(params.at(i).toInt());
        }
    }
}
