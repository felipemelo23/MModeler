#ifndef OCTREECMD_H
#define OCTREECMD_H

#include "command.h"

#include <QStringList>

class OctreeCMD : public Command
{
public:
    OctreeCMD();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // OCTREECMD_H
