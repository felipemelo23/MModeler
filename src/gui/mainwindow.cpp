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
    connect(ui->feedBtn,SIGNAL(clicked(bool)),this,SLOT(feedCommand()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::feedCommand()
{
    interpreter->interpretCommand(ui->lineEdit->text());
    ui->lineEdit->clear();
}
