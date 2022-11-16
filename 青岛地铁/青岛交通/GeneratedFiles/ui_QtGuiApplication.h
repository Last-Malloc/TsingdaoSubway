/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION_H
#define UI_QTGUIAPPLICATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <mypen.h>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplicationClass
{
public:
    QWidget *centralWidget;
    QWidget *widget_2;
    QWidget *widget;
    QToolButton *btnOK;
    QLineEdit *LineStart;
    QLineEdit *LineEnd;
    QToolButton *min;
    QToolButton *close;
    QToolButton *help;
    Mypen *mypen;

    void setupUi(QMainWindow *QtGuiApplicationClass)
    {
        if (QtGuiApplicationClass->objectName().isEmpty())
            QtGuiApplicationClass->setObjectName(QStringLiteral("QtGuiApplicationClass"));
        QtGuiApplicationClass->resize(1140, 720);
        QIcon icon;
        icon.addFile(QStringLiteral(":/QtGuiApplication/Resources/tubiao.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QtGuiApplicationClass->setWindowIcon(icon);
        QtGuiApplicationClass->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(QtGuiApplicationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(true);
        centralWidget->setStyleSheet(QStringLiteral(""));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 1140, 720));
        widget_2->setContextMenuPolicy(Qt::ActionsContextMenu);
        widget_2->setStyleSheet(QStringLiteral("background-image: url(:/QtGuiApplication/Resources/beijng.jpg);"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1140, 720));
        btnOK = new QToolButton(widget);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setEnabled(true);
        btnOK->setGeometry(QRect(770, 130, 76, 71));
        btnOK->setCursor(QCursor(Qt::PointingHandCursor));
        btnOK->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QtGuiApplication/Resources/555.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon1);
        btnOK->setIconSize(QSize(65, 59));
        btnOK->setCheckable(false);
        btnOK->setToolButtonStyle(Qt::ToolButtonIconOnly);
        btnOK->setAutoRaise(true);
        LineStart = new QLineEdit(widget);
        LineStart->setObjectName(QStringLiteral("LineStart"));
        LineStart->setGeometry(QRect(60, 130, 351, 70));
        LineStart->setMouseTracking(true);
        LineStart->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);\n"
"font: 18pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"border-color: rgb(255, 255, 255);"));
        LineEnd = new QLineEdit(widget);
        LineEnd->setObjectName(QStringLiteral("LineEnd"));
        LineEnd->setGeometry(QRect(410, 130, 351, 70));
        LineEnd->setAutoFillBackground(false);
        LineEnd->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);\n"
"font: 18pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"border-color: rgb(255, 255, 255);"));
        min = new QToolButton(widget);
        min->setObjectName(QStringLiteral("min"));
        min->setGeometry(QRect(1050, 0, 47, 31));
        min->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/\345\260\217\345\233\276\346\240\207/Resources/\346\234\200\345\260\217\345\214\226.ico"), QSize(), QIcon::Normal, QIcon::Off);
        min->setIcon(icon2);
        min->setIconSize(QSize(30, 30));
        min->setAutoRaise(true);
        close = new QToolButton(widget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(1100, 0, 47, 31));
        close->setCursor(QCursor(Qt::ClosedHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/\345\260\217\345\233\276\346\240\207/Resources/\345\205\263\351\227\255.ico"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon3);
        close->setIconSize(QSize(30, 30));
        close->setAutoRaise(true);
        help = new QToolButton(widget);
        help->setObjectName(QStringLiteral("help"));
        help->setGeometry(QRect(1000, 0, 47, 31));
        help->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/\345\260\217\345\233\276\346\240\207/Resources/\345\270\256\345\212\251.ico"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon4);
        help->setIconSize(QSize(30, 30));
        help->setAutoRaise(true);
        mypen = new Mypen(centralWidget);
        mypen->setObjectName(QStringLiteral("mypen"));
        mypen->setGeometry(QRect(0, 0, 1140, 720));
        mypen->setFrameShape(QFrame::StyledPanel);
        mypen->setFrameShadow(QFrame::Raised);
        QtGuiApplicationClass->setCentralWidget(centralWidget);
        widget_2->raise();
        mypen->raise();
        widget->raise();

        retranslateUi(QtGuiApplicationClass);

        QMetaObject::connectSlotsByName(QtGuiApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplicationClass)
    {
        QtGuiApplicationClass->setWindowTitle(QApplication::translate("QtGuiApplicationClass", "\351\235\222\345\262\233\345\234\260\351\223\201\344\272\244\351\200\232\345\222\250\350\257\242\347\263\273\347\273\237", nullptr));
        btnOK->setText(QApplication::translate("QtGuiApplicationClass", "...", nullptr));
#ifndef QT_NO_WHATSTHIS
        LineStart->setWhatsThis(QApplication::translate("QtGuiApplicationClass", "<html><head/><body><p>\344\273\216\346\263\225</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        LineStart->setText(QString());
        LineStart->setPlaceholderText(QApplication::translate("QtGuiApplicationClass", "           \350\257\267\350\276\223\345\205\245\350\265\267\347\202\271\347\253\231", nullptr));
        LineEnd->setText(QString());
        LineEnd->setPlaceholderText(QApplication::translate("QtGuiApplicationClass", "           \350\257\267\350\276\223\345\205\245\347\273\210\347\202\271\347\253\231", nullptr));
        min->setText(QApplication::translate("QtGuiApplicationClass", "...", nullptr));
        close->setText(QApplication::translate("QtGuiApplicationClass", "...", nullptr));
        help->setText(QApplication::translate("QtGuiApplicationClass", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplicationClass: public Ui_QtGuiApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION_H
