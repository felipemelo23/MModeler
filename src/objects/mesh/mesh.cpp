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

}

void Mesh::mev(std::__cxx11::string vertexId)
{

}

void Mesh::mef(std::__cxx11::string sVertexId, std::__cxx11::string eVertexId)
{

}

vector<MEdge *> Mesh::ev(std::__cxx11::string vertexId)
{
    vector<MEdge*> result = vector<MEdge*>();

    MEdge *vertexEdge = edges.at(vertices.at(vertexId)->getEdgeId());

    result.push_back(vertexEdge);
    result.push_back(vertexEdge->getRnext());

    vector<string> facesVisited = vector<string>();

    facesVisited.push_back(vertexEdge->getLeft()->getId());
    facesVisited.push_back(vertexEdge->getRight()->getId());

    MEdge *currEdge = vertexEdge->getRnext();

    while (currEdge->getId() != vertexEdge->getLprev()->getId()) {
        if (!isFaceVisited(facesVisited,currEdge->getRight()->getId())) {
            vector<MEdge*> faceEdges = ef(currEdge->getRight()->getId());

            for (MEdge* edge : faceEdges) {
                if ((edge->getStart()->getId() == vertexId)||
                    (edge->getEnd()->getId() == vertexId)) {
                    result.push_back(edge);
                    currEdge = edge;
                    break;
                }
            }
        }

        if (!isFaceVisited(facesVisited,currEdge->getLeft()->getId())) {
            vector<MEdge*> faceEdges = ef(currEdge->getLeft()->getId());

            for (MEdge* edge : faceEdges) {
                if ((edge->getStart()->getId() == vertexId)||
                    (edge->getEnd()->getId() == vertexId)) {
                    result.push_back(edge);
                    currEdge = edge;
                    break;
                }
            }
        }
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
    vector<MEdge *> result = vector<MEdge *>();

    MVertex *vertex;
    MEdge *nextEdge;

    MEdge *edge0 = edges.at(faces.at(faceId)->getEdgeId());

    result.push_back(edge0);

    if (edge0->getLeft()->getId() == faceId) {
        vertex = edge0->getStart();
        nextEdge = edge0->getLnext();
    }

    if (edge0->getRight()->getId() == faceId) {
        vertex = edge0->getEnd();
        nextEdge = edge0->getRnext();
    }

    while (nextEdge->getId() != edge0->getId()) {
        result.push_back(nextEdge);

        if (nextEdge->getStart()->getId() == vertex->getId()) {
            vertex = nextEdge->getEnd();
            nextEdge = nextEdge->getRnext();
        }

        if (nextEdge->getEnd()->getId() == vertex->getId()) {
            vertex = nextEdge->getStart();
            nextEdge = nextEdge->getLnext();
        }
    }

    return result;
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
