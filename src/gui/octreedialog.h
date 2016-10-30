#ifndef OCTREEDIALOG_H
#define OCTREEDIALOG_H

#include <QDialog>

namespace Ui {
class OctreeDialog;
}

class OctreeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OctreeDialog(QWidget *parent = 0, int *targetId = NULL, int *octreeDepth = NULL, bool *ok = NULL);
    ~OctreeDialog();

    bool getOk() const;

    int getOperation() const;

    static const int OCTREE = 0;
    static const int EMPTY_OCTREE = 1;
    static const int CLASSIFY = 2;
    static const int INTERSECTION = 3;

    double getOctreeSize() const;

private slots:
    void on_insertEmptyOctreeBtn_accepted();

    void on_insertOctreeBtn_accepted();

    void on_classifyOctree_accepted();

    void on_intersectionBtn_accepted();

private:
    Ui::OctreeDialog *ui;
    int *targetId;
    int *octreeDepth;
    double octreeSize;
    bool ok;
    int operation;

};

#endif // OCTREEDIALOG_H
