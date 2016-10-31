#include "csgfilemanager.h"

CSGFileManager::CSGFileManager(QString filename)
{
    this->filename = filename;
    this->csgtrees = vector<CompoundObject*>();
}

void CSGFileManager::load()
{
    ifstream file;
    file.open(filename.toStdString());

    string token;

    queue<Object*> obj_pair;
    bool root;

    do
    {
        file >> token;

        switch (token)
        {

        case "O":

            obj_pair = queue<Object*>();
            root=true;

            break;

        case "B":

            if(obj_pair.size()<2)
            {
                double params[6];

                for(int i=0; i<6; i++)
                {
                    file >> params[i];
                }

                obj_pair.push(new Box());
                obj_pair.back->scale(params[3], params[4], params[5]);
                obj_pair.back->translate(params[0], params[1], params[2]);
            }

            break;

        case "S":

            if(obj_pair.size()<2)
            {
                double params[4];

                for(int i=0; i<4; i++)
                {
                    file >> params[i];
                }

                obj_pair.push(new Sphere());
                obj_pair.back->scale(params[3], params[3], params[3]);
                obj_pair.back->translate(params[0], params[1], params[2]);
            }

            break;

        case "C":

            if(obj_pair.size()<2)
            {
                double params[4];

                for(int i=0; i<5; i++)
                {
                    file >> params[i];
                }

                obj_pair.push(new Cylinder());
                obj_pair.back->scale(params[3], params[3], params[4]);
                obj_pair.back->translate(params[0], params[1], params[2]);
            }

            break;

        case "t":
            if(obj_pair.size()>0)
            {
                double params[3];

                for(int i=0; i<3; i++)
                {
                    file >> params[i];
                }

                obj_pair.back->translate(params[0], params[1], params[2]);
            }

            break;

        case "s":
            if(obj_pair.size()>0)
            {
                double params[3];

                for(int i=0; i<3; i++)
                {
                    file >> params[i];
                }

                obj_pair.back->scale(params[0], params[1], params[2]);
            }

            break;

        case "r":
            if(obj_pair.size()>0)
            {
                double params[4];
                bool axis[3];

                for(int i=0; i<4; i++)
                {
                    file >> params[i];
                    if(i<3)
                    {
                        if(params[i]>0) axis[i] = true;
                        else axis[i] = false;
                    }
                }

                obj_pair.back->rotate(params[0], axis[0], axis[1], axis[2]);
            }

            break;

        case "u":
            if(obj_pair.size()==2)
            {
                if(root)
                {
                    csgtrees.push_back(new CompoundObject(obj_pair.front(), obj_pair.back(), CompoundObject::UNION));
                }
                else
                {
//                    csgtrees.at(csgtrees.size()-1)
                }
            }

            break;

        case "i":

            break;

        case "d":

            break;

        default:
            break;
        }

    } while(!file.eof());

    file.close();
}
