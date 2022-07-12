/********************************************************************************
** Form generated from reading UI file 'constraintprops.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSTRAINTPROPS_H
#define UI_CONSTRAINTPROPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_constraintProps
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_2;
    QComboBox *selectProp_comboBox;
    QSpinBox *scaleProp_spinBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *constraintProps)
    {
        if (constraintProps->objectName().isEmpty())
            constraintProps->setObjectName("constraintProps");
        constraintProps->resize(256, 402);
        centralwidget = new QWidget(constraintProps);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setBold(true);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        label = new QLabel(groupBox_2);
        label->setObjectName("label");

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        selectProp_comboBox = new QComboBox(groupBox_2);
        selectProp_comboBox->setObjectName("selectProp_comboBox");

        gridLayout_3->addWidget(selectProp_comboBox, 0, 1, 1, 1);

        scaleProp_spinBox = new QSpinBox(groupBox_2);
        scaleProp_spinBox->setObjectName("scaleProp_spinBox");

        gridLayout_3->addWidget(scaleProp_spinBox, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName("gridLayout_4");
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");

        gridLayout_4->addWidget(label_5, 5, 0, 1, 1);

        horizontalSlider = new QSlider(groupBox_3);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider, 2, 0, 1, 2);

        horizontalSlider_2 = new QSlider(groupBox_3);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider_2, 4, 0, 1, 2);

        horizontalSlider_3 = new QSlider(groupBox_3);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider_3, 6, 0, 1, 2);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        constraintProps->setCentralWidget(centralwidget);
        menubar = new QMenuBar(constraintProps);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 256, 21));
        constraintProps->setMenuBar(menubar);
        statusbar = new QStatusBar(constraintProps);
        statusbar->setObjectName("statusbar");
        constraintProps->setStatusBar(statusbar);

        retranslateUi(constraintProps);

        QMetaObject::connectSlotsByName(constraintProps);
    } // setupUi

    void retranslateUi(QMainWindow *constraintProps)
    {
        constraintProps->setWindowTitle(QCoreApplication::translate("constraintProps", "constraintProps", nullptr));
        groupBox->setTitle(QCoreApplication::translate("constraintProps", "Constraint Props", nullptr));
        pushButton->setText(QCoreApplication::translate("constraintProps", "Reset", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("constraintProps", "Prop List", nullptr));
        label->setText(QCoreApplication::translate("constraintProps", "Select Prop", nullptr));
        label_2->setText(QCoreApplication::translate("constraintProps", "Scale Prop", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("constraintProps", "Prop Orientation", nullptr));
        label_4->setText(QCoreApplication::translate("constraintProps", "Y-Rotation", nullptr));
        label_5->setText(QCoreApplication::translate("constraintProps", "Z-Rotation", nullptr));
        label_3->setText(QCoreApplication::translate("constraintProps", "X-Rotation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class constraintProps: public Ui_constraintProps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSTRAINTPROPS_H
