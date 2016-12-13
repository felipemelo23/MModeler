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

private:
    static vector< pair<Vec3,Vec3> > getEdges(vector<Face> faces);
    static int *getNeighborEdges(pair<Vec3,Vec3> edge, vector< pair<Vec3,Vec3> > edges);
    static bool edgeEqual(pair<Vec3,Vec3> e1, pair<Vec3,Vec3> e2);

    static void buildGenMesh_recursive(vector< pair<Vec3,Vec3> > edges, Mesh *mesh, int edge_qtd, int eID=-1, int vID=-1, int fID=-1, int it=1, int parent_edge=-1);
};

#endif // MESHFACTORY_H
