#ifndef OBJECTSMANAGER_H
#define OBJECTSMANAGER_H

#include <vector>
#include <queue>

using std::vector;
using std::queue;

class ObjectsManager
{
public:
    ObjectsManager();
    ~ObjectsManager();

    void addObject(Object *object);
    Object *getObject(int index);
    void removeObject(int index);
    int numOfObjects();

    bool hasDirts();
    int popDirt();
    void pushDirt(int value);

private:
    vector<Object*> *objects;
    queue<int> *dirts;

};

#endif // OBJECTSMANAGER_H
