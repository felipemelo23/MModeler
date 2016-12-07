#ifndef MEDGE_H
#define MEDGE_H

#include "mface.h"
#include "mvertex.h"
#include <string>

using std::string;

class MEdge
{
public:
    MEdge(string id, MVertex *start, MVertex *end, MFace *left, MFace *right, MEdge *lprev, MEdge *lnext, MEdge *rprev, MEdge *rnext);

    MVertex *getStart() const;
    void setStart(MVertex *value);

    MVertex *getEnd() const;
    void setEnd(MVertex *value);

    MFace *getLeft() const;
    void setLeft(MFace *value);

    MFace *getRight() const;
    void setRight(MFace *value);

    MEdge *getLprev() const;
    void setLprev(MEdge *value);

    MEdge *getLnext() const;
    void setLnext(MEdge *value);

    MEdge *getRprev() const;
    void setRprev(MEdge *value);

    MEdge *getRnext() const;
    void setRnext(MEdge *value);

private:
    string id;

    MVertex *start;
    MVertex *end;

    MFace *left;
    MFace *right;

    MEdge *lprev;
    MEdge *lnext;

    MEdge *rprev;
    MEdge *rnext;
};

#endif // MEDGE_H
