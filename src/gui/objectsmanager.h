#ifndef OBJECTSMANAGER_H
#define OBJECTSMANAGER_H

#include <vector>
#include <queue>
#include <utility>

#include <objects/object.h>

using std::vector;
using std::queue;
using std::pair;

class ObjectsManager
{
public:
    ObjectsManager();
    ~ObjectsManager();

    void addObject(Object *object);
    Object *getObject(int index);
    void removeObject(int index);
    int numOfObjects();

    void addSelected(int objId);
    void removeSelected(int objId);
    int getSelected(int index);
    int numOfSelected();

    bool hasDirts();
    int popDirt();
    void pushDirt(int value, int mode);

private:
    vector<Object*> *objects;
    vector<int> *selecteds;
    queue<pair<int,int> > *dirts;

};

#endif // OBJECTSMANAGER_H
