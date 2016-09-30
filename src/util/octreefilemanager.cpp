#include "octreefilemanager.h"

/* Converte a octree para string e depois utiliza o metodo definido
 * na classe FileManager para gravar a string num arquivo texto.
*/
bool OctreeFileManager::saveOctree(int pos, Ocnode *object, string *line, string file_name)
{
    int child_size = object->getChildren()->size();

    if(child_size == 0)         //noh folha, pode ser preto ou branco
    {

    }
    else if(child_size > 0)     //noh cinza
    {

    }
    else                        //extrutura da octree estah errada
        return false;
}

bool OctreeFileManager::saveScene(Ocnode **objects, string file_name)
{

}

Ocnode *OctreeFileManager::getOctreeFromFile(Ocnode *object, string file_name, int position)
{

}

Ocnode **OctreeFileManager::getSceneFromFile(Ocnode **object, string file_name)
{

}
