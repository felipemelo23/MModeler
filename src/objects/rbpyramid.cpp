#include <objects/rbpyramid.h>

#include <algebra/mtx2x2.h>
#include <algebra/mtx3x3.h>
#include <algebra/vec2.h>
#include <iostream>

using namespace std;

int RBPyramid::getNumOfSides() const
{
    return numOfSides;
}

vector<RCResult> RBPyramid::checkIntersection(Ray ray)
{
    vector<RCResult> results = vector<RCResult>();

    for (int i=0;i<numOfSides+1;i++) {
        RCResult result = faces[i].checkIntersection(ray);
        result.setMaterial(material);
        if (result.getIntersected()) results.push_back(result);
    }

    results = sort(results);

    return results;
}

void RBPyramid::generateVertices()
{
    Vec4 *v = new Vec4[numOfSides + 1];

    Mtx4x4 rot = Mtx4x4::getRotateMtx_((2*3.141592)/numOfSides,false,true,false);

    v[0] = Vec4(0,0.5,0,1);
    v[1] = Vec4(0,-0.5,0.5,1);

    for (int i=2;i<numOfSides+1;i++)
    {
        v[i] = rot*v[i-1];
    }

    for (int i=0;i<numOfSides+1;i++)
    {
        v[i] = ow*v[i];
    }

    if (vertices != NULL) delete[] vertices;
    vertices = v;
}

void RBPyramid::generateFaces()
{
    Vec4 *v = getVertices();
    faces = new Face[numOfSides+1];

    int *bottomVertices = new int[numOfSides];
    Vec4 *bottomInv = new Vec4[numOfSides];

    for (int i=0;i<numOfSides;i++) {
        bottomVertices[i] = i+1;
        bottomInv[numOfSides-1-i] = v[i+1];
    }

    faces[0] = Face(numOfSides,material,bottomInv);

    for (int i=0;i<numOfSides;i++) {
        faces[i+1] = Face(3,material,v[0],v[bottomVertices[i]],v[bottomVertices[(i+1)%numOfSides]]);
    }
}

vector<RCResult> RBPyramid::sort(vector<RCResult> results) {
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

Vec4 *RBPyramid::getVertices()
{
    return vertices;
}

RBPyramid::RBPyramid(int numOfSides) : Object()
{
    this->numOfSides = numOfSides;
    this->type = Object::RBPYRAMID;
    this->name = "Pyramid";
    this->vertices = NULL;
    this->generateVertices();
    this->generateFaces();
}

RBPyramid::~RBPyramid() {}

void RBPyramid::section(Vec2 *v, double radius)
{
    double teta = (2*3.141592)/numOfSides;

    v[0] = Vec2(0,radius);

    Mtx2x2 rot = Mtx2x2::getRotateMtx_(teta);

    for (int i=1;i<numOfSides;i++)
    {
        v[i] = rot*v[i-1];
    }
}

int RBPyramid::isInside(Vec4 pos)
{
    bool output = true;
    int on = 1;
    Vec4 canon = wo*pos;

    if ((canon.getY() > 0.50001)||(canon.getY() < -0.50001))
        return false;

    double r = (1-canon.getY()-0.5)/2;

    if (r != 0) {
        Vec2 *v = new Vec2[numOfSides];

        section(v,r);

        Vec2 pos2d = Vec2(canon.getX(),canon.getZ());

        int i = 0;
        while ((output)&&(i<numOfSides)) {
            double lambda = (v[i]-pos2d).cross_(v[(i+1)%numOfSides]-pos2d);

            if (fabs(lambda) <= 0.00001)
                output *= -1;
            else if (lambda > 0)
                output *= 1;
            else
                output *= 0;

            i++;
        }

        delete[] v;
    } else {
        if ((fabs(canon.getX()) > 0)||(fabs(canon.getZ()) > 0))
            output = false;
    }

    if (output < 0)
        cout << output << endl;
    return output;
}

Vec3 RBPyramid::getMaximumCoords()
{
    Vec4 *v = getVertices();

    double x = v[0].getX();
    double y = v[0].getY();
    double z = v[0].getZ();

    for (int i=1;i<numOfSides+1;i++)
    {
        if (x < v[i].getX()) x = v[i].getX();
        if (y < v[i].getY()) y = v[i].getY();
        if (z < v[i].getZ()) z = v[i].getZ();
    }

    return Vec3(x,y,z);
}

Vec3 RBPyramid::getMinimumCoords()
{
    Vec4 *v = getVertices();

    double x = v[0].getX();
    double y = v[0].getY();
    double z = v[0].getZ();

    for (int i=1;i<numOfSides+1;i++)
    {
        if (x > v[i].getX()) x = v[i].getX();
        if (y > v[i].getY()) y = v[i].getY();
        if (z > v[i].getZ()) z = v[i].getZ();
    }

    return Vec3(x,y,z);
}

void RBPyramid::translate(double x, double y, double z)
{
    Object::translate(x,y,z);
    this->generateVertices();
}

void RBPyramid::scale(double x, double y, double z)
{
    Object::scale(x,y,z);
    this->generateVertices();
}

void RBPyramid::rotate(double degree, bool x, bool y, bool z)
{
    Object::rotate(degree,x,y,z);
    this->generateVertices();
}
