#ifndef GLOCTREEADAPTER_H
#define GLOCTREEADAPTER_H

#include "globject.h"

#include <objects/ocnode.h>



class glOctreeAdapter
{
public:
    static glObject *adapt(Ocnode *octree);
};

#endif // GLOCTREEADAPTER_H
