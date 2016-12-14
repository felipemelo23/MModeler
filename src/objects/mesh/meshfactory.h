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
    static int *getNeighborFaces(pair<Vec3,Vec3> edge, vector<Face> faces);
    static bool edgeEqual(pair<Vec3,Vec3> e1, pair<Vec3,Vec3> e2);
    static bool edgeEqual(MEdge e1, MEdge e2);
    static bool edgeEqual(MEdge e1, pair<Vec3,Vec3> e2);

    static void buildEdge(Mesh *mesh, int eID, MVertex *vs, MVertex *ve);
    static void makeAdjascents(Mesh *mesh, int eID, MEdge *rprev, MEdge *lnext, MEdge *rnext, MEdge *lprev);
    static void linkEdgeFace(Mesh *mesh, int eID, int RfID, int LfID);
};

#endif // MESHFACTORY_H
