#include <objects/ocnode.h>

Ocnode::Ocnode(bool isRoot) : Object()
{
    this->type = Object::OCTREE;
    this->name = "Octree";

    this->children = NULL;
    this->isRoot = isRoot;
}

Ocnode::~Ocnode()
{
    delete ow;
    delete wo;
    if (children != NULL) {
        for (int i=0;i<8;i++)
            delete getChild(i);
        delete children;
    }
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

vector<Ocnode *> *Ocnode::getChildren() const
{
    return children;
}

void Ocnode::setChildren(vector<Ocnode *> *children)
{
    if (this->children != NULL) delete this->children;

    this->children = children;
}

void Ocnode::addChild(Ocnode *child)
{
    if (children == NULL)
        children = new vector<Ocnode*>();

    if (children->size() < 8)
        children->push_back(child);
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

void Ocnode::translate(double x, double y, double z)
{
    Object::translate(x,y,z);

    if (children != NULL)
        for (int i=0;i<8;i++)
            children->at(i)->translate(x,y,z);
}

void Ocnode::scale(double x, double y, double z)
{
    Object::scale(x,y,z);

    if (children != NULL)
        for (int i=0;i<8;i++)
            children->at(i)->scale(x,y,z);
}

void Ocnode::rotate(double degree, bool x, bool y, bool z)
{
    Object::rotate(degree,x,y,z);

    if (children != NULL)
        for (int i=0;i<8;i++)
            children->at(i)->rotate(degree,x,y,z);
}

/* Pseudo Codigo:

  -> Obter vertices do ocnode;
  -> Conferir se o no eh raiz:
    >> se sim: criar a boundingbox e converter o centro do noh
        para coordenadas de mundo.

  -> Conferir se pontos estao contidos no objeto:
    >> se todos: preto
    >> se nenhum: branco
    >> default: cinza

  -> Se maxDepth foi alcancado, encerrar a recursao

*/

void Ocnode::classify(Object *src, int maxDepth,bool hasBoundingBox)
{
    //define a boundingbox do objeto
    if((isRoot)&&(!hasBoundingBox))
    {
        Vec3 *range = src->getMaximumCoords()->sub(src->getMinimumCoords());
        Vec3 *p = src->getMaximumCoords()->sum(src->getMinimumCoords())->prod(0.5);
        size = max(max(range->getX(),range->getY()) , range->getZ());
        translate(p->getX(),p->getY(),p->getZ());
    }

    Vec4 **v = getVertices();
    int count=0;

    for(int i=0; i<8; i++)
        if(src->isInside(v[i])) count++;

    if(((count < 8) && (count > 0) && (depth < maxDepth)) || (isRoot))  //cinza
    {
        state = 0;

        children = new vector<Ocnode*>();

        for(int i=0; i<8; i++)
        {
            children->push_back(new Ocnode());
            children->at(i)->setDepth(depth+1);
            children->at(i)->setSize(size/2);

            children->at(i)->translate(getOrigin()->getX(),getOrigin()->getY(),getOrigin()->getZ());
        }

        double t = size/4;
        children->at(0)->translate(t,t,t);
        children->at(1)->translate(-t,t,t);
        children->at(2)->translate(-t,-t,t);
        children->at(3)->translate(t,-t,t);
        children->at(4)->translate(t,t,-t);
        children->at(5)->translate(-t,t,-t);
        children->at(6)->translate(-t,-t,-t);
        children->at(7)->translate(t,-t,-t);

        for (int i=0;i<8;i++)
            children->at(i)->classify(src,maxDepth);
    } else if ((count < 8) && (count > 0) && (depth >= maxDepth)) {
        state = 1;
    }
    else if (count == 0)    //branco
    {
        state = -1;
    }
    else if (count == 8)    //preto
    {
        state = 1;
    }
}

Ocnode* Ocnode::intersection(Ocnode *A, Ocnode *B)
{
    Ocnode *octree = new Ocnode(true);

    octree->setSize(A->getSize());
    octree->setState(0);
    octree->translate(A->getOrigin()->getX(),A->getOrigin()->getY(),A->getOrigin()->getY());
    octree->setChildren(getCommonChildren(A,B));

    return octree;
}

vector<Ocnode*> *Ocnode::getCommonChildren(Ocnode* A, Ocnode *B) {
    vector<Ocnode*> *commonChildren = new vector<Ocnode*>();

    Ocnode *child;
    if ((A->getChildren() != NULL)&&(B->getChildren() != NULL)) {
        for (int i=0;i<8;i++) {
            child = new Ocnode();
            child->setDepth(A->getChild(i)->getDepth());
            child->setSize(A->getChild(i)->getSize());
            child->translate(A->getChild(i)->getOrigin()->getX(),
                             A->getChild(i)->getOrigin()->getY(),
                             A->getChild(i)->getOrigin()->getZ());

            if ((A->getChild(i)->getState() == B->getChild(i)->getState())&&
                (A->getChild(i)->getState() == 1)){
                child->setState(1);
            } else if ((A->getChild(i)->getState() == B->getChild(i)->getState())&&
                       (A->getChild(i)->getState() == 0)) {
                child->setState(0);
                child->setChildren(getCommonChildren(A->getChild(i),B->getChild(i)));
            } else {
                child->setState(-1);
            }

            commonChildren->push_back(child);
        }
    }

    return commonChildren;
}























