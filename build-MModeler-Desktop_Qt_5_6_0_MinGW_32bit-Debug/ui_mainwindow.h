/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <gui/gldisplaywidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenOF;
    QAction *actionSaveOF;
    QAction *actionOpenSF;
    QAction *actionSaveSF;
    QAction *actionOpenCF;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *visTab;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *insertSphereBtn;
    QPushButton *insertBoxBtn;
    QPushButton *insertCylinderBtn;
    QPushButton *insertPyramidBtn;
    QPushButton *insertPrismBtn;
    QPushButton *insertOctreeBtn;
    QPushButton *insertCSGBtn;
    QLabel *label_8;
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
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QSpinBox *widthSpn;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QSpinBox *heightSpn;
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(717, 622);
        QIcon icon;
        icon.addFile(QStringLiteral(":/root/gui/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpenOF = new QAction(MainWindow);
        actionOpenOF->setObjectName(QStringLiteral("actionOpenOF"));
        actionSaveOF = new QAction(MainWindow);
        actionSaveOF->setObjectName(QStringLiteral("actionSaveOF"));
        actionOpenSF = new QAction(MainWindow);
        actionOpenSF->setObjectName(QStringLiteral("actionOpenSF"));
        actionSaveSF = new QAction(MainWindow);
        actionSaveSF->setObjectName(QStringLiteral("actionSaveSF"));
        actionOpenCF = new QAction(MainWindow);
        actionOpenCF->setObjectName(QStringLiteral("actionOpenCF"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        visTab = new QWidget();
        visTab->setObjectName(QStringLiteral("visTab"));
        verticalLayout_9 = new QVBoxLayout(visTab);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        insertSphereBtn = new QPushButton(visTab);
        insertSphereBtn->setObjectName(QStringLiteral("insertSphereBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(insertSphereBtn->sizePolicy().hasHeightForWidth());
        insertSphereBtn->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/root/gui/sphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertSphereBtn->setIcon(icon1);
        insertSphereBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(insertSphereBtn);

        insertBoxBtn = new QPushButton(visTab);
        insertBoxBtn->setObjectName(QStringLiteral("insertBoxBtn"));
        sizePolicy.setHeightForWidth(insertBoxBtn->sizePolicy().hasHeightForWidth());
        insertBoxBtn->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/root/gui/cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertBoxBtn->setIcon(icon2);
        insertBoxBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(insertBoxBtn);

        insertCylinderBtn = new QPushButton(visTab);
        insertCylinderBtn->setObjectName(QStringLiteral("insertCylinderBtn"));
        sizePolicy.setHeightForWidth(insertCylinderBtn->sizePolicy().hasHeightForWidth());
        insertCylinderBtn->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/root/gui/cylinder.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertCylinderBtn->setIcon(icon3);
        insertCylinderBtn->setIconSize(QSize(32, 32));
        insertCylinderBtn->setFlat(false);

        horizontalLayout->addWidget(insertCylinderBtn);

        insertPyramidBtn = new QPushButton(visTab);
        insertPyramidBtn->setObjectName(QStringLiteral("insertPyramidBtn"));
        sizePolicy.setHeightForWidth(insertPyramidBtn->sizePolicy().hasHeightForWidth());
        insertPyramidBtn->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/root/gui/pyramid.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertPyramidBtn->setIcon(icon4);
        insertPyramidBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(insertPyramidBtn);

        insertPrismBtn = new QPushButton(visTab);
        insertPrismBtn->setObjectName(QStringLiteral("insertPrismBtn"));
        sizePolicy.setHeightForWidth(insertPrismBtn->sizePolicy().hasHeightForWidth());
        insertPrismBtn->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/root/gui/prism.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertPrismBtn->setIcon(icon5);
        insertPrismBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(insertPrismBtn);

        insertOctreeBtn = new QPushButton(visTab);
        insertOctreeBtn->setObjectName(QStringLiteral("insertOctreeBtn"));
        sizePolicy.setHeightForWidth(insertOctreeBtn->sizePolicy().hasHeightForWidth());
        insertOctreeBtn->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/root/gui/octree.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertOctreeBtn->setIcon(icon6);
        insertOctreeBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(insertOctreeBtn);

        insertCSGBtn = new QPushButton(visTab);
        insertCSGBtn->setObjectName(QStringLiteral("insertCSGBtn"));
        sizePolicy.setHeightForWidth(insertCSGBtn->sizePolicy().hasHeightForWidth());
        insertCSGBtn->setSizePolicy(sizePolicy);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/root/gui/csg.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertCSGBtn->setIcon(icon7);
        insertCSGBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(insertCSGBtn);

        label_8 = new QLabel(visTab);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);


        verticalLayout_3->addLayout(horizontalLayout);

        display = new glDisplayWidget(visTab);
        display->setObjectName(QStringLiteral("display"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
        display->setSizePolicy(sizePolicy1);
        display->setMinimumSize(QSize(400, 300));
        display->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_3->addWidget(display);


        horizontalLayout_13->addLayout(verticalLayout_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        objectsTree = new QTreeWidget(visTab);
        objectsTree->setObjectName(QStringLiteral("objectsTree"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(objectsTree->sizePolicy().hasHeightForWidth());
        objectsTree->setSizePolicy(sizePolicy2);
        objectsTree->setMinimumSize(QSize(200, 0));
        objectsTree->setMaximumSize(QSize(200, 16777215));
        objectsTree->setAnimated(true);

        verticalLayout_8->addWidget(objectsTree);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        translBtn = new QPushButton(visTab);
        translBtn->setObjectName(QStringLiteral("translBtn"));
        sizePolicy.setHeightForWidth(translBtn->sizePolicy().hasHeightForWidth());
        translBtn->setSizePolicy(sizePolicy);
        translBtn->setMinimumSize(QSize(200, 40));

        verticalLayout_7->addWidget(translBtn);

        rotBtn = new QPushButton(visTab);
        rotBtn->setObjectName(QStringLiteral("rotBtn"));
        sizePolicy.setHeightForWidth(rotBtn->sizePolicy().hasHeightForWidth());
        rotBtn->setSizePolicy(sizePolicy);
        rotBtn->setMinimumSize(QSize(200, 40));

        verticalLayout_7->addWidget(rotBtn);

        sclBtn = new QPushButton(visTab);
        sclBtn->setObjectName(QStringLiteral("sclBtn"));
        sizePolicy.setHeightForWidth(sclBtn->sizePolicy().hasHeightForWidth());
        sclBtn->setSizePolicy(sizePolicy);
        sclBtn->setMinimumSize(QSize(200, 40));

        verticalLayout_7->addWidget(sclBtn);

        delBtn = new QPushButton(visTab);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        sizePolicy.setHeightForWidth(delBtn->sizePolicy().hasHeightForWidth());
        delBtn->setSizePolicy(sizePolicy);
        delBtn->setMinimumSize(QSize(200, 40));

        verticalLayout_7->addWidget(delBtn);


        verticalLayout_8->addLayout(verticalLayout_7);


        horizontalLayout_13->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout_13);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cmdFeed = new QLineEdit(visTab);
        cmdFeed->setObjectName(QStringLiteral("cmdFeed"));
        cmdFeed->setEnabled(true);
        cmdFeed->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        cmdFeed->setFont(font);
        cmdFeed->setAutoFillBackground(false);
        cmdFeed->setClearButtonEnabled(true);

        horizontalLayout_3->addWidget(cmdFeed);


        verticalLayout_9->addLayout(horizontalLayout_3);

        tabWidget->addTab(visTab, QString());
        renderTab = new QWidget();
        renderTab->setObjectName(QStringLiteral("renderTab"));
        renderTab->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_9 = new QHBoxLayout(renderTab);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        canvas = new QLabel(renderTab);
        canvas->setObjectName(QStringLiteral("canvas"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy3);
        canvas->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(canvas);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        groupBox_4 = new QGroupBox(renderTab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy4);
        verticalLayout_11 = new QVBoxLayout(groupBox_4);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        widthSpn = new QSpinBox(groupBox_4);
        widthSpn->setObjectName(QStringLiteral("widthSpn"));
        widthSpn->setMaximum(500);
        widthSpn->setSingleStep(50);
        widthSpn->setValue(300);

        horizontalLayout_10->addWidget(widthSpn);


        horizontalLayout_12->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_11->addWidget(label_7);

        heightSpn = new QSpinBox(groupBox_4);
        heightSpn->setObjectName(QStringLiteral("heightSpn"));
        heightSpn->setMaximum(500);
        heightSpn->setSingleStep(50);
        heightSpn->setValue(200);

        horizontalLayout_11->addWidget(heightSpn);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_11->addLayout(horizontalLayout_12);


        verticalLayout_10->addWidget(groupBox_4);

        groupBox = new QGroupBox(renderTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(50, 0));
        groupBox->setMaximumSize(QSize(250, 16777215));
        groupBox->setAutoFillBackground(false);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        xCamPos = new QDoubleSpinBox(groupBox);
        xCamPos->setObjectName(QStringLiteral("xCamPos"));
        xCamPos->setDecimals(4);
        xCamPos->setMinimum(-10000);
        xCamPos->setMaximum(10000);
        xCamPos->setSingleStep(0.1);
        xCamPos->setValue(2);

        horizontalLayout_2->addWidget(xCamPos);

        yCamPos = new QDoubleSpinBox(groupBox);
        yCamPos->setObjectName(QStringLiteral("yCamPos"));
        yCamPos->setDecimals(4);
        yCamPos->setMinimum(-10000);
        yCamPos->setMaximum(10000);
        yCamPos->setSingleStep(0.1);
        yCamPos->setValue(2);

        horizontalLayout_2->addWidget(yCamPos);

        zCamPos = new QDoubleSpinBox(groupBox);
        zCamPos->setObjectName(QStringLiteral("zCamPos"));
        zCamPos->setDecimals(4);
        zCamPos->setMinimum(-10000);
        zCamPos->setMaximum(10000);
        zCamPos->setSingleStep(0.1);
        zCamPos->setValue(3);

        horizontalLayout_2->addWidget(zCamPos);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        xCamLookAt = new QDoubleSpinBox(groupBox);
        xCamLookAt->setObjectName(QStringLiteral("xCamLookAt"));
        xCamLookAt->setDecimals(4);
        xCamLookAt->setMinimum(-10000);
        xCamLookAt->setMaximum(10000);
        xCamLookAt->setSingleStep(0.1);

        horizontalLayout_4->addWidget(xCamLookAt);

        yCamLookAt = new QDoubleSpinBox(groupBox);
        yCamLookAt->setObjectName(QStringLiteral("yCamLookAt"));
        yCamLookAt->setDecimals(4);
        yCamLookAt->setMinimum(-10000);
        yCamLookAt->setMaximum(10000);
        yCamLookAt->setSingleStep(0.1);

        horizontalLayout_4->addWidget(yCamLookAt);

        zCamLookAt = new QDoubleSpinBox(groupBox);
        zCamLookAt->setObjectName(QStringLiteral("zCamLookAt"));
        zCamLookAt->setDecimals(4);
        zCamLookAt->setMinimum(-10000);
        zCamLookAt->setMaximum(10000);
        zCamLookAt->setSingleStep(0.1);

        horizontalLayout_4->addWidget(zCamLookAt);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        xCamVUp = new QDoubleSpinBox(groupBox);
        xCamVUp->setObjectName(QStringLiteral("xCamVUp"));
        xCamVUp->setDecimals(4);
        xCamVUp->setMinimum(-10000);
        xCamVUp->setMaximum(10000);
        xCamVUp->setSingleStep(0.1);

        horizontalLayout_5->addWidget(xCamVUp);

        yCamVUp = new QDoubleSpinBox(groupBox);
        yCamVUp->setObjectName(QStringLiteral("yCamVUp"));
        yCamVUp->setDecimals(4);
        yCamVUp->setMinimum(-10000);
        yCamVUp->setMaximum(10000);
        yCamVUp->setSingleStep(0.1);
        yCamVUp->setValue(1);

        horizontalLayout_5->addWidget(yCamVUp);

        zCamVUp = new QDoubleSpinBox(groupBox);
        zCamVUp->setObjectName(QStringLiteral("zCamVUp"));
        zCamVUp->setDecimals(4);
        zCamVUp->setMinimum(-10000);
        zCamVUp->setMaximum(10000);
        zCamVUp->setSingleStep(0.1);

        horizontalLayout_5->addWidget(zCamVUp);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_10->addWidget(groupBox);

        groupBox_2 = new QGroupBox(renderTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMaximumSize(QSize(250, 16777215));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        ambLightRed = new QDoubleSpinBox(groupBox_2);
        ambLightRed->setObjectName(QStringLiteral("ambLightRed"));
        ambLightRed->setDecimals(4);
        ambLightRed->setMaximum(1);
        ambLightRed->setSingleStep(0.01);
        ambLightRed->setValue(1);

        horizontalLayout_6->addWidget(ambLightRed);

        ambLightGreen = new QDoubleSpinBox(groupBox_2);
        ambLightGreen->setObjectName(QStringLiteral("ambLightGreen"));
        ambLightGreen->setDecimals(4);
        ambLightGreen->setMaximum(1);
        ambLightGreen->setSingleStep(0.01);
        ambLightGreen->setValue(1);

        horizontalLayout_6->addWidget(ambLightGreen);

        ambLightBlue = new QDoubleSpinBox(groupBox_2);
        ambLightBlue->setObjectName(QStringLiteral("ambLightBlue"));
        ambLightBlue->setDecimals(4);
        ambLightBlue->setMaximum(1);
        ambLightBlue->setSingleStep(0.01);
        ambLightBlue->setValue(1);

        horizontalLayout_6->addWidget(ambLightBlue);


        verticalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_10->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(renderTab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMaximumSize(QSize(250, 16777215));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_6->addWidget(label_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        xLightPos = new QDoubleSpinBox(groupBox_3);
        xLightPos->setObjectName(QStringLiteral("xLightPos"));
        xLightPos->setDecimals(4);
        xLightPos->setMinimum(-10000);
        xLightPos->setMaximum(10000);
        xLightPos->setSingleStep(0.1);
        xLightPos->setValue(0);

        horizontalLayout_8->addWidget(xLightPos);

        yLightPos = new QDoubleSpinBox(groupBox_3);
        yLightPos->setObjectName(QStringLiteral("yLightPos"));
        yLightPos->setDecimals(4);
        yLightPos->setMinimum(-10000);
        yLightPos->setMaximum(10000);
        yLightPos->setSingleStep(0.1);
        yLightPos->setValue(5);

        horizontalLayout_8->addWidget(yLightPos);

        zLightPos = new QDoubleSpinBox(groupBox_3);
        zLightPos->setObjectName(QStringLiteral("zLightPos"));
        zLightPos->setDecimals(4);
        zLightPos->setMinimum(-10000);
        zLightPos->setMaximum(10000);
        zLightPos->setSingleStep(0.1);
        zLightPos->setValue(5);

        horizontalLayout_8->addWidget(zLightPos);


        verticalLayout_6->addLayout(horizontalLayout_8);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_6->addWidget(label_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pontualLightRed = new QDoubleSpinBox(groupBox_3);
        pontualLightRed->setObjectName(QStringLiteral("pontualLightRed"));
        pontualLightRed->setDecimals(4);
        pontualLightRed->setMaximum(1);
        pontualLightRed->setSingleStep(0.01);
        pontualLightRed->setValue(1);

        horizontalLayout_7->addWidget(pontualLightRed);

        pontualLightGreen = new QDoubleSpinBox(groupBox_3);
        pontualLightGreen->setObjectName(QStringLiteral("pontualLightGreen"));
        pontualLightGreen->setDecimals(4);
        pontualLightGreen->setMaximum(1);
        pontualLightGreen->setSingleStep(0.01);
        pontualLightGreen->setValue(1);

        horizontalLayout_7->addWidget(pontualLightGreen);

        pontualLightBlue = new QDoubleSpinBox(groupBox_3);
        pontualLightBlue->setObjectName(QStringLiteral("pontualLightBlue"));
        pontualLightBlue->setDecimals(4);
        pontualLightBlue->setMaximum(1);
        pontualLightBlue->setSingleStep(0.01);
        pontualLightBlue->setValue(1);

        horizontalLayout_7->addWidget(pontualLightBlue);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout_10->addWidget(groupBox_3);

        renderBtn = new QPushButton(renderTab);
        renderBtn->setObjectName(QStringLiteral("renderBtn"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(renderBtn->sizePolicy().hasHeightForWidth());
        renderBtn->setSizePolicy(sizePolicy5);
        renderBtn->setMinimumSize(QSize(0, 50));

        verticalLayout_10->addWidget(renderBtn);


        horizontalLayout_9->addLayout(verticalLayout_10);

        tabWidget->addTab(renderTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 717, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuSave = new QMenu(menuFile);
        menuSave->setObjectName(QStringLiteral("menuSave"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(menuSave->menuAction());
        menuOpen->addAction(actionOpenSF);
        menuOpen->addAction(actionOpenOF);
        menuOpen->addAction(actionOpenCF);
        menuSave->addAction(actionSaveSF);
        menuSave->addAction(actionSaveOF);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        insertCylinderBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MModeler", 0));
        actionOpenOF->setText(QApplication::translate("MainWindow", "Octrees File", 0));
        actionSaveOF->setText(QApplication::translate("MainWindow", "Octrees File", 0));
        actionOpenSF->setText(QApplication::translate("MainWindow", "Scene File", 0));
        actionSaveSF->setText(QApplication::translate("MainWindow", "Scene File", 0));
        actionOpenCF->setText(QApplication::translate("MainWindow", "CSG File", 0));
        insertSphereBtn->setText(QString());
        insertBoxBtn->setText(QString());
        insertCylinderBtn->setText(QString());
        insertPyramidBtn->setText(QString());
        insertPrismBtn->setText(QString());
        insertOctreeBtn->setText(QString());
        insertCSGBtn->setText(QString());
        label_8->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = objectsTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Objects", 0));
        translBtn->setText(QApplication::translate("MainWindow", "Translate", 0));
        rotBtn->setText(QApplication::translate("MainWindow", "Rotate", 0));
        sclBtn->setText(QApplication::translate("MainWindow", "Scale", 0));
        delBtn->setText(QApplication::translate("MainWindow", "Delete", 0));
        cmdFeed->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(visTab), QApplication::translate("MainWindow", "Visualization", 0));
        canvas->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Tamanho da Imagem", 0));
        label_6->setText(QApplication::translate("MainWindow", "Width", 0));
        label_7->setText(QApplication::translate("MainWindow", "Height", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Camera", 0));
        label->setText(QApplication::translate("MainWindow", "Position", 0));
        label_2->setText(QApplication::translate("MainWindow", "Look At", 0));
        label_3->setText(QApplication::translate("MainWindow", "View Up", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ambient Light", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Pontual Light", 0));
        label_4->setText(QApplication::translate("MainWindow", "Position", 0));
        label_5->setText(QApplication::translate("MainWindow", "Color", 0));
        renderBtn->setText(QApplication::translate("MainWindow", "Render", 0));
        tabWidget->setTabText(tabWidget->indexOf(renderTab), QApplication::translate("MainWindow", "Rendered", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuOpen->setTitle(QApplication::translate("MainWindow", "Open", 0));
        menuSave->setTitle(QApplication::translate("MainWindow", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
