#include "glsphereadapter.h"
#include <iostream>

using namespace std;

glObject *glSphereAdapter::adapt(Sphere *sphere)
{
    int height = 16;
    int width = 16;

    Vec4 *v = sphere->getVertices(height,width);

    glFace *faces = new glFace[height*width];

    for (int i=0;i<width;i++) {
        int currBase = 2+(height-1)*i;
        int nextBase = 2+(height-1)*((i+1)%width);

        faces[height*i] = glFace(3,1,nextBase,currBase);
        faces[(height*i)+height-1] = glFace(3,0,currBase+height-2,nextBase+height-2);

        if (height > 2) {
            for (int j=1;j<height-1;j++) {
                faces[(height*i)+j] = glFace(4,nextBase+j-1,nextBase+j,currBase+j,currBase+j-1);
            }
        }


    }

    glObject *obj = new glObject();

    for (int i=0;i<((height-1)*width)+2;i++)
        obj->addVertex(v[i].getVec3_());

    for (int i=0;i<height*width;i++) {
        obj->addFace(faces[i]);
    }

    delete[] faces;
    delete[] v;

    obj->setSmooth(true);

    return obj;
}
