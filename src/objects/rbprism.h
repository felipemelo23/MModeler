#ifndef RBPRISM_H
#define RBPRISM_H

#include <objects/object.h>

class RBPrism : public Object
{
private:
    int numOfSides;

public:
    RBPrism(int numOfSides=3);
    ~RBPrism();

};

#endif // RBPRISM_H
