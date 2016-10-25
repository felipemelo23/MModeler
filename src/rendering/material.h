#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

class Material
{
public:
    Material();
    Material(Color *ambient, Color *diffuse, Color *specular, double shininess);

    Color *getAmbient() const;
    Color *getDiffuse() const;
    Color *getSpecular() const;
    double getShininess() const;

private:
    Color *ambient;
    Color *diffuse;
    Color *specular;
    double shininess;
};

#endif // MATERIAL_H
