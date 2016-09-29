#ifndef GLRBPYRAMIDADAPTER_H
#define GLRBPYRAMIDADAPTER_H

#include "globject.h"

#include <objects/rbpyramid.h>

class glRBPyramidAdapter
{
public:
    static glObject *adapt(RBPyramid *pyramid);
};

#endif // GLRBPYRAMIDADAPTER_H
