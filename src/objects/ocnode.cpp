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

vector<Ocnode *> *Ocnode::getChildrenCopy()
{
    if (children == NULL)
        return NULL;

    vector<Ocnode *> *copy = new vector<Ocnode *>();

    Ocnode *child;
    for (int i=0;i<8;i++) {
        child = new Ocnode();
        child->setSize(getChild(i)->getSize());
        child->setState(getChild(i)->getState());
        child->setDepth(getChild(i)->getDepth());
        child->translate(getChild(i)->getOrigin()->getX(),
                         getChild(i)->getOrigin()->getY(),
                         getChild(i)->getOrigin()->getZ());
        child->setChildren(getChild(i)->getChildrenCopy());
        copy->push_back(child);
    }

    return copy;
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

void Ocnode::classify(vector<Object *> src, int maxDepth,bool hasBoundingBox)
{
    int count=0;
    Vec4 **v = getVertices();

    for (int i=0;i<src.size();i++) {
        int countObj = 0;

        for(int j=0; j<8; j++)
            if(src.at(j)->isInside(v[i])) countObj++;

        if (countObj > count) count = countObj;
    }

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
            } else if ((A->getChild(i)->getState() == 0)&&(B->getChild(i)->getState() == 1)){
                child->setState(0);
                child->setChildren(A->getChildrenCopy());
            } else if ((A->getChild(i)->getState() == 1)&&(B->getChild(i)->getState() == 0)){
                child->setState(0);
                child->setChildren(B->getChildrenCopy());
            } else {
                child->setState(-1);
            }

            commonChildren->push_back(child);
        }
    }

    return commonChildren;
}























