/********************************************************************************
** Form generated from reading UI file 'csgdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSGDIALOG_H
#define UI_CSGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

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
            CsgDialog->setObjectName(QStringLiteral("CsgDialog"));
        CsgDialog->resize(380, 166);
        verticalLayout = new QVBoxLayout(CsgDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(CsgDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        objASpn = new QSpinBox(CsgDialog);
        objASpn->setObjectName(QStringLiteral("objASpn"));

        horizontalLayout_2->addWidget(objASpn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(CsgDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        objBSpn = new QSpinBox(CsgDialog);
        objBSpn->setObjectName(QStringLiteral("objBSpn"));

        horizontalLayout_3->addWidget(objBSpn);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(CsgDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        operationCB = new QComboBox(CsgDialog);
        operationCB->setObjectName(QStringLiteral("operationCB"));

        horizontalLayout->addWidget(operationCB);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(CsgDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        CsgDialog->setWindowTitle(QApplication::translate("CsgDialog", "Insert Compound Object", 0));
        label->setText(QApplication::translate("CsgDialog", "Object A", 0));
        label_2->setText(QApplication::translate("CsgDialog", "Object B", 0));
        label_3->setText(QApplication::translate("CsgDialog", "Operation", 0));
        operationCB->clear();
        operationCB->insertItems(0, QStringList()
         << QApplication::translate("CsgDialog", "Union", 0)
         << QApplication::translate("CsgDialog", "Intersection", 0)
         << QApplication::translate("CsgDialog", "Difference", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class CsgDialog: public Ui_CsgDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSGDIALOG_H
