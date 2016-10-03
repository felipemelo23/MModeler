#include "scenefilemanager.h"
#include <QStringList>
#include <iostream>

SceneFileManager::SceneFileManager(QString filename)
{
    this->filename = filename;
    this->commandList = vector<QString>();
}

void SceneFileManager::save()
{
    ofstream file;
    file.open(filename.toStdString());

    for (int i=0;i<commandList.size();i++)
        file << commandList.at(i).toStdString() << endl;

    file.close();
}

void SceneFileManager::load()
{
    ifstream file;
    file.open(filename.toStdString());

    string line;

    getline(file,line);
    do {
        if (QString::fromStdString(line).split(" ")[0] != "del")
            commandList.push_back(QString::fromStdString(line));
        getline(file,line);
    } while (!file.eof());

    file.close();
}

void SceneFileManager::setCommandList(const vector<QString> &value)
{
    commandList = value;
}

vector<QString> SceneFileManager::getCommandList() const
{
    return commandList;
}

void SceneFileManager::setFilename(const QString &value)
{
    filename = value;
}
