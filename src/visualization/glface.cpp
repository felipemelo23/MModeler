#include "glface.h"

glFace::glFace(int v1, int v2, int v3)
{
    vertices = new int[3];

    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
}

int *glFace::getVertices()
{
    return vertices;
}
