/********************************************************************************
** Form generated from reading UI file 'rotatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATEDIALOG_H
#define UI_ROTATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RotateDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RotateDialog)
    {
        if (RotateDialog->objectName().isEmpty())
            RotateDialog->setObjectName(QStringLiteral("RotateDialog"));
        RotateDialog->resize(321, 88);
        verticalLayout = new QVBoxLayout(RotateDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(RotateDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(RotateDialog);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(-360);
        doubleSpinBox->setMaximum(360);
        doubleSpinBox->setSingleStep(5);

        horizontalLayout_2->addWidget(doubleSpinBox);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(RotateDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(RotateDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(comboBox);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(RotateDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(RotateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RotateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RotateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RotateDialog);
    } // setupUi

    void retranslateUi(QDialog *RotateDialog)
    {
        RotateDialog->setWindowTitle(QApplication::translate("RotateDialog", "Rotate", 0));
        label->setText(QApplication::translate("RotateDialog", "Amount", 0));
        label_2->setText(QApplication::translate("RotateDialog", "Axis", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("RotateDialog", "x", 0)
         << QApplication::translate("RotateDialog", "y", 0)
         << QApplication::translate("RotateDialog", "z", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class RotateDialog: public Ui_RotateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATEDIALOG_H
