#include "myqqdemo.h"
#include "titlebar.h"
#include "columnwidget.h"

MyQQDemo::MyQQDemo(QWidget *parent, Qt::WFlags flags)
	: QFrame(parent, flags)
{
	setWindowFlags(Qt::FramelessWindowHint);

	setMinimumSize(270,650);
	setMaximumSize(600,715);

	//this->setFixedSize(270,650);
	//QString styleSheet = "QMainWindow:{border:0px;}";
	setStyleSheet("QFrame {background-image:url(:/MyQQDemo/Resources/main.jpg);border:0px solid black;}");

	m_pTitleBar = new TitleBar(this);
	m_pTitleBar->setGeometry(0,0,270,30);


	m_pColumnWidget = new ColumnWidget(this);

	m_pColumnWidget->setGeometry(0,50,270,30);

	//setCursor();


	
}

MyQQDemo::~MyQQDemo()
{

}
