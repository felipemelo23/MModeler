#ifndef OBJECT_H
#define OBJECT_H

#include <algebra/mtx4x4.h>
#include <algebra/vec3.h>
#include <algebra/vec2.h>

#include <QString>

#include <rendering/ray.h>
#include <rendering/rcresult.h>

/*A classe object servira apenas como interface para
facilitar implementacao e para fazer passagem de parametross*/

class Object
{
protected:
    Mtx4x4 wo;
    Mtx4x4 ow;
    int type;
    QString name;
    Material *material;

public:
    Object();

    virtual Vec3 getOrigin();
    QString getName();
    void setName(QString name);
    int getType();

    virtual void translate(double x, double y, double z);
    virtual void scale(double x, double y, double z);
    virtual void rotate(double degree, bool x=true, bool y=false, bool z=false);

    virtual int isInside(Vec4 pos)=0;
    virtual vector<RCResult> checkIntersection(Ray ray);

    virtual Vec3 getMinimumCoords()=0;
    virtual Vec3 getMaximumCoords()=0;

    virtual void section(Vec2 *v, double radius=0.5);

    static const int SPHERE = 0;
    static const int RBPRISM = 1;
    static const int RBPYRAMID = 2;
    static const int OCTREE = 3;
    static const int CONE = 4;
    static const int CYLINDER = 5;
    static const int COMPOUND = 6;
    static const int CSGTREE = 7;
    static const int BOX = 8;

    Material *getMaterial() const;
    void setMaterial(Material *value);
};

#endif // OBJECT_H
