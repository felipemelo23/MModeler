#ifndef ROTATE_H
#define ROTATE_H

#include "command.h"

#include <QStringList>


class Rotate : public Command
{
public:
    Rotate();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // ROTATE_H
