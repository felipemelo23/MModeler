#ifndef OCNODE_H
#define OCNODE_H

#include <objects/object.h>
#include <vector>
#include <algorithm>

using namespace std;

class Ocnode : public Object
{

private:
    short state;
    int depth=0;
    double size;
    Ocnode* parent;
    vector<Ocnode*> *children;
    bool isRoot;

public:
    Ocnode(bool isRoot=false);

    short getState() const;
    void setState(short value);
    int getDepth() const;
    void setDepth(int value);
    double getSize() const;
    void setSize(double value);
    Ocnode *getParent() const;
    void setParent(Ocnode *value);
    vector<Ocnode *> *getChildren() const;
    Ocnode *getChild(int index);

    void classify(Object* src, int maxDepth);

    bool isInside(Vec4 *pos);
    Vec3 *getMinimumCoords();
    Vec3 *getMaximumCoords();
    Vec4 **getVertices();
};

#endif // Ocnode_H
