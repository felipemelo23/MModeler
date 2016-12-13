#ifndef FACE_H
#define FACE_H

#include <algebra/vec3.h>
#include <algebra/vec4.h>
#include <rendering/ray.h>
#include <utility>
#include <rendering/rcresult.h>

using namespace std;

class Face
{
public:
    Face();
    Face(int sides, Material *material, Vec4 *v);
    Face(int sides, Material *material, Vec4 v1, Vec4 v2, Vec4 v3, ...);
    ~Face();

    int getSides() const;
    Vec4 *getVertices() const;

    RCResult checkIntersection(Ray ray);

    Material *getMaterial() const;
    void setMaterial(Material *value);

    vector< pair<Vec3,Vec3> > getEdges();


private:
    int sides;
    Vec4 *vertices;
    bool isInside(Vec4 pos);

    Material *material;
};

#endif // FACE_H
