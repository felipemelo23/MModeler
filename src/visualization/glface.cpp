#include "glface.h"

glFace::glFace(int sides, int v1, int v2, int v3, ...)
{
    this->sides = sides;
    vertices = new int[sides];

    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;


    if (this->sides > 3) {
        va_list vl;

        va_start(vl,v3);

        for (int i=3;i<this->sides;i++) {
            int value = va_arg(vl,int);
            vertices[i] = value;
        }

        va_end(vl);
    }
}

int *glFace::getVertices()
{
    return vertices;
}

int glFace::getSides() const
{
    return sides;
}
