#ifndef SCENE_H
#define SCENE_H

#include "ambientlight.h"
#include "light.h"

#include <objects/object.h>

class Scene
{
public:
    Scene();

    Object *getObject(int index);
    void addObject(Object *obj);
    int numOfObjects();

    Light *getLight(int index);
    void addLight(Light *light);
    int numOfLights();

    AmbientLight getAmbLight() const;
    void setAmbLight(AmbientLight value);

private:
    vector<Object*> *objects;
    vector<Light*> *lights;

    AmbientLight ambLight;
};

#endif // SCENE_H
