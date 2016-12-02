#include "glcylinderadapter.h"

glObject *glCylinderAdapter::adapt(Cylinder *cylinder)
{
    int numOfSides = 16;

    Vec4 *v = cylinder->getVertices(numOfSides);

    glFace *faces = new glFace[numOfSides+2];

    int *bottomVertices = new int[numOfSides];
    int *topVertices = new int[numOfSides];
    int *bottomInv = new int[numOfSides];

    for (int i=0;i<numOfSides;i++) {
        bottomVertices[i] = i;
        topVertices[i] = numOfSides+i;
        bottomInv[numOfSides-1-i] = i;
    }

    faces[0] = glFace(numOfSides,bottomInv);
    faces[1] = glFace(numOfSides,topVertices);

    for (int i=0;i<numOfSides;i++) {
        faces[i+2] = glFace(4,topVertices[i],bottomVertices[i],bottomVertices[(i+1)%numOfSides],
                                               topVertices[(i+1)%numOfSides]);
    }

    glObject *obj = new glObject();

    for (int i=0;i<numOfSides*2;i++)
        obj->addVertex(v[i].getVec3_());

    for (int i=0;i<numOfSides+2;i++) {
        obj->addFace(faces[i]);
    }

    delete[] v;
    delete[] faces;

    return obj;
}
