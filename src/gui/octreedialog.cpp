#include "octreedialog.h"
#include "ui_octreedialog.h"
#include <iostream>

using namespace std;

OctreeDialog::OctreeDialog(QWidget *parent, int *targetId, int *octreeDepth, bool *ok) :
    QDialog(parent),
    ui(new Ui::OctreeDialog)
{
    ui->setupUi(this);
    this->targetId = targetId;
    this->octreeDepth = octreeDepth;
    this->ok = false;
}

OctreeDialog::~OctreeDialog()
{
    delete ui;
}

bool OctreeDialog::getOk() const
{
    return ok;
}

void OctreeDialog::on_insertEmptyOctreeBtn_accepted()
{
    cout << "a" << endl;
    operation = EMPTY_OCTREE;
    octreeSize = ui->octreeSize->value();
    ok = true;
}

void OctreeDialog::on_insertOctreeBtn_accepted()
{
    *targetId = ui->targetIdSpn->value();
    *octreeDepth = ui->octreeDepthSpn->value();
    ok = true;
    operation = OCTREE;
}

void OctreeDialog::on_classifyOctree_accepted()
{

}

void OctreeDialog::on_intersectionBtn_accepted()
{

}

double OctreeDialog::getOctreeSize() const
{
    return octreeSize;
}

int OctreeDialog::getOperation() const
{
    return operation;
}
