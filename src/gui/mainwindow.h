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
};

#endif // MAINWINDOW_H
