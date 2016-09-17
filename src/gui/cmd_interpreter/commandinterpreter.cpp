#include "commandinterpreter.h"
#include "delete.h"
#include "deselect.h"
#include "insert.h"
#include "rotate.h"
#include "scale.h"
#include "select.h"
#include "translate.h"

CommandInterpreter::CommandInterpreter(ObjectsManager *objects)
{
    this->objects = objects;
    this->acceptableCommand = vector<Command*>();

    this->acceptableCommand.push_back(new Insert());
    this->acceptableCommand.push_back(new Delete());
    this->acceptableCommand.push_back(new Select());
    this->acceptableCommand.push_back(new Deselect());
    this->acceptableCommand.push_back(new Translate());
    this->acceptableCommand.push_back(new Rotate());
    this->acceptableCommand.push_back(new Scale());
}

void CommandInterpreter::interpretCommand(QString command)
{
    QStringList tokens = command.split(" ");

    for (int i=0;i<acceptableCommand.size();i++) {
        if ((tokens.at(0) == acceptableCommand.at(i)->getCommand())||
            (tokens.at(0) == acceptableCommand.at(i)->getShortcut())) {
            acceptableCommand.at(i)->execute(tokens,objects);
            break;
        }
    }
}