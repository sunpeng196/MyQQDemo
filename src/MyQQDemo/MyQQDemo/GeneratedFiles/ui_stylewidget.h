/********************************************************************************
** Form generated from reading UI file 'stylewidget.ui'
**
** Created: Fri Jul 3 17:13:58 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLEWIDGET_H
#define UI_STYLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StyleWidget
{
public:
    QPushButton *pushBtnContract;
    QPushButton *groupBtn;
    QPushButton *lastBtn;

    void setupUi(QWidget *StyleWidget)
    {
        if (StyleWidget->objectName().isEmpty())
            StyleWidget->setObjectName(QString::fromUtf8("StyleWidget"));
        StyleWidget->resize(270, 38);
        StyleWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/MainTab/Resources/main_tabctrl_background.png);"));
        pushBtnContract = new QPushButton(StyleWidget);
        pushBtnContract->setObjectName(QString::fromUtf8("pushBtnContract"));
        pushBtnContract->setGeometry(QRect(11, 11, 51, 23));
        pushBtnContract->setStyleSheet(QString::fromUtf8(""));
        pushBtnContract->setCheckable(true);
        pushBtnContract->setChecked(false);
        groupBtn = new QPushButton(StyleWidget);
        groupBtn->setObjectName(QString::fromUtf8("groupBtn"));
        groupBtn->setGeometry(QRect(90, 10, 61, 24));
        groupBtn->setStyleSheet(QString::fromUtf8(""));
        groupBtn->setCheckable(true);
        groupBtn->setFlat(true);
        lastBtn = new QPushButton(StyleWidget);
        lastBtn->setObjectName(QString::fromUtf8("lastBtn"));
        lastBtn->setGeometry(QRect(180, 10, 61, 23));
        lastBtn->setCheckable(true);

        retranslateUi(StyleWidget);

        QMetaObject::connectSlotsByName(StyleWidget);
    } // setupUi

    void retranslateUi(QWidget *StyleWidget)
    {
        StyleWidget->setWindowTitle(QApplication::translate("StyleWidget", "StyleWidget", 0, QApplication::UnicodeUTF8));
        pushBtnContract->setText(QApplication::translate("StyleWidget", "\350\201\224\347\263\273\344\272\272", 0, QApplication::UnicodeUTF8));
        groupBtn->setText(QApplication::translate("StyleWidget", "\347\276\244/\347\273\204", 0, QApplication::UnicodeUTF8));
        lastBtn->setText(QApplication::translate("StyleWidget", "\346\234\200\350\277\221\345\233\236\350\257\235", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StyleWidget: public Ui_StyleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLEWIDGET_H
