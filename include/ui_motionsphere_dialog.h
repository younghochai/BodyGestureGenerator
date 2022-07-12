/********************************************************************************
** Form generated from reading UI file 'motionsphere_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTIONSPHERE_DIALOG_H
#define UI_MOTIONSPHERE_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLNativeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_motionSphere_dialog
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionImport;
    QAction *actionExport;
    QAction *actionExit;
    QAction *actionSegments_Props;
    QAction *actionRecord;
    QAction *actionSnapshot;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *MS_groupBox;
    QGridLayout *gridLayout_2;
    QVTKOpenGLNativeWidget *motionSphere_qvtkWidget;
    QGroupBox *MS_segmentSelection_groupBox;
    QGridLayout *gridLayout_3;
    QGroupBox *fullbodyMS_groupBox;
    QGridLayout *gridLayout_4;
    QCheckBox *fullbodyMS_checkBox;
    QGroupBox *upperbodyMS_groupBox;
    QGridLayout *gridLayout_5;
    QCheckBox *upperbodyMS_checkBox;
    QCheckBox *ubRUA_MS_checkBox;
    QCheckBox *ubRLA_MS_checkBox;
    QCheckBox *ubLUA_MS_checkBox;
    QCheckBox *ubLLA_MS_checkBox;
    QGroupBox *torsoMS_groupBox;
    QGridLayout *gridLayout_7;
    QCheckBox *torPL_MS_checkBox;
    QCheckBox *torCH_MS_checkBox;
    QGroupBox *lowerbodyMS_groupBox;
    QGridLayout *gridLayout_6;
    QCheckBox *lowerbodyMS_checkBox;
    QCheckBox *lbRUL_MS_checkBox;
    QCheckBox *lbRLL_MS_checkBox;
    QCheckBox *lbLUL_MS_checkBox;
    QCheckBox *lbLL_MS_checkBox;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuTools_2;
    QMenu *menuAuthoring;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *motionSphere_dialog)
    {
        if (motionSphere_dialog->objectName().isEmpty())
            motionSphere_dialog->setObjectName("motionSphere_dialog");
        motionSphere_dialog->resize(716, 762);
        motionSphere_dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 68);\n"
"color: rgb(255, 255, 255);"));
        actionNew = new QAction(motionSphere_dialog);
        actionNew->setObjectName("actionNew");
        QFont font;
        font.setPointSize(9);
        actionNew->setFont(font);
        actionOpen = new QAction(motionSphere_dialog);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(motionSphere_dialog);
        actionSave->setObjectName("actionSave");
        actionSave_As = new QAction(motionSphere_dialog);
        actionSave_As->setObjectName("actionSave_As");
        actionImport = new QAction(motionSphere_dialog);
        actionImport->setObjectName("actionImport");
        actionExport = new QAction(motionSphere_dialog);
        actionExport->setObjectName("actionExport");
        actionExit = new QAction(motionSphere_dialog);
        actionExit->setObjectName("actionExit");
        actionSegments_Props = new QAction(motionSphere_dialog);
        actionSegments_Props->setObjectName("actionSegments_Props");
        actionRecord = new QAction(motionSphere_dialog);
        actionRecord->setObjectName("actionRecord");
        actionSnapshot = new QAction(motionSphere_dialog);
        actionSnapshot->setObjectName("actionSnapshot");
        centralwidget = new QWidget(motionSphere_dialog);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        MS_groupBox = new QGroupBox(centralwidget);
        MS_groupBox->setObjectName("MS_groupBox");
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        MS_groupBox->setFont(font1);
        gridLayout_2 = new QGridLayout(MS_groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        motionSphere_qvtkWidget = new QVTKOpenGLNativeWidget(MS_groupBox);
        motionSphere_qvtkWidget->setObjectName("motionSphere_qvtkWidget");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(motionSphere_qvtkWidget->sizePolicy().hasHeightForWidth());
        motionSphere_qvtkWidget->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(motionSphere_qvtkWidget, 0, 0, 1, 1);


        gridLayout->addWidget(MS_groupBox, 0, 0, 1, 1);

        MS_segmentSelection_groupBox = new QGroupBox(centralwidget);
        MS_segmentSelection_groupBox->setObjectName("MS_segmentSelection_groupBox");
        MS_segmentSelection_groupBox->setMinimumSize(QSize(0, 100));
        MS_segmentSelection_groupBox->setFont(font);
        gridLayout_3 = new QGridLayout(MS_segmentSelection_groupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        fullbodyMS_groupBox = new QGroupBox(MS_segmentSelection_groupBox);
        fullbodyMS_groupBox->setObjectName("fullbodyMS_groupBox");
        fullbodyMS_groupBox->setFont(font);
        gridLayout_4 = new QGridLayout(fullbodyMS_groupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        fullbodyMS_checkBox = new QCheckBox(fullbodyMS_groupBox);
        fullbodyMS_checkBox->setObjectName("fullbodyMS_checkBox");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fullbodyMS_checkBox->sizePolicy().hasHeightForWidth());
        fullbodyMS_checkBox->setSizePolicy(sizePolicy1);
        fullbodyMS_checkBox->setFont(font);

        gridLayout_4->addWidget(fullbodyMS_checkBox, 0, 0, 1, 1);


        gridLayout_3->addWidget(fullbodyMS_groupBox, 0, 0, 1, 1);

        upperbodyMS_groupBox = new QGroupBox(MS_segmentSelection_groupBox);
        upperbodyMS_groupBox->setObjectName("upperbodyMS_groupBox");
        upperbodyMS_groupBox->setFont(font);
        gridLayout_5 = new QGridLayout(upperbodyMS_groupBox);
        gridLayout_5->setObjectName("gridLayout_5");
        upperbodyMS_checkBox = new QCheckBox(upperbodyMS_groupBox);
        upperbodyMS_checkBox->setObjectName("upperbodyMS_checkBox");
        sizePolicy1.setHeightForWidth(upperbodyMS_checkBox->sizePolicy().hasHeightForWidth());
        upperbodyMS_checkBox->setSizePolicy(sizePolicy1);
        upperbodyMS_checkBox->setMinimumSize(QSize(0, 30));
        upperbodyMS_checkBox->setFont(font);

        gridLayout_5->addWidget(upperbodyMS_checkBox, 0, 0, 2, 1);

        ubRUA_MS_checkBox = new QCheckBox(upperbodyMS_groupBox);
        ubRUA_MS_checkBox->setObjectName("ubRUA_MS_checkBox");
        sizePolicy1.setHeightForWidth(ubRUA_MS_checkBox->sizePolicy().hasHeightForWidth());
        ubRUA_MS_checkBox->setSizePolicy(sizePolicy1);
        ubRUA_MS_checkBox->setFont(font);

        gridLayout_5->addWidget(ubRUA_MS_checkBox, 0, 1, 1, 1);

        ubRLA_MS_checkBox = new QCheckBox(upperbodyMS_groupBox);
        ubRLA_MS_checkBox->setObjectName("ubRLA_MS_checkBox");
        sizePolicy1.setHeightForWidth(ubRLA_MS_checkBox->sizePolicy().hasHeightForWidth());
        ubRLA_MS_checkBox->setSizePolicy(sizePolicy1);
        ubRLA_MS_checkBox->setFont(font);

        gridLayout_5->addWidget(ubRLA_MS_checkBox, 0, 2, 1, 1);

        ubLUA_MS_checkBox = new QCheckBox(upperbodyMS_groupBox);
        ubLUA_MS_checkBox->setObjectName("ubLUA_MS_checkBox");
        sizePolicy1.setHeightForWidth(ubLUA_MS_checkBox->sizePolicy().hasHeightForWidth());
        ubLUA_MS_checkBox->setSizePolicy(sizePolicy1);
        ubLUA_MS_checkBox->setFont(font);

        gridLayout_5->addWidget(ubLUA_MS_checkBox, 1, 1, 1, 1);

        ubLLA_MS_checkBox = new QCheckBox(upperbodyMS_groupBox);
        ubLLA_MS_checkBox->setObjectName("ubLLA_MS_checkBox");
        sizePolicy1.setHeightForWidth(ubLLA_MS_checkBox->sizePolicy().hasHeightForWidth());
        ubLLA_MS_checkBox->setSizePolicy(sizePolicy1);
        ubLLA_MS_checkBox->setFont(font);

        gridLayout_5->addWidget(ubLLA_MS_checkBox, 1, 2, 1, 1);


        gridLayout_3->addWidget(upperbodyMS_groupBox, 0, 1, 1, 1);

        torsoMS_groupBox = new QGroupBox(MS_segmentSelection_groupBox);
        torsoMS_groupBox->setObjectName("torsoMS_groupBox");
        torsoMS_groupBox->setFont(font);
        gridLayout_7 = new QGridLayout(torsoMS_groupBox);
        gridLayout_7->setObjectName("gridLayout_7");
        torPL_MS_checkBox = new QCheckBox(torsoMS_groupBox);
        torPL_MS_checkBox->setObjectName("torPL_MS_checkBox");
        sizePolicy1.setHeightForWidth(torPL_MS_checkBox->sizePolicy().hasHeightForWidth());
        torPL_MS_checkBox->setSizePolicy(sizePolicy1);
        torPL_MS_checkBox->setFont(font);

        gridLayout_7->addWidget(torPL_MS_checkBox, 0, 0, 1, 1);

        torCH_MS_checkBox = new QCheckBox(torsoMS_groupBox);
        torCH_MS_checkBox->setObjectName("torCH_MS_checkBox");
        sizePolicy1.setHeightForWidth(torCH_MS_checkBox->sizePolicy().hasHeightForWidth());
        torCH_MS_checkBox->setSizePolicy(sizePolicy1);
        torCH_MS_checkBox->setFont(font);

        gridLayout_7->addWidget(torCH_MS_checkBox, 0, 1, 1, 1);


        gridLayout_3->addWidget(torsoMS_groupBox, 0, 3, 1, 1);

        lowerbodyMS_groupBox = new QGroupBox(MS_segmentSelection_groupBox);
        lowerbodyMS_groupBox->setObjectName("lowerbodyMS_groupBox");
        lowerbodyMS_groupBox->setFont(font);
        gridLayout_6 = new QGridLayout(lowerbodyMS_groupBox);
        gridLayout_6->setObjectName("gridLayout_6");
        lowerbodyMS_checkBox = new QCheckBox(lowerbodyMS_groupBox);
        lowerbodyMS_checkBox->setObjectName("lowerbodyMS_checkBox");
        sizePolicy1.setHeightForWidth(lowerbodyMS_checkBox->sizePolicy().hasHeightForWidth());
        lowerbodyMS_checkBox->setSizePolicy(sizePolicy1);
        lowerbodyMS_checkBox->setMinimumSize(QSize(0, 30));
        lowerbodyMS_checkBox->setFont(font);

        gridLayout_6->addWidget(lowerbodyMS_checkBox, 0, 0, 2, 1);

        lbRUL_MS_checkBox = new QCheckBox(lowerbodyMS_groupBox);
        lbRUL_MS_checkBox->setObjectName("lbRUL_MS_checkBox");
        sizePolicy1.setHeightForWidth(lbRUL_MS_checkBox->sizePolicy().hasHeightForWidth());
        lbRUL_MS_checkBox->setSizePolicy(sizePolicy1);
        lbRUL_MS_checkBox->setFont(font);

        gridLayout_6->addWidget(lbRUL_MS_checkBox, 0, 1, 1, 1);

        lbRLL_MS_checkBox = new QCheckBox(lowerbodyMS_groupBox);
        lbRLL_MS_checkBox->setObjectName("lbRLL_MS_checkBox");
        sizePolicy1.setHeightForWidth(lbRLL_MS_checkBox->sizePolicy().hasHeightForWidth());
        lbRLL_MS_checkBox->setSizePolicy(sizePolicy1);
        lbRLL_MS_checkBox->setFont(font);

        gridLayout_6->addWidget(lbRLL_MS_checkBox, 0, 2, 1, 1);

        lbLUL_MS_checkBox = new QCheckBox(lowerbodyMS_groupBox);
        lbLUL_MS_checkBox->setObjectName("lbLUL_MS_checkBox");
        sizePolicy1.setHeightForWidth(lbLUL_MS_checkBox->sizePolicy().hasHeightForWidth());
        lbLUL_MS_checkBox->setSizePolicy(sizePolicy1);
        lbLUL_MS_checkBox->setFont(font);

        gridLayout_6->addWidget(lbLUL_MS_checkBox, 1, 1, 1, 1);

        lbLL_MS_checkBox = new QCheckBox(lowerbodyMS_groupBox);
        lbLL_MS_checkBox->setObjectName("lbLL_MS_checkBox");
        sizePolicy1.setHeightForWidth(lbLL_MS_checkBox->sizePolicy().hasHeightForWidth());
        lbLL_MS_checkBox->setSizePolicy(sizePolicy1);
        lbLL_MS_checkBox->setFont(font);

        gridLayout_6->addWidget(lbLL_MS_checkBox, 1, 2, 1, 1);


        gridLayout_3->addWidget(lowerbodyMS_groupBox, 0, 2, 1, 1);


        gridLayout->addWidget(MS_segmentSelection_groupBox, 1, 0, 1, 1);

        motionSphere_dialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(motionSphere_dialog);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 716, 23));
        menubar->setMinimumSize(QSize(0, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuFile->setFont(font);
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuTools_2 = new QMenu(menubar);
        menuTools_2->setObjectName("menuTools_2");
        menuAuthoring = new QMenu(menubar);
        menuAuthoring->setObjectName("menuAuthoring");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        motionSphere_dialog->setMenuBar(menubar);
        toolBar = new QToolBar(motionSphere_dialog);
        toolBar->setObjectName("toolBar");
        toolBar->setMinimumSize(QSize(0, 30));
        motionSphere_dialog->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuTools_2->menuAction());
        menubar->addAction(menuAuthoring->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionImport);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuTools_2->addAction(actionSegments_Props);
        menuTools_2->addSeparator();
        menuTools_2->addAction(actionRecord);
        menuTools_2->addAction(actionSnapshot);

        retranslateUi(motionSphere_dialog);

        QMetaObject::connectSlotsByName(motionSphere_dialog);
    } // setupUi

    void retranslateUi(QMainWindow *motionSphere_dialog)
    {
        motionSphere_dialog->setWindowTitle(QCoreApplication::translate("motionSphere_dialog", "Motion-Sphere", nullptr));
        actionNew->setText(QCoreApplication::translate("motionSphere_dialog", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("motionSphere_dialog", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("motionSphere_dialog", "Save..", nullptr));
        actionSave_As->setText(QCoreApplication::translate("motionSphere_dialog", "Save As..", nullptr));
        actionImport->setText(QCoreApplication::translate("motionSphere_dialog", "Import", nullptr));
        actionExport->setText(QCoreApplication::translate("motionSphere_dialog", "Export", nullptr));
        actionExit->setText(QCoreApplication::translate("motionSphere_dialog", "Exit", nullptr));
        actionSegments_Props->setText(QCoreApplication::translate("motionSphere_dialog", "Segments Props", nullptr));
        actionRecord->setText(QCoreApplication::translate("motionSphere_dialog", "Record", nullptr));
        actionSnapshot->setText(QCoreApplication::translate("motionSphere_dialog", "Snapshot", nullptr));
        MS_groupBox->setTitle(QCoreApplication::translate("motionSphere_dialog", "Motion-Sphere", nullptr));
        MS_segmentSelection_groupBox->setTitle(QCoreApplication::translate("motionSphere_dialog", "Segment Selection", nullptr));
        fullbodyMS_groupBox->setTitle(QCoreApplication::translate("motionSphere_dialog", "Fullbody", nullptr));
        fullbodyMS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "Fullbody", nullptr));
        upperbodyMS_groupBox->setTitle(QCoreApplication::translate("motionSphere_dialog", "Upperbody", nullptr));
        upperbodyMS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "Upper\n"
"Body", nullptr));
        ubRUA_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "RUA", nullptr));
        ubRLA_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "RLA", nullptr));
        ubLUA_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "LUA", nullptr));
        ubLLA_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "LLA", nullptr));
        torsoMS_groupBox->setTitle(QCoreApplication::translate("motionSphere_dialog", "Torso", nullptr));
        torPL_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "Pelvis", nullptr));
        torCH_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "Chest", nullptr));
        lowerbodyMS_groupBox->setTitle(QCoreApplication::translate("motionSphere_dialog", "Lowerbody", nullptr));
        lowerbodyMS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "Lower\n"
"Body", nullptr));
        lbRUL_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "RUL", nullptr));
        lbRLL_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "RLL", nullptr));
        lbLUL_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "LUL", nullptr));
        lbLL_MS_checkBox->setText(QCoreApplication::translate("motionSphere_dialog", "LLL", nullptr));
        menuFile->setTitle(QCoreApplication::translate("motionSphere_dialog", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("motionSphere_dialog", "Edit", nullptr));
        menuTools_2->setTitle(QCoreApplication::translate("motionSphere_dialog", "Tools", nullptr));
        menuAuthoring->setTitle(QCoreApplication::translate("motionSphere_dialog", "Authoring", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("motionSphere_dialog", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("motionSphere_dialog", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class motionSphere_dialog: public Ui_motionSphere_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTIONSPHERE_DIALOG_H
