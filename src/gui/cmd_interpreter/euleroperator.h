#ifndef EULEROPERATOR_H
#define EULEROPERATOR_H

#include "command.h"

#include <QStringList>

class EulerOperator : public Command
{
public:
    EulerOperator();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // EULEROPERATOR_H
