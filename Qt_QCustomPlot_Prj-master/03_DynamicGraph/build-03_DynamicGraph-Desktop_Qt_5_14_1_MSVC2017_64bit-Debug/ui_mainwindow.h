/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *widget_1;
    QWidget *widget;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox;
    QPushButton *pushButton_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *LabelX_2;
    QLineEdit *LineX_2;
    QFormLayout *formLayout_4;
    QLabel *LabelY_2;
    QLineEdit *LineY_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(644, 435);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_1 = new QCustomPlot(centralwidget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));

        horizontalLayout->addWidget(widget_1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(120, 2000));
        checkBox_1 = new QCheckBox(widget);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setEnabled(true);
        checkBox_1->setGeometry(QRect(9, 9, 52, 19));
        checkBox_1->setChecked(true);
        checkBox_2 = new QCheckBox(widget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(9, 50, 52, 19));
        checkBox_2->setChecked(true);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-10, 130, 111, 151));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 110, 71, 23));
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 30, 81, 61));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        LabelX_2 = new QLabel(layoutWidget_2);
        LabelX_2->setObjectName(QString::fromUtf8("LabelX_2"));
        LabelX_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, LabelX_2);

        LineX_2 = new QLineEdit(layoutWidget_2);
        LineX_2->setObjectName(QString::fromUtf8("LineX_2"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, LineX_2);


        verticalLayout_3->addLayout(formLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        LabelY_2 = new QLabel(layoutWidget_2);
        LabelY_2->setObjectName(QString::fromUtf8("LabelY_2"));
        LabelY_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, LabelY_2);

        LineY_2 = new QLineEdit(layoutWidget_2);
        LineY_2->setObjectName(QString::fromUtf8("LineY_2"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, LineY_2);


        verticalLayout_3->addLayout(formLayout_4);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 644, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox_1->setText(QCoreApplication::translate("MainWindow", "\346\263\242\345\275\2421", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\345\275\2422", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\250\241\346\213\237\345\256\236\346\227\266\346\225\260\346\215\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "push", nullptr));
        LabelX_2->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        LabelY_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
