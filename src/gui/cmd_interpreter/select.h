#ifndef SELECT_H
#define SELECT_H

#include "command.h"

#include <QStringList>

class Select : public Command
{
public:
    Select();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // SELECT_H
