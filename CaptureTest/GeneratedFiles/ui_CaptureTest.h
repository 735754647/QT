/********************************************************************************
** Form generated from reading UI file 'CaptureTest.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURETEST_H
#define UI_CAPTURETEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaptureTestClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *CaptureTestClass)
    {
        if (CaptureTestClass->objectName().isEmpty())
            CaptureTestClass->setObjectName(QStringLiteral("CaptureTestClass"));
        CaptureTestClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(CaptureTestClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CaptureTestClass);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        retranslateUi(CaptureTestClass);

        QMetaObject::connectSlotsByName(CaptureTestClass);
    } // setupUi

    void retranslateUi(QWidget *CaptureTestClass)
    {
        CaptureTestClass->setWindowTitle(QApplication::translate("CaptureTestClass", "CaptureTest", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CaptureTestClass: public Ui_CaptureTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURETEST_H
