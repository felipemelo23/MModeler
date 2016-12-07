#include "medge.h"

MEdge::MEdge(string id, MVertex *start, MVertex *end, MFace *left, MFace *right, MEdge *lprev, MEdge *lnext, MEdge *rprev, MEdge *rnext)
{
    this->id = id;

    this->start = start;
    this->end = end;

    this->left = left;
    this->right = right;

    this->lprev = lprev;
    this->lnext = lnext;

    this->rprev = rprev;
    this->rnext = rnext;
}

MVertex *MEdge::getStart() const
{
    return start;
}

void MEdge::setStart(MVertex *value)
{
    start = value;
}

MVertex *MEdge::getEnd() const
{
    return end;
}

void MEdge::setEnd(MVertex *value)
{
    end = value;
}

MFace *MEdge::getLeft() const
{
    return left;
}

void MEdge::setLeft(MFace *value)
{
    left = value;
}

MFace *MEdge::getRight() const
{
    return right;
}

void MEdge::setRight(MFace *value)
{
    right = value;
}

MEdge *MEdge::getLprev() const
{
    return lprev;
}

void MEdge::setLprev(MEdge *value)
{
    lprev = value;
}

MEdge *MEdge::getLnext() const
{
    return lnext;
}

void MEdge::setLnext(MEdge *value)
{
    lnext = value;
}

MEdge *MEdge::getRprev() const
{
    return rprev;
}

void MEdge::setRprev(MEdge *value)
{
    rprev = value;
}

MEdge *MEdge::getRnext() const
{
    return rnext;
}

void MEdge::setRnext(MEdge *value)
{
    rnext = value;
}
