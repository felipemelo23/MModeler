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
    vector<MEdge *> ef(string faceId);
    vector<MVertex *> vv(string vertexId);
    vector<MVertex *> ve(string edgeId);
    vector<MVertex *> vf(string faceId);

    std::pair<MFace*, MFace*> fe(string edgeId);

    int isInside(Vec4 pos);
    vector<RCResult> checkIntersection(Ray ray);

    Vec3 getMinimumCoords();
    Vec3 getMaximumCoords();

    void translate(double x, double y, double z);
    void scale(double x, double y, double z);
    void rotate(double degree, bool x=true, bool y=false, bool z=false);

    unordered_map<string, MFace *> getFaces() const;
    unordered_map<string, MVertex *> getVertices() const;
    unordered_map<string, MEdge *> getEdges() const;

    vector<string> getActiveVertices() const;

    vector<string> getActiveEdges() const;

    vector<string> getActiveFaces() const;

    double getSurfaceArea();

    Vec3 getFaceCenter(vector<MVertex *> faceVertices);

    void clearActives();
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
    bool contains(vector<string> list, string item);
};

#endif // MESH_H
