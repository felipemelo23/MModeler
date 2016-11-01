#include "objectsmanager.h"

#include <QThread>

ObjectsManager::ObjectsManager()
{
    objects = new vector<Object*>();
    selecteds = new vector<int>();
    dirts = new vector<pair<int,int> >();
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
    pushDirt(objects->size()-1,+1);
    selecteds->clear();
    addSelected(objects->size()-1);
}

Object *ObjectsManager::getObject(int index)
{
    return objects->at(index);
}

void ObjectsManager::removeObject(int index)
{
    if (objects->size() > 0) {
        removeSelected(index);
        if (index < objects->size()) {
            objects->erase(objects->begin()+index);
            for (int i=0;i<dirts->size();i++) {
                if ((dirts->at(i).first == index)&&(dirts->at(i).second > -1))
                    dirts->erase(dirts->begin()+i);
            }
            pushDirt(index,-1);
        }
    }
}

int ObjectsManager::numOfObjects()
{
    return objects->size();
}

void ObjectsManager::addSelected(int objId)
{
    bool contains = false;
    if ((objects->size() > objId)&&(objId >= 0)) {
        if (selecteds->size() > 0) {
            for (int i=0;i<selecteds->size();i++) {
                contains = contains || selecteds->at(i) == objId;
            }
        }

        if (!contains) selecteds->push_back(objId);
    }
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

    if (index >= 0) selecteds->erase(selecteds->begin() + index);
}

int ObjectsManager::getSelected(int index)
{
    return selecteds->at(index);
}

int ObjectsManager::numOfSelected()
{
    return selecteds->size();
}

bool ObjectsManager::isSelected(int index)
{
    if (selecteds->size() > 0) {
        for (int i=0;i<selecteds->size();i++)
            if (selecteds->at(i) == index) return true;
    }

    return false;
}

bool ObjectsManager::hasDirts()
{
    return !dirts->empty();
}

pair<int,int> ObjectsManager::popDirt()
{
    pair<int,int> front = dirts->front();
    dirts->erase(dirts->begin());
    return front;
}

/*
   value : id do objeto
   mode : modo de alteração (add = +1; remove = -1; alteration = 0)
*/
void ObjectsManager::pushDirt(int value, int mode)
{
    dirts->push_back(std::make_pair(value,mode));
}
