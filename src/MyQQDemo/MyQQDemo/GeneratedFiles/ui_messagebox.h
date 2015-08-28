/********************************************************************************
** Form generated from reading UI file 'messagebox.ui'
**
** Created: Tue Aug 25 16:43:25 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEBOX_H
#define UI_MESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageBox
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *closeBtn;
    QListView *listView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;

    void setupUi(QWidget *MessageBox)
    {
        if (MessageBox->objectName().isEmpty())
            MessageBox->setObjectName(QString::fromUtf8("MessageBox"));
        MessageBox->resize(401, 250);
        verticalLayout = new QVBoxLayout(MessageBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MessageBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        closeBtn = new QToolButton(MessageBox);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout->addLayout(horizontalLayout);

        listView = new QListView(MessageBox);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButton_4 = new QToolButton(MessageBox);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));

        horizontalLayout_2->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(MessageBox);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));

        horizontalLayout_2->addWidget(toolButton_3);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(MessageBox);
        QObject::connect(closeBtn, SIGNAL(clicked()), MessageBox, SLOT(close()));

        QMetaObject::connectSlotsByName(MessageBox);
    } // setupUi

    void retranslateUi(QWidget *MessageBox)
    {
        MessageBox->setWindowTitle(QApplication::translate("MessageBox", "MessageBox", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MessageBox", "\346\266\210\346\201\257\347\233\222\345\255\220(3)", 0, QApplication::UnicodeUTF8));
        closeBtn->setText(QApplication::translate("MessageBox", "\345\205\263\351\227\255\346\214\211\351\222\256", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("MessageBox", "\345\217\226\346\266\210\351\227\252\347\203\201", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("MessageBox", "\346\237\245\347\234\213\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MessageBox: public Ui_MessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEBOX_H
