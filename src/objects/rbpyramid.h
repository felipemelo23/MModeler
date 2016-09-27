#ifndef RBPYRAMID_H
#define RBPYRAMID_H

#include <objects/object.h>

class RBPyramid : public Object
{
private:
    int numOfSides;

public:
    RBPyramid(int numOfSides=3);
    ~RBPyramid();
};

#endif // RBPYRAMID_H
