#include "objectsmanager.h"

ObjectsManager::ObjectsManager()
{
    objects = new vector<Object*>();
    selecteds = new vector<int>();
    dirts = new queue<int>();
}

ObjectsManager::~ObjectsManager()
{
    if (objects->size() > 0)
        for (int i=0;i<objects->size();i++)
            delete objects->at(i);
    delete objects;
    delete selecteds;
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

void ObjectsManager::addSelected(int objId)
{
    selecteds->push_back(objId);
}

void ObjectsManager::removeSelected(int objId)
{
    int index = -1;

    if (selecteds->size() > 0)
        for (int i=0;i<selecteds->size();i++) {
            if (selecteds->at(i) == objId) {
                index = i;
                break;
            }
        }

    if (index > 0) objects->erase(objects->begin() + index);
}

int ObjectsManager::getSelected(int index)
{
    return selecteds->at(index);
}

int ObjectsManager::numOfSelected()
{
    return selecteds->size();
}

bool ObjectsManager::hasDirts()
{
    return !dirts->empty();
}

int ObjectsManager::popDirt()
{
    pair<int,int> front = dirts->front();
    dirts->pop();
    return front;
}

/*
   value : id do objeto
   mode : modo de alteração (add = +1; remove = -1; alteration = 0)
*/
void ObjectsManager::pushDirt(int value, int mode)
{
    dirts->push(std::make_pair<int,int>(value,mode));
}
