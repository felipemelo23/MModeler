#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "command.h"

#include <QStringList>

class Translate : public Command
{
public:
    Translate();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // TRANSLATE_H
