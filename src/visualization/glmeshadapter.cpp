
#include "glmeshadapter.h"

glObject *glMeshAdapter::adapt(Mesh *mesh)
{
    return new glMesh(mesh);
}
