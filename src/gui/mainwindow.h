#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtreewidget.h>
#include <gui/cmd_interpreter/commandinterpreter.h>
#include <objects/ocnode.h>
#include <QThread>

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
private slots:
    void feedCommand();
    void openOctreeFile();
    void saveOctreeFile();
    void openSceneFile();
    void saveSceneFile();
    void on_objectsTree_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_insertSphereBtn_clicked();
    void on_insertPrismBtn_clicked();
    void on_insertPyramidBtn_clicked();
    void on_delBtn_clicked();
};

#endif // MAINWINDOW_H
