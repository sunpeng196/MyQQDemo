/********************************************************************************
** Form generated from reading UI file 'qqchatwindow.ui'
**
** Created: Mon Aug 24 17:33:25 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQCHATWINDOW_H
#define UI_QQCHATWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QQChatWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *QQChatWindow)
    {
        if (QQChatWindow->objectName().isEmpty())
            QQChatWindow->setObjectName(QString::fromUtf8("QQChatWindow"));
        QQChatWindow->resize(512, 432);
        verticalLayout = new QVBoxLayout(QQChatWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(QQChatWindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton = new QToolButton(QQChatWindow);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(QQChatWindow);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(QQChatWindow);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));

        horizontalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(QQChatWindow);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));

        horizontalLayout->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(QQChatWindow);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));

        horizontalLayout->addWidget(toolButton_5);


        verticalLayout->addLayout(horizontalLayout);

        textEdit_2 = new QTextEdit(QQChatWindow);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout->addWidget(textEdit_2);


        retranslateUi(QQChatWindow);

        QMetaObject::connectSlotsByName(QQChatWindow);
    } // setupUi

    void retranslateUi(QWidget *QQChatWindow)
    {
        QQChatWindow->setWindowTitle(QApplication::translate("QQChatWindow", "QQChatWindow", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("QQChatWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\345\216\206\345\217\262\350\201\212\345\244\251\350\256\260\345\275\225</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("QQChatWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("QQChatWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("QQChatWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("QQChatWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("QQChatWindow", "...", 0, QApplication::UnicodeUTF8));
        textEdit_2->setHtml(QApplication::translate("QQChatWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\216\260\345\234\250\350\201\212\345\244\251\350\256\260\345\275\225</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QQChatWindow: public Ui_QQChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQCHATWINDOW_H
