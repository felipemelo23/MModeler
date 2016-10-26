#ifndef FACE_H
#define FACE_H

#include <algebra/vec3.h>
#include <algebra/vec4.h>
#include <rendering/ray.h>
#include <rendering/rcresult.h>

class Face
{
public:
    Face(int sides, Vec4 **v, Material *material);
    Face(int sides, Material *material, Vec4 *v1, Vec4 *v2, Vec4 *v3, ...);

    int getSides() const;
    Vec4 **getVertices() const;

    RCResult checkIntersection(Ray *ray);

    Material *getMaterial() const;
    void setMaterial(Material *value);


private:
    int sides;
    Vec4 **vertices;
    bool isInside(Vec4 *pos);

    Material *material;
};

#endif // FACE_H
