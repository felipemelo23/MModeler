#ifndef OCTREEFILEMANAGER_H
#define OCTREEFILEMANAGER_H

#include <util/filemanager.h>
#include <objects/ocnode.h>

class OctreeFileManager : protected FileManager
{
public:
    static bool saveOctree(int pos=0, Ocnode *object, string *line, string file_name);
    static bool saveScene(Ocnode **objects, string file_name);
    static Ocnode *getOctreeFromFile(Ocnode *object, string file_name, int position=0);
    static Ocnode **getSceneFromFile(Ocnode **object, string file_name);
};

#endif // OCTREEFILEMANAGER_H
