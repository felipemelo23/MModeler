#ifndef GLFACE_H
#define GLFACE_H


class glFace
{
public:
    glFace(int v1, int v2, int v3);

    int *getVertices();

private:
    int *vertices;

};

#endif // GLFACE_H
