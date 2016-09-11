#ifndef GLSCENE_H
#define GLSCENE_H

#include "globject.h"
#include <vector>

using std::vector;

class glScene
{
public:
    glScene();
    ~glScene();

    void addObject(glObject *object);
    glObject *getObject(int index);
    void removeObject(int index);
    int numOfObjects();

    void drawObjects();
    void setAllSolid(bool solid);

private:
    vector<glObject*> *objects;
};

#endif // GLSCENE_H
