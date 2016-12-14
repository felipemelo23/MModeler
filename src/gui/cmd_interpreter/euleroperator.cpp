#include "euleroperator.h"

#include <objects/mesh/mesh.h>
#include <iostream>

using namespace std;

EulerOperator::EulerOperator()
{
    this->command = "euler";
    this->shortcut = "eu";
}

void EulerOperator::execute(QStringList params, ObjectsManager *objects)
{
    if (params.size() > 1) {
        if (params.at(1) == "mvfs") {
            Mesh *mesh = (Mesh*) objects->getObject(params.at(2).toInt());

            mesh->mvfs();

            objects->pushDirt(params.at(2).toInt(),0);
        }

        if (params.at(1) == "mev") {
            int numOfParams = params.size();
            Mesh *mesh = (Mesh*) objects->getObject(params.at(2).toInt());
            Vec3 dir = Vec3(params.at(4).toDouble(), params.at(5).toDouble(), params.at(6).toDouble());

            switch (numOfParams) {
            case 7: // ONE SINGLE VERTEX
                mesh->mev(params.at(3).toStdString(),dir);

                objects->pushDirt(params.at(2).toInt(),0);
                break;
            case 8: // ONE VERTEX AND ONE EDGE
                mesh->mev(params.at(3).toStdString(),dir,params.at(7).toStdString());

                objects->pushDirt(params.at(2).toInt(),0);
                break;
            case 9: // ONE VERTEX AND TWO EDGES
                mesh->mev(params.at(3).toStdString(),dir,params.at(7).toStdString(),params.at(8).toStdString());

                objects->pushDirt(params.at(2).toInt(),0);
                break;
            default:
                break;
            }
        }
    }
}
