#ifndef GLFACE_H
#define GLFACE_H

#include <stdarg.h>

class glFace
{
public:
    glFace(int sides, int *v);
    glFace(int sides, int v1, int v2, int v3, ...);

    int *getVertices();

    int getSides() const;

private:
    int sides;
    int *vertices;

};

#endif // GLFACE_H
