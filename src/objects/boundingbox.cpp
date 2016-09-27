#include <objects/boundingbox.h>

/* Gera uma bounding box a partir de um objeto, para isso
 * precisamos saber as coordenadas minimas e maximas dos
 * mesmos.
*/
BoundingBox::BoundingBox(Object *content)
{
    setContent(content);

    this->minCoords = content->getMinimumCoords();
    this->maxCoords = content->getMaximumCoords();
}

BoundingBox::~BoundingBox()
{
    delete minCoords;
    delete maxCoords;
}

Object *BoundingBox::getContent() const
{
    return content;
}

void BoundingBox::setContent(Object *content)
{
    this->content = content;
}

Vec3 *BoundingBox::getMaximumCoords()
{
    return maxCoords;
}

Vec3 *BoundingBox::getMinimumCoords()
{
    return minCoords;
}
