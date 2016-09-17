#include "glscene.h"

glScene::glScene()
{
    this->objects = new vector<glObject*>();
}

glScene::~glScene()
{
    for (int i=0;i<objects->size();i++)
        delete objects->at(i);
    delete objects;
}

void glScene::addObject(glObject *object)
{
    this->objects->push_back(object);
}

glObject *glScene::getObject(int index)
{
    return objects->at(index);
}

void glScene::setObject(int index, glObject *object)
{
    glObject *trash = objects->at(index);

    objects->at(index) = object;

    delete trash;
}

void glScene::removeObject(int index)
{
    objects->erase(objects->begin()+index);
}

int glScene::numOfObjects()
{
    return objects->size();
}

void glScene::drawObjects()
{
    if (objects->size() > 0)
        for (int i=0;i<objects->size();i++)
            objects->at(i)->draw();
}

void glScene::setAllSolid(bool solid)
{
    if (objects->size() > 0)
        for (int i=0;i<objects->size();i++)
            objects->at(i)->setSolid(solid);
}
