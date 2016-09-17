#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include "command.h"
#include <gui/objectsmanager.h>
#include <QStringList>
#include <QString>
#include <vector>

using std::string;
using std::vector;

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
