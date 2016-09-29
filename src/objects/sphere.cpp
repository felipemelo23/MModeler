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

Vec4 **Sphere::getVertices(int height, int width)
{
    Vec4 **v = new Vec4*[(height-1)*width + 2];

    Mtx4x4 *rotZ = Mtx4x4::getRotateMtx((3.141592)/height,false,false,true);
    Mtx4x4 *rotY = Mtx4x4::getRotateMtx((2*3.141592)/width,false,true,false);

    v[0] = new Vec4(0,0.5,0,1);
    v[1] = new Vec4(0,-0.5,0,1);

    for (int i=0;i<height-1;i++) {
        v[i+2] = rotZ->prod(v[i+1]);
    }

    for (int i=1;i<width;i++) {
        int currBase = 2+(height-1)*i;
        int prevBase = 2+(height-1)*(i-1);
        for (int j=0;j<height-1;j++) {
            v[currBase+j] = rotY->prod(v[prevBase+j]);
        }
    }

    Vec4 *trash;
    for (int i=0;i<(height-1)*width + 2;i++) {
        trash = v[i];
        v[i] = ow->prod(v[i]);
        delete trash;
    }

    delete rotZ;
    delete rotY;

    return v;
}

















