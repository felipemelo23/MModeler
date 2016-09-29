#ifndef INSERTCMD_H
#define INSERTCMD_H

#include "command.h"
#include <objects/ocnode.h>
#include <objects/rbprism.h>
#include <objects/rbpyramid.h>
#include <objects/sphere.h>
#include <QStringList>

class InsertCmd : public Command
{
public:
    InsertCmd();

    void execute(QStringList params, ObjectsManager *objects);
};
#endif // INSERTCMD_H
