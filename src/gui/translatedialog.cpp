#include "translatedialog.h"
#include "ui_translatedialog.h"

TranslateDialog::TranslateDialog(QWidget *parent, double *x, double *y, double *z) :
    QDialog(parent),
    ui(new Ui::TranslateDialog)
{
    ui->setupUi(this);

    this->x = x;
    this->y = y;
    this->z = z;
    ok = false;
}

TranslateDialog::~TranslateDialog()
{
    delete ui;
}

void TranslateDialog::on_buttonBox_accepted()
{
    *x = ui->x->value();
    *y = ui->y->value();
    *z = ui->z->value();
    ok = true;
}

void TranslateDialog::on_buttonBox_rejected()
{
    ok = false;
}

bool TranslateDialog::getOk() const
{
    return ok;
}

void TranslateDialog::setScaleDialog()
{
    ui->x->setValue(1.0);
    ui->y->setValue(1.0);
    ui->z->setValue(1.0);
    setWindowTitle("Scale");
}
