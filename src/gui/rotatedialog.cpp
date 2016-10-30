#include "rotatedialog.h"
#include "ui_rotatedialog.h"

RotateDialog::RotateDialog(QWidget *parent, double *amount, QString *axis) :
    QDialog(parent),
    ui(new Ui::RotateDialog)
{
    ui->setupUi(this);
    this->amount = amount;
    this->axis = axis;
}

RotateDialog::~RotateDialog()
{
    delete ui;
}

void RotateDialog::on_buttonBox_accepted()
{
    *amount = ui->doubleSpinBox->value();
    *axis = ui->comboBox->currentText();
    ok = true;
}

void RotateDialog::on_buttonBox_rejected()
{
    ok = false;
}

bool RotateDialog::getOk() const
{
    return ok;
}
