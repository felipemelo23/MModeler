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

    void mvfs();
    void mev(string vertexId, Vec3 dir, string edge1Id="", string edge2Id="");
    void mev(string sEdgeId, string eEdgeId, string vertexId);
    void mef();

    vector<MEdge*> ev(string vertexId);
    vector<MEdge*> ee(string edgeId);
    std::pair<MFace*, MFace*> fe(string edgeId);
    vector<MEdge *> ef(string faceId);

    int isInside(Vec4 pos);
    vector<RCResult> checkIntersection(Ray ray);

    Vec3 getMinimumCoords();
    Vec3 getMaximumCoords();

private:
    unordered_map<string, MVertex*> vertices;
    unordered_map<string, MFace*> faces;
    unordered_map<string, MEdge*> edges;

    bool isFaceVisited(vector<string> facesVisited, string faceId);
    void setTopWings(MEdge *edge, MEdge *nl=NULL, MEdge *pr=NULL);
    void setBotWings(MEdge *edge, MEdge *pl=NULL, MEdge *nr=NULL);
    void setWings(MVertex *vertex, MEdge *edge, MEdge *wings);
    MEdge *getEdgeCCW(MVertex *vertex, MEdge *edge);
    MEdge *getEdgeCW(MVertex *vertex, MEdge *edge);
    MVertex *getNextVertex(MVertex *vertex, MEdge *edge);
    vector<MEdge*> getEdges(MFace *loop);
};

#endif // MESH_H
