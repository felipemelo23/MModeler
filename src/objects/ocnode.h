#ifndef OCNODE_H
#define OCNODE_H

#include <objects/object.h>
#include <vector>

using namespace std;

typedef vector<Ocnode*> Children;

class Ocnode : public Object
{
private:
    short state;
    int depth;
    double size;
    Ocnode* parent;
    Children child;

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
    Children getChild() const;
    void setChild(const Children &value);

    void classify(Object* src, int maxDepth);
};

#endif // Ocnode_H
