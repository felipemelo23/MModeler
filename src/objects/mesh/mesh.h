#ifndef MESH_H
#define MESH_H

#include "medge.h"
#include "mface.h"
#include "mvertex.h"

#include <objects/object.h>
#include <unordered_map>

using std::unordered_map;

class Mesh : public Object
{
public:
    Mesh();

    MVertex *getVertex(string id);
    MFace *getFace(string id);
    MEdge *getEdge(string id);

    void addVertex(string id, MVertex *vertex);
    void addFace(string id, MFace *face);
    void addEdge(string id, MEdge *edge);

    int isInside(Vec4 pos);
    vector<RCResult> checkIntersection(Ray ray);

    Vec3 getMinimumCoords();
    Vec3 getMaximumCoords();

private:
    unordered_map<string, MVertex*> vertices;
    unordered_map<string, MFace*> faces;
    unordered_map<string, MEdge*> edges;

};

#endif // MESH_H
