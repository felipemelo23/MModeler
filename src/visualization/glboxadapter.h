#ifndef GLBOXADAPTER_H
#define GLBOXADAPTER_H

#include "globject.h"

#include <objects/box.h>



class glBoxAdapter
{
public:
    static glObject *adapt(Box *box);
};

#endif // GLBOXADAPTER_H
