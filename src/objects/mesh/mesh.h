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
    void mef(string v1Id, string e1Id, string v2Id, string e2Id);

    vector<MEdge*> ev(string vertexId);
    vector<MEdge*> ee(string edgeId);
    std::pair<MFace*, MFace*> fe(string edgeId);
    vector<MEdge *> ef(string faceId);
    vector<MVertex *> vf(string faceId);

    int isInside(Vec4 pos);
    vector<RCResult> checkIntersection(Ray ray);

    Vec3 getMinimumCoords();
    Vec3 getMaximumCoords();

    unordered_map<string, MFace *> getFaces() const;
    unordered_map<string, MVertex *> getVertices() const;
    unordered_map<string, MEdge *> getEdges() const;

    vector<string> getActiveVertices() const;

    vector<string> getActiveEdges() const;

    vector<string> getActiveFaces() const;

    double getSurfaceArea();

    Vec3 getFaceCenter(vector<MVertex *> faceVertices);

private:
    unordered_map<string, MVertex*> vertices;
    unordered_map<string, MFace*> faces;
    unordered_map<string, MEdge*> edges;

    vector<string> activeVertices;
    vector<string> activeEdges;
    vector<string> activeFaces;

    void setTopWings(MEdge *edge, MEdge *nl=NULL, MEdge *pr=NULL);
    void setBotWings(MEdge *edge, MEdge *pl=NULL, MEdge *nr=NULL);
    void setWings(MVertex *vertex, MEdge *edge, MEdge *wings);
    MEdge *getEdgeCCW(MVertex *vertex, MEdge *edge);
    MEdge *getEdgeCW(MVertex *vertex, MEdge *edge);
    MVertex *getNextVertex(MVertex *vertex, MEdge *edge);
    vector<MEdge*> getLoopEdges(MFace *loop);
};

#endif // MESH_H
