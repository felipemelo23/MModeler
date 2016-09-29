#include <objects/sphere.h>

Sphere::Sphere() : Object() {
    type = Object::SPHERE;
    name = "Sphere";
}

Sphere::~Sphere()
{
    delete ow;
    delete wo;
}

Vec3 *Sphere::getMinimumCoords()
{
    Vec4 **v = new Vec4*[8];
    Vec4 *trash;

    v[0] = new Vec4(-1,-1,-1,1);
    v[1] = new Vec4(-1,-1,1,1);
    v[2] = new Vec4(-1,1,-1,1);
    v[3] = new Vec4(-1,1,1,1);
    v[4] = new Vec4(1,-1,-1,1);
    v[5] = new Vec4(1,-1,1,1);
    v[6] = new Vec4(1,1,-1,1);
    v[7] = new Vec4(1,1,1,1);

    for (int i=0;i<8;i++) {
        trash = v[i];
        v[i] = ow->prod(v[i]);
        delete trash;
    }

    double x = v[0]->getX();
    double y = v[0]->getY();
    double z = v[0]->getZ();

    for (int i=1;i<8;i++) {
        if (x < v[i]->getX()) x = v[i]->getX();
        if (y < v[i]->getY()) y = v[i]->getY();
        if (z < v[i]->getZ()) z = v[i]->getZ();
    }

    for (int i=0;i<8;i++) {
        delete v[i];
    }
    delete v;

    return new Vec3(x,y,z);
}

Vec3 *Sphere::getMaximumCoords()
{
    Vec4 **v = new Vec4*[8];
    Vec4 *trash;

    v[0] = new Vec4(-1,-1,-1,1);
    v[1] = new Vec4(-1,-1,1,1);
    v[2] = new Vec4(-1,1,-1,1);
    v[3] = new Vec4(-1,1,1,1);
    v[4] = new Vec4(1,-1,-1,1);
    v[5] = new Vec4(1,-1,1,1);
    v[6] = new Vec4(1,1,-1,1);
    v[7] = new Vec4(1,1,1,1);

    for (int i=0;i<8;i++)
    {
        trash = v[i];
        v[i] = ow->prod(v[i]);
        delete trash;
    }

    double x = v[0]->getX();
    double y = v[0]->getY();
    double z = v[0]->getZ();

    for (int i=1;i<8;i++)
    {
        if (x > v[i]->getX()) x = v[i]->getX();
        if (y > v[i]->getY()) y = v[i]->getY();
        if (z > v[i]->getZ()) z = v[i]->getZ();
    }

    for (int i=0;i<8;i++) {
        delete v[i];
    }
    delete v;

    return new Vec3(x,y,z);
}

bool Sphere::isInside(Vec4 *pos)
{
    Vec4 *canon = wo->prod(pos);

    double norm = canon->normColumn(0);

    delete canon;

    return norm <= 1;
}
