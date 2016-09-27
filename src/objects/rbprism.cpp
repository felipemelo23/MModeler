#include <objects/rbprism.h>

RBPrism::RBPrism(int numOfSides)
{

}

RBPrism::~RBPrism()
{

}

void RBPrism::section(Vec2 **v, double ray)
{
    double teta = (2*3.141592)/numOfSides;

    v[0] = new Vec2(0,1); //o "raio" maximo do prisma canonico serah 1

    Mtx *rot = new Mtx(2,2,cos(teta),-sin(teta),
                           sin(teta,cos(teta)));

    for (int i=1;i<numOfSides;i++)
    {
        v[i] = rot->prod(v[i-1]);
    }
}

bool RBPrism::isInside(Vec3 pos)
{
    Vec4 *canon = wo->prod(pos);

    if ((canon->getY() > 1)||(canon->getY() < 0))
        return false;

    Vec2 **v = new Vec2*[numOfSides];
    section(v);

    Vec2 *pos2d = new Vec2(canon->getX(),canon->getZ());

    bool output = true;
    int i = 0;
    while ((output)&&(i<numOfSides))
    {
        output = (v[i]->sub(pos2d)->cross(v[(i+1)%numOfSides]) >= 0); //cross nao deve ser entre dois vetores?
        i++;
    }

    //limpeza de memoria:

        delete canon;
        delete pos2d;
        for(int i=0; i<numOfSides; i++)
            delete v[i];
        delete v;

    //memoria limpa...

    return output;
}

//faremos as coordenadas maximas e minimas apenas nos planos que sao as tampas do prisma

Vec3* RBPrism::getMaximumCoords()
{
    Vec2 **v = new Vec2*[numOfSides];
    section(v);

    for (int i=0;i<numOfSides;i++)
    {
        v[i] = ow->prod(v[i]);
    }

    //como a seccao eh um poligono, entao sua coordenada Y serah correspondente a Z, em 3D.

    double x = v[0]->getX();
    double z = v[0]->getY();
    double y = 1; //? isso ta certo?

    //isso daqui sempre vai resultar (1,1,1)?
    for (int i=1;i<numOfSides;i++)
    {
        if (x > v[i]->getX()) x = v[i]->getX();
        if (z > v[i]->getZ()) z = v[i]->getZ();
    }

    //limpeza de memoria:

        for(int i=0; i<numOfSides; i++)
            delete v[i];
        delete v;

    //memoria limpa...

    return new Vec3(x,y,z);
}

Vec3* RBPrism::getMinimumCoords()
{

}

