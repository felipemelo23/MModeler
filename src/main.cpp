#include "gui/mainwindow.h"
#include <QApplication>
#include <algebra/mtx4x4.h>
#include <algebra/vec3.h>
#include <algebra/vec4.h>
#include <iostream>
#include <objects/sphere.h>
#include <rendering/camera.h>
#include <rendering/ray.h>
#include <rendering/raycaster.h>
#include <rendering/render.h>
#include <rendering/scene.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
