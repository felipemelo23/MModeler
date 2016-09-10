#include "gui/mainwindow.h"
#include <QApplication>
#include <algebra/vec3.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
