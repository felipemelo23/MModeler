
#include <objects/rbprism.h>

#include <algebra/mtx2x2.h>

#include <iostream>

using namespace std;

int RBPrism::getNumOfSides() const
{
    return numOfSides;
}

vector<RCResult> RBPrism::checkIntersection(Ray ray)
{
    vector<RCResult> results = vector<RCResult>();

    Face *faces = getFaces();

    for (int i=0;i<numOfSides+2;i++) {
        RCResult result = faces[i].checkIntersection(ray);
        result.setMaterial(material);
        if (result.getIntersected()) {
            results.push_back(result);
        }
    }

    results = sort(results);

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

void RBPrism::generateVertices()
{
    Vec4 *v = new Vec4[2*numOfSides];

    Mtx4x4 rot = Mtx4x4::getRotateMtx_((2*3.141592)/numOfSides,false,true,false);

    v[0] = Vec4(0,-0.5,0.5,1);
    v[numOfSides] = Vec4(0,0.5,0.5,1);

    for (int i=1;i<numOfSides;i++)
    {
        v[i] = rot*v[i-1];
        v[numOfSides+i] = rot*v[numOfSides+i-1];
    }

    for (int i=0;i<numOfSides;i++)
    {
        v[i] = ow*v[i];
        v[numOfSides+i] = ow*v[numOfSides+i];
    }

    vertices = v;
}

void RBPrism::generateFaces()
{
    Vec4 *v = getVertices();

    Face *faces = new Face[numOfSides+2];

    Vec4 *bottomVertices = new Vec4[numOfSides];
    Vec4 *topVertices = new Vec4[numOfSides];
    Vec4 *bottomInv = new Vec4[numOfSides];

    for (int i=0;i<numOfSides;i++) {
        bottomVertices[i] = v[i];
        topVertices[i] = v[numOfSides+i];
        bottomInv[numOfSides-1-i] = v[i];
    }

    faces[0] = Face(numOfSides,bottomInv,material);
    faces[1] = Face(numOfSides,topVertices,material);

    for (int i=0;i<numOfSides;i++) {
        faces[i+2] = Face(4,material,topVertices[i],bottomVertices[i],bottomVertices[(i+1)%numOfSides],
                                               topVertices[(i+1)%numOfSides]);
    }

    this->faces = faces;
}

Vec4 *RBPrism::getVertices()
{
    return this->vertices;
}

Face *RBPrism::getFaces() {
    return this->faces;
}

RBPrism::RBPrism(int numOfSides) : Object()
{
    this->numOfSides = numOfSides;
    this->type = Object::RBPRISM;
    this->name = "Prism";
    this->generateVertices();
    this->generateFaces();
}

RBPrism::~RBPrism() {}

void RBPrism::section(Vec2 *v, double radius)
{
    double teta = (2*3.141592)/numOfSides;

    v[0] = Vec2(0,radius); //o "raio" maximo do prisma canonico serah 1

    Mtx2x2 rot = Mtx2x2::getRotateMtx_(teta);

    for (int i=1;i<numOfSides;i++)
    {
        v[i] = rot*v[i-1];
    }
}

int RBPrism::isInside(Vec4 pos)
{
    Vec4 canon = wo*pos;

    if ((canon.getY() > 0.5)||(canon.getY() < -0.5))
        return false;

    Vec2 *v = new Vec2[numOfSides];
    section(v);

    Vec2 pos2d = Vec2(canon.getX(),canon.getZ());

    bool output = true;
    int i = 0;
    while ((output)&&(i<numOfSides))
    {
        output = ((v[i]-pos2d).cross_(v[(i+1)%numOfSides]-pos2d) >= 0); //cross nao deve ser entre dois vetores?
        i++;
    }

    delete[] v;

    return output;
}

//faremos as coordenadas maximas e minimas apenas nos planos que sao as tampas do prisma

Vec3 RBPrism::getMaximumCoords()
{
    Vec4 *v = getVertices();

    double x = v[0].getX();
    double y = v[0].getY();
    double z = v[0].getZ();

    for (int i=1;i<2*numOfSides;i++)
    {
        if (x < v[i].getX()) x = v[i].getX();
        if (y < v[i].getY()) y = v[i].getY();
        if (z < v[i].getZ()) z = v[i].getZ();
    }

    return Vec3(x,y,z);
}

Vec3 RBPrism::getMinimumCoords()
{
    Vec4 *v = getVertices();

    double x = v[0].getX();
    double y = v[0].getY();
    double z = v[0].getZ();

    for (int i=1;i<2*numOfSides;i++)
    {
        if (x > v[i].getX()) x = v[i].getX();
        if (y > v[i].getY()) y = v[i].getY();
        if (z > v[i].getZ()) z = v[i].getZ();
    }

    return Vec3(x,y,z);
}

