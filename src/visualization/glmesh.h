#ifndef GLMESH_H
#define GLMESH_H

#include "globject.h"
#include <unordered_map>
#include <objects/mesh/medge.h>
#include <objects/mesh/mesh.h>
#include <objects/mesh/mvertex.h>

using std::unordered_map;

class glMesh : public glObject
{
public:
    glMesh(Mesh *mesh, QGLWidget *widget);

    void draw();

private:
    Mesh *mesh;
    QGLWidget *widget;

    bool contains(vector<string> list, string item);
};

#endif // GLMESH_H
