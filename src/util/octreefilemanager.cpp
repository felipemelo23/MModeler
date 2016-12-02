#include "octreefilemanager.h"

OctreeFileManager::OctreeFileManager(QString filename)
{
    this->filename = filename;
    this->octrees = vector<Ocnode*>();
}

vector<Ocnode *> OctreeFileManager::getOctrees()
{
    return octrees;
}

void OctreeFileManager::setOctrees(vector<Ocnode *> octrees)
{
    this->octrees = octrees;
}

void OctreeFileManager::addOctree(Ocnode *octree)
{
    this->octrees.push_back(octree);
}

QString OctreeFileManager::getFilename()
{
    return filename;
}

void OctreeFileManager::setFilename(QString filename)
{
    this->filename = filename;
}

void OctreeFileManager::save()
{
    ofstream file;

    file.open(filename.toStdString());
    if (octrees.size() > 0)
        for (int i=0;i<octrees.size();i++) {
            file << saveOctree(octrees.at(i)).toStdString() << endl;
        }
    file.close();
}

QString OctreeFileManager::saveOctree(Ocnode *octree) {
    QString line = "";
    line += QString::number(octree->getOrigin().getX()) + ",";
    line += QString::number(octree->getOrigin().getY()) + ",";
    line += QString::number(octree->getOrigin().getZ()) + ",";
    line += QString::number(octree->getSize()) + " ";
    line += octreeRepresetation(octree);

    return line;
}

QString OctreeFileManager::octreeRepresetation(Ocnode *octree) {
    QString line = "(";

    for (int i=0;i<8;i++) {
        Ocnode *child = octree->getChild(i);

        switch (child->getState()) {
        case -1:
            line += "w";
            break;
        case 1:
            line += "b";
            break;
        case 0:
            line += octreeRepresetation(child);
            break;
        }
    }

    return line;
}

void OctreeFileManager::load()
{
    ifstream file;
    file.open(filename.toStdString());

    string position;
    string representation;

    file >> position;
    file >> representation;
    do {
        addOctree(loadOctree(QString::fromStdString(position), QString::fromStdString(representation)));
        file >> position;
        file >> representation;
    } while(!file.eof());

    file.close();
}

Ocnode *OctreeFileManager::loadOctree(QString position, QString representation)
{
    QStringList coords = position.split(",");

    Ocnode* root = new Ocnode(true);
    root->translate(coords.at(0).toDouble(),coords.at(1).toDouble(),coords.at(2).toDouble());
    root->setSize(coords.at(3).toDouble());

    queue<char> *repQueue = makeRepresentationQueue(representation);

    loadChildren(root,repQueue);

    return root;
}

queue<char> *OctreeFileManager::makeRepresentationQueue(QString representation) {
    queue<char> *repQueue = new queue<char>();

    for (int i=1;i<representation.size();i++)
        repQueue->push(representation.at(i).toLatin1());

    return repQueue;
}

void OctreeFileManager::loadChildren(Ocnode *parent, queue<char> *repQueue) {
    Ocnode *child;
    for (int i=0;i<8;i++) {
        child = new Ocnode();
        child->setDepth(parent->getDepth() + 1);
        child->setSize(parent->getSize()/2);
        child->translate(parent->getOrigin().getX(),parent->getOrigin().getY(),parent->getOrigin().getZ());
        reposition(child,i);

        char state = repQueue->front();
        repQueue->pop();

        switch (state) {
        case 'w':
            child->setState(-1);
            break;
        case 'b':
            child->setState(1);
            break;
        case '(':
            child->setState(0);
            loadChildren(child,repQueue);
            break;
        }

        parent->addChild(child);
    }
}

void OctreeFileManager::reposition(Ocnode *node, int index) {
    double x,y,z;
    double amount = node->getSize()/2;

    switch (index) {
    case 0:
        x = -amount;
        y = -amount;
        z = amount;
        break;
    case 1:
        x = amount;
        y = -amount;
        z = amount;
        break;
    case 2:
        x = -amount;
        y = -amount;
        z = -amount;
        break;
    case 3:
        x = amount;
        y = -amount;
        z = -amount;
        break;
    case 4:
        x = -amount;
        y = amount;
        z = amount;
        break;
    case 5:
        x = amount;
        y = amount;
        z = amount;
        break;
    case 6:
        x = -amount;
        y = amount;
        z = -amount;
        break;
    case 7:
        x = amount;
        y = amount;
        z = -amount;
        break;
    }

    node->translate(x,y,z);
}
