#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <queue>
#include <QStringList>
#include <iostream>

using namespace std;

class FileManager
{
public:
    virtual void save()=0;
    virtual void load()=0;
};

#endif // FILEMANAGER_H
