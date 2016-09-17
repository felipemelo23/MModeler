#ifndef SCALE_H
#define SCALE_H

#include "command.h"

#include <QStringList>

class Scale : public Command
{
public:
    Scale();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // SCALE_H
