#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtreewidget.h>
#include <gui/cmd_interpreter/commandinterpreter.h>
#include <objects/ocnode.h>
#include <QThread>
#include <rendering/render.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CommandInterpreter *interpreter;
    ObjectsManager *objects;

    vector<QString> commandList;

    void updateObjectsTree();
    void createOctreeRep(QTreeWidgetItem *item, Ocnode *node);
    void createCSGRep(QTreeWidgetItem *item, Object *obj);
private slots:
    void feedCommand();
    void openOctreeFile();
    void saveOctreeFile();
    void openSceneFile();
    void saveSceneFile();
    void openCSGFile();
    void on_objectsTree_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_insertSphereBtn_clicked();
    void on_delBtn_clicked();
    void on_renderBtn_clicked();
    void on_insertOctreeBtn_clicked();
    void on_objectsTree_itemClicked(QTreeWidgetItem *item, int column);
    void on_translBtn_clicked();
    void on_sclBtn_clicked();
    void on_rotBtn_clicked();
    void on_insertCSGBtn_clicked();
    void on_insertBoxBtn_clicked();
    void on_insertCylinderBtn_clicked();
    void on_cmdFeed_returnPressed();
    void on_insertPyramidBtn_clicked();
    void on_insertPrismBtn_clicked();
};

#endif // MAINWINDOW_H
