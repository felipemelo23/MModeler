#include "raycaster.h"


RCResult RayCaster::cast(Ray *ray, Scene *scene)
{
    if (scene->numOfObjects() > 0) {
        vector<std::pair<RCResult,RCResult> > results = vector<std::pair<RCResult,RCResult> >();

        for (int i=0;i<scene->numOfObjects();i++) {
            std::pair<RCResult,RCResult> result = scene->getObject(i)->checkIntersection(ray);

            if (result.first.getIntersected()&&(result.first.getT() > 0)) results.push_back(result);
        }

        return getNearestIntersection(results);
    }

    return RCResult();
}

RCResult RayCaster::getNearestIntersection(vector<std::pair<RCResult,RCResult> > results) {
    if (results.size() > 0) {
        RCResult result = results.at(0).first;


        for (int i=1;i<results.size();i++) {
            if (results.at(i).first.getT() < result.getT()) result = results.at(i).first;
        }

        return result;
    }

    return RCResult();
}
