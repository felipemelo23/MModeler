#ifndef TRANSLATEDIALOG_H
#define TRANSLATEDIALOG_H

#include <QDialog>

namespace Ui {
class TranslateDialog;
}

class TranslateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TranslateDialog(QWidget *parent = 0, double *x = NULL, double *y = NULL, double *z = NULL);
    ~TranslateDialog();

    bool getOk() const;

    void setScaleDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::TranslateDialog *ui;
    double *x;
    double *y;
    double *z;
    bool ok;


};

#endif // TRANSLATEDIALOG_H
