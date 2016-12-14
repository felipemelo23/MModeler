#include "adjacencyoperator.h"

#include <objects/mesh/mesh.h>

AdjacencyOperator::AdjacencyOperator()
{
    this->command = "adjacency";
    this->shortcut = "adj";
}

void AdjacencyOperator::execute(QStringList params, ObjectsManager *objects)
{
    if ((params.size() == 4)&&(objects->numOfObjects() > params.at(2).toInt())&&
            (objects->getObject(params.at(2).toInt())->getType() == Object::MESH)) {
        QString adjType = params.at(1);
        Mesh *mesh = (Mesh*) objects->getObject(params.at(2).toInt());

        if (adjType == "ev") {
            mesh->ev(params.at(3).toStdString());
            objects->pushDirt(params.at(2).toInt(),0);
        }
        if (adjType == "ee") {
            mesh->ee(params.at(3).toStdString());
            objects->pushDirt(params.at(2).toInt(),0);
        }
        if (adjType == "fe") {
            mesh->fe(params.at(3).toStdString());
            objects->pushDirt(params.at(2).toInt(),0);
        }
        if (adjType == "ef") {
            mesh->ef(params.at(3).toStdString());
            objects->pushDirt(params.at(2).toInt(),0);
        }
        if (adjType == "vv") {
            mesh->vv(params.at(3).toStdString());
            objects->pushDirt(params.at(2).toInt(),0);
        }
        if (adjType == "ve") {
            mesh->ve(params.at(3).toStdString());
            objects->pushDirt(params.at(2).toInt(),0);
        }
        if (adjType == "vf") {
            mesh->vf(params.at(3).toStdString());
            objects->pushDirt(params.at(2).toInt(),0);
        }
        if (adjType == "clear") {
            mesh->clearActives();
            objects->pushDirt(params.at(2).toInt(),0);
        }
    }
}
