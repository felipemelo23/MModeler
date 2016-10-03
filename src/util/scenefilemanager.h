#ifndef SCENEFILEMANAGER_H
#define SCENEFILEMANAGER_H

#include "filemanager.h"
#include <fstream>
#include <gui/objectsmanager.h>
#include <string>

using namespace std;

class SceneFileManager : public FileManager
{
public:
    SceneFileManager(QString filename);

    void save();
    void load();

    void setCommandList(const vector<QString> &value);
    vector<QString> getCommandList() const;

    void setFilename(const QString &value);

private:
    QString filename;
    vector<QString> commandList;
};

#endif // SCENEFILEMANAGER_H
