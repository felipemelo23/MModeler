/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <gui/gldisplaywidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenOF;
    QAction *actionSaveOF;
    QAction *actionOpenSF;
    QAction *actionSaveSF;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *visTab;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *insertSphereBtn;
    QPushButton *insertBoxBtn;
    QPushButton *insertCylinderBtn;
    QPushButton *insertOctreeBtn;
    QPushButton *insertCSGBtn;
    glDisplayWidget *display;
    QVBoxLayout *verticalLayout_8;
    QTreeWidget *objectsTree;
    QVBoxLayout *verticalLayout_7;
    QPushButton *translBtn;
    QPushButton *rotBtn;
    QPushButton *sclBtn;
    QPushButton *delBtn;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *cmdFeed;
    QWidget *renderTab;
    QHBoxLayout *horizontalLayout_9;
    QLabel *canvas;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *xCamPos;
    QDoubleSpinBox *yCamPos;
    QDoubleSpinBox *zCamPos;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *xCamLookAt;
    QDoubleSpinBox *yCamLookAt;
    QDoubleSpinBox *zCamLookAt;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QDoubleSpinBox *xCamVUp;
    QDoubleSpinBox *yCamVUp;
    QDoubleSpinBox *zCamVUp;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QDoubleSpinBox *ambLightRed;
    QDoubleSpinBox *ambLightGreen;
    QDoubleSpinBox *ambLightBlue;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_8;
    QDoubleSpinBox *xLightPos;
    QDoubleSpinBox *yLightPos;
    QDoubleSpinBox *zLightPos;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QDoubleSpinBox *pontualLightRed;
    QDoubleSpinBox *pontualLightGreen;
    QDoubleSpinBox *pontualLightBlue;
    QPushButton *renderBtn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen;
    QMenu *menuSave;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(688, 520);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/root/gui/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpenOF = new QAction(MainWindow);
        actionOpenOF->setObjectName(QString::fromUtf8("actionOpenOF"));
        actionSaveOF = new QAction(MainWindow);
        actionSaveOF->setObjectName(QString::fromUtf8("actionSaveOF"));
        actionOpenSF = new QAction(MainWindow);
        actionOpenSF->setObjectName(QString::fromUtf8("actionOpenSF"));
        actionSaveSF = new QAction(MainWindow);
        actionSaveSF->setObjectName(QString::fromUtf8("actionSaveSF"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        visTab = new QWidget();
        visTab->setObjectName(QString::fromUtf8("visTab"));
        verticalLayout_9 = new QVBoxLayout(visTab);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        insertSphereBtn = new QPushButton(visTab);
        insertSphereBtn->setObjectName(QString::fromUtf8("insertSphereBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(insertSphereBtn->sizePolicy().hasHeightForWidth());
        insertSphereBtn->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(insertSphereBtn);

        insertBoxBtn = new QPushButton(visTab);
        insertBoxBtn->setObjectName(QString::fromUtf8("insertBoxBtn"));
        sizePolicy.setHeightForWidth(insertBoxBtn->sizePolicy().hasHeightForWidth());
        insertBoxBtn->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(insertBoxBtn);

        insertCylinderBtn = new QPushButton(visTab);
        insertCylinderBtn->setObjectName(QString::fromUtf8("insertCylinderBtn"));
        sizePolicy.setHeightForWidth(insertCylinderBtn->sizePolicy().hasHeightForWidth());
        insertCylinderBtn->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(insertCylinderBtn);

        insertOctreeBtn = new QPushButton(visTab);
        insertOctreeBtn->setObjectName(QString::fromUtf8("insertOctreeBtn"));
        sizePolicy.setHeightForWidth(insertOctreeBtn->sizePolicy().hasHeightForWidth());
        insertOctreeBtn->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(insertOctreeBtn);

        insertCSGBtn = new QPushButton(visTab);
        insertCSGBtn->setObjectName(QString::fromUtf8("insertCSGBtn"));
        sizePolicy.setHeightForWidth(insertCSGBtn->sizePolicy().hasHeightForWidth());
        insertCSGBtn->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(insertCSGBtn);


        horizontalLayout->addLayout(verticalLayout_3);

        display = new glDisplayWidget(visTab);
        display->setObjectName(QString::fromUtf8("display"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
        display->setSizePolicy(sizePolicy1);
        display->setMinimumSize(QSize(400, 300));
        display->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout->addWidget(display);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        objectsTree = new QTreeWidget(visTab);
        objectsTree->setObjectName(QString::fromUtf8("objectsTree"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(objectsTree->sizePolicy().hasHeightForWidth());
        objectsTree->setSizePolicy(sizePolicy2);
        objectsTree->setMinimumSize(QSize(150, 0));
        objectsTree->setMaximumSize(QSize(300, 16777215));
        objectsTree->setAnimated(true);

        verticalLayout_8->addWidget(objectsTree);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        translBtn = new QPushButton(visTab);
        translBtn->setObjectName(QString::fromUtf8("translBtn"));

        verticalLayout_7->addWidget(translBtn);

        rotBtn = new QPushButton(visTab);
        rotBtn->setObjectName(QString::fromUtf8("rotBtn"));

        verticalLayout_7->addWidget(rotBtn);

        sclBtn = new QPushButton(visTab);
        sclBtn->setObjectName(QString::fromUtf8("sclBtn"));

        verticalLayout_7->addWidget(sclBtn);

        delBtn = new QPushButton(visTab);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));

        verticalLayout_7->addWidget(delBtn);


        verticalLayout_8->addLayout(verticalLayout_7);


        horizontalLayout->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cmdFeed = new QLineEdit(visTab);
        cmdFeed->setObjectName(QString::fromUtf8("cmdFeed"));
        cmdFeed->setEnabled(false);
        cmdFeed->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        cmdFeed->setFont(font);
        cmdFeed->setAutoFillBackground(false);
//        cmdFeed->setClearButtonEnabled(true);

        horizontalLayout_3->addWidget(cmdFeed);


        verticalLayout_9->addLayout(horizontalLayout_3);

        tabWidget->addTab(visTab, QString());
        renderTab = new QWidget();
        renderTab->setObjectName(QString::fromUtf8("renderTab"));
        renderTab->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_9 = new QHBoxLayout(renderTab);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        canvas = new QLabel(renderTab);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy3);
        canvas->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(canvas);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox = new QGroupBox(renderTab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        groupBox->setMinimumSize(QSize(50, 0));
        groupBox->setMaximumSize(QSize(250, 16777215));
        groupBox->setAutoFillBackground(false);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        xCamPos = new QDoubleSpinBox(groupBox);
        xCamPos->setObjectName(QString::fromUtf8("xCamPos"));
        xCamPos->setDecimals(4);
        xCamPos->setMinimum(-10000);
        xCamPos->setMaximum(10000);
        xCamPos->setSingleStep(0.1);
        xCamPos->setValue(2);

        horizontalLayout_2->addWidget(xCamPos);

        yCamPos = new QDoubleSpinBox(groupBox);
        yCamPos->setObjectName(QString::fromUtf8("yCamPos"));
        yCamPos->setDecimals(4);
        yCamPos->setMinimum(-10000);
        yCamPos->setMaximum(10000);
        yCamPos->setSingleStep(0.1);
        yCamPos->setValue(2);

        horizontalLayout_2->addWidget(yCamPos);

        zCamPos = new QDoubleSpinBox(groupBox);
        zCamPos->setObjectName(QString::fromUtf8("zCamPos"));
        zCamPos->setDecimals(4);
        zCamPos->setMinimum(-10000);
        zCamPos->setMaximum(10000);
        zCamPos->setSingleStep(0.1);
        zCamPos->setValue(3);

        horizontalLayout_2->addWidget(zCamPos);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        xCamLookAt = new QDoubleSpinBox(groupBox);
        xCamLookAt->setObjectName(QString::fromUtf8("xCamLookAt"));
        xCamLookAt->setDecimals(4);
        xCamLookAt->setMinimum(-10000);
        xCamLookAt->setMaximum(10000);
        xCamLookAt->setSingleStep(0.1);

        horizontalLayout_4->addWidget(xCamLookAt);

        yCamLookAt = new QDoubleSpinBox(groupBox);
        yCamLookAt->setObjectName(QString::fromUtf8("yCamLookAt"));
        yCamLookAt->setDecimals(4);
        yCamLookAt->setMinimum(-10000);
        yCamLookAt->setMaximum(10000);
        yCamLookAt->setSingleStep(0.1);

        horizontalLayout_4->addWidget(yCamLookAt);

        zCamLookAt = new QDoubleSpinBox(groupBox);
        zCamLookAt->setObjectName(QString::fromUtf8("zCamLookAt"));
        zCamLookAt->setDecimals(4);
        zCamLookAt->setMinimum(-10000);
        zCamLookAt->setMaximum(10000);
        zCamLookAt->setSingleStep(0.1);

        horizontalLayout_4->addWidget(zCamLookAt);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        xCamVUp = new QDoubleSpinBox(groupBox);
        xCamVUp->setObjectName(QString::fromUtf8("xCamVUp"));
        xCamVUp->setDecimals(4);
        xCamVUp->setMinimum(-10000);
        xCamVUp->setMaximum(10000);
        xCamVUp->setSingleStep(0.1);

        horizontalLayout_5->addWidget(xCamVUp);

        yCamVUp = new QDoubleSpinBox(groupBox);
        yCamVUp->setObjectName(QString::fromUtf8("yCamVUp"));
        yCamVUp->setDecimals(4);
        yCamVUp->setMinimum(-10000);
        yCamVUp->setMaximum(10000);
        yCamVUp->setSingleStep(0.1);
        yCamVUp->setValue(1);

        horizontalLayout_5->addWidget(yCamVUp);

        zCamVUp = new QDoubleSpinBox(groupBox);
        zCamVUp->setObjectName(QString::fromUtf8("zCamVUp"));
        zCamVUp->setDecimals(4);
        zCamVUp->setMinimum(-10000);
        zCamVUp->setMaximum(10000);
        zCamVUp->setSingleStep(0.1);

        horizontalLayout_5->addWidget(zCamVUp);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_10->addWidget(groupBox);

        groupBox_2 = new QGroupBox(renderTab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy4.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy4);
        groupBox_2->setMaximumSize(QSize(250, 16777215));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ambLightRed = new QDoubleSpinBox(groupBox_2);
        ambLightRed->setObjectName(QString::fromUtf8("ambLightRed"));
        ambLightRed->setDecimals(4);
        ambLightRed->setMaximum(1);
        ambLightRed->setSingleStep(0.01);
        ambLightRed->setValue(1);

        horizontalLayout_6->addWidget(ambLightRed);

        ambLightGreen = new QDoubleSpinBox(groupBox_2);
        ambLightGreen->setObjectName(QString::fromUtf8("ambLightGreen"));
        ambLightGreen->setDecimals(4);
        ambLightGreen->setMaximum(1);
        ambLightGreen->setSingleStep(0.01);
        ambLightGreen->setValue(1);

        horizontalLayout_6->addWidget(ambLightGreen);

        ambLightBlue = new QDoubleSpinBox(groupBox_2);
        ambLightBlue->setObjectName(QString::fromUtf8("ambLightBlue"));
        ambLightBlue->setDecimals(4);
        ambLightBlue->setMaximum(1);
        ambLightBlue->setSingleStep(0.01);
        ambLightBlue->setValue(1);

        horizontalLayout_6->addWidget(ambLightBlue);


        verticalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_10->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(renderTab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy4.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy4);
        groupBox_3->setMaximumSize(QSize(250, 16777215));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_6->addWidget(label_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        xLightPos = new QDoubleSpinBox(groupBox_3);
        xLightPos->setObjectName(QString::fromUtf8("xLightPos"));
        xLightPos->setDecimals(4);
        xLightPos->setMinimum(-10000);
        xLightPos->setMaximum(10000);
        xLightPos->setSingleStep(0.1);
        xLightPos->setValue(0);

        horizontalLayout_8->addWidget(xLightPos);

        yLightPos = new QDoubleSpinBox(groupBox_3);
        yLightPos->setObjectName(QString::fromUtf8("yLightPos"));
        yLightPos->setDecimals(4);
        yLightPos->setMinimum(-10000);
        yLightPos->setMaximum(10000);
        yLightPos->setSingleStep(0.1);
        yLightPos->setValue(5);

        horizontalLayout_8->addWidget(yLightPos);

        zLightPos = new QDoubleSpinBox(groupBox_3);
        zLightPos->setObjectName(QString::fromUtf8("zLightPos"));
        zLightPos->setDecimals(4);
        zLightPos->setMinimum(-10000);
        zLightPos->setMaximum(10000);
        zLightPos->setSingleStep(0.1);
        zLightPos->setValue(5);

        horizontalLayout_8->addWidget(zLightPos);


        verticalLayout_6->addLayout(horizontalLayout_8);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_6->addWidget(label_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pontualLightRed = new QDoubleSpinBox(groupBox_3);
        pontualLightRed->setObjectName(QString::fromUtf8("pontualLightRed"));
        pontualLightRed->setDecimals(4);
        pontualLightRed->setMaximum(1);
        pontualLightRed->setSingleStep(0.01);
        pontualLightRed->setValue(1);

        horizontalLayout_7->addWidget(pontualLightRed);

        pontualLightGreen = new QDoubleSpinBox(groupBox_3);
        pontualLightGreen->setObjectName(QString::fromUtf8("pontualLightGreen"));
        pontualLightGreen->setDecimals(4);
        pontualLightGreen->setMaximum(1);
        pontualLightGreen->setSingleStep(0.01);
        pontualLightGreen->setValue(1);

        horizontalLayout_7->addWidget(pontualLightGreen);

        pontualLightBlue = new QDoubleSpinBox(groupBox_3);
        pontualLightBlue->setObjectName(QString::fromUtf8("pontualLightBlue"));
        pontualLightBlue->setDecimals(4);
        pontualLightBlue->setMaximum(1);
        pontualLightBlue->setSingleStep(0.01);
        pontualLightBlue->setValue(1);

        horizontalLayout_7->addWidget(pontualLightBlue);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout_10->addWidget(groupBox_3);

        renderBtn = new QPushButton(renderTab);
        renderBtn->setObjectName(QString::fromUtf8("renderBtn"));

        verticalLayout_10->addWidget(renderBtn);


        horizontalLayout_9->addLayout(verticalLayout_10);

        tabWidget->addTab(renderTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        menuSave = new QMenu(menuFile);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(menuSave->menuAction());
        menuOpen->addAction(actionOpenSF);
        menuOpen->addAction(actionOpenOF);
        menuSave->addAction(actionSaveSF);
        menuSave->addAction(actionSaveOF);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MModeler", 0, QApplication::UnicodeUTF8));
        actionOpenOF->setText(QApplication::translate("MainWindow", "Octrees File", 0, QApplication::UnicodeUTF8));
        actionSaveOF->setText(QApplication::translate("MainWindow", "Octrees File", 0, QApplication::UnicodeUTF8));
        actionOpenSF->setText(QApplication::translate("MainWindow", "Scene File", 0, QApplication::UnicodeUTF8));
        actionSaveSF->setText(QApplication::translate("MainWindow", "Scene File", 0, QApplication::UnicodeUTF8));
        insertSphereBtn->setText(QApplication::translate("MainWindow", "Sphere", 0, QApplication::UnicodeUTF8));
        insertBoxBtn->setText(QApplication::translate("MainWindow", "Box", 0, QApplication::UnicodeUTF8));
        insertCylinderBtn->setText(QApplication::translate("MainWindow", "Cylinder", 0, QApplication::UnicodeUTF8));
        insertOctreeBtn->setText(QApplication::translate("MainWindow", "Octree", 0, QApplication::UnicodeUTF8));
        insertCSGBtn->setText(QApplication::translate("MainWindow", "CSG", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = objectsTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Objects", 0, QApplication::UnicodeUTF8));
        translBtn->setText(QApplication::translate("MainWindow", "Translate", 0, QApplication::UnicodeUTF8));
        rotBtn->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        sclBtn->setText(QApplication::translate("MainWindow", "Scale", 0, QApplication::UnicodeUTF8));
        delBtn->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        cmdFeed->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(visTab), QApplication::translate("MainWindow", "Visualization", 0, QApplication::UnicodeUTF8));
        canvas->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Camera", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Look At", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "View Up", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ambient Light", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Pontual Light", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Color", 0, QApplication::UnicodeUTF8));
        renderBtn->setText(QApplication::translate("MainWindow", "Render", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(renderTab), QApplication::translate("MainWindow", "Rendered", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuOpen->setTitle(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        menuSave->setTitle(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
