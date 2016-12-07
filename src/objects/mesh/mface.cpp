#include "mface.h"

MFace::MFace(string id, string edgeId)
{
    this->id = id;
    this->edgeId = edgeId;
}

string MFace::getId() const
{
    return id;
}

void MFace::setId(const string &value)
{
    id = value;
}

string MFace::getEdgeId() const
{
    return edgeId;
}

void MFace::setEdgeId(const string &value)
{
    edgeId = value;
}
