#ifndef SELFSCALE_H
#define SELFSCALE_H

#include "command.h"
#include <QStringList>

class SelfScale : public Command
{
public:
    SelfScale();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // SELFSCALE_H
