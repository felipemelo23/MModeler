#ifndef GLMESHADAPTER_H
#define GLMESHADAPTER_H

#include "globject.h"
#include "glmesh.h"
#include <objects/mesh/mesh.h>

class glMeshAdapter
{
public:
    static glObject *adapt(Mesh *mesh, QGLWidget *widget);
};

#endif // GLMESHADAPTER_H
