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
