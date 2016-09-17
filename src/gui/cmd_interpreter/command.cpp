#include "command.h"

Command::Command() {}

QString Command::getCommand() const
{
    return command;
}

QString Command::getShortcut() const
{
    return shortcut;
}
