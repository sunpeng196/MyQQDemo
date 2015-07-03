/********************************************************************************
** Form generated from reading UI file 'userinfowidget2.ui'
**
** Created: Fri Jul 3 17:13:58 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOWIDGET2_H
#define UI_USERINFOWIDGET2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfoWidget2
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;

    void setupUi(QWidget *UserInfoWidget2)
    {
        if (UserInfoWidget2->objectName().isEmpty())
            UserInfoWidget2->setObjectName(QString::fromUtf8("UserInfoWidget2"));
        UserInfoWidget2->resize(283, 99);
        verticalLayout = new QVBoxLayout(UserInfoWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(UserInfoWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\256\213\344\275\223"));
        font.setPointSize(16);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        toolButton = new QToolButton(UserInfoWidget2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UserINfo/Resources/UserInfo/imonline.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(UserInfoWidget2);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/UserINfo/Resources/UserInfo/icon_weibo_normal.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(UserInfoWidget2);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/UserINfo/Resources/UserInfo/qzone16_main.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit = new QLineEdit(UserInfoWidget2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButton_4 = new QToolButton(UserInfoWidget2);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setIcon(icon2);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(UserInfoWidget2);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/UserINfo/Resources/UserInfo/PaiPai_MainService.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon3);
        toolButton_5->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(UserInfoWidget2);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/UserINfo/Resources/UserInfo/logo_shadow.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon4);
        toolButton_6->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_6);

        horizontalSpacer = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButton_7 = new QToolButton(UserInfoWidget2);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setIcon(icon1);
        toolButton_7->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_7);

        toolButton_8 = new QToolButton(UserInfoWidget2);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        toolButton_8->setIcon(icon3);
        toolButton_8->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_8);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(UserInfoWidget2);

        QMetaObject::connectSlotsByName(UserInfoWidget2);
    } // setupUi

    void retranslateUi(QWidget *UserInfoWidget2)
    {
        UserInfoWidget2->setWindowTitle(QApplication::translate("UserInfoWidget2", "UserInfoWidget2", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserInfoWidget2", "1234", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("UserInfoWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("UserInfoWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("UserInfoWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("UserInfoWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("UserInfoWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_6->setText(QApplication::translate("UserInfoWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_7->setText(QApplication::translate("UserInfoWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_8->setText(QApplication::translate("UserInfoWidget2", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserInfoWidget2: public Ui_UserInfoWidget2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOWIDGET2_H
