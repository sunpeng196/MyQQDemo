/********************************************************************************
** Form generated from reading UI file 'appwidget2.ui'
**
** Created: Fri Jul 3 17:13:58 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPWIDGET2_H
#define UI_APPWIDGET2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppWidget2
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_12;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;

    void setupUi(QWidget *AppWidget2)
    {
        if (AppWidget2->objectName().isEmpty())
            AppWidget2->setObjectName(QString::fromUtf8("AppWidget2"));
        AppWidget2->resize(297, 72);
        verticalLayout = new QVBoxLayout(AppWidget2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_8 = new QToolButton(AppWidget2);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MyQQDemo/Resources/app_icon_16 (3).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon);
        toolButton_8->setIconSize(QSize(20, 20));
        toolButton_8->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_8);

        toolButton_9 = new QToolButton(AppWidget2);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MyQQDemo/Resources/app_icon_16 (4).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_9->setIcon(icon1);
        toolButton_9->setIconSize(QSize(20, 20));
        toolButton_9->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_9);

        toolButton_10 = new QToolButton(AppWidget2);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/MyQQDemo/Resources/app_icon_16.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_10->setIcon(icon2);
        toolButton_10->setIconSize(QSize(20, 20));
        toolButton_10->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_10);

        toolButton_11 = new QToolButton(AppWidget2);
        toolButton_11->setObjectName(QString::fromUtf8("toolButton_11"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/MyQQDemo/Resources/app_icon_16 (5).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_11->setIcon(icon3);
        toolButton_11->setIconSize(QSize(20, 20));
        toolButton_11->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_11);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_12 = new QToolButton(AppWidget2);
        toolButton_12->setObjectName(QString::fromUtf8("toolButton_12"));
        toolButton_12->setIcon(icon1);
        toolButton_12->setIconSize(QSize(20, 20));
        toolButton_12->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_12);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButton = new QToolButton(AppWidget2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/AppMenu/Resources/mainmenubutton/menu_btn2_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(24, 24));
        toolButton->setPopupMode(QToolButton::InstantPopup);
        toolButton->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton);

        toolButton_2 = new QToolButton(AppWidget2);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/AppWidget/Resources/button/tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon5);
        toolButton_2->setIconSize(QSize(24, 24));
        toolButton_2->setPopupMode(QToolButton::InstantPopup);
        toolButton_2->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(AppWidget2);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/AppWidget/Resources/button/message.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon6);
        toolButton_3->setIconSize(QSize(24, 24));
        toolButton_3->setPopupMode(QToolButton::InstantPopup);
        toolButton_3->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(AppWidget2);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/AppWidget/Resources/button/filemanager.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon7);
        toolButton_4->setIconSize(QSize(24, 24));
        toolButton_4->setPopupMode(QToolButton::InstantPopup);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(AppWidget2);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/AppWidget/Resources/button/mycollection_mainpanel.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon8);
        toolButton_5->setIconSize(QSize(24, 24));
        toolButton_5->setPopupMode(QToolButton::InstantPopup);
        toolButton_5->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(AppWidget2);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/AppWidget/Resources/button/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon9);
        toolButton_6->setIconSize(QSize(24, 24));
        toolButton_6->setPopupMode(QToolButton::InstantPopup);
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_6->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_6);

        toolButton_7 = new QToolButton(AppWidget2);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/AppWidget/Resources/qplusentrancebtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon10);
        toolButton_7->setIconSize(QSize(24, 24));
        toolButton_7->setPopupMode(QToolButton::InstantPopup);
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_7->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_7);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AppWidget2);

        QMetaObject::connectSlotsByName(AppWidget2);
    } // setupUi

    void retranslateUi(QWidget *AppWidget2)
    {
        AppWidget2->setWindowTitle(QApplication::translate("AppWidget2", "AppWidget2", 0, QApplication::UnicodeUTF8));
        toolButton_8->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_9->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_10->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_11->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
        toolButton_12->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton->setToolTip(QApplication::translate("AppWidget2", "\344\270\273\350\217\234\345\215\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_2->setToolTip(QApplication::translate("AppWidget2", "\346\211\223\345\274\200\347\263\273\347\273\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_2->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_3->setToolTip(QApplication::translate("AppWidget2", "\346\211\223\345\274\200\346\266\210\346\201\257\347\256\241\347\220\206\345\231\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_3->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_4->setToolTip(QApplication::translate("AppWidget2", "\346\211\223\345\274\200\346\226\207\344\273\266\345\212\251\346\211\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_4->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_5->setToolTip(QApplication::translate("AppWidget2", "\346\211\223\345\274\200\346\210\221\347\232\204\346\224\266\350\227\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_5->setText(QApplication::translate("AppWidget2", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_6->setToolTip(QApplication::translate("AppWidget2", "\346\211\276\344\272\272\343\200\201\346\211\276\347\276\244\343\200\201\346\211\276\346\234\215\345\212\241", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_6->setText(QApplication::translate("AppWidget2", "\346\237\245\346\211\276", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_7->setToolTip(QApplication::translate("AppWidget2", "\346\211\223\345\274\200\345\272\224\347\224\250\345\256\235", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_7->setText(QApplication::translate("AppWidget2", "\345\272\224\347\224\250\345\256\235", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AppWidget2: public Ui_AppWidget2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPWIDGET2_H
