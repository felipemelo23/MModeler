#ifndef GLCOMPOUNDOBJECTADAPTER_H
#define GLCOMPOUNDOBJECTADAPTER_H

#include "globject.h"

#include <objects/compoundobject.h>



class glCompoundObjectAdapter
{
public:
    static glObject *adapt(CompoundObject *obj);
private:
    static glObject *adaptSubObject(Object *obj);
};

#endif // GLCOMPOUNDOBJECTADAPTER_H
