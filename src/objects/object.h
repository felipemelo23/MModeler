#ifndef OBJECT_H
#define OBJECT_H

#include <algebra/mtx4x4.h>
#include <algebra/vec3.h>

/*A classe object servira apenas como interface para
facilitar implementacao e para fazer passagem de parametross*/

class Object
{
private:
    Mtx4x4 *wo;
    Mtx4x4 *ow;

public:
    Vec3 getOrigin();

    void translate(double x, double y, double z);
    void scale(double x, double y, double z);
    void rotate(double degree, bool x=true, bool y=false, bool z=false);

    virtual bool isInside(Vec4 *pos)=0;

    virtual Vec3 *getMinimumCoords()=0;
    virtual Vec3 *getMaximumCoords()=0;
};

#endif // OBJECT_H
