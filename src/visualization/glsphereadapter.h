#ifndef GLSPHEREADAPTER_H
#define GLSPHEREADAPTER_H

#include "globject.h"
#include <objects/sphere.h>

class glSphereAdapter
{
public:
    static glObject *adapt(Sphere *sphere);
};

#endif // GLSPHEREADAPTER_H
