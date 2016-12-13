#include "mesh.h"

Mesh::Mesh()
{
    this->vertices = unordered_map<string, MVertex*>();
    this->faces = unordered_map<string, MFace*>();
    this->edges = unordered_map<string, MEdge*>();
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
    vertices.insert(std::make_pair(id,vertex));
}

void Mesh::addFace(std::__cxx11::string id, MFace *face)
{
    faces.insert(std::make_pair(id,face));
}

void Mesh::addEdge(std::__cxx11::string id, MEdge *edge)
{
    edges.insert(std::make_pair(id,edge));
}

void Mesh::mvfs()
{
    string vertexId = QString::number(vertices.size()).toStdString();
    string faceId = QString::number((faces.size())).toStdString();

    vertices.insert(std::make_pair(vertexId,new MVertex(vertexId,"",0,0,0)));
    faces.insert(std::make_pair(faceId,new MFace(faceId,"")));
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

    MEdge *new_edge;
    new_edge = new MEdge(QString::number(edges.size()).toStdString(), vertex, new_vertex, NULL, NULL, new_edge, new_edge, new_edge, new_edge);

    if (edge2Id == "") {
        if (edge1Id != "")
            setBotWings(new_edge, edge1, edge1);
        setWings(vertex, edge1, new_edge);
    } else {
        new_edge->setLprev(edge1);
        new_edge->setRprev(edge2);

        /* GETTING NEW_EDGE'S NEXT RIGHT EDGE */
        MEdge *curr_edge = edge1;
        MEdge *next_edge = getEdgeCW(vertex, curr_edge);

        while (next_edge->getId() != edge2->getId()) {
            curr_edge = next_edge;
            next_edge = getEdgeCW(vertex, curr_edge);
        }

        new_edge->setRnext(curr_edge);

        /* GETTING NEW_EDGE'S NEXT LEFT EDGE */
        curr_edge = edge2;
        next_edge = getEdgeCW(vertex, curr_edge);

        while (next_edge->getId() != edge1->getId()) {
            curr_edge = next_edge;
            next_edge = getEdgeCW(vertex, curr_edge);
        }

        new_edge->setLnext(curr_edge);

        MEdge *nl = new_edge->getLnext();
        MEdge *pl = new_edge->getLprev();
        MEdge *nr = new_edge->getRnext();
        MEdge *pr = new_edge->getRprev();

        if (new_vertex->getId() == nl->getStart()->getId()) {
            nl->setLprev(new_edge);
        } else if (new_vertex->getId() == nl->getEnd()->getId()) {
            nl->setRprev(new_edge);
        }

        if (vertex->getId() == pl->getStart()->getId()) {
            pl->setRnext(new_edge);
        } else if (vertex->getId() == pl->getEnd()->getId()) {
            pl->setLnext(new_edge);
        }

        if (vertex->getId() == nr->getStart()->getId()) {
            nr->setLprev(new_edge);
        } else if (vertex->getId() == nr->getEnd()->getId()) {
            nr->setRprev(new_edge);
        }

        if (new_vertex->getId() == pr->getStart()->getId()) {
            pr->setRnext(new_edge);
        } else if (new_vertex->getId() == pr->getEnd()->getId()) {
            pr->setLnext(new_edge);
        }

    }
}

void Mesh::mev(std::__cxx11::string sEdgeId, std::__cxx11::string eEdgeId, std::__cxx11::string vertexId)
{

}

void Mesh::mef()
{

}

vector<MEdge *> Mesh::ev(std::__cxx11::string vertexId)
{
    MVertex *vertex = vertices.at(vertexId);
    MEdge *initial_edge = edges.at(vertex->getEdgeId());

    vector<MEdge*> result = vector<MEdge*>();
    result.push_back(initial_edge);

    MEdge *curr_edge = initial_edge;
    MEdge *next_edge = getEdgeCW(vertex, curr_edge);

    while (next_edge->getId() != initial_edge->getId()) {
        curr_edge = next_edge;
        next_edge = getEdgeCW(vertex, curr_edge);

        result.push_back(curr_edge);
    }

    return result;
}

bool Mesh::isFaceVisited(vector<string> facesVisited, string faceId) {
    bool result = false;

    for (string face : facesVisited) {
        if (face == faceId) {
            result = true;
            break;
        }
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

vector<MEdge *> Mesh::getEdges(MFace *loop)
{
    MEdge *initial_edge = edges.at(loop->getEdgeId());
    vector<MEdge *> result = vector<MEdge*>();
    result.push_back(initial_edge);

    MVertex *vertex;
    if (loop->getOrientation() == MFace::CCW)
        vertex = initial_edge->getEnd();
    else
        vertex = initial_edge->getStart();

    MEdge *curr_edge = initial_edge;
    MEdge *next_edge = getEdgeCCW(vertex, curr_edge);

    while (next_edge->getId() != initial_edge->getId()) {
        curr_edge = next_edge;
        vertex = getNextVertex(vertex, curr_edge);
        next_edge = getEdgeCCW(vertex, curr_edge);

        result.push_back(curr_edge);
    }

    return result;
}

vector<MEdge *> Mesh::ee(std::__cxx11::string edgeId)
{
    vector<MEdge *> edges1 = ev(edges.at(edgeId)->getStart()->getId());
    vector<MEdge *> edges2 = ev(edges.at(edgeId)->getEnd()->getId());

    for (MEdge *edge : edges2) {
        if (edge->getId() != edgeId) edges1.push_back(edge);
    }

    return edges1;
}

std::pair<MFace *, MFace *> Mesh::fe(std::__cxx11::string edgeId)
{
    MEdge *edge = edges.at(edgeId);
    return std::make_pair(edge->getRight(), edge->getLeft());
}

vector<MEdge *> Mesh::ef(std::__cxx11::string faceId)
{
    return getEdges(faces.at(faceId));
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
