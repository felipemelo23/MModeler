#ifndef OCNODE_H
#define OCNODE_H

#include <objects/object.h>
#include <vector>

using namespace std;

class Ocnode : public Object
{

private:
    short state;
    int depth;
    double size;
    Ocnode* parent;
    vector<Ocnode*> child;

public:
    Ocnode();

    short getState() const;
    void setState(short value);
    int getDepth() const;
    void setDepth(int value);
    double getSize() const;
    void setSize(double value);
    Ocnode *getParent() const;
    void setParent(Ocnode *value);
    vector<Ocnode*> getChild() const;
    void setChild(const vector<Ocnode*> &value);

    void classify(Object* src, int maxDepth);

    bool isInside(Vec4 *pos);
    Vec3 *getMinimumCoords();
    Vec3 *getMaximumCoords();
};

#endif // Ocnode_H
