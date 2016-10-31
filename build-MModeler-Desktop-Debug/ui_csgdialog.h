/********************************************************************************
** Form generated from reading UI file 'csgdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSGDIALOG_H
#define UI_CSGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CsgDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *objASpn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *objBSpn;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *operationCB;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CsgDialog)
    {
        if (CsgDialog->objectName().isEmpty())
            CsgDialog->setObjectName(QString::fromUtf8("CsgDialog"));
        CsgDialog->resize(380, 166);
        verticalLayout = new QVBoxLayout(CsgDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(CsgDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        objASpn = new QSpinBox(CsgDialog);
        objASpn->setObjectName(QString::fromUtf8("objASpn"));

        horizontalLayout_2->addWidget(objASpn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(CsgDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        objBSpn = new QSpinBox(CsgDialog);
        objBSpn->setObjectName(QString::fromUtf8("objBSpn"));

        horizontalLayout_3->addWidget(objBSpn);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(CsgDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        operationCB = new QComboBox(CsgDialog);
        operationCB->setObjectName(QString::fromUtf8("operationCB"));

        horizontalLayout->addWidget(operationCB);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(CsgDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CsgDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CsgDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CsgDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CsgDialog);
    } // setupUi

    void retranslateUi(QDialog *CsgDialog)
    {
        CsgDialog->setWindowTitle(QApplication::translate("CsgDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CsgDialog", "Object A", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CsgDialog", "Object B", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CsgDialog", "Operation", 0, QApplication::UnicodeUTF8));
        operationCB->clear();
        operationCB->insertItems(0, QStringList()
         << QApplication::translate("CsgDialog", "Union", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CsgDialog", "Intersection", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CsgDialog", "Difference", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class CsgDialog: public Ui_CsgDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSGDIALOG_H
