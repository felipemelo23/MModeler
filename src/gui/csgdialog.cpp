#include "csgdialog.h"
#include "ui_csgdialog.h"

CsgDialog::CsgDialog(QWidget *parent, int *objA, int *objB, int *op) :
    QDialog(parent),
    ui(new Ui::CsgDialog)
{
    ui->setupUi(this);
    this->objA = objA;
    this->objB = objB;
    this->op = op;

    ok = false;
}

CsgDialog::~CsgDialog()
{
    delete ui;
}

void CsgDialog::on_buttonBox_accepted()
{
    *objA = ui->objASpn->value();
    *objB = ui->objBSpn->value();
    *op = ui->operationCB->currentIndex();

    ok = true;
}

bool CsgDialog::getOk() const
{
    return ok;
}
