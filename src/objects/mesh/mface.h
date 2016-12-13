#ifndef MFACE_H
#define MFACE_H

#include <string>

using std::string;

class MFace
{
public:
    MFace(string id, string edgeId, int orientation=CCW);

    string getId() const;
    void setId(const string &value);

    string getEdgeId() const;
    void setEdgeId(const string &value);

    static const bool CCW = true;
    static const bool CW = false;

    int getOrientation() const;
    void setOrientation(int value);

private:
    string id;
    string edgeId;
    int orientation;
};

#endif // MFACE_H
