#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <objects/rbprism.h>
#include <objects/rbpyramid.h>
#include <objects/sphere.h>
#include <rendering/camera.h>
#include <rendering/light.h>
#include <rendering/render.h>
#include <rendering/scene.h>
#include <util/objectquery.h>
#include <util/octreefilemanager.h>
#include <util/scenefilemanager.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objects = new ObjectsManager();
    ui->display->setObjects(objects);
    interpreter = new CommandInterpreter(objects);
    commandList = vector<QString>();

    connect(ui->feedBtn,SIGNAL(clicked(bool)),this,SLOT(feedCommand()));
    connect(ui->actionOpenOF,SIGNAL(triggered(bool)),this,SLOT(openOctreeFile()));
    connect(ui->actionSaveOF,SIGNAL(triggered(bool)),this,SLOT(saveOctreeFile()));
    connect(ui->actionOpenSF,SIGNAL(triggered(bool)),this,SLOT(openSceneFile()));
    connect(ui->actionSaveSF,SIGNAL(triggered(bool)),this,SLOT(saveSceneFile()));

    Object *sphere1 = new Sphere();
    sphere1->setMaterial(new Material(new Color(0.3,0,0),new Color(0.6,0,0),new Color(0.9,0.8,0.8),0.5));
    sphere1->scale(2,2,2);
    sphere1->rotate(90,false,true,false);

    Object *sphere2 = new Sphere();
    sphere2->setMaterial(new Material(new Color(0,0.3,0),new Color(0,0.6,0),new Color(0.8,0.9,0.8),1));
    sphere2->translate(-1,0,0);

    Light *light1 = new Light(new Vec3(10,10,10),new Color(1,1,1),0.8);

    Scene *scene = new Scene();

    scene->addObject(sphere1);
    scene->addObject(sphere2);
    scene->addLight(light1);

    Camera *camera = new Camera(new Vec3(0,0,5),new Vec3(0,0,0),new Vec3(0,1,0));

    QImage *image = new QImage(200,200,QImage().Format_RGB32);

    Render *r = new Render(scene,camera,image);

    r->render();

    ui->canvas->setPixmap(QPixmap::fromImage(*image));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::feedCommand()
{

    if (ui->cmdFeed->text() == "reset") {
        for (int i=objects->numOfObjects()-1;i>=0;--i)
            interpreter->interpretCommand("del " + QString::number(i));
        commandList.clear();
    } else {
        commandList.push_back(ui->cmdFeed->text());
        interpreter->interpretCommand(ui->cmdFeed->text());
    }
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

void MainWindow::openSceneFile()
{
    QFileDialog *openDialog = new QFileDialog(this);

    QString filename = openDialog->getOpenFileName(this,tr("Carregar Cena"),"",tr("Arquivo de Cena (*.scn)"));

    if (!filename.isEmpty()) {
        SceneFileManager sfm(filename);

        sfm.load();

        for (int i=0;i<sfm.getCommandList().size();i++) {
            interpreter->interpretCommand(sfm.getCommandList().at(i));
            commandList.push_back(sfm.getCommandList().at(i));
        }

        updateObjectsTree();
    }
}

void MainWindow::saveSceneFile()
{
    QFileDialog *saveDialog = new QFileDialog(this);

    QString filename = saveDialog->getSaveFileName(this,tr("Salvar Cena"),"",tr("Arquivo de Cena (*.scn)"));

    if (!filename.isEmpty()) {
        SceneFileManager sfm(filename);

        sfm.setCommandList(commandList);

        sfm.save();
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
                subItem->setText(0, "Volume: " + QString::number(ObjectQuery::getVolume(obj,4)) + " uv");
                item->addChild(subItem);
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
