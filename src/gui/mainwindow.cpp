#include "csgdialog.h"
#include "mainwindow.h"
#include "octreedialog.h"
#include "rotatedialog.h"
#include "translatedialog.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QInputDialog>
#include <iostream>
#include <objects/compoundobject.h>
#include <objects/mesh/mesh.h>
#include <objects/rbprism.h>
#include <objects/rbpyramid.h>
#include <objects/sphere.h>
#include <rendering/camera.h>
#include <rendering/light.h>
#include <rendering/render.h>
#include <rendering/scene.h>
#include <util/csgfilemanager.h>
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

    connect(ui->actionOpenOF,SIGNAL(triggered(bool)),this,SLOT(openOctreeFile()));
    connect(ui->actionSaveOF,SIGNAL(triggered(bool)),this,SLOT(saveOctreeFile()));
    connect(ui->actionOpenSF,SIGNAL(triggered(bool)),this,SLOT(openSceneFile()));
    connect(ui->actionSaveSF,SIGNAL(triggered(bool)),this,SLOT(saveSceneFile()));
    connect(ui->actionOpenCF,SIGNAL(triggered(bool)),this,SLOT(openCSGFile()));
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

void MainWindow::openCSGFile()
{
    QFileDialog *openDialog = new QFileDialog(this);

    QString filename = openDialog->getOpenFileName(this,tr("Carregar CSG"),"",tr("Arquivo de CSG (*.csg)"));

    if (!filename.isEmpty()) {
        CSGFileManager sfm(filename);

        sfm.load();

        for (int i=0;i<sfm.getCompoundObjs().size();i++) {
            objects->addObject(sfm.getCompoundObjs().at(i));
        }

        updateObjectsTree();
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
            subItem->setText(0, "Position: " + QString::number(obj->getOrigin().getX()) + "," +
                                               QString::number(obj->getOrigin().getY()) + "," +
                                               QString::number(obj->getOrigin().getZ()));
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

            if (obj->getType() == Object::COMPOUND) {
                createCSGRep(subItem,obj);
                item->addChild(subItem);
            }

            if (obj->getType() == Object::MESH) {
                subItem = new QTreeWidgetItem();
                subItem->setText(0,"Vertices: " + QString::number(((Mesh*)obj)->getVertices().size()));
                item->addChild(subItem);
                subItem = new QTreeWidgetItem();
                subItem->setText(0,"Edges: " + QString::number(((Mesh*)obj)->getEdges().size()));
                item->addChild(subItem);
                subItem = new QTreeWidgetItem();
                subItem->setText(0,"Faces: " + QString::number(((Mesh*)obj)->getFaces().size()));
                item->addChild(subItem);
            }

            ui->objectsTree->addTopLevelItem(item);
        }
    }   
}

void MainWindow::createCSGRep(QTreeWidgetItem *item,Object *obj) {
    item->setText(0,obj->getName());

    if (obj->getType() == Object::COMPOUND) {
        QTreeWidgetItem *subItem = new QTreeWidgetItem();
        createCSGRep(subItem,((CompoundObject*)obj)->getObjectA());
        item->addChild(subItem);

        subItem = new QTreeWidgetItem();
        QString operation;
        if (((CompoundObject*)obj)->getOperation() == CompoundObject::INTERSECT) {
            operation = "INTERSECTION";
        } else if (((CompoundObject*)obj)->getOperation() == CompoundObject::DIFFERENCE) {
            operation = "DIFFERENCE";
        } else {
            operation = "UNION";
        }
        subItem->setText(0, operation);
        item->addChild(subItem);

        subItem = new QTreeWidgetItem();
        createCSGRep(subItem,((CompoundObject*)obj)->getObjectB());
        item->addChild(subItem);
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

void MainWindow::on_objectsTree_itemDoubleClicked(QTreeWidgetItem *item, int column)
{

}

void MainWindow::on_insertSphereBtn_clicked()
{
    ui->cmdFeed->setText("insert sphere");
    feedCommand();
}

void MainWindow::on_delBtn_clicked()
{
    bool ok;
    int id = QInputDialog::getInt(this,tr("Deleting Object"),tr("Object Id"),0,0,100,1,&ok);

    if (ok) {
        ui->cmdFeed->setText("del " + QString::number(id));
        feedCommand();
    }
}

void MainWindow::on_renderBtn_clicked()
{
    Scene scene = Scene();

    if (objects->numOfObjects() > 0) {
        for (int i=0;i<objects->numOfObjects();i++) {
            if ((objects->getObject(i)->getType() == Object::SPHERE)||
                (objects->getObject(i)->getType() == Object::RBPRISM)||
                (objects->getObject(i)->getType() == Object::RBPYRAMID)||
                (objects->getObject(i)->getType() == Object::COMPOUND)||
                (objects->getObject(i)->getType() == Object::BOX)||
                (objects->getObject(i)->getType() == Object::CYLINDER))
                scene.addObject(objects->getObject(i));
        }
    }

    AmbientLight ambLight = AmbientLight(Color(ui->ambLightRed->value(),ui->ambLightGreen->value(),ui->ambLightBlue->value()),1);

    Light *light = new Light(Vec3(ui->xLightPos->value(),ui->yLightPos->value(),ui->zLightPos->value()),
                             Color(ui->pontualLightRed->value(),ui->pontualLightGreen->value(),ui->pontualLightBlue->value()),1);

    scene.setAmbLight(ambLight);
    scene.addLight(light);

    Camera camera = Camera(Vec3(ui->xCamPos->value(),ui->yCamPos->value(),ui->zCamPos->value()),
                           Vec3(ui->xCamLookAt->value(),ui->yCamLookAt->value(),ui->zCamLookAt->value()),
                           Vec3(ui->xCamVUp->value(),ui->yCamVUp->value(),ui->zCamVUp->value()));

    double camW = ui->widthSpn->value()/(float) max(ui->widthSpn->value(),ui->heightSpn->value());
    double camH = ui->heightSpn->value()/(float) max(ui->widthSpn->value(),ui->heightSpn->value());

    camera.setMaxPP(Vec2(camW/2,camH/2));
    camera.setMinPP(Vec2(-camW/2,-camH/2));

    QImage *image = new QImage(ui->widthSpn->value(),ui->heightSpn->value(),QImage::Format_RGB32);
    Render render = Render(scene,camera,image);

    render.render();

    ui->canvas->setPixmap(QPixmap::fromImage(*image));
}

void MainWindow::on_insertOctreeBtn_clicked()
{
    int targetId;
    int octreeDepth;
    OctreeDialog *od = new OctreeDialog(this,&targetId,&octreeDepth);

    od->exec();

    if (od->getOk()) {
        switch (od->getOperation()) {
        case OctreeDialog::OCTREE:
            ui->cmdFeed->setText("insert octree " + QString::number(targetId) + " " + QString::number(octreeDepth));
            break;
        case OctreeDialog::EMPTY_OCTREE:
            ui->cmdFeed->setText("insert octree " + QString::number(od->getOctreeSize()));
            break;
        }

        feedCommand();
    }

    delete od;
}

void MainWindow::on_objectsTree_itemClicked(QTreeWidgetItem *item, int column)
{
    if (item->parent() == 0) {
        QStringList test = item->text(0).split(" ");
        int id = ((QString) test.last()).toInt();

        if (!objects->isSelected(id))
            ui->cmdFeed->setText("select " + QString::number(id));
        else
            ui->cmdFeed->setText("deselect " + QString::number(id));

        feedCommand();
    }
}

void MainWindow::on_translBtn_clicked()
{
    double x,y,z;

    TranslateDialog *td = new TranslateDialog(this,&x,&y,&z);

    td->exec();

    if (td->getOk()) {
        ui->cmdFeed->setText("translate " + QString::number(x) + " "
                             + QString::number(y) + " " + QString::number(z));
        feedCommand();
    }

    delete td;
}

void MainWindow::on_sclBtn_clicked()
{
    double x,y,z;

    TranslateDialog *sd = new TranslateDialog(this,&x,&y,&z);

    sd->setScaleDialog();

    sd->exec();

    if (sd->getOk()) {
        ui->cmdFeed->setText("scale " + QString::number(x) + " "
                             + QString::number(y) + " " + QString::number(z));
        feedCommand();
    }

    delete sd;
}

void MainWindow::on_rotBtn_clicked()
{
    double amount;
    QString axis;

    RotateDialog *rd = new RotateDialog(this,&amount,&axis);

    rd->exec();

    if (rd->getOk()) {
        ui->cmdFeed->setText("rotate " + QString::number(amount) + " " + axis);
        feedCommand();
    }

    delete rd;
}

void MainWindow::on_insertCSGBtn_clicked()
{
    int objA, objB, op;

    CsgDialog *cd = new CsgDialog(this,&objA,&objB,&op);

    cd->exec();

    if (cd->getOk()) {
        QString mode;

        if (op == CompoundObject::INTERSECT)
            mode = "i";
        else if (op == CompoundObject::DIFFERENCE)
            mode = "d";
        else
            mode = "u";

        ui->cmdFeed->setText("insert csg " + QString::number(objA) + " " + QString::number(objB) + " " + mode);

        feedCommand();
    }

    delete cd;
}

void MainWindow::on_insertBoxBtn_clicked()
{
    ui->cmdFeed->setText("insert box");
    feedCommand();
}

void MainWindow::on_insertCylinderBtn_clicked()
{
    ui->cmdFeed->setText("insert cylinder");
    feedCommand();
}

void MainWindow::on_cmdFeed_returnPressed()
{
    feedCommand();
}

void MainWindow::on_insertPyramidBtn_clicked()
{
    bool ok;
    int sides = QInputDialog::getInt(this,tr("Insert Pyramid"),tr("Number of Sides"),3,3,20,1,&ok);

    if (ok) {
        ui->cmdFeed->setText("insert pyramid " + QString::number(sides));
        feedCommand();
    }
}

void MainWindow::on_insertPrismBtn_clicked()
{
    bool ok;
    int sides = QInputDialog::getInt(this,tr("Insert Prism"),tr("Number of Sides"),3,3,20,1,&ok);

    if (ok) {
        ui->cmdFeed->setText("insert prism " + QString::number(sides));
        feedCommand();
    }
}
