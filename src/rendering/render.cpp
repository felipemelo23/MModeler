#include "raycaster.h"
#include "render.h"
#include <iostream>

using namespace std;

Render::Render(Scene scene, Camera camera, QImage *canvas)
{
    this->scene = scene;
    this->camera = camera;
    this->canvas = canvas;
    this->backgroundColor = QColor(255,255,255);
}

void Render::render()
{
    double widthPP = camera.getMaxPP().getX() - camera.getMinPP().getX();
    double heightPP = camera.getMaxPP().getY() - camera.getMinPP().getY();

    double dX = widthPP/canvas->width();
    double dY = heightPP/canvas->height();

    double initialX = camera.getMinPP().getX() + (dX/2);

    double currX;
    double currY = camera.getMaxPP().getY() - (dY/2);

    Vec3 origin = Vec3();
    Vec3 dir = Vec3();
    for (int i=0;i<canvas->height();i++) {
        currX = initialX;
        for (int j=0;j<canvas->width();j++) {
            dir.setX(currX);
            dir.setY(currY);
            dir.setZ(camera.getProjectionPlane());
            dir.normalize();

            Ray ray = Ray(origin,dir);

            ray = ray.transform(camera.getCW());

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
    Color I;
    Color Ia = Color(0,0,0);
    Color Id = Color(0,0,0);
    Color Is = Color(0,0,0);

    Vec3 eye = camera.getOrigin() - income.getPoint();
    eye.normalize();

    Ia = (scene.getAmbLight().getColor()*income.getMaterial()->getAmbient())*scene.getAmbLight().getIntesity();

    if (scene.numOfLights() > 0) {
        for (int i=0;i<scene.numOfLights();i++) {
            Light light = *(scene.getLight(i));

            Vec3 lightDir = light.getOrigin() - income.getPoint();
            lightDir.normalize();

            Vec3 reflect = income.getNormal()*(income.getNormal().dot_(lightDir))*2 - lightDir;
            reflect.normalize();

            Id = Id + light.getColor() * income.getMaterial()->getDiffuse() * max(income.getNormal().dot_(lightDir),0.0) * light.getIntensity();
            Is = Is + light.getColor() * income.getMaterial()->getSpecular() * pow(max(reflect.dot_(eye),0.0),income.getMaterial()->getShininess()) * light.getIntensity();
        }
    }

    I = Ia + Id + Is;

    return QColor(255*min(I.getRed(),1.0),255*min(I.getGreen(),1.0),255*min(I.getBlue(),1.0));
}

QColor Render::getBackgroundColor() const
{
    return backgroundColor;
}

void Render::setBackgroundColor(const QColor &value)
{
    backgroundColor = value;
}

void Render::setScene(Scene value)
{
    scene = value;
}
