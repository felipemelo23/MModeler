#include "mesh.h"
#include <iostream>

using namespace std;

Mesh::Mesh()
{
    this->vertices = unordered_map<string, MVertex*>();
    this->faces = unordered_map<string, MFace*>();
    this->edges = unordered_map<string, MEdge*>();

    this->activeVertices = vector<string>();
    this->activeFaces = vector<string>();
    this->activeEdges = vector<string>();

    this->type = Object::MESH;
    this->name = "Mesh";
}

MVertex *Mesh::getVertex(std::__cxx11::string id)
{
    return vertices.at(id);
}

MFace *Mesh::getFace(std::__cxx11::string id)
{
    return faces.at(id);
}

MEdge *Mesh::getEdge(std::__cxx11::string id)
{
    return edges.at(id);
}

void Mesh::addVertex(std::__cxx11::string id, MVertex *vertex)
{
    vertices.emplace(id,vertex);
}

void Mesh::addFace(std::__cxx11::string id, MFace *face)
{
    faces.emplace(id,face);
}

void Mesh::addEdge(std::__cxx11::string id, MEdge *edge)
{
    edges.emplace(id,edge);
}

void Mesh::mvfs()
{
    string vertexId = QString::number(vertices.size()).toStdString();
    string faceId = QString::number((faces.size())).toStdString();

    addVertex(vertexId,new MVertex(vertexId,"",0,0,0));
    addFace(faceId,new MFace(faceId,""));
}

void Mesh::clearActives() {
    activeVertices = vector<string>();
    activeEdges = vector<string>();
    activeFaces = vector<string>();
}

void Mesh::mev(std::__cxx11::string vertexId, Vec3 dir, std::__cxx11::string edge1Id, std::__cxx11::string edge2Id)
{
    MVertex *vertex = vertices.at(vertexId);

    MEdge *edge1;
    if (edge1Id != "")
        edge1 = edges.at(edge1Id);
    MEdge *edge2;
    if (edge2Id != "")
        edge2 = edges.at(edge2Id);

    Vec3 new_vertex_pos = *vertex + dir;
    MVertex *new_vertex = new MVertex(QString::number(vertices.size()).toStdString(), "", new_vertex_pos);
    addVertex(QString::number(vertices.size()).toStdString(), new_vertex);

    MEdge *new_edge;
    new_edge = new MEdge(QString::number(edges.size()).toStdString(), vertex, new_vertex, NULL, NULL, NULL, NULL, NULL, NULL);
    new_edge->setLnext(new_edge);
    new_edge->setLprev(new_edge);
    new_edge->setRnext(new_edge);
    new_edge->setRprev(new_edge);

    new_vertex->setEdgeId(new_edge->getId());
    addEdge(QString::number(edges.size()).toStdString(), new_edge);

    if (edge2Id == "") {
        if (edge1Id == "") {
            new_edge->setLeft(faces.at("0"));
            new_edge->setRight(faces.at("0"));
            MFace *face = faces.at("0");
            face->setEdgeId(new_edge->getId());
        } else {
            setBotWings(new_edge,edge1,edge1);
            setWings(vertex, edge1, new_edge);

            if (vertex->getId() == edge1->getEnd()->getId()) {
                new_edge->setLeft(edge1->getLeft());
                new_edge->setRight(edge1->getRight());
            } else if (vertex->getId() == edge1->getStart()->getId()) {
                new_edge->setLeft(edge1->getRight());
                new_edge->setRight(edge1->getLeft());
            }
        }
    } else {
        if (edge1->getLeft()->getId() == edge2->getLeft()->getId()) {
            new_edge->setLprev(edge1);
            new_edge->setRnext(edge2);
            edge1->setLnext(new_edge);
            edge2->setLprev(new_edge);
            new_edge->setLeft(edge1->getLeft());
            new_edge->setRight(edge1->getLeft());
        } else if (edge1->getRight()->getId() == edge2->getRight()->getId()) {
            new_edge->setLprev(edge2);
            new_edge->setRnext(edge1);
            edge1->setRprev(new_edge);
            edge2->setRnext(new_edge);
            new_edge->setLeft(edge1->getRight());
            new_edge->setRight(edge1->getRight());
        } else if (edge1->getLeft()->getId() == edge2->getRight()->getId()) {
            if (edge1->getStart()->getId() == vertexId) {
                new_edge->setLprev(edge2);
                new_edge->setRnext(edge1);
                edge1->setLprev(new_edge);
                edge2->setRnext(new_edge);
            } else if (edge1->getEnd()->getId() == vertexId) {
                new_edge->setLprev(edge1);
                new_edge->setRnext(edge2);
                edge1->setLnext(new_edge);
                edge2->setRprev(new_edge);
            }
        } else if (edge1->getRight()->getId() == edge2->getLeft()->getId()) {
            if (edge1->getStart()->getId() == vertexId) {
                new_edge->setLprev(edge1);
                new_edge->setRnext(edge2);
                edge1->setRnext(new_edge);
                edge2->setLprev(new_edge);
            } else if (edge1->getEnd()->getId() == vertexId) {
                new_edge->setLprev(edge2);
                new_edge->setRnext(edge1);
                edge1->setRprev(new_edge);
                edge2->setLnext(new_edge);
            }
        }
    }

}

//void Mesh::mev(std::__cxx11::string vertexId, Vec3 dir, std::__cxx11::string edge1Id, std::__cxx11::string edge2Id)
//{
//    MVertex *vertex = vertices.at(vertexId);

//    MEdge *edge1;
//    if (edge1Id != "")
//        edge1 = edges.at(edge1Id);
//    MEdge *edge2;
//    if (edge2Id != "")
//        edge2 = edges.at(edge2Id);

//    Vec3 new_vertex_pos = *vertex + dir;
//    MVertex *new_vertex = new MVertex(QString::number(vertices.size()).toStdString(), "", new_vertex_pos);
//    addVertex(QString::number(vertices.size()).toStdString(), new_vertex);

//    MEdge *new_edge;
//    new_edge = new MEdge(QString::number(edges.size()).toStdString(), vertex, new_vertex, NULL, NULL, NULL, NULL, NULL, NULL);
//    new_edge->setLnext(new_edge);
//    new_edge->setLprev(new_edge);
//    new_edge->setRnext(new_edge);
//    new_edge->setRprev(new_edge);

//    new_vertex->setEdgeId(new_edge->getId());
//    addEdge(QString::number(edges.size()).toStdString(), new_edge);

//    if (edge2Id == "") {
//        if (edge1Id != "") {
//            setBotWings(new_edge, edge1, edge1);
//            if (vertex->getId() == edge1->getEnd()->getId()) {
//                new_edge->setLeft(edge1->getLeft());
//                new_edge->setRight(edge1->getRight());
//            } else if (vertex->getId() == edge1->getStart()->getId()) {
//                new_edge->setLeft(edge1->getRight());
//                new_edge->setRight(edge1->getLeft());
//            }

//            setWings(vertex, edge1, new_edge);
//        }
//        else {
//            new_edge->setLeft(faces.at("0"));
//            new_edge->setRight(faces.at("0"));
//        }
//    } else {
//        cout << 2 << endl;
//        new_edge->setLprev(edge1);
//        new_edge->setRprev(edge2);

//        /* GETTING NEW_EDGE'S NEXT RIGHT EDGE */
//        MEdge *curr_edge = edge1;
//        MEdge *next_edge = getEdgeCW(vertex, curr_edge);

//        while (next_edge->getId() != edge2->getId()) {
//            curr_edge = next_edge;
//            next_edge = getEdgeCW(vertex, curr_edge);
//        }

//        new_edge->setRnext(curr_edge);

//        /* GETTING NEW_EDGE'S NEXT LEFT EDGE */
//        curr_edge = edge2;
//        next_edge = getEdgeCW(vertex, curr_edge);

//        while (next_edge->getId() != edge1->getId()) {
//            curr_edge = next_edge;
//            next_edge = getEdgeCW(vertex, curr_edge);
//        }

//        new_edge->setLnext(curr_edge);

//        MEdge *nl = new_edge->getLnext();
//        MEdge *pl = new_edge->getLprev();
//        MEdge *nr = new_edge->getRnext();
//        MEdge *pr = new_edge->getRprev();

//        if (vertex->getId() == nl->getStart()->getId())
//            nl->setStart(new_vertex);
//        else if (vertex->getId() == nl->getEnd()->getId())
//            nl->setEnd(new_vertex);

//        if (vertex->getId() == pr->getStart()->getId())
//            pr->setStart(new_vertex);
//        else if (vertex->getId() == pr->getEnd()->getId())
//            pr->setEnd(new_vertex);

//        if (new_vertex->getId() == nl->getStart()->getId()) {
//            nl->setLprev(new_edge);
//        } else if (new_vertex->getId() == nl->getEnd()->getId()) {
//            nl->setRprev(new_edge);
//        }

//        if (vertex->getId() == pl->getStart()->getId()) {
//            pl->setRnext(new_edge);
//        } else if (vertex->getId() == pl->getEnd()->getId()) {
//            pl->setLnext(new_edge);
//        }

//        if (vertex->getId() == nr->getStart()->getId()) {
//            nr->setLprev(new_edge);
//        } else if (vertex->getId() == nr->getEnd()->getId()) {
//            nr->setRprev(new_edge);
//        }

//        if (new_vertex->getId() == pr->getStart()->getId()) {
//            pr->setRnext(new_edge);
//        } else if (new_vertex->getId() == pr->getEnd()->getId()) {
//            pr->setLnext(new_edge);
//        }

//    }
//}

void Mesh::mef(std::__cxx11::string v1Id, std::__cxx11::string e1Id, std::__cxx11::string v2Id, std::__cxx11::string e2Id)
{

}

vector<MEdge *> Mesh::ev(std::__cxx11::string vertexId)
{
    activeVertices = vector<string>();
    activeEdges = vector<string>();
    activeFaces = vector<string>();

    MVertex *vertex = vertices.at(vertexId);



    MEdge *initial_edge;
    if (vertex->getEdgeId() != "") {
        initial_edge = edges.at(vertex->getEdgeId());
    } else {
        for (pair<string,MEdge*> edge : edges) {
            if ((edge.second->getEnd()->getId() == vertexId)||
                (edge.second->getStart()->getId() == vertexId)) {
                initial_edge = edge.second;
                break;
            }
        }
    }

    vector<MEdge*> result = vector<MEdge*>();
    result.push_back(initial_edge);

    MEdge *curr_edge = initial_edge;
    MEdge *next_edge = getEdgeCW(vertex, curr_edge);

    while (next_edge->getId() != initial_edge->getId()) {
        curr_edge = next_edge;
        next_edge = getEdgeCW(vertex, curr_edge);

        result.push_back(curr_edge);
        activeEdges.push_back(curr_edge->getId());
    }

    for (auto edge : result) {
        activeEdges.push_back(edge->getId());
    }

    return result;

}

void Mesh::setTopWings(MEdge *edge, MEdge *nl, MEdge *pr)
{
    if (nl != NULL) edge->setLnext(nl);
    if (pr != NULL) edge->setRprev(pr);
}

void Mesh::setBotWings(MEdge *edge, MEdge *pl, MEdge *nr)
{
    if (pl != NULL) edge->setLprev(pl);
    if (nr != NULL) edge->setRnext(nr);
}

void Mesh::setWings(MVertex *vertex, MEdge *edge, MEdge *wings)
{
    if (vertex->getId() == edge->getEnd()->getId()) {
        setTopWings(edge,wings,wings);
    } else if (vertex->getId() == edge->getStart()->getId()) {
        setBotWings(edge,wings,wings);
    }
}

MEdge *Mesh::getEdgeCCW(MVertex *vertex, MEdge *edge)
{
    if (vertex->getId() == edge->getEnd()->getId()) {
        return edge->getLnext();
    } else if (vertex->getId() == edge->getStart()->getId()) {
        return edge->getRnext();
    }
}

MEdge *Mesh::getEdgeCW(MVertex *vertex, MEdge *edge)
{
    if (vertex->getId() == edge->getEnd()->getId()) {
        return edge->getRprev();
    } else if (vertex->getId() == edge->getStart()->getId()) {
        return edge->getLprev();
    }
}

MVertex *Mesh::getNextVertex(MVertex *vertex, MEdge *edge)
{
    if (vertex->getId() == edge->getEnd()->getId()) {
        return edge->getStart();
    } else if (vertex->getId() == edge->getStart()->getId()) {
        return edge->getEnd();
    }
}

vector<MEdge *> Mesh::getLoopEdges(MFace *loop)
{
    MEdge *initial_edge = edges.at(loop->getEdgeId());
    vector<MEdge *> result = vector<MEdge*>();
    result.push_back(initial_edge);

    MVertex *vertex;
    if (loop->getOrientation() == MFace::CCW)
        vertex = initial_edge->getEnd();
    else
        vertex = initial_edge->getStart();
    MVertex *initial_vertex = vertex;
    MEdge *curr_edge = initial_edge;
    MEdge *next_edge = getEdgeCCW(vertex, curr_edge);

    while (vertex->getId() != initial_vertex->getId()) {
        curr_edge = next_edge;
        vertex = getNextVertex(vertex, curr_edge);
        next_edge = getEdgeCCW(vertex, curr_edge);

        result.push_back(curr_edge);
    }

    return result;
}

vector<MEdge *> Mesh::ee(std::__cxx11::string edgeId)
{
    activeVertices.clear();
    activeEdges.clear();
    activeFaces.clear();

    vector<MEdge *> edges1 = ev(edges.at(edgeId)->getStart()->getId());
    vector<MEdge *> edges2 = ev(edges.at(edgeId)->getEnd()->getId());

    for (MEdge *edge : edges2) {
        if (edge->getId() != edgeId) edges1.push_back(edge);
    }

    for (MEdge *edge : edges1) {
        activeEdges.push_back(edge->getId());
    }

    return edges1;
}

std::pair<MFace *, MFace *> Mesh::fe(std::__cxx11::string edgeId)
{
    activeVertices.clear();
    activeEdges.clear();
    activeFaces.clear();

    MEdge *edge = edges.at(edgeId);

    activeFaces.push_back(edge->getRight()->getId());
    activeFaces.push_back(edge->getLeft()->getId());

    return std::make_pair(edge->getRight(), edge->getLeft());
}

vector<MEdge *> Mesh::ef(std::__cxx11::string faceId)
{
    clearActives();

    vector<MEdge *> loopEdges = getLoopEdges(faces.at(faceId));

    for (MEdge *edge : loopEdges) {
        activeEdges.push_back(edge->getId());
    }

    return loopEdges;
}

vector<MVertex *> Mesh::vv(string vertexId)
{
    vector<MEdge *> adjEdges = ev(vertexId);
    vector<MVertex *> result = vector<MVertex *>();

    for (MEdge *edge : adjEdges) {
        if (edge->getEnd()->getId() != vertexId)
            result.push_back(edge->getEnd());

        if (edge->getStart()->getId() != vertexId)
            result.push_back(edge->getStart());
    }

    clearActives();

    for (MVertex *vertex : result)
        activeVertices.push_back(vertex->getId());

    return result;
}

vector<MVertex *> Mesh::ve(string edgeId)
{
    clearActives();
    MEdge *edge = edges.at(edgeId);

    activeVertices.push_back(edge->getStart()->getId());
    activeVertices.push_back(edge->getEnd()->getId());

    return vector<MVertex*>();
}

vector<MVertex *> Mesh::vf(std::__cxx11::string faceId)
{
    vector<MEdge *> faceEdges = ef(faceId);
    vector<MVertex *> result = vector<MVertex*>();

    clearActives();

    for (MEdge *edge : faceEdges) {

        if (!contains(activeVertices, edge->getEnd()->getId()))
            activeVertices.push_back(edge->getEnd()->getId());
        if (!contains(activeVertices, edge->getStart()->getId()))
            activeVertices.push_back(edge->getStart()->getId());
    }

    return result;
}

bool Mesh::contains(vector<string> list, string item) {
    for (string listItem : list)
        if (listItem == item) return true;
    return false;
}

int Mesh::isInside(Vec4 pos)
{
    return 0;
}

vector<RCResult> Mesh::checkIntersection(Ray ray)
{
    return vector<RCResult>();
}

Vec3 Mesh::getMinimumCoords()
{
    double minX = std::numeric_limits<double>::max();
    double minY = std::numeric_limits<double>::max();
    double minZ = std::numeric_limits<double>::max();

    for (std::pair<string, MVertex *> i : vertices) {
        if (i.second->getX() < minX) minX = i.second->getX();
        if (i.second->getY() < minY) minY = i.second->getY();
        if (i.second->getZ() < minZ) minZ = i.second->getZ();
    }

    return Vec3(minX,minY,minZ);
}

Vec3 Mesh::getMaximumCoords()
{
    double maxX = std::numeric_limits<double>::min();
    double maxY = std::numeric_limits<double>::min();
    double maxZ = std::numeric_limits<double>::min();

    for (std::pair<string, MVertex *> i : vertices) {
        if (i.second->getX() > maxX) maxX = i.second->getX();
        if (i.second->getY() > maxY) maxY = i.second->getY();
        if (i.second->getZ() > maxZ) maxZ = i.second->getZ();
    }

    return Vec3(maxX,maxY,maxZ);
}

void Mesh::translate(double x, double y, double z)
{
    Mtx4x4 T = Mtx4x4::getTranslateMtx_(x,y,z);

    for (pair<string,MVertex *> v : vertices) {
        MVertex *vertex = v.second;
        Vec3 new_pos = T.prod_(*vertex,1);
        vertex->setX(new_pos.getX());
        vertex->setY(new_pos.getY());
        vertex->setZ(new_pos.getZ());
    }
}

void Mesh::scale(double x, double y, double z)
{
    Mtx4x4 S = Mtx4x4::getScaleMtx_(x,y,z);

    for (pair<string,MVertex *> v : vertices) {
        MVertex *vertex = v.second;
        Vec3 new_pos = S.prod_(*vertex,1);
        vertex->setX(new_pos.getX());
        vertex->setY(new_pos.getY());
        vertex->setZ(new_pos.getZ());
    }
}

void Mesh::rotate(double degree, bool x, bool y, bool z)
{
    Mtx4x4 R = Mtx4x4::getRotateMtx_(degree,x,y,z);

    for (pair<string,MVertex *> v : vertices) {
        MVertex *vertex = v.second;
        Vec3 new_pos = R.prod_(*vertex,1);
        vertex->setX(new_pos.getX());
        vertex->setY(new_pos.getY());
        vertex->setZ(new_pos.getZ());
    }
}

unordered_map<string, MFace *> Mesh::getFaces() const
{
    return faces;
}

unordered_map<string, MVertex *> Mesh::getVertices() const
{
    return vertices;
}

unordered_map<string, MEdge *> Mesh::getEdges() const
{
    return edges;
}

vector<string> Mesh::getActiveVertices() const
{
    return activeVertices;
}

vector<string> Mesh::getActiveEdges() const
{
    return activeEdges;
}

vector<string> Mesh::getActiveFaces() const
{
    return activeFaces;
}

double Mesh::getSurfaceArea()
{
    double area = 0;

    for (std::pair<string,MFace *> face : faces) {
        vector<MVertex*> faceVertices = vf(face.second->getId());

        Vec3 faceCenter = getFaceCenter(faceVertices);

        for (int i=0;i<faceVertices.size();i++) {
            Vec3 v1 = *(faceVertices[i]) - faceCenter;
            Vec3 v2 = *(faceVertices[i%faceVertices.size()]) - faceCenter;

            area = v1.cross_(v2).getNorm();
        }
    }

    return area;
}

Vec3 Mesh::getFaceCenter(vector<MVertex*> faceVertices)
{

}




















