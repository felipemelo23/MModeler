#include <objects/rbpyramid.h>

#include <algebra/mtx2x2.h>
#include <algebra/mtx3x3.h>
#include <algebra/vec2.h>

RBPyramid::RBPyramid(int numOfSides)
{
    this->numOfSides = numOfSides;
    this->type = Object::RPPYRAMID;
}

RBPyramid::~RBPyramid()
{
    delete ow;
    delete wo;
}

void RBPyramid::section(Vec2 **v, double radius)
{
    double teta = (2*3.141592)/numOfSides;

    v[0] = new Vec2(0,radius);

    Mtx2x2 *rot = Mtx2x2::getRotateMtx(teta);

    for (int i=1;i<numOfSides;i++)
    {
        v[i] = rot->prod(v[i-1]);
    }
}

bool RBPyramid::isInside(Vec4 *pos)
{
    Vec4 *canon = wo->prod(pos);

    if ((canon->getY() > 1)||(canon->getY() < 0))
        return false;

    double r = (1-canon->getY())/2;

    Vec2 **v = new Vec2*[numOfSides];

    section(v,r);

    Vec2 *pos2d = new Vec2(canon->getX(),canon->getZ());

    bool output = true;
    int i = 0;
    while ((output)&&(i<numOfSides)) {
        output = v[i]->sub(pos2d)->cross(v[(i+1)%numOfSides]) >= 0;
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

Vec3* RBPrism::getMaximumCoords()
{
    //qual vai ser a coordenada maxima?
}

Vec3* RBPrism::getMinimumCoords()
{
    Vec3 **v = new Vec3*[numOfSides + 1];

    Mtx3x3 *rot = Mtx3x3::getRotateMtx((2*3.141592)/numOfSides,false,true,false);

    v[0] = new Vec3(0,1,0);
    v[1] = new Vec3(0,0,1);

    for (int i=2;i<numOfSides;i++)
    {
        v[i] = rot->prod(v[i-1]);
    }

    //como a seccao eh um poligono, entao sua coordenada Y serah correspondente a Z, em 3D.

    double x = v[0]->getX();
    double z = v[0]->getY();

    for (int i=1;i<8;i++)
    {
        if (x < v[i]->getX()) x = v[i]->getX();
        if (z , v[i]->getZ()) z = v[i]->getZ();
    }

    double y = -1;

    //limpeza de memoria:

        for(int i=0; i<numOfSides; i++)
            delete v[i];
        delete v;

    //memoria limpa...

    return new Vec3(x,y,z);
}
