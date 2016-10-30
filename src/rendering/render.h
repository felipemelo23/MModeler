#ifndef RENDER_H
#define RENDER_H

#include "camera.h"
#include "scene.h"

#include <QImage>



class Render
{
public:
    Render(Scene *scene, Camera *camera, QImage *canvas);

    void render();

    QColor getBackgroundColor() const;
    void setBackgroundColor(const QColor &value);

    void setScene(Scene *value);

private:
    Scene *scene;
    Camera *camera;
    QImage *canvas;

    QColor backgroundColor;

    QColor getPixelColor(RCResult income);
    QColor calculatePhong(RCResult income);
};

#endif // RENDER_H
