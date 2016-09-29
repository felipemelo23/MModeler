#include <objects/ocnode.h>

Ocnode::Ocnode() : Object()
{
    this->type = Object::OCTREE;
    this->name = "Octree";
}

short Ocnode::getState() const
{
    return state;
}

void Ocnode::setState(short value)
{
    state = value;
}

int Ocnode::getDepth() const
{
    return depth;
}

void Ocnode::setDepth(int value)
{
    depth = value;
}

double Ocnode::getSize() const
{
    return size;
}

void Ocnode::setSize(double value)
{
    size = value;
}

Ocnode *Ocnode::getParent() const
{
    return parent;
}

void Ocnode::setParent(Ocnode *value)
{
    parent = value;
}

vector<Ocnode *> Ocnode::getChild() const
{
    return child;
}

void Ocnode::setChild(const vector<Ocnode *> &value)
{
    child = value;
}

void Ocnode::classify(Object *src, int maxDepth)
{

}

bool Ocnode::isInside(Vec4 *pos)
{

}

Vec3 *Ocnode::getMinimumCoords()
{

}

Vec3 *Ocnode::getMaximumCoords()
{

}
