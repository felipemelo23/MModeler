#include "compoundobject.h"
#include "rbprism.h"
#include "rbpyramid.h"
#include "sphere.h"

#include <iostream>

using namespace std;

CompoundObject::CompoundObject(Object *a, Object *b, int op)
{
    this->a = a;
    this->b = b;
    this->name = "Compound Object";
    this->type = Object::COMPOUND;
    this->operation = op;
    this->material = a->getMaterial();
}

CompoundObject::~CompoundObject()
{
    delete ow;
    delete wo;
}

int CompoundObject::isInside(Vec4 *pos)
{
    bool value = false;
    switch (operation) {
    case UNION:
        value = a->isInside(pos)||b->isInside(pos);
        break;
    case INTERSECT:
        value = a->isInside(pos)&&b->isInside(pos);
        break;
    case DIFFERENCE:
        value = a->isInside(pos)&&(b->isInside(pos) <= 0);
        break;
    }

    return value;
}

vector<RCResult> CompoundObject::checkIntersection(Ray *ray)
{
    vector<RCResult> aResults = a->checkIntersection(ray);
    vector<RCResult> bResults = b->checkIntersection(ray);
    vector<RCResult> results = vector<RCResult>();

    switch (operation) {
    case UNION:
        if ((aResults.size() > 0)&&(bResults.size() > 0)) {
            if (aResults.at(0).getT() < bResults.at(0).getT()) {
                RCResult result = aResults.at(0);
                result.setMaterial(material);
                results.push_back(result);
            } else {
                RCResult result = bResults.at(0);
                result.setMaterial(material);
                results.push_back(result);
            }
        } else if (aResults.size() > 0) {
            RCResult result = aResults.at(0);
            result.setMaterial(material);
            results.push_back(result);
        } else if (bResults.size() > 0) {
            RCResult result = bResults.at(0);
            result.setMaterial(material);
            results.push_back(result);
        }
        break;
    case INTERSECT:
    {
        vector<RCResult> sortedResults = merge(aResults,bResults);
        int i = 0;

        if (sortedResults.size() > 0) {
            while ((i < sortedResults.size())&&
                   !((a->isInside(new Vec4(sortedResults.at(i).getPoint(),1)))&&
                     (b->isInside(new Vec4(sortedResults.at(i).getPoint(),1)))))
                i++;

            if (i < sortedResults.size()) {
                RCResult result = sortedResults.at(i);
                result.setMaterial(material);
                results.push_back(result);
            }
        }

        break;
    }
    case DIFFERENCE:
    {
        vector<RCResult> sortedResults = merge(aResults,bResults);
        int i = 0;

        while ((i < sortedResults.size())&&
               (!a->isInside(new Vec4(sortedResults.at(i).getPoint(),1))||
                !(b->isInside(new Vec4(sortedResults.at(i).getPoint(),1)) <= 0)))
            i++;

        if (i < sortedResults.size()) {
            RCResult result = sortedResults.at(i);
            result.setMaterial(material);
            if (b->isInside(new Vec4(sortedResults.at(i).getPoint(),1)) == -1)
                result.setNormal(result.getNormal()->prod(-1));
            results.push_back(result);
        }
        break;
    }
    }

    return results;
}

Vec3 *CompoundObject::getMaximumCoords()
{
    Vec3 *maxA = a->getMaximumCoords();
    Vec3 *maxB = b->getMaximumCoords();

    Vec3 *maxCoords = new Vec3(max(maxA->getX(),maxB->getX()),
                               max(maxA->getY(),maxB->getY()),
                               max(maxA->getZ(),maxB->getZ()));

    delete maxA;
    delete maxB;

    return maxCoords;
}

Vec3 *CompoundObject::getMinimumCoords()
{
    Vec3 *minA = a->getMinimumCoords();
    Vec3 *minB = b->getMinimumCoords();

    Vec3 *minCoords = new Vec3(min(minA->getX(),minB->getX()),
                               min(minA->getY(),minB->getY()),
                               min(minA->getZ(),minB->getZ()));

    delete minA;
    delete minB;

    return minCoords;
}

Object *CompoundObject::getObjectA()
{
    return a;
}

Object *CompoundObject::getObjectB()
{
    return b;
}

Vec3 *CompoundObject::getOrigin()
{
    return a->getOrigin()->sum(b->getOrigin())->prod(0.5);
}

void CompoundObject::translate(double x, double y, double z)
{
    a->translate(x,y,z);
    b->translate(x,y,z);
}

void CompoundObject::scale(double x, double y, double z)
{
    a->scale(x,y,z);
    b->scale(x,y,z);
}

void CompoundObject::rotate(double degree, bool x, bool y, bool z)
{
    a->rotate(degree,x,y,z);
    b->rotate(degree,x,y,z);
}

vector<RCResult> CompoundObject::merge(vector<RCResult> aResult, vector<RCResult> bResult)
{
    vector<RCResult> sortedResults = vector<RCResult>();
    int i = 0;
    int j = 0;

    while ((i < aResult.size())&&(j < bResult.size())) {
        if (aResult.at(i).getT() < bResult.at(j).getT()) {
            sortedResults.push_back(aResult.at(i));
            i++;
        } else {
            sortedResults.push_back(bResult.at(j));
            j++;
        }
    }

    if (i < aResult.size()) {
        for (int k=i;k<aResult.size();k++)
            sortedResults.push_back(aResult.at(k));
    } else {
        for (int k=j;k<bResult.size();k++)
            sortedResults.push_back(bResult.at(k));
    }

    return sortedResults;
}
