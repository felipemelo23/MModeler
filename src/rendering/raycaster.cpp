#include "raycaster.h"


RCResult RayCaster::cast(Ray *ray, Scene *scene)
{
    if (scene->numOfObjects() > 0) {
        vector<RCResult> results = vector<RCResult>();

        for (int i=0;i<scene->numOfObjects();i++) {
            vector<RCResult> result = scene->getObject(i)->checkIntersection(ray);

            if ((result.size() > 0) && (result.at(0).getT() > 0)) {
                for (int j=0;j<result.size();j++)
                    results.push_back(result.at(j));
            }
        }

        return getNearestIntersection(results);
    }

    return RCResult();
}

RCResult RayCaster::getNearestIntersection(vector<RCResult> results) {
    if (results.size() > 0) {
        RCResult result = results.at(0);

        for (int i=1;i<results.size();i++) {
            if (results.at(i).getT() < result.getT()) result = results.at(i);
        }

        return result;
    }

    return RCResult();
}
