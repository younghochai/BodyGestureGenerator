/********************************************************************************
** Form generated from reading UI file 'jointsphere_Dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINTSPHERE_DIALOG_H
#define UI_JOINTSPHERE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jointSphere_Dialog
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QCheckBox *rua_JS_checkBox;
    QCheckBox *lua_JS_checkBox;
    QCheckBox *lla_JS_checkBox;
    QCheckBox *rla_JS_checkBox;
    QCheckBox *ub_JS_checkBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QCheckBox *lb_JS_checkBox;
    QCheckBox *rul_JS_checkBox;
    QCheckBox *rll_JS_checkBox;
    QCheckBox *lul_JS_checkBox;
    QCheckBox *lll_JS_checkBox;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_6;
    QDoubleSpinBox *JSwidth_doubleSpinBox;
    QLabel *label;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_3;
    QCheckBox *fb_JS_checkBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QMainWindow *jointSphere_Dialog)
    {
        if (jointSphere_Dialog->objectName().isEmpty())
            jointSphere_Dialog->setObjectName("jointSphere_Dialog");
        jointSphere_Dialog->resize(264, 290);
        jointSphere_Dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 68);\n"
"color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(jointSphere_Dialog);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName("gridLayout_4");
        rua_JS_checkBox = new QCheckBox(groupBox_2);
        rua_JS_checkBox->setObjectName("rua_JS_checkBox");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rua_JS_checkBox->sizePolicy().hasHeightForWidth());
        rua_JS_checkBox->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(rua_JS_checkBox, 1, 0, 1, 1);

        lua_JS_checkBox = new QCheckBox(groupBox_2);
        lua_JS_checkBox->setObjectName("lua_JS_checkBox");
        sizePolicy.setHeightForWidth(lua_JS_checkBox->sizePolicy().hasHeightForWidth());
        lua_JS_checkBox->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(lua_JS_checkBox, 2, 0, 1, 1);

        lla_JS_checkBox = new QCheckBox(groupBox_2);
        lla_JS_checkBox->setObjectName("lla_JS_checkBox");

        gridLayout_4->addWidget(lla_JS_checkBox, 2, 1, 1, 1);

        rla_JS_checkBox = new QCheckBox(groupBox_2);
        rla_JS_checkBox->setObjectName("rla_JS_checkBox");
        sizePolicy.setHeightForWidth(rla_JS_checkBox->sizePolicy().hasHeightForWidth());
        rla_JS_checkBox->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(rla_JS_checkBox, 1, 1, 1, 1);

        ub_JS_checkBox = new QCheckBox(groupBox_2);
        ub_JS_checkBox->setObjectName("ub_JS_checkBox");
        sizePolicy.setHeightForWidth(ub_JS_checkBox->sizePolicy().hasHeightForWidth());
        ub_JS_checkBox->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(ub_JS_checkBox, 0, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName("gridLayout_5");
        lb_JS_checkBox = new QCheckBox(groupBox_3);
        lb_JS_checkBox->setObjectName("lb_JS_checkBox");
        sizePolicy.setHeightForWidth(lb_JS_checkBox->sizePolicy().hasHeightForWidth());
        lb_JS_checkBox->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(lb_JS_checkBox, 0, 0, 1, 2);

        rul_JS_checkBox = new QCheckBox(groupBox_3);
        rul_JS_checkBox->setObjectName("rul_JS_checkBox");
        sizePolicy.setHeightForWidth(rul_JS_checkBox->sizePolicy().hasHeightForWidth());
        rul_JS_checkBox->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(rul_JS_checkBox, 1, 0, 1, 1);

        rll_JS_checkBox = new QCheckBox(groupBox_3);
        rll_JS_checkBox->setObjectName("rll_JS_checkBox");
        sizePolicy.setHeightForWidth(rll_JS_checkBox->sizePolicy().hasHeightForWidth());
        rll_JS_checkBox->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(rll_JS_checkBox, 1, 1, 1, 1);

        lul_JS_checkBox = new QCheckBox(groupBox_3);
        lul_JS_checkBox->setObjectName("lul_JS_checkBox");
        sizePolicy.setHeightForWidth(lul_JS_checkBox->sizePolicy().hasHeightForWidth());
        lul_JS_checkBox->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(lul_JS_checkBox, 2, 0, 1, 1);

        lll_JS_checkBox = new QCheckBox(groupBox_3);
        lll_JS_checkBox->setObjectName("lll_JS_checkBox");

        gridLayout_5->addWidget(lll_JS_checkBox, 2, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout_6 = new QGridLayout(groupBox_4);
        gridLayout_6->setObjectName("gridLayout_6");
        JSwidth_doubleSpinBox = new QDoubleSpinBox(groupBox_4);
        JSwidth_doubleSpinBox->setObjectName("JSwidth_doubleSpinBox");
        sizePolicy.setHeightForWidth(JSwidth_doubleSpinBox->sizePolicy().hasHeightForWidth());
        JSwidth_doubleSpinBox->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(JSwidth_doubleSpinBox, 0, 1, 1, 1);

        label = new QLabel(groupBox_4);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 2, 0, 1, 2);

        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName("groupBox_6");
        gridLayout_3 = new QGridLayout(groupBox_6);
        gridLayout_3->setObjectName("gridLayout_3");
        fb_JS_checkBox = new QCheckBox(groupBox_6);
        fb_JS_checkBox->setObjectName("fb_JS_checkBox");
        sizePolicy.setHeightForWidth(fb_JS_checkBox->sizePolicy().hasHeightForWidth());
        fb_JS_checkBox->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(fb_JS_checkBox, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_6, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 0, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 3, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        jointSphere_Dialog->setCentralWidget(centralwidget);

        retranslateUi(jointSphere_Dialog);

        QMetaObject::connectSlotsByName(jointSphere_Dialog);
    } // setupUi

    void retranslateUi(QMainWindow *jointSphere_Dialog)
    {
        jointSphere_Dialog->setWindowTitle(QCoreApplication::translate("jointSphere_Dialog", "jointSphere", nullptr));
        groupBox->setTitle(QCoreApplication::translate("jointSphere_Dialog", "Joint Sphere", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("jointSphere_Dialog", "Upperbody", nullptr));
        rua_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "RUA", nullptr));
        lua_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "LUA", nullptr));
        lla_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "LLA", nullptr));
        rla_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "RLA", nullptr));
        ub_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "Upperbody", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("jointSphere_Dialog", "Lowerbody", nullptr));
        lb_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "Lowerbody", nullptr));
        rul_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "RUL", nullptr));
        rll_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "RLL", nullptr));
        lul_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "LUL", nullptr));
        lll_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "LLL", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("jointSphere_Dialog", "Trajectory Settings", nullptr));
        label->setText(QCoreApplication::translate("jointSphere_Dialog", "Trajectory Width", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("jointSphere_Dialog", "Fullbody", nullptr));
        fb_JS_checkBox->setText(QCoreApplication::translate("jointSphere_Dialog", "Fullbody", nullptr));
        pushButton->setText(QCoreApplication::translate("jointSphere_Dialog", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jointSphere_Dialog: public Ui_jointSphere_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINTSPHERE_DIALOG_H
