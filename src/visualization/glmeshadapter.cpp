
#include "glmeshadapter.h"

glObject *glMeshAdapter::adapt(Mesh *mesh, QGLWidget *widget)
{
    return new glMesh(mesh, widget);
}
