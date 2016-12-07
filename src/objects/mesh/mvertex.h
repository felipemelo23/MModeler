#ifndef MVERTEX_H
#define MVERTEX_H

#include <algebra/vec3.h>
#include <string>

using std::string;

class MVertex : public Vec3
{
public:
    MVertex(string id, string edgeId, double x, double y, double z);

    string getId() const;
    void setId(const string &value);

    void setEdgeId(const string &value);
    string getEdgeId() const;

private:
    string id;
    string edgeId;
};

#endif // MVERTEX_H
