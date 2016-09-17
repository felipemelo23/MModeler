#ifndef DESELECT_H
#define DESELECT_H

#include "command.h"

#include <QStringList>

class Deselect : public Command
{
public:
    Deselect();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // DESELECT_H
