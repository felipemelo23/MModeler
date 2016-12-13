#include "mvertex.h"

MVertex::MVertex(string id, string edgeId, double x, double y, double z) : Vec3(x,y,z)
{
    this->id = id;
    this->edgeId = edgeId;
}

MVertex::MVertex(std::__cxx11::string id, std::__cxx11::string edgeId, Vec3 pos) : Vec3(pos.getX(), pos.getY(), pos.getZ())
{
    this->id = id;
    this->edgeId = edgeId;
}

string MVertex::getId() const
{
    return id;
}

void MVertex::setEdgeId(const string &value)
{
    edgeId = value;
}

void MVertex::setId(const string &value)
{
    id = value;
}

string MVertex::getEdgeId() const
{
    return edgeId;
}
