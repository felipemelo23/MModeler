#ifndef OBJECTQUERY_H
#define OBJECTQUERY_H

#include <objects/ocnode.h>



class ObjectQuery
{
public:
    ObjectQuery();

    static double getVolume(Ocnode *octree);
    static double getVolume(Object *obj, int precision);
};

#endif // OBJECTQUERY_H
