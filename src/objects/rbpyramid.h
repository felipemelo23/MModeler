#ifndef RBPYRAMID_H
#define RBPYRAMID_H

#include "face.h"

#include <objects/object.h>

class RBPyramid : public Object
{
private:
    int numOfSides;

    Vec4 *vertices;
    Face *faces;

    void generateVertices();
    void generateFaces();

    vector<RCResult> sort(vector<RCResult> results);
public:
    RBPyramid(int numOfSides=3);
    ~RBPyramid();
    void section(Vec2 *v, double radius);
    int isInside(Vec4 pos);
    Vec3 getMaximumCoords();
    Vec3 getMinimumCoords();
    int getNumOfSides() const;

    vector<RCResult> checkIntersection(Ray ray);

    Vec4 *getVertices();
};

#endif // RBPYRAMID_H
