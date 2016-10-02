#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtreewidget.h>
#include <gui/cmd_interpreter/commandinterpreter.h>
#include <objects/ocnode.h>

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

    void updateObjectsTree();
    void createOctreeRep(QTreeWidgetItem *item, Ocnode *node);
private slots:
    void feedCommand();
    void openOctreeFile();
    void saveOctreeFile();
};

#endif // MAINWINDOW_H
