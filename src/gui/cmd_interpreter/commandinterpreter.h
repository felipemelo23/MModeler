#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include "command.h"
#include "delete.h"
#include "deselect.h"
#include "rotate.h"
#include "scale.h"
#include "select.h"
#include "translate.h"
#include <gui/objectsmanager.h>
#include <QStringList>
#include <QString>
#include <vector>

class CommandInterpreter
{
public:
    CommandInterpreter(ObjectsManager *objects);

    void interpretCommand(QString command);

private:
    ObjectsManager *objects;
    vector<Command*> acceptableCommand;
};

#endif // COMMANDINTERPRETER_H
