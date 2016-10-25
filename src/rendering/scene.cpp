#include "scene.h"

Scene::Scene()
{
    this->objects = new vector<Object*>();
    this->lights = new vector<Light*>();
    this->ambLight = new AmbientLight();
}

Object *Scene::getObject(int index)
{
    return objects->at(index);
}

void Scene::addObject(Object *obj)
{
    objects->push_back(obj);
}

int Scene::numOfObjects()
{
    return objects->size();
}

Light *Scene::getLight(int index)
{
    return lights->at(index);
}

void Scene::addLight(Light *light)
{
    lights->push_back(light);
}

int Scene::numOfLights()
{
    return lights->size();
}

AmbientLight *Scene::getAmbLight() const
{
    return ambLight;
}

void Scene::setAmbLight(AmbientLight *value)
{
    ambLight = value;
}
