/********************************************************************************
** Form generated from reading UI file 'stylewidget.ui'
**
** Created: Tue Jul 7 08:54:52 2015
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
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StyleWidget
{
public:
    QTreeWidget *treeWidget;

    void setupUi(QWidget *StyleWidget)
    {
        if (StyleWidget->objectName().isEmpty())
            StyleWidget->setObjectName(QString::fromUtf8("StyleWidget"));
        StyleWidget->resize(565, 440);
        StyleWidget->setStyleSheet(QString::fromUtf8(""));
        treeWidget = new QTreeWidget(StyleWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(60, 20, 411, 311));
        treeWidget->setFrameShape(QFrame::VLine);
        treeWidget->setLineWidth(0);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setEditTriggers(QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked);
        treeWidget->setTabKeyNavigation(true);
        treeWidget->setProperty("showDropIndicator", QVariant(true));
        treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        treeWidget->setIconSize(QSize(12, 12));
        treeWidget->setTextElideMode(Qt::ElideMiddle);
        treeWidget->setIndentation(15);
        treeWidget->setRootIsDecorated(true);
        treeWidget->setAnimated(false);
        treeWidget->setHeaderHidden(false);
        treeWidget->setExpandsOnDoubleClick(true);
        treeWidget->header()->setVisible(true);

        retranslateUi(StyleWidget);

        QMetaObject::connectSlotsByName(StyleWidget);
    } // setupUi

    void retranslateUi(QWidget *StyleWidget)
    {
        StyleWidget->setWindowTitle(QApplication::translate("StyleWidget", "StyleWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StyleWidget: public Ui_StyleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLEWIDGET_H
