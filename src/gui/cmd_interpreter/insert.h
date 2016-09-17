#ifndef INSERT_H
#define INSERT_H

#include "command.h"
#include <QStringList>

class Insert : public Command
{
public:
    Insert();

    void execute(QStringList params, ObjectsManager *objects);

#endif // INSERT_H
