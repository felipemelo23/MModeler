#ifndef SELFROTATE_H
#define SELFROTATE_H

#include "command.h"

#include <QStringList>

class SelfRotate : public Command
{
public:
    SelfRotate();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // SELFROTATE_H
