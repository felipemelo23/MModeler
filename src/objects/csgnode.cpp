#include "csgnode.h"

CSGNode::CSGNode(bool isRoot, int depth, short type)
{
    this->children = NULL;
    this->type = type;
    this->isRoot = isRoot;
    this->depth = depth;
}

CSGNode::~CSGNode()
{
    if (children != NULL)
    {
        for (int i=0;i<2;i++)
            delete getChild(i);
        delete children;
    }
}

CSGNode *CSGNode::getChild(int index)
{
    if (index < 2) return children->at(index);
    return NULL;
}

bool CSGNode::hasChildren()
{
    if(this->children != NULL)
        return true;
    else
        return false;
}

void CSGNode::newChild(CSGNode *child)
{
    this->children->push_back(child);
}

bool CSGNode::put(Object *obj, short type, short direction)
{
    if((this->hasChildren()) && ((type == PRIMITIVE) || (type == NEW)))    //inconsistencias
    {
        return false;
    }

    if(type == PRIMITIVE)   //se estamos inserindo uma primitiva
    {
        //se o nosso noh eh um novo noh ou uma primitiva, redefinimos este como primitiva
        if((this->type == NEW) || (this->type == PRIMITIVE))
        {
            this->type = PRIMITIVE;
            this->obj = obj;

            return true;
        }
    }
    else    //se estamos inserindo uma operacao
    {
        //criamos dois nohs vazios que serao recursivamente preenchidos com as primitivas
        if(this->type == PRIMITIVE)
        {
            bool output;

            this->newChild(new CSGNode(false, depth+1, NEW));
            this->newChild(new CSGNode(false, depth+1, NEW));

            if(direction==RIGHT)    //inserimos o novo objeto a direita na arvore
            {
                output = this->getChild(0)->put(this->obj, PRIMITIVE, direction);
                output = this->getChild(1)->put(obj, PRIMITIVE, direction);
            }
            else
            {
                output = this->getChild(0)->put(obj, PRIMITIVE, direction);
                output = this->getChild(1)->put(this->obj, PRIMITIVE, direction);
            }

            this->type = type;
            delete this->obj;

            return output;
        }
        //Ao inserirmos uma operacao booleana onde ja existe alguma operacao, substituimos a
        //atual pela nova.
        else
        {
            this->type = type;
        }
    }

    return false;
}

bool CSGNode::isInside(Vec4 *pos)
{
    if(this->type == PRIMITIVE)
    {
        return this->obj->isInside(pos);
    }
    else if(this->type != NEW)
    {
        bool out0;
        bool out1;

        out0 = this->getChild(0)->isInside(pos);
        out1 = this->getChild(1)->isInside(pos);

        switch (this->type)
        {
        case OP_UNION:
            if(out0 || out1)
                return true;

        case OP_INTERSECTION:
            if(out0 && out1)
                return true;

        case OP_DIFERENCE:
            if(out0 && !out1)
                return true;
        }
    }

    return false;
}

Vec3 *CSGNode::getMaximumCoords()
{
    if(this->type == PRIMITIVE)
    {
        return this->obj->getMaximumCoords();
    }
    else if(this->type != NEW)
    {
        //TO DO: Nao sei como achar o ponto para a composicao de objetos
    }

    return false;
}

Vec3 *CSGNode::getMinimumCoords()
{
    if(this->type == PRIMITIVE)
    {
        return this->obj->getMinimumCoords();
    }
    else if(this->type != NEW)
    {
        //TO DO: Nao sei como achar o ponto para a composicao de objetos
    }

    return false;
}
