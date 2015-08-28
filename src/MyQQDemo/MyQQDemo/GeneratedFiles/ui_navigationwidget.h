/********************************************************************************
** Form generated from reading UI file 'navigationwidget.ui'
**
** Created: Tue Aug 25 15:57:30 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATIONWIDGET_H
#define UI_NAVIGATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavigationWidget
{
public:
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;

    void setupUi(QWidget *NavigationWidget)
    {
        if (NavigationWidget->objectName().isEmpty())
            NavigationWidget->setObjectName(QString::fromUtf8("NavigationWidget"));
        NavigationWidget->resize(94, 16);
        NavigationWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        toolButton = new QToolButton(NavigationWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(91, 50, 26, 25));
        toolButton->setAutoRaise(true);
        toolButton->setArrowType(Qt::DownArrow);
        toolButton_2 = new QToolButton(NavigationWidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(208, 50, 26, 25));
        toolButton_2->setAutoRaise(true);
        toolButton_2->setArrowType(Qt::DownArrow);
        toolButton_3 = new QToolButton(NavigationWidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(325, 50, 26, 25));
        toolButton_3->setAutoRaise(true);
        toolButton_3->setArrowType(Qt::DownArrow);

        retranslateUi(NavigationWidget);

        QMetaObject::connectSlotsByName(NavigationWidget);
    } // setupUi

    void retranslateUi(QWidget *NavigationWidget)
    {
        NavigationWidget->setWindowTitle(QApplication::translate("NavigationWidget", "NavigationWidget", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("NavigationWidget", "...", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("NavigationWidget", "...", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("NavigationWidget", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NavigationWidget: public Ui_NavigationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATIONWIDGET_H
