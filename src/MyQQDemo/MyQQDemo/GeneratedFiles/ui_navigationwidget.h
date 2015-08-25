/********************************************************************************
** Form generated from reading UI file 'navigationwidget.ui'
**
** Created: Tue Aug 25 15:43:38 2015
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavigationWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;

    void setupUi(QWidget *NavigationWidget)
    {
        if (NavigationWidget->objectName().isEmpty())
            NavigationWidget->setObjectName(QString::fromUtf8("NavigationWidget"));
        NavigationWidget->resize(307, 54);
        NavigationWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        horizontalLayout = new QHBoxLayout(NavigationWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton = new QToolButton(NavigationWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setAutoRaise(true);
        toolButton->setArrowType(Qt::DownArrow);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(NavigationWidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setAutoRaise(true);
        toolButton_2->setArrowType(Qt::DownArrow);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(NavigationWidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setAutoRaise(true);
        toolButton_3->setArrowType(Qt::DownArrow);

        horizontalLayout->addWidget(toolButton_3);


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
