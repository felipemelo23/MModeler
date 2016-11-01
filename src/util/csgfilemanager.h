#ifndef CSGFILEMANAGER_H
#define CSGFILEMANAGER_H

#include <util/filemanager.h>
#include <objects/compoundobject.h>
#include <objects/cylinder.h>
#include <objects/box.h>
#include <objects/sphere.h>
#include <sstream>
#include <stack>

using namespace std;

class CSGFileManager : public FileManager
{
private:
    vector<CompoundObject*> compoundObjs;
    stack<Object*> objects;
    QString filename;

    void parseCSGTree(QStringList tokens);
    void parseTransformations(QStringList *tokens);
public:
    CSGFileManager(QString filename);

    void save();
    void load();
    vector<CompoundObject *> getCompoundObjs() const;
};

#endif // CSGFILEMANAGER_H
