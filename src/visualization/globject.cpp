#include "globject.h"
#include <iostream>

using namespace std;

glObject::glObject()
{
    this->vertices = new vector<Vec3>();
    this->faces = new vector<glFace>();

    this->vertexNormals = new vector<Vec3>();
    this->faceNormals = new vector<Vec3>();

    this->solid = true;
    this->smooth = false;
    this->opacity = 1.0;

    this->color = new double[3];

    this->color[0] = 0.8;
    this->color[1] = 0.8;
    this->color[2] = 0.8;
}

glObject::~glObject()
{
    delete vertices;
    delete faces;
    delete vertexNormals;
    delete faceNormals;
}

void glObject::addVertex(Vec3 vertex)
{
    vertices->push_back(vertex);
    vertexNormals->push_back(Vec3(0,0,0));
}

Vec3 glObject::getVertex(int index)
{
    return vertices->at(index);
}

void glObject::setVertexNormal(int index, Vec3 vertex)
{
    vertexNormals->at(index) = vertex;
}

Vec3 glObject::getVertexNormal(int index)
{
    return vertexNormals->at(index);
}

int glObject::numOfVertices()
{
    return vertices->size();
}

void glObject::addFace(glFace face)
{
    faces->push_back(face);

    int *vi = face.getVertices();

    Vec3 faceNormal = Vec3();
    Vec3 v1;
    Vec3 v2;

    v1 = getVertex(vi[0]) - getVertex(vi[2]);
    v2 = getVertex(vi[1]) - getVertex(vi[2]);

    faceNormal = v1.cross_(v2);

    faceNormal.normalize();
    faceNormals->push_back(faceNormal);

    for (int i=0;i<face.getSides();i++) {
        v1 = getVertexNormal(vi[i]) + faceNormal;
        v1.normalize();
        setVertexNormal(vi[i],v1);
    }
}

glFace glObject::getFace(int index)
{
    return faces->at(index);
}

Vec3 glObject::getFaceNormal(int index)
{
    return faceNormals->at(index);
}

int glObject::numOfFaces()
{
    return faces->size();
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
    for (int i=0;i<numOfFaces();i++) {
        int *v = faces->at(i).getVertices();
        Vec3 temp;
        Vec3 normal;

        if ((solid)&&(!faces->at(i).getEmpty())) {
            glColor4d(color[0],color[1],color[2],opacity);
            glEnable(GL_LIGHTING);
            glBegin(GL_POLYGON);
        } else {
            glColor4d(color[0],color[1],color[2],1);
            glDisable(GL_LIGHTING);
            glBegin(GL_LINE_STRIP);
        }

        for (int j=0;j<faces->at(i).getSides();j++) {
            temp = getVertex(v[j]);

            if (smooth)
                normal = getVertexNormal(v[j]);
            else
                normal = getFaceNormal(i);

            glNormal3d(-normal.getX(),-normal.getY(),-normal.getZ());

            glVertex3d(temp.getX(),temp.getY(),temp.getZ());
        }

        if (!solid) {
            temp = getVertex(v[0]);

            if (smooth)
                normal = getVertexNormal(v[0]);
            else
                normal = getFaceNormal(i);

            glNormal3d(normal.getX(),normal.getY(),normal.getZ());
            glVertex3d(temp.getX(),temp.getY(),temp.getZ());
        }

        glEnd();
    }
}

void glObject::setOpacity(double value)
{
    opacity = value;
}
