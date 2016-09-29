#include <objects/ocnode.h>

Ocnode::Ocnode() : Object()
{
    this->type = Object::OCTREE;
    this->name = "Octree";

    this->children = NULL;
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

vector<Ocnode *> *Ocnode::getChildren() const
{
    return children;
}

Ocnode *Ocnode::getChild(int index)
{
    if (index < 8) return children->at(index);
    return NULL;
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

Vec4 **Ocnode::getVertices()
{
    Vec4 **v = new Vec4*[8];

    v[0] = new Vec4(size/2,-size/2,size/2,1);
    v[1] = new Vec4(-size/2,-size/2,size/2,1);
    v[2] = new Vec4(-size/2,-size/2,-size/2,1);
    v[3] = new Vec4(size/2,-size/2,-size/2,1);
    v[4] = new Vec4(size/2,size/2,-size/2,1);
    v[5] = new Vec4(-size/2,size/2,-size/2,1);
    v[6] = new Vec4(-size/2,size/2,size/2,1);
    v[7] = new Vec4(size/2,size/2,size/2,1);

    Vec4 *trash;
    for (int i=0;i<8;i++)
    {
        trash = v[i];
        v[i] = ow->prod(v[i]);
        delete trash;
    }

    return v;
}

void Ocnode::classify(Object *src, int maxDepth)
{

}
