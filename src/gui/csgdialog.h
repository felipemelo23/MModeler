#ifndef CSGDIALOG_H
#define CSGDIALOG_H

#include <QDialog>

namespace Ui {
class CsgDialog;
}

class CsgDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CsgDialog(QWidget *parent = 0, int *objA = NULL, int *objB = NULL, int *op = NULL);
    ~CsgDialog();

    bool getOk() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CsgDialog *ui;

    int *objA;
    int *objB;
    int *op;

    bool ok;
};

#endif // CSGDIALOG_H
