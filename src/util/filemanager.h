#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class FileManager
{
protected:
    ifstream *file_reader;
    ofstream *file_writer;

    vector<string*> readScene(int readPos, string file_name);
    bool writeScene(bool rewrite, vector<string*> objects, string file_name);
};

#endif // FILEMANAGER_H
