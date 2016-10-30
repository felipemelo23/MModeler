#ifndef GLCYLINDERADAPTER_H
#define GLCYLINDERADAPTER_H

#include "globject.h"
#include "objects/cylinder.h"

class glCylinderAdapter
{
public:
    static glObject *adapt(Cylinder *cylinder);
};

#endif // GLCYLINDERADAPTER_H
