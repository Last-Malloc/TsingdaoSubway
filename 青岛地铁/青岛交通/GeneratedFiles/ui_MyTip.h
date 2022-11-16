/********************************************************************************
** Form generated from reading UI file 'MyTip.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTIP_H
#define UI_MYTIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyTip
{
public:
    QPushButton *tipCancel;
    QPushButton *tipOK;
    QComboBox *mohu_station;

    void setupUi(QDialog *MyTip)
    {
        if (MyTip->objectName().isEmpty())
            MyTip->setObjectName(QStringLiteral("MyTip"));
        MyTip->resize(400, 300);
        MyTip->setStyleSheet(QStringLiteral("image: url(:/QtGuiApplication/Resources/tip_background.jpg);"));
        tipCancel = new QPushButton(MyTip);
        tipCancel->setObjectName(QStringLiteral("tipCancel"));
        tipCancel->setGeometry(QRect(270, 230, 111, 41));
        tipCancel->setCursor(QCursor(Qt::PointingHandCursor));
        tipOK = new QPushButton(MyTip);
        tipOK->setObjectName(QStringLiteral("tipOK"));
        tipOK->setGeometry(QRect(150, 230, 111, 41));
        tipOK->setCursor(QCursor(Qt::PointingHandCursor));
        mohu_station = new QComboBox(MyTip);
        mohu_station->setObjectName(QStringLiteral("mohu_station"));
        mohu_station->setGeometry(QRect(70, 110, 251, 61));
        mohu_station->setCursor(QCursor(Qt::PointingHandCursor));
        mohu_station->setAutoFillBackground(false);
        mohu_station->setStyleSheet(QStringLiteral("font: 18pt \"Adobe Arabic\";"));

        retranslateUi(MyTip);

        QMetaObject::connectSlotsByName(MyTip);
    } // setupUi

    void retranslateUi(QDialog *MyTip)
    {
        MyTip->setWindowTitle(QApplication::translate("MyTip", "MyTip", nullptr));
        tipCancel->setText(QApplication::translate("MyTip", "\345\217\226\346\266\210", nullptr));
        tipOK->setText(QApplication::translate("MyTip", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTip: public Ui_MyTip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTIP_H
