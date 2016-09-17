#ifndef DELETE_H
#define DELETE_H

#include "command.h"

#include <QStringList>

class Delete : public Command
{
public:
    Delete();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // DELETE_H
