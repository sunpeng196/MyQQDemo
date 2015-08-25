/********************************************************************************
** Form generated from reading UI file 'friendinfoui.ui'
**
** Created: Mon Aug 24 17:08:01 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDINFOUI_H
#define UI_FRIENDINFOUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendInfoUI
{
public:
    QLabel *label;
    QLabel *labelName;
    QLabel *label_3;
    QLabel *labelNickName;

    void setupUi(QWidget *FriendInfoUI)
    {
        if (FriendInfoUI->objectName().isEmpty())
            FriendInfoUI->setObjectName(QString::fromUtf8("FriendInfoUI"));
        FriendInfoUI->resize(400, 300);
        label = new QLabel(FriendInfoUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 54, 12));
        labelName = new QLabel(FriendInfoUI);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setGeometry(QRect(90, 40, 81, 16));
        label_3 = new QLabel(FriendInfoUI);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 54, 12));
        labelNickName = new QLabel(FriendInfoUI);
        labelNickName->setObjectName(QString::fromUtf8("labelNickName"));
        labelNickName->setGeometry(QRect(80, 80, 81, 16));

        retranslateUi(FriendInfoUI);

        QMetaObject::connectSlotsByName(FriendInfoUI);
    } // setupUi

    void retranslateUi(QWidget *FriendInfoUI)
    {
        FriendInfoUI->setWindowTitle(QApplication::translate("FriendInfoUI", "FriendInfoUI", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FriendInfoUI", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        labelName->setText(QString());
        label_3->setText(QApplication::translate("FriendInfoUI", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        labelNickName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendInfoUI: public Ui_FriendInfoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDINFOUI_H
