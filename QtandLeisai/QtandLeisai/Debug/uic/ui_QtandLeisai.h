/********************************************************************************
** Form generated from reading UI file 'QtandLeisai.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTANDLEISAI_H
#define UI_QTANDLEISAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtandLeisaiClass
{
public:
    QWidget *centralWidget;
    QPushButton *Bt_CardLint;
    QPushButton *Bt_AxisEn;
    QPushButton *Bt_AxisRestEn;
    QPushButton *Bt_AxisJOGAdd;
    QPushButton *Bt_AxisJOGSub;
    QLineEdit *LE_AxisSpeed;
    QLabel *label;
    QLineEdit *LE_AxisPosition;
    QLabel *label_2;
    QPushButton *Bt_AxisRun;
    QPushButton *Bt_AxisStop;
    QPushButton *Bt_AxisGoHome;
    QCheckBox *chB_MoveOri;
    QLabel *label_4;
    QLabel *LB_MovePS;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtandLeisaiClass)
    {
        if (QtandLeisaiClass->objectName().isEmpty())
            QtandLeisaiClass->setObjectName(QString::fromUtf8("QtandLeisaiClass"));
        QtandLeisaiClass->resize(1112, 436);
        QtandLeisaiClass->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:2px groove gray;border-radius:10px;padding:2px 4px;\n"
"	font: 14pt \"\346\226\260\345\256\213\344\275\223\";\n"
"}                          \n"
"QPushButton:hover{\n"
"background-color:rgb(229, 241, 251); \n"
"color: black;}\n"
"QPushButton:pressed{\n"
"background-color:rgb(204, 228, 247);\n"
"border-style: inset;}"));
        centralWidget = new QWidget(QtandLeisaiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Bt_CardLint = new QPushButton(centralWidget);
        Bt_CardLint->setObjectName(QString::fromUtf8("Bt_CardLint"));
        Bt_CardLint->setGeometry(QRect(70, 50, 101, 41));
        Bt_AxisEn = new QPushButton(centralWidget);
        Bt_AxisEn->setObjectName(QString::fromUtf8("Bt_AxisEn"));
        Bt_AxisEn->setGeometry(QRect(190, 50, 101, 41));
        Bt_AxisRestEn = new QPushButton(centralWidget);
        Bt_AxisRestEn->setObjectName(QString::fromUtf8("Bt_AxisRestEn"));
        Bt_AxisRestEn->setGeometry(QRect(190, 100, 101, 41));
        Bt_AxisJOGAdd = new QPushButton(centralWidget);
        Bt_AxisJOGAdd->setObjectName(QString::fromUtf8("Bt_AxisJOGAdd"));
        Bt_AxisJOGAdd->setGeometry(QRect(310, 50, 101, 41));
        Bt_AxisJOGSub = new QPushButton(centralWidget);
        Bt_AxisJOGSub->setObjectName(QString::fromUtf8("Bt_AxisJOGSub"));
        Bt_AxisJOGSub->setGeometry(QRect(310, 100, 101, 41));
        LE_AxisSpeed = new QLineEdit(centralWidget);
        LE_AxisSpeed->setObjectName(QString::fromUtf8("LE_AxisSpeed"));
        LE_AxisSpeed->setGeometry(QRect(600, 50, 101, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 60, 51, 21));
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        LE_AxisPosition = new QLineEdit(centralWidget);
        LE_AxisPosition->setObjectName(QString::fromUtf8("LE_AxisPosition"));
        LE_AxisPosition->setGeometry(QRect(600, 90, 101, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(490, 100, 91, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        Bt_AxisRun = new QPushButton(centralWidget);
        Bt_AxisRun->setObjectName(QString::fromUtf8("Bt_AxisRun"));
        Bt_AxisRun->setGeometry(QRect(600, 130, 101, 41));
        Bt_AxisStop = new QPushButton(centralWidget);
        Bt_AxisStop->setObjectName(QString::fromUtf8("Bt_AxisStop"));
        Bt_AxisStop->setGeometry(QRect(600, 180, 101, 41));
        Bt_AxisGoHome = new QPushButton(centralWidget);
        Bt_AxisGoHome->setObjectName(QString::fromUtf8("Bt_AxisGoHome"));
        Bt_AxisGoHome->setGeometry(QRect(200, 160, 101, 41));
        chB_MoveOri = new QCheckBox(centralWidget);
        chB_MoveOri->setObjectName(QString::fromUtf8("chB_MoveOri"));
        chB_MoveOri->setGeometry(QRect(730, 90, 71, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 20, 101, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        LB_MovePS = new QLabel(centralWidget);
        LB_MovePS->setObjectName(QString::fromUtf8("LB_MovePS"));
        LB_MovePS->setGeometry(QRect(590, 20, 101, 21));
        LB_MovePS->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        QtandLeisaiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtandLeisaiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1112, 23));
        QtandLeisaiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtandLeisaiClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtandLeisaiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtandLeisaiClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtandLeisaiClass->setStatusBar(statusBar);

        retranslateUi(QtandLeisaiClass);

        QMetaObject::connectSlotsByName(QtandLeisaiClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtandLeisaiClass)
    {
        QtandLeisaiClass->setWindowTitle(QCoreApplication::translate("QtandLeisaiClass", "QtandLeisai", nullptr));
        Bt_CardLint->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\210\235\345\247\213\345\214\226", nullptr));
        Bt_AxisEn->setText(QCoreApplication::translate("QtandLeisaiClass", "\350\275\264\344\275\277\350\203\275", nullptr));
        Bt_AxisRestEn->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\244\215\344\275\215\344\275\277\350\203\275", nullptr));
        Bt_AxisJOGAdd->setText(QCoreApplication::translate("QtandLeisaiClass", "JOG+", nullptr));
        Bt_AxisJOGSub->setText(QCoreApplication::translate("QtandLeisaiClass", "JOG-", nullptr));
        label->setText(QCoreApplication::translate("QtandLeisaiClass", "\351\200\237\345\272\246\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("QtandLeisaiClass", "\347\233\256\346\240\207\344\275\215\347\275\256\357\274\232", nullptr));
        Bt_AxisRun->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\220\257\345\212\250", nullptr));
        Bt_AxisStop->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\201\234\346\255\242", nullptr));
        Bt_AxisGoHome->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\233\236\345\216\237\347\202\271", nullptr));
        chB_MoveOri->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\217\215\345\220\221", nullptr));
        label_4->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\275\223\345\211\215\344\275\215\347\275\256\357\274\232", nullptr));
        LB_MovePS->setText(QCoreApplication::translate("QtandLeisaiClass", ".", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtandLeisaiClass: public Ui_QtandLeisaiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTANDLEISAI_H
