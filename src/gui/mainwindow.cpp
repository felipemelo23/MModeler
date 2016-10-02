#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <objects/rbprism.h>
#include <objects/rbpyramid.h>
#include <util/octreefilemanager.h>

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
    connect(ui->actionOpenOF,SIGNAL(triggered(bool)),this,SLOT(openOctreeFile()));
    connect(ui->actionSaveOF,SIGNAL(triggered(bool)),this,SLOT(saveOctreeFile()));
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

void MainWindow::openOctreeFile()
{
    QFileDialog *openDialog = new QFileDialog(this);

    QString filename = openDialog->getOpenFileName(this,tr("Carregar Octrees"),"",tr("Arquivo de Octrees (*.oct)"));

    if (!filename.isEmpty()) {
        OctreeFileManager ofm(filename);

        ofm.load();

        vector<Ocnode*> octrees = ofm.getOctrees();

        for (int i=0;i<octrees.size();i++) {
            objects->addObject(octrees.at(i));
        }
    }

    updateObjectsTree();
}

void MainWindow::saveOctreeFile()
{
    QFileDialog *saveDialog = new QFileDialog(this);

    QString filename = saveDialog->getSaveFileName(this,tr("Salvar Octrees"),"",tr("Arquivo de Octrees (*.oct)"));

    if (!filename.isEmpty()) {
        vector<Ocnode*> octrees = vector<Ocnode*>();
        if (objects->numOfObjects() > 0)
            for (int i=0;i<objects->numOfObjects();i++) {
                if (objects->getObject(i)->getType() == Object::OCTREE)
                    octrees.push_back((Ocnode*)objects->getObject(i));
            }
        OctreeFileManager ofm(filename);
        ofm.setOctrees(octrees);
        ofm.save();
    }
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

            if (obj->getType() == Object::OCTREE) {
                subItem = new QTreeWidgetItem();
                subItem->setText(0,"ROOT");
                createOctreeRep(subItem,(Ocnode*)obj);
                item->addChild(subItem);
            }

            ui->objectsTree->addTopLevelItem(item);
        }
    }   
}

void MainWindow::createOctreeRep(QTreeWidgetItem *item,Ocnode *node) {
    if (node->getChildren() != NULL) {
        for (int i=0;i<8;i++) {
            QTreeWidgetItem *subItem = new QTreeWidgetItem();

            switch (node->getChild(i)->getState()) {
            case -1:
                subItem->setText(0,"WHITE");
                break;
            case 1:
                subItem->setText(0,"BLACK");
                break;
            case 0:
                subItem->setText(0,"GRAY");
                createOctreeRep(subItem,node->getChild(i));
                break;
            }

            item->addChild(subItem);
        }
    }
}
