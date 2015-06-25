#include "myqqdemo.h"
#include "titlebar.h"
#include "columnwidget.h"
#include "toolwidget.h"
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include "searchlineedit.h"
#include "buddylistwidget.h"

MyQQDemo::MyQQDemo(QWidget *parent, Qt::WFlags flags)
	: QFrame(parent, flags)
{
	setWindowFlags(Qt::FramelessWindowHint);

	setMinimumSize(270,650);
	setMaximumSize(600,715);

	this->setFixedSize(QSize(281,700));

	//this->setFixedSize(270,650);
	//QString styleSheet = "QMainWindow:{border:0px;}";
	setStyleSheet("QFrame {background-image:url(:/MyQQDemo/Resources/main.jpg);border:0px solid black;}");

	m_pTitleBar = new TitleBar(this);
	m_pTitleBar->setGeometry(0,0,281,30);


 	m_pColumnWidget = new ColumnWidget(this);

 	m_pColumnWidget->setGeometry(0,170,281,35);

	//setCursor();

// 	m_pToolWidget = new ToolWidget(this);
// 
// 	m_pToolWidget->setGeometry(0,100,270,30);

	m_pSytemTrayIcon = new QSystemTrayIcon(this);
	m_pSytemTrayIcon->setIcon(QIcon(""));
	m_pSytemTrayIcon->show();

	QMenu *pMenu = m_pSytemTrayIcon->contextMenu();
	//pMenu->addAction(new QAction(tr("显示主界面")));

	m_pSytemTrayIcon->setContextMenu(pMenu);

	m_pSearchLineEdit = new SearchLineEdit(this);

	m_pSearchLineEdit->setGeometry(0,100,260,30);

	m_pBuddyList = new BuddyListWidget(this);

	m_pBuddyList->SetBuddyItemHeadFlashAnim(0,1,true);

	m_pBuddyList->setGeometry(1,207,278,443);
	m_pAppWidget = new AppWidget(this);

	m_pAppWidget->setGeometry(0,657,278,30);

	

	

	
}

MyQQDemo::~MyQQDemo()
{

}

void MyQQDemo::mousePressEvent( QMouseEvent * e )
{

}

void MyQQDemo::mouseMoveEvent( QMouseEvent * e )
{

}

void MyQQDemo::mouseReleaseEvent( QMouseEvent * e )
{

}
