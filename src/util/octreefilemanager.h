#ifndef OCTREEFILEMANAGER_H
#define OCTREEFILEMANAGER_H

#include <util/filemanager.h>
#include <objects/ocnode.h>
#include <fstream>
#include <queue>

class OctreeFileManager : public FileManager
{
public:
    OctreeFileManager(QString filename);

    vector<Ocnode*> getOctrees();
    void setOctrees(vector<Ocnode*> octrees);
    void addOctree(Ocnode *octree);
    QString getFilename();
    void setFilename(QString filename);

    void save();
    void load();

private:
    vector<Ocnode*> octrees;
    QString filename;

    QString saveOctree(Ocnode *octree);
    QString octreeRepresetation(Ocnode *octree);
    Ocnode *loadOctree(QString position, QString representation);
    queue<char> *makeRepresentationQueue(QString representation);
    void loadChildren(Ocnode *parent, queue<char> *repQueue);
    void reposition(Ocnode *node, int index);
};

#endif // OCTREEFILEMANAGER_H
