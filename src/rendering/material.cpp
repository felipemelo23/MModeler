#include "material.h"

Material::Material()
{
    this->ambient = new Color(1,1,1);
    this->diffuse = new Color(1,1,1);
    this->specular = new Color(1,1,1);
    this->shininess = 10;
}

Material::Material(Color *ambient, Color *diffuse, Color *specular, double shininess)
{
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
}

Color *Material::getAmbient() const
{
    return ambient;
}

Color *Material::getDiffuse() const
{
    return diffuse;
}

Color *Material::getSpecular() const
{
    return specular;
}

double Material::getShininess() const
{
    return shininess;
}
