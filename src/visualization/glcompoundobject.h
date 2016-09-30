#ifndef GLCOMPOUNDOBJECT_H
#define GLCOMPOUNDOBJECT_H

#include "globject.h"

class glCompoundObject : public glObject
{
public:
    glCompoundObject();
    ~glCompoundObject();

    void addSubObject(glObject *obj);
    glObject *getSubObject(int index);
    int numOfSubObjects();

    void draw();

    void setColor(double color[3]);

private:
    vector<glObject*> subObjects;
};

#endif // GLCOMPOUNDOBJECT_H
