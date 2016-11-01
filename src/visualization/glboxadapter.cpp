#include "glboxadapter.h"

glObject *glBoxAdapter::adapt(Box *box)
{
    glObject *obj = new glObject();

    Vec4 **v = box->getVertices();

    glFace **faces = new glFace*[6];

    faces[0] = new glFace(4,0,1,2,3);
    faces[1] = new glFace(4,4,5,6,7);
    faces[2] = new glFace(4,7,6,1,0);
    faces[3] = new glFace(4,5,4,3,2);
    faces[4] = new glFace(4,4,7,0,3);
    faces[5] = new glFace(4,6,5,2,1);

    for (int i=0;i<8;i++)
        obj->addVertex(v[i]->getVec3());

    for (int i=0;i<6;i++) {
        obj->addFace(faces[i]);
    }

    for(int i=0; i<8; i++)
        delete v[i];
    delete v;

    return obj;
}