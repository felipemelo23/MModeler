/********************************************************************************
** Form generated from reading UI file 'translatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATEDIALOG_H
#define UI_TRANSLATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

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
            TranslateDialog->setObjectName(QStringLiteral("TranslateDialog"));
        TranslateDialog->resize(418, 84);
        verticalLayout = new QVBoxLayout(TranslateDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(TranslateDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        x = new QDoubleSpinBox(TranslateDialog);
        x->setObjectName(QStringLiteral("x"));
        x->setDecimals(4);
        x->setMinimum(-10000);
        x->setMaximum(10000);
        x->setSingleStep(0.1);

        horizontalLayout->addWidget(x);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(TranslateDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        y = new QDoubleSpinBox(TranslateDialog);
        y->setObjectName(QStringLiteral("y"));
        y->setDecimals(4);
        y->setMinimum(-10000);
        y->setMaximum(10000);
        y->setSingleStep(0.1);

        horizontalLayout_2->addWidget(y);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(TranslateDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        z = new QDoubleSpinBox(TranslateDialog);
        z->setObjectName(QStringLiteral("z"));
        z->setDecimals(4);
        z->setMinimum(-10000);
        z->setMaximum(10000);
        z->setSingleStep(0.1);

        horizontalLayout_3->addWidget(z);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(TranslateDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        TranslateDialog->setWindowTitle(QApplication::translate("TranslateDialog", "Translate", 0));
        label->setText(QApplication::translate("TranslateDialog", "x:", 0));
        label_2->setText(QApplication::translate("TranslateDialog", "y:", 0));
        label_3->setText(QApplication::translate("TranslateDialog", "z:", 0));
    } // retranslateUi

};

namespace Ui {
    class TranslateDialog: public Ui_TranslateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATEDIALOG_H
