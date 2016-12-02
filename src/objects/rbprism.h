#ifndef RBPRISM_H
#define RBPRISM_H

#include "face.h"

#include <objects/object.h>
#include <algebra/mtx3x3.h>

class RBPrism : public Object
{
private:
    int numOfSides;

    Vec4 *vertices;
    Face *faces;

    vector<RCResult> sort(vector<RCResult> results);
    void generateVertices();
    void generateFaces();
    Face *getFaces();
public:
    RBPrism(int numOfSides=3);
    ~RBPrism();
    void section(Vec2 *v, double radius=0.5);
    int isInside(Vec4 pos);
    Vec3 getMaximumCoords();
    Vec3 getMinimumCoords();
    int getNumOfSides() const;

    void translate(double x, double y, double z);
    void scale(double x, double y, double z);
    void rotate(double degree, bool x=true, bool y=false, bool z=false);

    vector<RCResult> checkIntersection(Ray ray);

    Vec4 *getVertices();
};

#endif // RBPRISM_H
