#ifndef CSGFILEMANAGER_H
#define CSGFILEMANAGER_H

#include <util/filemanager.h>
#include <objects/compoundobject.h>
#include <objects/cylinder.h>
#include <objects/box.h>
#include <objects/sphere.h>
#include <sstream>

class CSGFileManager : public FileManager
{
private:
    vector<CompoundObject*> csgtrees;
    QString filename;



public:
    CSGFileManager(QString filename);

    void save();
    void load();
};

#endif // CSGFILEMANAGER_H
