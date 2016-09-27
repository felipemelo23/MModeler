#include <objects/rbpyramid.h>

#include <algebra/vec2.h>

RBPyramid::RBPyramid(int numOfSides)
{
    this->numOfSides = numOfSides;
}

RBPyramid::~RBPyramid()
{
    delete ow;
    delete wo;
}

bool RBPyramid::isInside(Vec4 *pos)
{
    Vec4 *canon = wo->prod(pos);

    if ((canon->getY() > 1)||(canon->getY() < 0))
        return false;

    double r = (1-canon->getY())/2;
    double teta = (2*3.141592)/numOfSides;

    Vec2 **v = new Vec2*[numOfSides];

    v[0] = new Vec2(0,r);

    Mtx *rot = new Mtx(2,2,cos(teta),-sin(teta),
                           sin(teta,cos(teta)));

    for (int i=1;i<numOfSides;i++)
    {
        v[i] = rot->prod(v[i-1]);
    }

    Vec2 *pos2d = new Vec2(canon->getX(),canon->getZ());

    bool output = true;
    int i = 0;
    while ((output)&&(i<numOfSides)) {
        output = v[i]->sub(pos2d)->cross(v[(i+1)%numOfSides]) >= 0;
        i++;
    }

    return output;
}
