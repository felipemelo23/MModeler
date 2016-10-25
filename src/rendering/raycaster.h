#ifndef RAYCASTER_H
#define RAYCASTER_H

#include "ray.h"
#include "rcresult.h"
#include "scene.h"

class RayCaster
{
public:
    static RCResult cast(Ray *ray, Scene *scene);
private:
    static RCResult getNearestIntersection(vector<std::pair<RCResult, RCResult> > results);
};

#endif // RAYCASTER_H
