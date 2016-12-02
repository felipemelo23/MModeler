#include "glcompoundobject.h"
#include "gloctreeadapter.h"
#include <iostream>

using namespace std;

glObject *glOctreeAdapter::adapt(Ocnode *octree)
{
    glCompoundObject *obj = new glCompoundObject();

    if (octree->getState() == 1) {
        Vec4 *v = octree->getVertices();

        glFace *faces = new glFace[6];

        faces[0] = glFace(4,0,1,2,3);
        faces[1] = glFace(4,4,5,6,7);
        faces[2] = glFace(4,7,6,1,0);
        faces[3] = glFace(4,5,4,3,2);
        faces[4] = glFace(4,4,7,0,3);
        faces[5] = glFace(4,6,5,2,1);

        for (int i=0;i<8;i++)
            obj->addVertex(v[i].getVec3_());

        for (int i=0;i<6;i++) {
            obj->addFace(faces[i]);
        }

        delete[] faces;
        delete[] v;
    }

    if (octree->getChildren() != NULL) {
        for (int i=0;i<8;i++) {
            if (octree->getChild(i)->getState() > -1)
                obj->addSubObject(adapt(octree->getChild(i)));
        }
    }

    return obj;
}
