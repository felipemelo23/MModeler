#include "glface.h"
#include "globject.h"
#include "glrbpyramidadapter.h"
#include <iostream>

using namespace std;

glObject *glRBPyramidAdapter::adapt(RBPyramid *pyramid)
{
    int numOfSides = pyramid->getNumOfSides();

    Vec4 *v = pyramid->getVertices();

    glFace *faces = new glFace[numOfSides+1];

    int *bottomVertices = new int[numOfSides];
    int *bottomInv = new int[numOfSides];

    for (int i=0;i<numOfSides;i++) {
        bottomVertices[i] = i+1;
        bottomInv[numOfSides-1-i] = i+1;
    }

    faces[0] = glFace(numOfSides,bottomInv);

    for (int i=0;i<numOfSides;i++) {
        faces[i+1] = glFace(3,0,bottomVertices[i],bottomVertices[(i+1)%numOfSides]);
    }

    glObject *obj = new glObject();

    for (int i=0;i<numOfSides+1;i++)
        obj->addVertex(v[i].getVec3_());

    for (int i=0;i<numOfSides+1;i++) {
        obj->addFace(faces[i]);
    }

    delete[] faces;

    return obj;
}
