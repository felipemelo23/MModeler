/********************************************************************************
** Form generated from reading UI file 'translatedialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATEDIALOG_H
#define UI_TRANSLATEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TranslateDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *x;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *y;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *z;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TranslateDialog)
    {
        if (TranslateDialog->objectName().isEmpty())
            TranslateDialog->setObjectName(QString::fromUtf8("TranslateDialog"));
        TranslateDialog->resize(418, 84);
        verticalLayout = new QVBoxLayout(TranslateDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(TranslateDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        x = new QDoubleSpinBox(TranslateDialog);
        x->setObjectName(QString::fromUtf8("x"));
        x->setDecimals(4);
        x->setMinimum(-10000);
        x->setMaximum(10000);
        x->setSingleStep(0.1);

        horizontalLayout->addWidget(x);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(TranslateDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        y = new QDoubleSpinBox(TranslateDialog);
        y->setObjectName(QString::fromUtf8("y"));
        y->setDecimals(4);
        y->setMinimum(-10000);
        y->setMaximum(10000);
        y->setSingleStep(0.1);

        horizontalLayout_2->addWidget(y);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(TranslateDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        z = new QDoubleSpinBox(TranslateDialog);
        z->setObjectName(QString::fromUtf8("z"));
        z->setDecimals(4);
        z->setMinimum(-10000);
        z->setMaximum(10000);
        z->setSingleStep(0.1);

        horizontalLayout_3->addWidget(z);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(TranslateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TranslateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TranslateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TranslateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TranslateDialog);
    } // setupUi

    void retranslateUi(QDialog *TranslateDialog)
    {
        TranslateDialog->setWindowTitle(QApplication::translate("TranslateDialog", "Translate", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TranslateDialog", "x:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TranslateDialog", "y:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TranslateDialog", "z:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TranslateDialog: public Ui_TranslateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATEDIALOG_H
