#ifndef MESHFACTORY_H
#define MESHFACTORY_H

#include "mesh.h"
#include <objects/face.h>

class MeshFactory
{
public:
    static Mesh *buildGenMesh(vector<Vec3*> vertices, vector<Face> faces);
    static Mesh *buildBox();
    static Mesh *buildSphere();
};

#endif // MESHFACTORY_H
