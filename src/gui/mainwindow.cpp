#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <objects/rbprism.h>
#include <objects/rbpyramid.h>

using namespace std;

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
    interpreter->interpretCommand(ui->cmdFeed->text());
    updateObjectsTree();
    ui->cmdFeed->clear();
}

void MainWindow::updateObjectsTree() {
    ui->objectsTree->clear();
    if (objects->numOfObjects() > 0) {
        QTreeWidgetItem *item;
        QTreeWidgetItem *subItem;

        for (int i=0;i<objects->numOfObjects();i++) {
            Object *obj = objects->getObject(i);
            item = new QTreeWidgetItem();
            if (objects->isSelected(i)) item->setTextColor(0, QColor(255,0,0));
            item->setText(0, obj->getName() + " - id: " + QString::number(i));

            subItem = new QTreeWidgetItem();
            subItem->setText(0, "Position: " + QString::number(obj->getOrigin()->getX()) + "," +
                                               QString::number(obj->getOrigin()->getY()) + "," +
                                               QString::number(obj->getOrigin()->getZ()));
            item->addChild(subItem);

            if (obj->getType() == Object::RBPRISM) {
                subItem = new QTreeWidgetItem();
                subItem->setText(0, "Sides: " + QString::number(((RBPrism*)obj)->getNumOfSides()));
                item->addChild(subItem);
            }

            if (obj->getType() == Object::RBPYRAMID) {
                subItem = new QTreeWidgetItem();
                subItem->setText(0, "Sides: " + QString::number(((RBPyramid*)obj)->getNumOfSides()));
                item->addChild(subItem);
            }

            ui->objectsTree->addTopLevelItem(item);
        }
    }
}
