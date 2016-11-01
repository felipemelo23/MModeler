#include "csgfilemanager.h"
#include <iostream>

using namespace std;

CSGFileManager::CSGFileManager(QString filename)
{
    this->filename = filename;
    this->compoundObjs = vector<CompoundObject*>();
}

void CSGFileManager::save()
{

}

void CSGFileManager::load()
{
    ifstream file;
    file.open(filename.toStdString());

    string line;

    getline(file,line);
    do {
        QStringList tokens = QString::fromStdString(line).split(" ");
        if (tokens.size() > 0) parseCSGTree(tokens);
        getline(file,line);
    } while (!file.eof());

    file.close();
}

vector<CompoundObject *> CSGFileManager::getCompoundObjs() const
{
    return compoundObjs;
}

void CSGFileManager::parseCSGTree(QStringList tokens)
{
    objects = stack<Object*>();

    while ((tokens.size() > 0)&&((tokens.at(0) == "B")||(tokens.at(0) == "S")||(tokens.at(0) == "C")||
           (tokens.at(0) == "u")||(tokens.at(0) == "i")||(tokens.at(0) == "d"))) {

        if (tokens.at(0) == "B") {
            double x = tokens.at(1).toDouble();
            double y = tokens.at(2).toDouble();
            double z = tokens.at(3).toDouble();
            double w = tokens.at(4).toDouble();
            double h = tokens.at(5).toDouble();
            double d = tokens.at(6).toDouble();

            for (int i=0;i<7;i++) {
                tokens.erase(tokens.begin());
            }

            objects.push(new Box());
            objects.top()->scale(w,h,d);
            objects.top()->translate(x,y,z);
        } else if (tokens.at(0) == "S") {
            double x = tokens.at(1).toDouble();
            double y = tokens.at(2).toDouble();
            double z = tokens.at(3).toDouble();
            double r = tokens.at(4).toDouble();

            for (int i=0;i<5;i++) {
                tokens.erase(tokens.begin());
            }

            objects.push(new Sphere());
            objects.top()->scale(2*r,2*r,2*r);
            objects.top()->translate(x,y,z);
        } else if (tokens.at(0) == "C") {
            double x = tokens.at(1).toDouble();
            double y = tokens.at(2).toDouble();
            double z = tokens.at(3).toDouble();
            double r = tokens.at(4).toDouble();
            double h = tokens.at(5).toDouble();

            for (int i=0;i<6;i++) {
                tokens.erase(tokens.begin());
            }

            objects.push(new Cylinder());
            objects.top()->scale(2*r,h,2*r);
            objects.top()->translate(x,0.5+y,z);
        } else if (tokens.at(0) == "O") {

        } else if (tokens.at(0) == "u") {
            Object *A = objects.top();
            objects.pop();
            Object *B = objects.top();
            objects.pop();
            Object *co = new CompoundObject(A,B,CompoundObject::UNION);
            objects.push(co);

            tokens.erase(tokens.begin());
        } else if (tokens.at(0) == "i") {
            Object *A = objects.top();
            objects.pop();
            Object *B = objects.top();
            objects.pop();
            Object *co = new CompoundObject(A,B,CompoundObject::INTERSECT);
            objects.push(co);

            tokens.erase(tokens.begin());
        } else if (tokens.at(0) == "d") {
            Object *A = objects.top();
            objects.pop();
            Object *B = objects.top();
            objects.pop();
            Object *co = new CompoundObject(A,B,CompoundObject::DIFFERENCE);
            objects.push(co);

            tokens.erase(tokens.begin());
        }

        if (tokens.size() > 0) parseTransformations(&tokens);
    }

    if (objects.size() == 1) compoundObjs.push_back((CompoundObject*)objects.top());
}

void CSGFileManager::parseTransformations(QStringList *tokens)
{
    while ((tokens->size()>0)&&((tokens->at(0) == "t")||(tokens->at(0) == "s")||(tokens->at(0) == "r"))) {
        if (tokens->at(0) == "t") {
            double x = tokens->at(1).toDouble();
            double y = tokens->at(2).toDouble();
            double z = tokens->at(3).toDouble();

            for (int i=0;i<4;i++) {
                tokens->erase(tokens->begin());
            }

            objects.top()->translate(x,y,z);
        } else if (tokens->at(0) == "s") {
            double x = tokens->at(1).toDouble();
            double y = tokens->at(2).toDouble();
            double z = tokens->at(3).toDouble();

            for (int i=0;i<4;i++) {
                tokens->erase(tokens->begin());
            }

            objects.top()->scale(x,y,z);
        } else if (tokens->at(0) == "r") {
            bool x = tokens->at(1).toInt();
            bool y = tokens->at(2).toInt();
            bool z = tokens->at(3).toInt();
            double d = tokens->at(4).toDouble();

            for (int i=0;i<5;i++) {
                tokens->erase(tokens->begin());
            }

            objects.top()->rotate((d*3.141592)/180,x,y,z);
        }
    }
}







