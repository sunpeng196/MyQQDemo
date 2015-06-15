/********************************************************************************
** Form generated from reading UI file 'myqqdemo.ui'
**
** Created: Mon Jun 15 18:04:04 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQQDEMO_H
#define UI_MYQQDEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyQQDemoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyQQDemoClass)
    {
        if (MyQQDemoClass->objectName().isEmpty())
            MyQQDemoClass->setObjectName(QString::fromUtf8("MyQQDemoClass"));
        MyQQDemoClass->resize(600, 400);
        menuBar = new QMenuBar(MyQQDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MyQQDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyQQDemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyQQDemoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyQQDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MyQQDemoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyQQDemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyQQDemoClass->setStatusBar(statusBar);

        retranslateUi(MyQQDemoClass);

        QMetaObject::connectSlotsByName(MyQQDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyQQDemoClass)
    {
        MyQQDemoClass->setWindowTitle(QApplication::translate("MyQQDemoClass", "MyQQDemo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyQQDemoClass: public Ui_MyQQDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQQDEMO_H
