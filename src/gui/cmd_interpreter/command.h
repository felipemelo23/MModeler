#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <gui/objectsmanager.h>

class Command
{
public:
    Command();

    virtual void execute(QStringList params, ObjectsManager *objects) = 0;

    QString getCommand() const;
    QString getShortcut() const;

protected:
    QString command;
    QString shortcut;

};

#endif // COMMAND_H
