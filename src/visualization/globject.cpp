#include "globject.h"
#include <iostream>

using namespace std;

glObject::glObject()
{
    this->vertices = new vector<Vec3*>();
    this->faces = new vector<glFace*>();

    this->vertexNormals = new vector<Vec3*>();
    this->faceNormals = new vector<Vec3*>();

    this->solid = true;
    this->smooth = false;

    this->color = new double[3];

    this->color[0] = 0.8;
    this->color[1] = 0.8;
    this->color[2] = 0.8;
}

void glObject::addVertex(Vec3 *vertex)
{
    vertices->push_back(vertex);
    vertexNormals->push_back(new Vec3(0,0,0));
}

Vec3 *glObject::getVertex(int index)
{
    return vertices->at(index);
}

void glObject::setVertexNormal(int index, Vec3 *vertex)
{
    Vec3 *last = vertexNormals->at(index);

    vertexNormals->at(index) = vertex;

    delete last;
}

Vec3 *glObject::getVertexNormal(int index)
{
    return vertexNormals->at(index);
}

int glObject::numOfVertices()
{
    return vertices->size();
}

void glObject::addFace(glFace *face)
{
    faces->push_back(face);

    int *vi = face->getVertices();

    Vec3 *v1 = getVertex(vi[1])->sub(getVertex(vi[0]));
    Vec3 *v2 = getVertex(vi[2])->sub(getVertex(vi[0]));
    Vec3 *v3;

    Vec3 *normal = v1->cross(v2);
    normal->normalize();

    faceNormals->push_back(normal);

    v1 = getVertex(vi[0])->sum(normal);
    v2 = getVertex(vi[1])->sum(normal);
    v3 = getVertex(vi[2])->sum(normal);

    v1->normalize();
    v2->normalize();
    v3->normalize();

    setVertexNormal(vi[0],v1);
    setVertexNormal(vi[1],v2);
    setVertexNormal(vi[2],v3);
}

glFace *glObject::getFace(int index)
{
    return faces->at(index);
}

Vec3 *glObject::getFaceNormal(int index)
{
    return faceNormals->at(index);
}

int glObject::numOfFaces()
{
    return faceNormals->size();
}

bool glObject::getSolid()
{
    return solid;
}

void glObject::setSolid(bool solid)
{
    this->solid = solid;
}

bool glObject::getSmooth()
{
    return smooth;
}

void glObject::setSmooth(bool smooth)
{
    this->smooth = smooth;
}

double *glObject::getColor()
{
    return color;
}

void glObject::setColor(double color[])
{
    this->color = color;
}

void glObject::draw()
{
    glColor3d(color[0],color[1],color[2]);

    if (solid)
        glEnable(GL_LIGHTING);
    else
        glDisable(GL_LIGHTING);

    for (int i=0;i<numOfFaces();i++) {
        int *v = faces->at(i)->getVertices();
        Vec3 *temp;
        Vec3 *normal;

        if (solid)
            glBegin(GL_TRIANGLES);
        else
            glBegin(GL_LINE_STRIP);

        for (int j=0;j<3;j++) {
            temp = getVertex(v[j]);

            if (smooth)
                normal = getVertexNormal(v[j]);
            else
                normal = getFaceNormal(i);

            glNormal3d(-normal->getX(),-normal->getY(),-normal->getZ());
            glVertex3d(temp->getX(),temp->getY(),temp->getZ());
        }

        if (!solid) {
            temp = getVertex(v[0]);

            if (smooth)
                normal = getVertexNormal(v[0]);
            else
                normal = getFaceNormal(i);

            glNormal3d(normal->getX(),normal->getY(),normal->getZ());
            glVertex3d(temp->getX(),temp->getY(),temp->getZ());
        }

        glEnd();
    }
}
