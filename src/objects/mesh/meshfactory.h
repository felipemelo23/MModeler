#ifndef MESHFACTORY_H
#define MESHFACTORY_H

#include "mesh.h"
#include <objects/face.h>

class MeshFactory
{
public:
    static Mesh factory(vector<Vec3*> vertices, vector<Face> faces);
};

#endif // MESHFACTORY_H
