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

//Provavelmente estes metodos nao serao necessarios

Vec3 *CSGNode::getMaximumCoords()
{
    if(this->type == PRIMITIVE)
    {
        return this->obj->getMaximumCoords();
    }
    else if(this->type != NEW)
    {
        int max_x, max_y, max_z;
        Vec3 *max = new Vec3();

        Vec3 *max_child_0 = this->getChild(0)->getMaximumCoords();

        int max_x_0 = max_child_0->getX();
        int max_y_0 = max_child_0->getY();
        int max_z_0 = max_child_0->getZ();

        Vec3 *max_child_1 = this->getChild(1)->getMaximumCoords();

        int max_x_1 = max_child_1->getX();
        int max_y_1 = max_child_1->getY();
        int max_z_1 = max_child_1->getZ();

        switch (this->type)
        {
        case OP_UNION:
            if(max_x_0 > max_x_1) max_x = max_x_0; else max_x = max_x_1;
            if(max_y_0 > max_y_1) max_y = max_y_0; else max_y = max_y_1;
            if(max_z_0 > max_z_1) max_z = max_z_0; else max_z = max_z_1;

        break;

        case OP_INTERSECTION:
            if(max_x_0 < max_x_1) max_x = max_x_0; else max_x = max_x_1;
            if(max_y_0 < max_y_1) max_y = max_y_0; else max_y = max_y_1;
            if(max_z_0 < max_z_1) max_z = max_z_0; else max_z = max_z_1;

        break;

        case OP_DIFERENCE:
            max_x = max_x_0;
            max_y = max_y_0;
            max_z = max_z_0;

        break;
        }

        return new Vec3(max_x, max_y, max_z);
    }
    else
    {
        return new Vec3(-999999);
    }
}

Vec3 *CSGNode::getMinimumCoords()
{
    if(this->type == PRIMITIVE)
    {
        return this->obj->getMinimumCoords();
    }
    else if(this->type != NEW)
    {
        int min_x, min_y, min_z;
        Vec3 *min = new Vec3();

        Vec3 *min_child_0 = this->getChild(0)->getMinimumCoords();

        int min_x_0 = min_child_0->getX();
        int min_y_0 = min_child_0->getY();
        int min_z_0 = min_child_0->getZ();

        Vec3 *min_child_1 = this->getChild(1)->getMinimumCoords();

        int min_x_1 = min_child_1->getX();
        int min_y_1 = min_child_1->getY();
        int min_z_1 = min_child_1->getZ();

        switch (this->type)
        {
        case OP_UNION:
            if(min_x_0 < min_x_1) min_x = min_x_0; else min_x = min_x_1;
            if(min_y_0 < min_y_1) min_y = min_y_0; else min_y = min_y_1;
            if(min_z_0 < min_z_1) min_z = min_z_0; else min_z = min_z_1;

        break;

        case OP_INTERSECTION:
            if(min_x_0 > min_x_1) min_x = min_x_0; else min_x = min_x_1;
            if(min_y_0 > min_y_1) min_y = min_y_0; else min_y = min_y_1;
            if(min_z_0 > min_z_1) min_z = min_z_0; else min_z = min_z_1;

        break;

        case OP_DIFERENCE:
            min_x = min_x_0;
            min_y = min_y_0;
            min_z = min_z_0;

        break;
        }

        return new Vec3(min_x, min_y, min_z);
    }
    else
    {
        return new Vec3(-999999);
    }
}
