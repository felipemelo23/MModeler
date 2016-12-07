#ifndef MFACE_H
#define MFACE_H

#include <string>

using std::string;

class MFace
{
public:
    MFace(string id, string edgeId);

    string getId() const;
    void setId(const string &value);

    string getEdgeId() const;
    void setEdgeId(const string &value);

private:
    string id;
    string edgeId;
};

#endif // MFACE_H
