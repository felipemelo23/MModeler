#ifndef FILEMANAGER_H
#define FILEMANAGER_H

class FileManager
{
public:
    virtual void save()=0;
    virtual void load()=0;
};

#endif // FILEMANAGER_H
