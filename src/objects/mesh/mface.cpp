#include "mface.h"

MFace::MFace(string id, string edgeId, int orientation)
{
    this->id = id;
    this->edgeId = edgeId;
    this->orientation = orientation;
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

int MFace::getOrientation() const
{
    return orientation;
}

void MFace::setOrientation(int value)
{
    orientation = value;
}
