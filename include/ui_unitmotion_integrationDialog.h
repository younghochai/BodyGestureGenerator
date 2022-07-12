///********************************************************************************
//** Form generated from reading UI file 'unitmotion_integrationDialog.ui'
//**
//** Created by: Qt User Interface Compiler version 6.4.0
//**
//** WARNING! All changes made in this file will be lost when recompiling UI file!
//********************************************************************************/
//
//#ifndef UI_UNITMOTION_INTEGRATIONDIALOG_H
//#define UI_UNITMOTION_INTEGRATIONDIALOG_H
//
//#include <QtCore/QVariant>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QGridLayout>
//#include <QtWidgets/QGroupBox>
//#include <QtWidgets/QMainWindow>
//#include <QtWidgets/QMenuBar>
//#include <QtWidgets/QPushButton>
//#include <QtWidgets/QRadioButton>
//#include <QtWidgets/QSpacerItem>
//#include <QtWidgets/QStatusBar>
//#include <QtWidgets/QWidget>
//
//QT_BEGIN_NAMESPACE
//
//class Ui_unitMotion_integrationDialog
//{
//public:
//    QWidget *centralwidget;
//    QGridLayout *gridLayout;
//    QGroupBox *umBlending_groupBox;
//    QGridLayout *gridLayout_2;
//    QGroupBox *groupBox;
//    QGridLayout *gridLayout_3;
//    QWidget *widget;
//    QRadioButton *sequentialBlending;
//    QRadioButton *superImposed;
//    QSpacerItem *horizontalSpacer;
//    QPushButton *blendUM;
//    QPushButton *discardUM;
//    QMenuBar *menubar;
//    QStatusBar *statusbar;
//
//    void setupUi(QMainWindow *unitMotion_integrationDialog)
//    {
//        if (unitMotion_integrationDialog->objectName().isEmpty())
//            unitMotion_integrationDialog->setObjectName("unitMotion_integrationDialog");
//        unitMotion_integrationDialog->resize(231, 262);
//        unitMotion_integrationDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 68);"));
//        centralwidget = new QWidget(unitMotion_integrationDialog);
//        centralwidget->setObjectName("centralwidget");
//        gridLayout = new QGridLayout(centralwidget);
//        gridLayout->setObjectName("gridLayout");
//        umBlending_groupBox = new QGroupBox(centralwidget);
//        umBlending_groupBox->setObjectName("umBlending_groupBox");
//        QFont font;
//        font.setPointSize(9);
//        umBlending_groupBox->setFont(font);
//        umBlending_groupBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
//        gridLayout_2 = new QGridLayout(umBlending_groupBox);
//        gridLayout_2->setObjectName("gridLayout_2");
//        groupBox = new QGroupBox(umBlending_groupBox);
//        groupBox->setObjectName("groupBox");
//        gridLayout_3 = new QGridLayout(groupBox);
//        gridLayout_3->setObjectName("gridLayout_3");
//        widget = new QWidget(groupBox);
//        widget->setObjectName("widget");
//        sequentialBlending = new QRadioButton(widget);
//        sequentialBlending->setObjectName("sequentialBlending");
//        sequentialBlending->setGeometry(QRect(20, 10, 82, 17));
//        superImposed = new QRadioButton(widget);
//        superImposed->setObjectName("superImposed");
//        superImposed->setGeometry(QRect(20, 40, 101, 17));
//
//        gridLayout_3->addWidget(widget, 0, 0, 1, 1);
//
//
//        gridLayout_2->addWidget(groupBox, 0, 0, 1, 3);
//
//        horizontalSpacer = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//
//        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);
//
//        blendUM = new QPushButton(umBlending_groupBox);
//        blendUM->setObjectName("blendUM");
//        blendUM->setFont(font);
//
//        gridLayout_2->addWidget(blendUM, 1, 1, 1, 1);
//
//        discardUM = new QPushButton(umBlending_groupBox);
//        discardUM->setObjectName("discardUM");
//        discardUM->setFont(font);
//
//        gridLayout_2->addWidget(discardUM, 1, 2, 1, 1);
//
//
//        gridLayout->addWidget(umBlending_groupBox, 0, 0, 1, 1);
//
//        unitMotion_integrationDialog->setCentralWidget(centralwidget);
//        menubar = new QMenuBar(unitMotion_integrationDialog);
//        menubar->setObjectName("menubar");
//        menubar->setGeometry(QRect(0, 0, 231, 21));
//        unitMotion_integrationDialog->setMenuBar(menubar);
//        statusbar = new QStatusBar(unitMotion_integrationDialog);
//        statusbar->setObjectName("statusbar");
//        unitMotion_integrationDialog->setStatusBar(statusbar);
//
//        retranslateUi(unitMotion_integrationDialog);
//
//        QMetaObject::connectSlotsByName(unitMotion_integrationDialog);
//    } // setupUi
//
//    void retranslateUi(QMainWindow *unitMotion_integrationDialog)
//    {
//        unitMotion_integrationDialog->setWindowTitle(QCoreApplication::translate("unitMotion_integrationDialog", "unitMotion_integrationDialog", nullptr));
//        umBlending_groupBox->setTitle(QCoreApplication::translate("unitMotion_integrationDialog", "Unit Motion Blending Options", nullptr));
//        groupBox->setTitle(QCoreApplication::translate("unitMotion_integrationDialog", "Blend Type", nullptr));
//        sequentialBlending->setText(QCoreApplication::translate("unitMotion_integrationDialog", "Sequential ", nullptr));
//        superImposed->setText(QCoreApplication::translate("unitMotion_integrationDialog", "Superimposed ", nullptr));
//        blendUM->setText(QCoreApplication::translate("unitMotion_integrationDialog", "Blend", nullptr));
//        discardUM->setText(QCoreApplication::translate("unitMotion_integrationDialog", "Discard", nullptr));
//    } // retranslateUi
//
//};
//
//namespace Ui {
//    class unitMotion_integrationDialog: public Ui_unitMotion_integrationDialog {};
//} // namespace Ui
//
//QT_END_NAMESPACE
//
//#endif // UI_UNITMOTION_INTEGRATIONDIALOG_H
