#include "raycaster.h"
#include "render.h"
#include <iostream>

using namespace std;

Render::Render(Scene *scene, Camera *camera, QImage *canvas)
{
    this->scene = scene;
    this->camera = camera;
    this->canvas = canvas;
    this->backgroundColor = QColor(255,255,255);
}

void Render::render()
{
    double widthPP = camera->getMaxPP()->getX() - camera->getMinPP()->getX();
    double heightPP = camera->getMaxPP()->getY() - camera->getMinPP()->getY();

    double dX = widthPP/canvas->width();
    double dY = heightPP/canvas->height();

    double initialX = camera->getMinPP()->getX() + (dX/2);

    double currX;
    double currY = camera->getMaxPP()->getY() - (dY/2);

    Vec3 *origin = new Vec3();
    Vec3 *dir = new Vec3();
    for (int i=0;i<canvas->height();i++) {
        currX = initialX;
        for (int j=0;j<canvas->width();j++) {
            dir->setX(currX);
            dir->setY(currY);
            dir->setZ(camera->getProjectionPlane());
            dir->normalize();

            Ray *ray = new Ray(origin,dir);

            ray = ray->transform(camera->getCW());

            RCResult result = RayCaster::cast(ray,scene);

            canvas->setPixelColor(j,i,getPixelColor(result));

            currX += dX;
        }
        currY -= dY;
    }
}

QColor Render::getPixelColor(RCResult income)
{
    if (income.getIntersected()) {
        return calculatePhong(income);
    }

    return backgroundColor;
}

QColor Render::calculatePhong(RCResult income)
{
    Color *I;
    Color *Ia = new Color(0,0,0);
    Color *Id = new Color(0,0,0);
    Color *Is = new Color(0,0,0);

    Vec3 *eye = camera->getOrigin()->sub(income.getPoint());
    eye->normalize();

    Ia = scene->getAmbLight()->getColor()->prod(income.getMaterial()->getAmbient())->prod(scene->getAmbLight()->getIntesity());

    if (scene->numOfLights() > 0) {
        for (int i=0;i<scene->numOfLights();i++) {
            Light *light = scene->getLight(i);

            Vec3 *lightDir = light->getOrigin()->sub(income.getPoint());
            lightDir->normalize();

            Vec3 *reflect = income.getNormal()->prod(income.getNormal()->dot(lightDir)*2)->sub(lightDir);
            reflect->normalize();

            Id->sum_(light->getColor()->prod(income.getMaterial()->getDiffuse())->prod(max(income.getNormal()->dot(lightDir),0.0))->prod(light->getIntensity()));
            Is->sum_(light->getColor()->prod(income.getMaterial()->getSpecular())->prod(pow(max(reflect->dot(eye),0.0),income.getMaterial()->getShininess()))->prod(light->getIntensity()));
        }
    }

    I = Ia->sum(Id)->sum(Is);

    return QColor(255*min(I->getRed(),1.0),255*min(I->getGreen(),1.0),255*min(I->getBlue(),1.0));
}

QColor Render::getBackgroundColor() const
{
    return backgroundColor;
}

void Render::setBackgroundColor(const QColor &value)
{
    backgroundColor = value;
}


