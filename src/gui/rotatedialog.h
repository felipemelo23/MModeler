#ifndef ROTATEDIALOG_H
#define ROTATEDIALOG_H

#include <QDialog>

namespace Ui {
class RotateDialog;
}

class RotateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RotateDialog(QWidget *parent = 0, double *amount = NULL, QString *axis = NULL);
    ~RotateDialog();

    bool getOk() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::RotateDialog *ui;
    double *amount;
    QString *axis;

    bool ok;
};

#endif // ROTATEDIALOG_H
