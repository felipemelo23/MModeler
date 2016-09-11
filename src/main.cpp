#include "gui/mainwindow.h"
#include <QApplication>
#include <algebra/mtx4x4.h>
#include <algebra/vec3.h>
#include <algebra/vec4.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Mtx4x4 *m = new Mtx4x4(1.0,2.0,3.0,1.0,
                           4.0,5.0,6.0,1.0,
                           7.0,8.0,9.0,1.0,
                           1.0,1.0,1.0,1.0);

    cout << m->toStdString() << endl;

    return a.exec();
}
