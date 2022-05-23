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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtandLeisaiClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *Bt_AxisGoHome;
    QPushButton *Bt_AxisEn;
    QPushButton *Bt_CardLint;
    QPushButton *Bt_AxisRestEn;
    QLabel *LB_AixsSta;
    QLabel *label_6;
    QPushButton *Bt_CleanAisxWarn;
    QPushButton *Bt_CardClose;
    QPushButton *Bt_RunTime;
    QGroupBox *groupBox_2;
    QPushButton *Bt_AxisJOGSub;
    QPushButton *Bt_AxisJOGAdd;
    QLabel *LB_MovePS;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *Bt_AxisRunAbs;
    QPushButton *Bt_AxisStop;
    QLabel *label;
    QLineEdit *LE_AxisSpeed;
    QCheckBox *chB_MoveOri;
    QLineEdit *LE_AxisPosition;
    QPushButton *Bt_AxisRunRel;
    QLabel *label_5;
    QLabel *LB_Aixs_Move_Sta;
    QLabel *label_3;
    QLineEdit *LE_JogMoveVlue;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QTableWidget *TK;
    QLineEdit *LE_OutPutVule;
    QLabel *label_7;
    QPushButton *Bt_SetOut;
    QPushButton *Bt_RestOut;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtandLeisaiClass)
    {
        if (QtandLeisaiClass->objectName().isEmpty())
            QtandLeisaiClass->setObjectName(QString::fromUtf8("QtandLeisaiClass"));
        QtandLeisaiClass->resize(1234, 682);
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
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 301, 291));
        groupBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\260\345\256\213\344\275\223\";"));
        Bt_AxisGoHome = new QPushButton(groupBox);
        Bt_AxisGoHome->setObjectName(QString::fromUtf8("Bt_AxisGoHome"));
        Bt_AxisGoHome->setGeometry(QRect(130, 190, 131, 41));
        Bt_AxisEn = new QPushButton(groupBox);
        Bt_AxisEn->setObjectName(QString::fromUtf8("Bt_AxisEn"));
        Bt_AxisEn->setGeometry(QRect(20, 140, 101, 41));
        Bt_CardLint = new QPushButton(groupBox);
        Bt_CardLint->setObjectName(QString::fromUtf8("Bt_CardLint"));
        Bt_CardLint->setGeometry(QRect(20, 90, 101, 41));
        Bt_AxisRestEn = new QPushButton(groupBox);
        Bt_AxisRestEn->setObjectName(QString::fromUtf8("Bt_AxisRestEn"));
        Bt_AxisRestEn->setGeometry(QRect(20, 190, 101, 41));
        LB_AixsSta = new QLabel(groupBox);
        LB_AixsSta->setObjectName(QString::fromUtf8("LB_AixsSta"));
        LB_AixsSta->setGeometry(QRect(140, 50, 101, 21));
        LB_AixsSta->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 50, 101, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        Bt_CleanAisxWarn = new QPushButton(groupBox);
        Bt_CleanAisxWarn->setObjectName(QString::fromUtf8("Bt_CleanAisxWarn"));
        Bt_CleanAisxWarn->setGeometry(QRect(130, 140, 131, 41));
        Bt_CardClose = new QPushButton(groupBox);
        Bt_CardClose->setObjectName(QString::fromUtf8("Bt_CardClose"));
        Bt_CardClose->setGeometry(QRect(130, 90, 131, 41));
        Bt_RunTime = new QPushButton(groupBox);
        Bt_RunTime->setObjectName(QString::fromUtf8("Bt_RunTime"));
        Bt_RunTime->setGeometry(QRect(20, 240, 101, 41));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 20, 471, 291));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\260\345\256\213\344\275\223\";"));
        Bt_AxisJOGSub = new QPushButton(groupBox_2);
        Bt_AxisJOGSub->setObjectName(QString::fromUtf8("Bt_AxisJOGSub"));
        Bt_AxisJOGSub->setGeometry(QRect(280, 200, 101, 41));
        Bt_AxisJOGAdd = new QPushButton(groupBox_2);
        Bt_AxisJOGAdd->setObjectName(QString::fromUtf8("Bt_AxisJOGAdd"));
        Bt_AxisJOGAdd->setGeometry(QRect(280, 150, 101, 41));
        LB_MovePS = new QLabel(groupBox_2);
        LB_MovePS->setObjectName(QString::fromUtf8("LB_MovePS"));
        LB_MovePS->setGeometry(QRect(140, 40, 101, 21));
        LB_MovePS->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 120, 91, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 40, 101, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        Bt_AxisRunAbs = new QPushButton(groupBox_2);
        Bt_AxisRunAbs->setObjectName(QString::fromUtf8("Bt_AxisRunAbs"));
        Bt_AxisRunAbs->setGeometry(QRect(50, 150, 101, 41));
        Bt_AxisStop = new QPushButton(groupBox_2);
        Bt_AxisStop->setObjectName(QString::fromUtf8("Bt_AxisStop"));
        Bt_AxisStop->setGeometry(QRect(50, 200, 101, 41));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 80, 51, 21));
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        LE_AxisSpeed = new QLineEdit(groupBox_2);
        LE_AxisSpeed->setObjectName(QString::fromUtf8("LE_AxisSpeed"));
        LE_AxisSpeed->setGeometry(QRect(150, 70, 101, 31));
        LE_AxisSpeed->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        chB_MoveOri = new QCheckBox(groupBox_2);
        chB_MoveOri->setObjectName(QString::fromUtf8("chB_MoveOri"));
        chB_MoveOri->setGeometry(QRect(280, 80, 71, 16));
        LE_AxisPosition = new QLineEdit(groupBox_2);
        LE_AxisPosition->setObjectName(QString::fromUtf8("LE_AxisPosition"));
        LE_AxisPosition->setGeometry(QRect(150, 110, 101, 31));
        LE_AxisPosition->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        Bt_AxisRunRel = new QPushButton(groupBox_2);
        Bt_AxisRunRel->setObjectName(QString::fromUtf8("Bt_AxisRunRel"));
        Bt_AxisRunRel->setGeometry(QRect(160, 150, 101, 41));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 40, 101, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        LB_Aixs_Move_Sta = new QLabel(groupBox_2);
        LB_Aixs_Move_Sta->setObjectName(QString::fromUtf8("LB_Aixs_Move_Sta"));
        LB_Aixs_Move_Sta->setGeometry(QRect(350, 40, 101, 21));
        LB_Aixs_Move_Sta->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 110, 111, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        LE_JogMoveVlue = new QLineEdit(groupBox_2);
        LE_JogMoveVlue->setObjectName(QString::fromUtf8("LE_JogMoveVlue"));
        LE_JogMoveVlue->setGeometry(QRect(380, 110, 71, 31));
        LE_JogMoveVlue->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(820, 20, 301, 291));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\260\345\256\213\344\275\223\";"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 320, 901, 311));
        groupBox_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\260\345\256\213\344\275\223\";"));
        TK = new QTableWidget(groupBox_4);
        TK->setObjectName(QString::fromUtf8("TK"));
        TK->setGeometry(QRect(10, 30, 881, 271));
        LE_OutPutVule = new QLineEdit(centralWidget);
        LE_OutPutVule->setObjectName(QString::fromUtf8("LE_OutPutVule"));
        LE_OutPutVule->setGeometry(QRect(1030, 340, 71, 31));
        LE_OutPutVule->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(950, 350, 101, 21));
        label_7->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\256\213\344\275\223\";"));
        Bt_SetOut = new QPushButton(centralWidget);
        Bt_SetOut->setObjectName(QString::fromUtf8("Bt_SetOut"));
        Bt_SetOut->setGeometry(QRect(930, 400, 101, 41));
        Bt_RestOut = new QPushButton(centralWidget);
        Bt_RestOut->setObjectName(QString::fromUtf8("Bt_RestOut"));
        Bt_RestOut->setGeometry(QRect(1040, 400, 101, 41));
        QtandLeisaiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtandLeisaiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1234, 23));
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
        groupBox->setTitle(QCoreApplication::translate("QtandLeisaiClass", "\345\210\235\345\247\213\345\214\226", nullptr));
        Bt_AxisGoHome->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\233\236\345\216\237\347\202\271", nullptr));
        Bt_AxisEn->setText(QCoreApplication::translate("QtandLeisaiClass", "\350\275\264\344\275\277\350\203\275", nullptr));
        Bt_CardLint->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\210\235\345\247\213\345\214\226", nullptr));
        Bt_AxisRestEn->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\244\215\344\275\215\344\275\277\350\203\275", nullptr));
        LB_AixsSta->setText(QCoreApplication::translate("QtandLeisaiClass", ".", nullptr));
        label_6->setText(QCoreApplication::translate("QtandLeisaiClass", "\344\274\272\346\234\215\347\212\266\346\200\201\357\274\232", nullptr));
        Bt_CleanAisxWarn->setText(QCoreApplication::translate("QtandLeisaiClass", "\346\270\205\351\231\244\344\274\272\346\234\215\346\212\245\350\255\246", nullptr));
        Bt_CardClose->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\205\263\351\227\255\345\215\241", nullptr));
        Bt_RunTime->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\220\257\345\212\250Time", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QtandLeisaiClass", "\350\275\264\346\216\247\345\210\266", nullptr));
        Bt_AxisJOGSub->setText(QCoreApplication::translate("QtandLeisaiClass", "JOG-", nullptr));
        Bt_AxisJOGAdd->setText(QCoreApplication::translate("QtandLeisaiClass", "JOG+", nullptr));
        LB_MovePS->setText(QCoreApplication::translate("QtandLeisaiClass", ".", nullptr));
        label_2->setText(QCoreApplication::translate("QtandLeisaiClass", "\347\233\256\346\240\207\344\275\215\347\275\256\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\275\223\345\211\215\344\275\215\347\275\256\357\274\232", nullptr));
        Bt_AxisRunAbs->setText(QCoreApplication::translate("QtandLeisaiClass", "\347\273\235\345\257\271\345\256\232\344\275\215", nullptr));
        Bt_AxisStop->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\201\234\346\255\242", nullptr));
        label->setText(QCoreApplication::translate("QtandLeisaiClass", "\351\200\237\345\272\246\357\274\232", nullptr));
        LE_AxisSpeed->setText(QCoreApplication::translate("QtandLeisaiClass", "20000", nullptr));
        chB_MoveOri->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\217\215\345\220\221", nullptr));
        Bt_AxisRunRel->setText(QCoreApplication::translate("QtandLeisaiClass", "\347\233\270\345\257\271\345\256\232\344\275\215", nullptr));
        label_5->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", nullptr));
        LB_Aixs_Move_Sta->setText(QCoreApplication::translate("QtandLeisaiClass", "\345\201\234\346\255\242", nullptr));
        label_3->setText(QCoreApplication::translate("QtandLeisaiClass", "JOG\347\247\273\345\212\250\351\207\217\357\274\232", nullptr));
        LE_JogMoveVlue->setText(QCoreApplication::translate("QtandLeisaiClass", "20000", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("QtandLeisaiClass", "\346\217\222\350\241\245", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("QtandLeisaiClass", "I/O\347\233\221\350\247\206", nullptr));
        LE_OutPutVule->setText(QCoreApplication::translate("QtandLeisaiClass", "0", nullptr));
        label_7->setText(QCoreApplication::translate("QtandLeisaiClass", "\350\276\223\345\207\272\345\217\243\357\274\232", nullptr));
        Bt_SetOut->setText(QCoreApplication::translate("QtandLeisaiClass", "Set", nullptr));
        Bt_RestOut->setText(QCoreApplication::translate("QtandLeisaiClass", "Rest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtandLeisaiClass: public Ui_QtandLeisaiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTANDLEISAI_H
