#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H

#include "color.h"

class AmbientLight
{
public:
    AmbientLight();
    AmbientLight(Color color, double intesity);

    Color getColor() const;
    double getIntesity() const;

private:
    Color color;
    double intesity;
};

#endif // AMBIENTLIGHT_H
