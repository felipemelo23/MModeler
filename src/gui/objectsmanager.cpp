#include "objectsmanager.h"

ObjectsManager::ObjectsManager()
{
    objects = new vector<Object*>();
    dirts = new queue<int>();
}

ObjectsManager::~ObjectsManager()
{
    for (int i=0;i<objects->size();i++)
        delete objects->at(i);
    delete objects;
    delete dirts;
}

void ObjectsManager::addObject(Object *object)
{
    objects->push_back(object);
}

Object *ObjectsManager::getObject(int index)
{
    return objects->at(index);
}

void ObjectsManager::removeObject(int index)
{
    objects->erase(objects->begin()+index);
}

int ObjectsManager::numOfObjects()
{
    return objects->size();
}

bool ObjectsManager::hasDirts()
{
    return !dirts->empty();
}

int ObjectsManager::popDirt()
{
    int index = dirts->front();
    dirts->pop();
    return index;
}

void ObjectsManager::pushDirt(int value)
{
    dirts->push(value);
}
