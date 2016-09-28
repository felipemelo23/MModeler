#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objects = new ObjectsManager();
    ui->display->setObjects(objects);
    interpreter = new CommandInterpreter(objects);
}

MainWindow::~MainWindow()
{
    delete ui;
}
