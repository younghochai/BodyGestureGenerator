/********************************************************************************
** Form generated from reading UI file 'EventQtSlotConnect.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTQTSLOTCONNECT_H
#define UI_EVENTQTSLOTCONNECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLNativeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_EventQtSlotConnect
{
public:
    QAction *actionOpenFile;
    QAction *actionExit;
    QAction *actionPrint;
    QAction *actionHelp;
    QAction *actionSave;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave_2;
    QAction *actionSave_As;
    QAction *action_txt;
    QAction *action_bvh;
    QAction *actionExport;
    QAction *actionExit_2;
    QAction *actionMove;
    QAction *actionRotate;
    QAction *actionScale;
    QAction *actionSelect_All;
    QAction *actionSelect_None;
    QAction *actionSelect_Invert;
    QAction *actionConstraint_Props;
    QAction *actionLighting;
    QAction *actionSnapshot;
    QAction *actionRecord;
    QAction *actionAnatomical_Inputs;
    QAction *actionAxis_Angle_Inputs;
    QAction *actionMotion_Sphere;
    QAction *DiscardUM;
    QAction *IntegrateUM;
    QAction *actionFullBody_JS;
    QAction *actionUpperBody_JS;
    QAction *actionLowerBody_JS;
    QAction *actionScene_props;
    QAction *actionJoint_Sphere;
    QAction *load_sfqFormat;
    QAction *actionsrq_Format;
    QAction *load_srqFormat;
    QAction *actionsfq_format;
    QAction *actionsrq_format;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QComboBox *modelType;
    QLabel *label_2;
    QSpinBox *height_spinBox;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QLCDNumber *KF_lcdNumber;
    QPushButton *kfCapture_Button;
    QPushButton *authorMode_Button;
    QPushButton *viewMode_Button;
    QSpacerItem *verticalSpacer;
    QWidget *widget_4;
    QGridLayout *gridLayout_6;
    QPushButton *quitButton;
    QPushButton *reset_Button;
    QPushButton *snapShot_Button;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QVTKOpenGLNativeWidget *qvtkWidget;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QPushButton *Generate_All_KFs_Button;
    QFrame *frame_2;
    QGridLayout *gridLayout_9;
    QPushButton *timerSetting_pushButton;
    QPushButton *play_Button;
    QSlider *keyframes_Slider;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    QGroupBox *IKsolver_groupBox;
    QGridLayout *gridLayout_11;
    QCheckBox *rfIK_checkBox;
    QCheckBox *lhIK_checkBox;
    QCheckBox *rhIK_checkBox;
    QCheckBox *lfIK_checkBox;
    QPushButton *restIK_Button;
    QCheckBox *fullbodyIK_checkBox;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QRadioButton *freeFoots_radioButton;
    QRadioButton *fixedFoots_radioButton;
    QRadioButton *fixedRF_radioButton;
    QRadioButton *fixedLF_radioButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuImport;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuAnimation;
    QMenu *menuBlend;
    QMenu *addUM_menu;
    QMenu *menuLoad;
    QMenu *menuAuthoring;
    QMenu *menuVisualization;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *EventQtSlotConnect)
    {
        if (EventQtSlotConnect->objectName().isEmpty())
            EventQtSlotConnect->setObjectName("EventQtSlotConnect");
        EventQtSlotConnect->resize(1340, 926);
        EventQtSlotConnect->setContextMenuPolicy(Qt::DefaultContextMenu);
        EventQtSlotConnect->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:1, cy:1, angle:358.2, stop:0 rgba(53, 53, 53, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: rgb(68, 68, 68);\n"
"color: rgb(255, 255, 255);"));
        actionOpenFile = new QAction(EventQtSlotConnect);
        actionOpenFile->setObjectName("actionOpenFile");
        actionOpenFile->setEnabled(true);
        actionExit = new QAction(EventQtSlotConnect);
        actionExit->setObjectName("actionExit");
        actionPrint = new QAction(EventQtSlotConnect);
        actionPrint->setObjectName("actionPrint");
        actionHelp = new QAction(EventQtSlotConnect);
        actionHelp->setObjectName("actionHelp");
        actionSave = new QAction(EventQtSlotConnect);
        actionSave->setObjectName("actionSave");
        actionNew = new QAction(EventQtSlotConnect);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(EventQtSlotConnect);
        actionOpen->setObjectName("actionOpen");
        actionSave_2 = new QAction(EventQtSlotConnect);
        actionSave_2->setObjectName("actionSave_2");
        actionSave_As = new QAction(EventQtSlotConnect);
        actionSave_As->setObjectName("actionSave_As");
        action_txt = new QAction(EventQtSlotConnect);
        action_txt->setObjectName("action_txt");
        action_bvh = new QAction(EventQtSlotConnect);
        action_bvh->setObjectName("action_bvh");
        actionExport = new QAction(EventQtSlotConnect);
        actionExport->setObjectName("actionExport");
        actionExit_2 = new QAction(EventQtSlotConnect);
        actionExit_2->setObjectName("actionExit_2");
        actionMove = new QAction(EventQtSlotConnect);
        actionMove->setObjectName("actionMove");
        actionRotate = new QAction(EventQtSlotConnect);
        actionRotate->setObjectName("actionRotate");
        actionScale = new QAction(EventQtSlotConnect);
        actionScale->setObjectName("actionScale");
        actionSelect_All = new QAction(EventQtSlotConnect);
        actionSelect_All->setObjectName("actionSelect_All");
        actionSelect_None = new QAction(EventQtSlotConnect);
        actionSelect_None->setObjectName("actionSelect_None");
        actionSelect_Invert = new QAction(EventQtSlotConnect);
        actionSelect_Invert->setObjectName("actionSelect_Invert");
        actionConstraint_Props = new QAction(EventQtSlotConnect);
        actionConstraint_Props->setObjectName("actionConstraint_Props");
        actionLighting = new QAction(EventQtSlotConnect);
        actionLighting->setObjectName("actionLighting");
        actionSnapshot = new QAction(EventQtSlotConnect);
        actionSnapshot->setObjectName("actionSnapshot");
        actionRecord = new QAction(EventQtSlotConnect);
        actionRecord->setObjectName("actionRecord");
        actionAnatomical_Inputs = new QAction(EventQtSlotConnect);
        actionAnatomical_Inputs->setObjectName("actionAnatomical_Inputs");
        actionAxis_Angle_Inputs = new QAction(EventQtSlotConnect);
        actionAxis_Angle_Inputs->setObjectName("actionAxis_Angle_Inputs");
        actionMotion_Sphere = new QAction(EventQtSlotConnect);
        actionMotion_Sphere->setObjectName("actionMotion_Sphere");
        DiscardUM = new QAction(EventQtSlotConnect);
        DiscardUM->setObjectName("DiscardUM");
        IntegrateUM = new QAction(EventQtSlotConnect);
        IntegrateUM->setObjectName("IntegrateUM");
        actionFullBody_JS = new QAction(EventQtSlotConnect);
        actionFullBody_JS->setObjectName("actionFullBody_JS");
        actionUpperBody_JS = new QAction(EventQtSlotConnect);
        actionUpperBody_JS->setObjectName("actionUpperBody_JS");
        actionLowerBody_JS = new QAction(EventQtSlotConnect);
        actionLowerBody_JS->setObjectName("actionLowerBody_JS");
        actionScene_props = new QAction(EventQtSlotConnect);
        actionScene_props->setObjectName("actionScene_props");
        actionJoint_Sphere = new QAction(EventQtSlotConnect);
        actionJoint_Sphere->setObjectName("actionJoint_Sphere");
        load_sfqFormat = new QAction(EventQtSlotConnect);
        load_sfqFormat->setObjectName("load_sfqFormat");
        actionsrq_Format = new QAction(EventQtSlotConnect);
        actionsrq_Format->setObjectName("actionsrq_Format");
        load_srqFormat = new QAction(EventQtSlotConnect);
        load_srqFormat->setObjectName("load_srqFormat");
        actionsfq_format = new QAction(EventQtSlotConnect);
        actionsfq_format->setObjectName("actionsfq_format");
        actionsrq_format = new QAction(EventQtSlotConnect);
        actionsrq_format->setObjectName("actionsrq_format");
        centralwidget = new QWidget(EventQtSlotConnect);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(125, 0));
        QFont font;
        font.setBold(true);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName("gridLayout_4");
        label = new QLabel(widget_2);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        modelType = new QComboBox(widget_2);
        modelType->setObjectName("modelType");
        modelType->setMinimumSize(QSize(75, 22));

        gridLayout_4->addWidget(modelType, 1, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        height_spinBox = new QSpinBox(widget_2);
        height_spinBox->setObjectName("height_spinBox");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(height_spinBox->sizePolicy().hasHeightForWidth());
        height_spinBox->setSizePolicy(sizePolicy2);
        height_spinBox->setMinimumSize(QSize(75, 22));

        gridLayout_4->addWidget(height_spinBox, 3, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 1);

        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName("gridLayout_3");
        KF_lcdNumber = new QLCDNumber(widget);
        KF_lcdNumber->setObjectName("KF_lcdNumber");
        sizePolicy2.setHeightForWidth(KF_lcdNumber->sizePolicy().hasHeightForWidth());
        KF_lcdNumber->setSizePolicy(sizePolicy2);
        KF_lcdNumber->setMinimumSize(QSize(45, 0));
        KF_lcdNumber->setMaximumSize(QSize(30, 16777215));

        gridLayout_3->addWidget(KF_lcdNumber, 3, 1, 1, 1);

        kfCapture_Button = new QPushButton(widget);
        kfCapture_Button->setObjectName("kfCapture_Button");
        QFont font3;
        font3.setPointSize(9);
        kfCapture_Button->setFont(font3);

        gridLayout_3->addWidget(kfCapture_Button, 3, 0, 1, 1);

        authorMode_Button = new QPushButton(widget);
        authorMode_Button->setObjectName("authorMode_Button");
        authorMode_Button->setFont(font3);

        gridLayout_3->addWidget(authorMode_Button, 2, 0, 1, 2);

        viewMode_Button = new QPushButton(widget);
        viewMode_Button->setObjectName("viewMode_Button");
        viewMode_Button->setFont(font3);

        gridLayout_3->addWidget(viewMode_Button, 1, 0, 1, 2);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        widget_4 = new QWidget(groupBox);
        widget_4->setObjectName("widget_4");
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setMinimumSize(QSize(0, 70));
        gridLayout_6 = new QGridLayout(widget_4);
        gridLayout_6->setObjectName("gridLayout_6");
        quitButton = new QPushButton(widget_4);
        quitButton->setObjectName("quitButton");
        quitButton->setFont(font3);

        gridLayout_6->addWidget(quitButton, 2, 0, 1, 1);

        reset_Button = new QPushButton(widget_4);
        reset_Button->setObjectName("reset_Button");
        reset_Button->setFont(font3);

        gridLayout_6->addWidget(reset_Button, 1, 0, 1, 1);

        snapShot_Button = new QPushButton(widget_4);
        snapShot_Button->setObjectName("snapShot_Button");
        snapShot_Button->setFont(font3);

        gridLayout_6->addWidget(snapShot_Button, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_4, 3, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(540, 450));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(true);
        groupBox_2->setFont(font4);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        qvtkWidget = new QVTKOpenGLNativeWidget(groupBox_2);
        qvtkWidget->setObjectName("qvtkWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(qvtkWidget, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName("groupBox_4");
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setMinimumSize(QSize(0, 100));
        groupBox_4->setFont(font);
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName("gridLayout_7");
        frame = new QFrame(groupBox_4);
        frame->setObjectName("frame");
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame);
        gridLayout_8->setObjectName("gridLayout_8");
        Generate_All_KFs_Button = new QPushButton(frame);
        Generate_All_KFs_Button->setObjectName("Generate_All_KFs_Button");
        sizePolicy1.setHeightForWidth(Generate_All_KFs_Button->sizePolicy().hasHeightForWidth());
        Generate_All_KFs_Button->setSizePolicy(sizePolicy1);
        Generate_All_KFs_Button->setMinimumSize(QSize(0, 45));
        Generate_All_KFs_Button->setFont(font2);

        gridLayout_8->addWidget(Generate_All_KFs_Button, 0, 1, 1, 1);


        gridLayout_7->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(groupBox_4);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(frame_2);
        gridLayout_9->setObjectName("gridLayout_9");
        timerSetting_pushButton = new QPushButton(frame_2);
        timerSetting_pushButton->setObjectName("timerSetting_pushButton");
        sizePolicy2.setHeightForWidth(timerSetting_pushButton->sizePolicy().hasHeightForWidth());
        timerSetting_pushButton->setSizePolicy(sizePolicy2);
        timerSetting_pushButton->setMinimumSize(QSize(0, 0));

        gridLayout_9->addWidget(timerSetting_pushButton, 1, 2, 1, 1);

        play_Button = new QPushButton(frame_2);
        play_Button->setObjectName("play_Button");
        sizePolicy2.setHeightForWidth(play_Button->sizePolicy().hasHeightForWidth());
        play_Button->setSizePolicy(sizePolicy2);
        play_Button->setFont(font3);

        gridLayout_9->addWidget(play_Button, 1, 0, 1, 1);

        keyframes_Slider = new QSlider(frame_2);
        keyframes_Slider->setObjectName("keyframes_Slider");
        keyframes_Slider->setStyleSheet(QString::fromUtf8("background-color: rgb(122, 122, 122);\n"
"background-color: rgb(68, 68, 68);"));
        keyframes_Slider->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(keyframes_Slider, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 1, 1, 1, 1);


        gridLayout_7->addWidget(frame_2, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_4, 1, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setMinimumSize(QSize(120, 0));
        groupBox_3->setMaximumSize(QSize(160, 16777215));
        groupBox_3->setFont(font);
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setObjectName("gridLayout_10");
        IKsolver_groupBox = new QGroupBox(groupBox_3);
        IKsolver_groupBox->setObjectName("IKsolver_groupBox");
        IKsolver_groupBox->setMaximumSize(QSize(120, 16777215));
        gridLayout_11 = new QGridLayout(IKsolver_groupBox);
        gridLayout_11->setObjectName("gridLayout_11");
        rfIK_checkBox = new QCheckBox(IKsolver_groupBox);
        rfIK_checkBox->setObjectName("rfIK_checkBox");
        rfIK_checkBox->setFont(font3);

        gridLayout_11->addWidget(rfIK_checkBox, 2, 0, 1, 1);

        lhIK_checkBox = new QCheckBox(IKsolver_groupBox);
        lhIK_checkBox->setObjectName("lhIK_checkBox");
        lhIK_checkBox->setMaximumSize(QSize(40, 16777215));
        lhIK_checkBox->setFont(font3);

        gridLayout_11->addWidget(lhIK_checkBox, 1, 1, 1, 1);

        rhIK_checkBox = new QCheckBox(IKsolver_groupBox);
        rhIK_checkBox->setObjectName("rhIK_checkBox");
        rhIK_checkBox->setFont(font3);

        gridLayout_11->addWidget(rhIK_checkBox, 1, 0, 1, 1);

        lfIK_checkBox = new QCheckBox(IKsolver_groupBox);
        lfIK_checkBox->setObjectName("lfIK_checkBox");
        lfIK_checkBox->setFont(font3);

        gridLayout_11->addWidget(lfIK_checkBox, 2, 1, 1, 1);

        restIK_Button = new QPushButton(IKsolver_groupBox);
        restIK_Button->setObjectName("restIK_Button");

        gridLayout_11->addWidget(restIK_Button, 3, 0, 1, 2);

        fullbodyIK_checkBox = new QCheckBox(IKsolver_groupBox);
        fullbodyIK_checkBox->setObjectName("fullbodyIK_checkBox");
        fullbodyIK_checkBox->setFont(font3);

        gridLayout_11->addWidget(fullbodyIK_checkBox, 0, 0, 1, 2);


        gridLayout_10->addWidget(IKsolver_groupBox, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 712, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_2, 4, 0, 1, 1);

        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setMinimumSize(QSize(0, 90));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName("gridLayout_5");
        freeFoots_radioButton = new QRadioButton(groupBox_5);
        freeFoots_radioButton->setObjectName("freeFoots_radioButton");
        freeFoots_radioButton->setMaximumSize(QSize(90, 16777215));
        freeFoots_radioButton->setFont(font3);

        gridLayout_5->addWidget(freeFoots_radioButton, 0, 0, 1, 2);

        fixedFoots_radioButton = new QRadioButton(groupBox_5);
        fixedFoots_radioButton->setObjectName("fixedFoots_radioButton");
        fixedFoots_radioButton->setFont(font3);

        gridLayout_5->addWidget(fixedFoots_radioButton, 1, 0, 1, 2);

        fixedRF_radioButton = new QRadioButton(groupBox_5);
        fixedRF_radioButton->setObjectName("fixedRF_radioButton");
        fixedRF_radioButton->setMaximumSize(QSize(40, 16777215));
        fixedRF_radioButton->setFont(font3);

        gridLayout_5->addWidget(fixedRF_radioButton, 2, 0, 1, 1);

        fixedLF_radioButton = new QRadioButton(groupBox_5);
        fixedLF_radioButton->setObjectName("fixedLF_radioButton");
        fixedLF_radioButton->setFont(font3);

        gridLayout_5->addWidget(fixedLF_radioButton, 2, 1, 1, 1);


        gridLayout_10->addWidget(groupBox_5, 2, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        EventQtSlotConnect->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(EventQtSlotConnect);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1340, 23));
        menuBar->setMinimumSize(QSize(0, 23));
        QFont font5;
        font5.setPointSize(10);
        menuBar->setFont(font5);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuImport = new QMenu(menuFile);
        menuImport->setObjectName("menuImport");
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName("menuEdit");
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName("menuTools");
        menuAnimation = new QMenu(menuBar);
        menuAnimation->setObjectName("menuAnimation");
        menuBlend = new QMenu(menuAnimation);
        menuBlend->setObjectName("menuBlend");
        addUM_menu = new QMenu(menuBlend);
        addUM_menu->setObjectName("addUM_menu");
        menuLoad = new QMenu(menuAnimation);
        menuLoad->setObjectName("menuLoad");
        menuAuthoring = new QMenu(menuBar);
        menuAuthoring->setObjectName("menuAuthoring");
        menuVisualization = new QMenu(menuBar);
        menuVisualization->setObjectName("menuVisualization");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        EventQtSlotConnect->setMenuBar(menuBar);
        toolBar = new QToolBar(EventQtSlotConnect);
        toolBar->setObjectName("toolBar");
        toolBar->setMinimumSize(QSize(0, 35));
        EventQtSlotConnect->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuAuthoring->menuAction());
        menuBar->addAction(menuAnimation->menuAction());
        menuBar->addAction(menuVisualization->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(menuImport->menuAction());
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_2);
        menuImport->addAction(action_txt);
        menuImport->addAction(action_bvh);
        menuEdit->addAction(actionMove);
        menuEdit->addAction(actionRotate);
        menuEdit->addAction(actionScale);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_All);
        menuEdit->addAction(actionSelect_None);
        menuEdit->addAction(actionSelect_Invert);
        menuEdit->addSeparator();
        menuTools->addAction(actionConstraint_Props);
        menuTools->addAction(actionScene_props);
        menuTools->addSeparator();
        menuTools->addAction(actionLighting);
        menuTools->addSeparator();
        menuTools->addAction(actionRecord);
        menuTools->addAction(actionSnapshot);
        menuTools->addSeparator();
        menuAnimation->addAction(menuLoad->menuAction());
        menuAnimation->addSeparator();
        menuAnimation->addAction(menuBlend->menuAction());
        menuBlend->addAction(addUM_menu->menuAction());
        menuBlend->addSeparator();
        menuBlend->addAction(IntegrateUM);
        menuBlend->addSeparator();
        menuBlend->addAction(DiscardUM);
        menuBlend->addSeparator();
        addUM_menu->addAction(actionsfq_format);
        addUM_menu->addSeparator();
        addUM_menu->addAction(actionsrq_format);
        menuLoad->addAction(load_sfqFormat);
        menuLoad->addSeparator();
        menuLoad->addAction(load_srqFormat);
        menuAuthoring->addAction(actionAnatomical_Inputs);
        menuAuthoring->addAction(actionAxis_Angle_Inputs);
        menuVisualization->addAction(actionMotion_Sphere);
        menuVisualization->addAction(actionJoint_Sphere);

        retranslateUi(EventQtSlotConnect);

        QMetaObject::connectSlotsByName(EventQtSlotConnect);
    } // setupUi

    void retranslateUi(QMainWindow *EventQtSlotConnect)
    {
        EventQtSlotConnect->setWindowTitle(QCoreApplication::translate("EventQtSlotConnect", "moMAEP - Modular Motion Authoring and Editing Platform", nullptr));
        actionOpenFile->setText(QCoreApplication::translate("EventQtSlotConnect", "Open File...", nullptr));
        actionExit->setText(QCoreApplication::translate("EventQtSlotConnect", "Exit", nullptr));
        actionPrint->setText(QCoreApplication::translate("EventQtSlotConnect", "Print", nullptr));
        actionHelp->setText(QCoreApplication::translate("EventQtSlotConnect", "Help", nullptr));
        actionSave->setText(QCoreApplication::translate("EventQtSlotConnect", "Save", nullptr));
        actionNew->setText(QCoreApplication::translate("EventQtSlotConnect", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("EventQtSlotConnect", "Open", nullptr));
        actionSave_2->setText(QCoreApplication::translate("EventQtSlotConnect", "Save..", nullptr));
        actionSave_As->setText(QCoreApplication::translate("EventQtSlotConnect", "Save As..", nullptr));
        action_txt->setText(QCoreApplication::translate("EventQtSlotConnect", ".txt", nullptr));
        action_bvh->setText(QCoreApplication::translate("EventQtSlotConnect", ".bvh", nullptr));
        actionExport->setText(QCoreApplication::translate("EventQtSlotConnect", "Export", nullptr));
        actionExit_2->setText(QCoreApplication::translate("EventQtSlotConnect", "Exit", nullptr));
        actionMove->setText(QCoreApplication::translate("EventQtSlotConnect", "Move", nullptr));
        actionRotate->setText(QCoreApplication::translate("EventQtSlotConnect", "Rotate", nullptr));
        actionScale->setText(QCoreApplication::translate("EventQtSlotConnect", "Scale", nullptr));
        actionSelect_All->setText(QCoreApplication::translate("EventQtSlotConnect", "Select All", nullptr));
        actionSelect_None->setText(QCoreApplication::translate("EventQtSlotConnect", "Select None", nullptr));
        actionSelect_Invert->setText(QCoreApplication::translate("EventQtSlotConnect", "Select Invert", nullptr));
        actionConstraint_Props->setText(QCoreApplication::translate("EventQtSlotConnect", "Constraint Props", nullptr));
        actionLighting->setText(QCoreApplication::translate("EventQtSlotConnect", "Lighting", nullptr));
        actionSnapshot->setText(QCoreApplication::translate("EventQtSlotConnect", "Snapshot", nullptr));
        actionRecord->setText(QCoreApplication::translate("EventQtSlotConnect", "Record", nullptr));
        actionAnatomical_Inputs->setText(QCoreApplication::translate("EventQtSlotConnect", "Anatomical Input", nullptr));
        actionAxis_Angle_Inputs->setText(QCoreApplication::translate("EventQtSlotConnect", "Axis-Angle Input", nullptr));
        actionMotion_Sphere->setText(QCoreApplication::translate("EventQtSlotConnect", "Motion-Sphere", nullptr));
        DiscardUM->setText(QCoreApplication::translate("EventQtSlotConnect", "Discard", nullptr));
        IntegrateUM->setText(QCoreApplication::translate("EventQtSlotConnect", "Integrate", nullptr));
        actionFullBody_JS->setText(QCoreApplication::translate("EventQtSlotConnect", "Full Body", nullptr));
        actionUpperBody_JS->setText(QCoreApplication::translate("EventQtSlotConnect", "Upper Body", nullptr));
        actionLowerBody_JS->setText(QCoreApplication::translate("EventQtSlotConnect", "Lower Body", nullptr));
        actionScene_props->setText(QCoreApplication::translate("EventQtSlotConnect", "Scene Props", nullptr));
        actionJoint_Sphere->setText(QCoreApplication::translate("EventQtSlotConnect", "Joint-Sphere", nullptr));
        load_sfqFormat->setText(QCoreApplication::translate("EventQtSlotConnect", "sfq Format", nullptr));
        actionsrq_Format->setText(QCoreApplication::translate("EventQtSlotConnect", "srq Format", nullptr));
        load_srqFormat->setText(QCoreApplication::translate("EventQtSlotConnect", "srq Format", nullptr));
        actionsfq_format->setText(QCoreApplication::translate("EventQtSlotConnect", "sfq Format", nullptr));
        actionsrq_format->setText(QCoreApplication::translate("EventQtSlotConnect", "srq Format", nullptr));
        groupBox->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Authoring Tools", nullptr));
        label->setText(QCoreApplication::translate("EventQtSlotConnect", "Select Biped", nullptr));
        label_2->setText(QCoreApplication::translate("EventQtSlotConnect", "Set Height", nullptr));
        kfCapture_Button->setText(QCoreApplication::translate("EventQtSlotConnect", "Capture KF", nullptr));
        authorMode_Button->setText(QCoreApplication::translate("EventQtSlotConnect", "Author", nullptr));
        viewMode_Button->setText(QCoreApplication::translate("EventQtSlotConnect", "View", nullptr));
        quitButton->setText(QCoreApplication::translate("EventQtSlotConnect", "Quit", nullptr));
        reset_Button->setText(QCoreApplication::translate("EventQtSlotConnect", "Reset", nullptr));
        snapShot_Button->setText(QCoreApplication::translate("EventQtSlotConnect", "Snapshot", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("EventQtSlotConnect", "MoMAP", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Playback", nullptr));
        Generate_All_KFs_Button->setText(QCoreApplication::translate("EventQtSlotConnect", "Generate \n"
"Frames", nullptr));
        timerSetting_pushButton->setText(QCoreApplication::translate("EventQtSlotConnect", "Timer \n"
"Settings", nullptr));
        play_Button->setText(QCoreApplication::translate("EventQtSlotConnect", "Play/Pause", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("EventQtSlotConnect", "IK Setting", nullptr));
        IKsolver_groupBox->setTitle(QCoreApplication::translate("EventQtSlotConnect", "IK Solver", nullptr));
        rfIK_checkBox->setText(QCoreApplication::translate("EventQtSlotConnect", "RF", nullptr));
        lhIK_checkBox->setText(QCoreApplication::translate("EventQtSlotConnect", "LH", nullptr));
        rhIK_checkBox->setText(QCoreApplication::translate("EventQtSlotConnect", "RH", nullptr));
        lfIK_checkBox->setText(QCoreApplication::translate("EventQtSlotConnect", "LF", nullptr));
        restIK_Button->setText(QCoreApplication::translate("EventQtSlotConnect", "Reset IK", nullptr));
        fullbodyIK_checkBox->setText(QCoreApplication::translate("EventQtSlotConnect", "Fullbody", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Foot Keys", nullptr));
        freeFoots_radioButton->setText(QCoreApplication::translate("EventQtSlotConnect", "Free Foot's", nullptr));
        fixedFoots_radioButton->setText(QCoreApplication::translate("EventQtSlotConnect", "Fixed Foot's", nullptr));
        fixedRF_radioButton->setText(QCoreApplication::translate("EventQtSlotConnect", "RF", nullptr));
        fixedLF_radioButton->setText(QCoreApplication::translate("EventQtSlotConnect", "LF", nullptr));
        menuFile->setTitle(QCoreApplication::translate("EventQtSlotConnect", "File", nullptr));
        menuImport->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Import", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Edit", nullptr));
        menuTools->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Tools", nullptr));
        menuAnimation->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Animation", nullptr));
        menuBlend->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Blend", nullptr));
        addUM_menu->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Add", nullptr));
        menuLoad->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Load", nullptr));
        menuAuthoring->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Authoring", nullptr));
        menuVisualization->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Visualization", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("EventQtSlotConnect", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("EventQtSlotConnect", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventQtSlotConnect: public Ui_EventQtSlotConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTQTSLOTCONNECT_H
