#ifndef CSGNODE_H
#define CSGNODE_H

#include <objects/object.h>
#include <objects/rbprism.h>
#include <objects/rbpyramid.h>
#include <objects/sphere.h>

#define OP_INTERSECTION     0
#define OP_UNION            1
#define OP_DIFERENCE        2
#define PRIMITIVE           3
#define NEW                 4

#define RIGHT               5
#define LEFT                6

class CSGNode : public Object
{
private:
    bool isRoot;
    short type;
    int depth;
    vector<CSGNode*> *children;
    Object *obj;

public:
    CSGNode(bool isRoot=false, int depth=0, short type=NEW);
    ~CSGNode();

//    short getState() const;
//    void setState(short value);
//    int getDepth() const;
//    void setDepth(int value);
//    double getSize() const;
//    void setSize(double value);
//    vector<CSGNode *> *getChildren() const;
//    vector<CSGNode *> *getChildrenCopy();
    CSGNode *getChild(int index);

    void newChild(CSGNode* child);

    bool put(Object *obj, short type=PRIMITIVE, short direction=RIGHT);

    bool hasChildren();

    int isInside(Vec4 *pos);
    Vec3 *getMinimumCoords();
    Vec3 *getMaximumCoords();
};

#endif // CSGNODE_H
