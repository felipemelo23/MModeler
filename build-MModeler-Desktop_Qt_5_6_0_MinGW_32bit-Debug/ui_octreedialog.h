/********************************************************************************
** Form generated from reading UI file 'octreedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OCTREEDIALOG_H
#define UI_OCTREEDIALOG_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OctreeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *targetIdSpn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *octreeDepthSpn;
    QDialogButtonBox *insertOctreeBtn;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *octreeSize;
    QDialogButtonBox *insertEmptyOctreeBtn;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *targetOctreeClssfSpn;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *targetObjClssfSpn;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *octreeDepthClssfSpn;
    QDialogButtonBox *classifyOctree;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *targetOctreeASpn;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpinBox *targetOctreeBSpn;
    QDialogButtonBox *intersectionBtn;

    void setupUi(QDialog *OctreeDialog)
    {
        if (OctreeDialog->objectName().isEmpty())
            OctreeDialog->setObjectName(QStringLiteral("OctreeDialog"));
        OctreeDialog->resize(402, 181);
        verticalLayout = new QVBoxLayout(OctreeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(OctreeDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        targetIdSpn = new QSpinBox(tab);
        targetIdSpn->setObjectName(QStringLiteral("targetIdSpn"));

        horizontalLayout->addWidget(targetIdSpn);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        octreeDepthSpn = new QSpinBox(tab);
        octreeDepthSpn->setObjectName(QStringLiteral("octreeDepthSpn"));
        octreeDepthSpn->setMinimum(2);
        octreeDepthSpn->setValue(4);

        horizontalLayout_2->addWidget(octreeDepthSpn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        insertOctreeBtn = new QDialogButtonBox(tab);
        insertOctreeBtn->setObjectName(QStringLiteral("insertOctreeBtn"));
        insertOctreeBtn->setOrientation(Qt::Horizontal);
        insertOctreeBtn->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(insertOctreeBtn);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        octreeSize = new QDoubleSpinBox(tab_2);
        octreeSize->setObjectName(QStringLiteral("octreeSize"));
        octreeSize->setDecimals(4);

        horizontalLayout_3->addWidget(octreeSize);


        verticalLayout_3->addLayout(horizontalLayout_3);

        insertEmptyOctreeBtn = new QDialogButtonBox(tab_2);
        insertEmptyOctreeBtn->setObjectName(QStringLiteral("insertEmptyOctreeBtn"));
        insertEmptyOctreeBtn->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(insertEmptyOctreeBtn);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        targetOctreeClssfSpn = new QSpinBox(tab_3);
        targetOctreeClssfSpn->setObjectName(QStringLiteral("targetOctreeClssfSpn"));

        horizontalLayout_6->addWidget(targetOctreeClssfSpn);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        targetObjClssfSpn = new QSpinBox(tab_3);
        targetObjClssfSpn->setObjectName(QStringLiteral("targetObjClssfSpn"));

        horizontalLayout_5->addWidget(targetObjClssfSpn);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        octreeDepthClssfSpn = new QSpinBox(tab_3);
        octreeDepthClssfSpn->setObjectName(QStringLiteral("octreeDepthClssfSpn"));
        octreeDepthClssfSpn->setMinimum(2);
        octreeDepthClssfSpn->setValue(4);

        horizontalLayout_4->addWidget(octreeDepthClssfSpn);


        verticalLayout_4->addLayout(horizontalLayout_4);

        classifyOctree = new QDialogButtonBox(tab_3);
        classifyOctree->setObjectName(QStringLiteral("classifyOctree"));
        classifyOctree->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(classifyOctree);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_5 = new QVBoxLayout(tab_4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        targetOctreeASpn = new QSpinBox(tab_4);
        targetOctreeASpn->setObjectName(QStringLiteral("targetOctreeASpn"));

        horizontalLayout_7->addWidget(targetOctreeASpn);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        targetOctreeBSpn = new QSpinBox(tab_4);
        targetOctreeBSpn->setObjectName(QStringLiteral("targetOctreeBSpn"));

        horizontalLayout_8->addWidget(targetOctreeBSpn);


        verticalLayout_5->addLayout(horizontalLayout_8);

        intersectionBtn = new QDialogButtonBox(tab_4);
        intersectionBtn->setObjectName(QStringLiteral("intersectionBtn"));
        intersectionBtn->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(intersectionBtn);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(OctreeDialog);
        QObject::connect(insertOctreeBtn, SIGNAL(accepted()), OctreeDialog, SLOT(accept()));
        QObject::connect(insertOctreeBtn, SIGNAL(rejected()), OctreeDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OctreeDialog);
    } // setupUi

    void retranslateUi(QDialog *OctreeDialog)
    {
        OctreeDialog->setWindowTitle(QApplication::translate("OctreeDialog", "Insert Octree", 0));
        label->setText(QApplication::translate("OctreeDialog", "Target Object", 0));
        label_2->setText(QApplication::translate("OctreeDialog", "Depth", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("OctreeDialog", "Insert Octree", 0));
        label_3->setText(QApplication::translate("OctreeDialog", "Octree Size", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("OctreeDialog", "Insert Empty Octree", 0));
        label_6->setText(QApplication::translate("OctreeDialog", "Target Octree", 0));
        label_5->setText(QApplication::translate("OctreeDialog", "Target Object", 0));
        label_4->setText(QApplication::translate("OctreeDialog", "Depth", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("OctreeDialog", "Classify Octree", 0));
        label_7->setText(QApplication::translate("OctreeDialog", "Octree A", 0));
        label_8->setText(QApplication::translate("OctreeDialog", "Octree B", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("OctreeDialog", "Intersection", 0));
    } // retranslateUi

};

namespace Ui {
    class OctreeDialog: public Ui_OctreeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OCTREEDIALOG_H
