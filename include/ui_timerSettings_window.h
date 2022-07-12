/********************************************************************************
** Form generated from reading UI file 'timerSettings_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERSETTINGS_WINDOW_H
#define UI_TIMERSETTINGS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timerSettings_Window
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QCheckBox *checkBox;
    QLabel *label;
    QSpinBox *spinBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QLabel *label_4;
    QSpinBox *timerStart_spinBox;
    QLabel *label_5;
    QSpinBox *spinBox_3;
    QLabel *label_6;
    QSpinBox *timerEnd_spinBox;
    QLabel *label_7;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_3;
    QLabel *label_8;
    QSpinBox *spinBox_6;
    QPushButton *timerSubmit_pushButton;
    QPushButton *timerClose;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_3;
    QLabel *label_2;
    QRadioButton *quater_speed;
    QRadioButton *half_speed;
    QRadioButton *one_speed;
    QRadioButton *two_speed;
    QLabel *label_3;
    QRadioButton *forwardPlayback;
    QRadioButton *reversePlayback;

    void setupUi(QMainWindow *timerSettings_Window)
    {
        if (timerSettings_Window->objectName().isEmpty())
            timerSettings_Window->setObjectName("timerSettings_Window");
        timerSettings_Window->resize(336, 478);
        timerSettings_Window->setMinimumSize(QSize(336, 0));
        timerSettings_Window->setMaximumSize(QSize(336, 478));
        timerSettings_Window->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 68);\n"
"color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(timerSettings_Window);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        groupBox->setFont(font);
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName("gridLayout_6");
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName("radioButton");

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName("radioButton_2");

        gridLayout_2->addWidget(radioButton_2, 0, 1, 1, 2);

        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName("radioButton_3");

        gridLayout_2->addWidget(radioButton_3, 1, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName("radioButton_4");

        gridLayout_2->addWidget(radioButton_4, 1, 1, 1, 2);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName("checkBox");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(checkBox, 2, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label, 2, 1, 1, 1);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName("spinBox");

        gridLayout_2->addWidget(spinBox, 2, 2, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 0, 0, 1, 2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName("gridLayout_3");
        radioButton_5 = new QRadioButton(groupBox_3);
        radioButton_5->setObjectName("radioButton_5");
        sizePolicy.setHeightForWidth(radioButton_5->sizePolicy().hasHeightForWidth());
        radioButton_5->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(radioButton_5, 0, 0, 1, 1);

        radioButton_6 = new QRadioButton(groupBox_3);
        radioButton_6->setObjectName("radioButton_6");
        sizePolicy.setHeightForWidth(radioButton_6->sizePolicy().hasHeightForWidth());
        radioButton_6->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(radioButton_6, 1, 0, 1, 1);

        radioButton_7 = new QRadioButton(groupBox_3);
        radioButton_7->setObjectName("radioButton_7");

        gridLayout_3->addWidget(radioButton_7, 2, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName("groupBox_5");
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName("gridLayout_5");
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName("label_4");

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

        timerStart_spinBox = new QSpinBox(groupBox_5);
        timerStart_spinBox->setObjectName("timerStart_spinBox");

        gridLayout_5->addWidget(timerStart_spinBox, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName("label_5");

        gridLayout_5->addWidget(label_5, 0, 2, 1, 1);

        spinBox_3 = new QSpinBox(groupBox_5);
        spinBox_3->setObjectName("spinBox_3");

        gridLayout_5->addWidget(spinBox_3, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName("label_6");

        gridLayout_5->addWidget(label_6, 1, 0, 1, 1);

        timerEnd_spinBox = new QSpinBox(groupBox_5);
        timerEnd_spinBox->setObjectName("timerEnd_spinBox");

        gridLayout_5->addWidget(timerEnd_spinBox, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName("label_7");

        gridLayout_5->addWidget(label_7, 1, 2, 1, 1);

        spinBox_5 = new QSpinBox(groupBox_5);
        spinBox_5->setObjectName("spinBox_5");

        gridLayout_5->addWidget(spinBox_5, 1, 3, 1, 1);

        pushButton_3 = new QPushButton(groupBox_5);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout_5->addWidget(pushButton_3, 2, 0, 1, 2);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName("label_8");

        gridLayout_5->addWidget(label_8, 2, 2, 1, 1);

        spinBox_6 = new QSpinBox(groupBox_5);
        spinBox_6->setObjectName("spinBox_6");

        gridLayout_5->addWidget(spinBox_6, 2, 3, 1, 1);


        gridLayout_6->addWidget(groupBox_5, 2, 0, 1, 3);

        timerSubmit_pushButton = new QPushButton(groupBox);
        timerSubmit_pushButton->setObjectName("timerSubmit_pushButton");

        gridLayout_6->addWidget(timerSubmit_pushButton, 3, 0, 1, 1);

        timerClose = new QPushButton(groupBox);
        timerClose->setObjectName("timerClose");

        gridLayout_6->addWidget(timerClose, 3, 2, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName("gridLayout_4");
        checkBox_2 = new QCheckBox(groupBox_4);
        checkBox_2->setObjectName("checkBox_2");
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(checkBox_2, 0, 0, 1, 2);

        checkBox_4 = new QCheckBox(groupBox_4);
        checkBox_4->setObjectName("checkBox_4");
        sizePolicy.setHeightForWidth(checkBox_4->sizePolicy().hasHeightForWidth());
        checkBox_4->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(checkBox_4, 0, 2, 1, 2);

        checkBox_3 = new QCheckBox(groupBox_4);
        checkBox_3->setObjectName("checkBox_3");
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(checkBox_3, 0, 4, 1, 2);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName("label_2");

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        quater_speed = new QRadioButton(groupBox_4);
        quater_speed->setObjectName("quater_speed");
        sizePolicy.setHeightForWidth(quater_speed->sizePolicy().hasHeightForWidth());
        quater_speed->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(quater_speed, 1, 1, 1, 1);

        half_speed = new QRadioButton(groupBox_4);
        half_speed->setObjectName("half_speed");
        sizePolicy.setHeightForWidth(half_speed->sizePolicy().hasHeightForWidth());
        half_speed->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(half_speed, 1, 2, 1, 2);

        one_speed = new QRadioButton(groupBox_4);
        one_speed->setObjectName("one_speed");

        gridLayout_4->addWidget(one_speed, 1, 4, 1, 1);

        two_speed = new QRadioButton(groupBox_4);
        two_speed->setObjectName("two_speed");

        gridLayout_4->addWidget(two_speed, 1, 5, 1, 1);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName("label_3");

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        forwardPlayback = new QRadioButton(groupBox_4);
        forwardPlayback->setObjectName("forwardPlayback");
        sizePolicy.setHeightForWidth(forwardPlayback->sizePolicy().hasHeightForWidth());
        forwardPlayback->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(forwardPlayback, 2, 1, 1, 2);

        reversePlayback = new QRadioButton(groupBox_4);
        reversePlayback->setObjectName("reversePlayback");
        sizePolicy.setHeightForWidth(reversePlayback->sizePolicy().hasHeightForWidth());
        reversePlayback->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(reversePlayback, 2, 3, 1, 2);


        gridLayout_6->addWidget(groupBox_4, 1, 0, 1, 3);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        timerSettings_Window->setCentralWidget(centralwidget);

        retranslateUi(timerSettings_Window);

        QMetaObject::connectSlotsByName(timerSettings_Window);
    } // setupUi

    void retranslateUi(QMainWindow *timerSettings_Window)
    {
        timerSettings_Window->setWindowTitle(QCoreApplication::translate("timerSettings_Window", "timerSettings_Window", nullptr));
        groupBox->setTitle(QCoreApplication::translate("timerSettings_Window", "Timer Settings", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("timerSettings_Window", "Frame Rate", nullptr));
        radioButton->setText(QCoreApplication::translate("timerSettings_Window", "RadioButton", nullptr));
        radioButton_2->setText(QCoreApplication::translate("timerSettings_Window", "RadioButton", nullptr));
        radioButton_3->setText(QCoreApplication::translate("timerSettings_Window", "RadioButton", nullptr));
        radioButton_4->setText(QCoreApplication::translate("timerSettings_Window", "RadioButton", nullptr));
        checkBox->setText(QCoreApplication::translate("timerSettings_Window", "Adjust \n"
"Keys", nullptr));
        label->setText(QCoreApplication::translate("timerSettings_Window", "FPS", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("timerSettings_Window", "Time Display", nullptr));
        radioButton_5->setText(QCoreApplication::translate("timerSettings_Window", "Frames", nullptr));
        radioButton_6->setText(QCoreApplication::translate("timerSettings_Window", "TICKS", nullptr));
        radioButton_7->setText(QCoreApplication::translate("timerSettings_Window", "RadioButton", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("timerSettings_Window", "Animation", nullptr));
        label_4->setText(QCoreApplication::translate("timerSettings_Window", "Start Time", nullptr));
        label_5->setText(QCoreApplication::translate("timerSettings_Window", "Length", nullptr));
        label_6->setText(QCoreApplication::translate("timerSettings_Window", "End Time", nullptr));
        label_7->setText(QCoreApplication::translate("timerSettings_Window", "Frame Count", nullptr));
        pushButton_3->setText(QCoreApplication::translate("timerSettings_Window", "Rest Timer", nullptr));
        label_8->setText(QCoreApplication::translate("timerSettings_Window", "Current Time", nullptr));
        timerSubmit_pushButton->setText(QCoreApplication::translate("timerSettings_Window", "OK", nullptr));
        timerClose->setText(QCoreApplication::translate("timerSettings_Window", "Close", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("timerSettings_Window", "Playback", nullptr));
        checkBox_2->setText(QCoreApplication::translate("timerSettings_Window", "Real Time", nullptr));
        checkBox_4->setText(QCoreApplication::translate("timerSettings_Window", "Loop", nullptr));
        checkBox_3->setText(QCoreApplication::translate("timerSettings_Window", "Active Viewport ", nullptr));
        label_2->setText(QCoreApplication::translate("timerSettings_Window", "Speed:", nullptr));
        quater_speed->setText(QCoreApplication::translate("timerSettings_Window", "1/4x", nullptr));
        half_speed->setText(QCoreApplication::translate("timerSettings_Window", "1/2x", nullptr));
        one_speed->setText(QCoreApplication::translate("timerSettings_Window", "1x", nullptr));
        two_speed->setText(QCoreApplication::translate("timerSettings_Window", "2x", nullptr));
        label_3->setText(QCoreApplication::translate("timerSettings_Window", "Direction", nullptr));
        forwardPlayback->setText(QCoreApplication::translate("timerSettings_Window", "Forward", nullptr));
        reversePlayback->setText(QCoreApplication::translate("timerSettings_Window", "Reverse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class timerSettings_Window: public Ui_timerSettings_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERSETTINGS_WINDOW_H
