#ifndef ADJACENCYOPERATOR_H
#define ADJACENCYOPERATOR_H

#include "command.h"

#include <qstringlist.h>



class AdjacencyOperator : public Command
{
public:
    AdjacencyOperator();

    void execute(QStringList params, ObjectsManager *objects);
};

#endif // ADJACENCYOPERATOR_H
