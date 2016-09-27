#include <objects/ocnode.h>

Ocnode::Ocnode()
{

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

Children Ocnode::getChild() const
{
    return child;
}

void Ocnode::setChild(const Children &value)
{
    child = value;
}

Object* Ocnode::getBoundingBox()
{

}

void Ocnode::rotate(double degree, bool x, bool y, bool z)
{

}

void Ocnode::scale(double x, double y, double z)
{

}

void Ocnode::translate(double x, double y, double z)
{

}

bool Ocnode::isInside(Vec3 pos)
{

}