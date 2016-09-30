#include "glcompoundobject.h"
#include "gloctreeadapter.h"
#include <iostream>

using namespace std;

glObject *glOctreeAdapter::adapt(Ocnode *octree)
{
    Vec4 **v = octree->getVertices();

    glFace **faces = new glFace*[6];

    faces[0] = new glFace(4,0,1,2,3);
    faces[1] = new glFace(4,4,5,6,7);
    faces[2] = new glFace(4,7,6,1,0);
    faces[3] = new glFace(4,5,4,3,2);
    faces[4] = new glFace(4,4,7,0,3);
    faces[5] = new glFace(4,6,5,2,1);

    if ((octree->getChildren() != NULL) || ((octree->getChildren() == NULL)&&(octree->getState()) < 0))
        for (int i=0;i<6;i++)
            faces[i]->setEmpty(true);

    glCompoundObject *obj = new glCompoundObject();

    for (int i=0;i<8;i++)
        obj->addVertex(v[i]->getVec3());

    for (int i=0;i<6;i++) {
        obj->addFace(faces[i]);
    }

    for(int i=0; i<8; i++)
        delete v[i];
    delete v;

    if (octree->getChildren() != NULL) {
        for (int i=0;i<8;i++) {
            obj->addSubObject(adapt(octree->getChild(i)));
        }
    }

    return obj;
}
