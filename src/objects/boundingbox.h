/*  BoundingBox serao involucros que vao conter um objeto.
 *  Nossas BB serao sempre paralelepipedos
*/

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <objects/object.h>
#include <algebra/vec3.h>

class BoundingBox : public Object
{
private:
    Vec3 *maxCoords;
    Vec3 *minCoords;
    Object* content;

public:    
    BoundingBox(Object* content);
    ~BoundingBox();

    Object* getContent() const;
    void setContent(Object* content);
};

#endif // BOUNDINGBOX_H
