#include "face.h"

#include <objects/rbprism.h>

#include <algebra/mtx2x2.h>

#include <iostream>

using namespace std;

int RBPrism::getNumOfSides() const
{
    return numOfSides;
}

vector<RCResult> RBPrism::checkIntersection(Ray *ray)
{
    vector<RCResult> results = vector<RCResult>();
    Vec4 **v = getVertices();

    Face **faces = new Face*[numOfSides+2];

    Vec4 **bottomVertices = new Vec4*[numOfSides];
    Vec4 **topVertices = new Vec4*[numOfSides];
    Vec4 **bottomInv = new Vec4*[numOfSides];

    for (int i=0;i<numOfSides;i++) {
        bottomVertices[i] = v[i];
        topVertices[i] = v[numOfSides+i];
        bottomInv[numOfSides-1-i] = v[i];
    }

    faces[0] = new Face(numOfSides,bottomInv,material);
    faces[1] = new Face(numOfSides,topVertices,material);

    for (int i=0;i<numOfSides;i++) {
        faces[i+2] = new Face(4,material,topVertices[i],bottomVertices[i],bottomVertices[(i+1)%numOfSides],
                                               topVertices[(i+1)%numOfSides]);
    }

    for (int i=0;i<numOfSides+2;i++) {
        RCResult result = faces[i]->checkIntersection(ray);
        if (result.getIntersected()) results.push_back(result);
    }

    results = sort(results);

    for (int i=0;i<numOfSides*2;i++)
        delete v[i];
    delete v;

    for (int i=0;i<numOfSides+2;i++)
        delete faces[i];
    delete faces;
    delete bottomVertices;
    delete topVertices;
    delete bottomInv;

    return results;
}

vector<RCResult> RBPrism::sort(vector<RCResult> results) {
    if (results.size() > 0) {
        for (int i=0;i<results.size()-1;i++) {
            for (int j=i;j<results.size();j++) {
                if (results.at(i).getT() > results.at(j).getT()) {
                    RCResult aux = results.at(i);
                    results.at(i) = results.at(j);
                    results.at(j) = aux;
                }
            }
        }
    }

    return results;
}

Vec4 **RBPrism::getVertices()
{
    Vec4 **v = new Vec4*[2*numOfSides];

    Mtx4x4 *rot = Mtx4x4::getRotateMtx((2*3.141592)/numOfSides,false,true,false);

    v[0] = new Vec4(0,-0.5,0.5,1);
    v[numOfSides] = new Vec4(0,0.5,0.5,1);

    for (int i=1;i<numOfSides;i++)
    {
        v[i] = rot->prod(v[i-1]);
        v[numOfSides+i] = rot->prod(v[numOfSides+i-1]);
    }

    Vec4 *garbage;
    for (int i=0;i<numOfSides;i++)
    {
        garbage = v[i];
        v[i] = ow->prod(v[i]);
        delete garbage;
        garbage = v[numOfSides+i];
        v[numOfSides+i] = ow->prod(v[numOfSides+i]);
        delete garbage;
    }

    return v;
}

RBPrism::RBPrism(int numOfSides) : Object()
{
    this->numOfSides = numOfSides;
    this->type = Object::RBPRISM;
    this->name = "Prism";
}

RBPrism::~RBPrism()
{
    delete ow;
    delete wo;
}

void RBPrism::section(Vec2 **v, double radius)
{
    double teta = (2*3.141592)/numOfSides;

    v[0] = new Vec2(0,0.5); //o "raio" maximo do prisma canonico serah 1

    Mtx2x2 *rot = Mtx2x2::getRotateMtx(teta);

    for (int i=1;i<numOfSides;i++)
    {
        v[i] = rot->prod(v[i-1]);
    }
}

int RBPrism::isInside(Vec4 *pos)
{
    Vec4 *canon = wo->prod(pos);

    if ((canon->getY() > 0.5)||(canon->getY() < -0.5))
        return false;

    Vec2 **v = new Vec2*[numOfSides];
    section(v);

    Vec2 *pos2d = new Vec2(canon->getX(),canon->getZ());

    bool output = true;
    int i = 0;
    while ((output)&&(i<numOfSides))
    {
        output = (v[i]->sub(pos2d)->cross(v[(i+1)%numOfSides]->sub(pos2d)) >= 0); //cross nao deve ser entre dois vetores?
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
    Vec4 **v = getVertices();

    double x = v[0]->getX();
    double y = v[0]->getY();
    double z = v[0]->getZ();

    for (int i=1;i<2*numOfSides;i++)
    {
        if (x < v[i]->getX()) x = v[i]->getX();
        if (y < v[i]->getY()) y = v[i]->getY();
        if (z < v[i]->getZ()) z = v[i]->getZ();
    }

    //limpeza de memoria:

    for(int i=0; i<2*numOfSides; i++)
        delete v[i];
    delete v;

    //memoria limpa...

    return new Vec3(x,y,z);
}

Vec3* RBPrism::getMinimumCoords()
{
    Vec4 **v = getVertices();

    double x = v[0]->getX();
    double y = v[0]->getY();
    double z = v[0]->getZ();

    for (int i=1;i<2*numOfSides;i++)
    {
        if (x > v[i]->getX()) x = v[i]->getX();
        if (y > v[i]->getY()) y = v[i]->getY();
        if (z > v[i]->getZ()) z = v[i]->getZ();
    }

    //limpeza de memoria:

    for(int i=0; i<2*numOfSides; i++)
        delete v[i];
    delete v;

    //memoria limpa...

    return new Vec3(x,y,z);
}

