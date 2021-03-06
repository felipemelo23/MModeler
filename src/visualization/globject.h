#ifndef GLOBJECT_H
#define GLOBJECT_H

#include "glface.h"

#include <vector>
#include <QGLWidget>
#include <algebra/vec3.h>

using std::vector;

class glObject
{
public:
    glObject();
    ~glObject();

    void addVertex(Vec3 vertex);
    Vec3 getVertex(int index);
    Vec3 getVertexNormal(int index);
    void setVertexNormal(int index, Vec3 vertex);
    int numOfVertices();

    void addFace(glFace face);
    glFace getFace(int index);
    Vec3 getFaceNormal(int index);
    int numOfFaces();

    bool getSolid();
    void setSolid(bool solid);

    bool getSmooth();
    void setSmooth(bool smooth);

    double *getColor();
    virtual void setColor(double color[3]);

    virtual void draw();

    void setOpacity(double value);

protected:
    vector<Vec3> *vertices;
    vector<glFace> *faces;

    vector<Vec3> *vertexNormals;
    vector<Vec3> *faceNormals;

    double opacity;
    bool solid;
    bool smooth;

    double* color;
};

#endif // GLOBJECT_H
