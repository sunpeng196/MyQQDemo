#include "appwidget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenu>

AppWidget::AppWidget(QWidget *parent)
	: QWidget(parent)
{
	mainLayout = new QHBoxLayout(this);
	setLayout(mainLayout);



	//setStyleSheet("background-color:red;");//rgb(233,221,213)
	m_pAppMenu = new QPushButton(this);
	  
	//m_pAppMenu->setGeometry(2,2,24,24);
	m_pAppMenu->setIcon(QIcon(":/AppMenu/Resources/mainmenubutton/menu_btn_normal.png"));

	m_pAppMenu->setToolTip("主菜单");

	m_pAppMenu->setFixedSize(20,20);

	m_pAppMenu->setFlat(true);

	m_pAppMenu->setObjectName("AppMenu");

	m_pAppMenu->setCheckable(false);
	m_pAppMenu->setStyleSheet("QPushButton{border:none}");


	QMenu *pMenu = new QMenu(m_pAppMenu);
	//m_pAppMenu->addAction(new QAction("传文件到手机"));
	//m_pAppMenu->addAction("导出手机相册");

	m_pAppMenu->setMenu(pMenu);


	m_pSystemSetting = new QPushButton(this);
	m_pSystemSetting->setToolTip("打开系统设置");
	m_pSystemSetting->setIcon(QIcon(""));

	m_pSystemSetting->setFixedSize(20,20);



	m_pMessageManager = new QPushButton(this);
	m_pMessageManager->setToolTip("打开消息管理器");
	m_pMessageManager->setFixedSize(20,20);

	m_pFileAssiant= new QPushButton(this);
	m_pFileAssiant->setToolTip("打开文件助手");
	m_pFileAssiant->setFixedSize(20,20);

	m_pMyShouCang= new QPushButton(this);
	m_pMyShouCang->setToolTip("打开我的收藏");
	m_pMyShouCang->setFixedSize(20,20);

	m_pFind = new QPushButton(this);
	m_pFind->setToolTip("查找");
	m_pFind->setFixedSize(20,20);

	m_pAppBaby = new QPushButton(this);
	m_pAppBaby->setFixedSize(20,20);

	m_pAppBaby->setToolTip("应用宝");

	mainLayout->addWidget(m_pAppMenu);
	mainLayout->addWidget(m_pSystemSetting);
	mainLayout->addWidget(m_pMessageManager);
	mainLayout->addWidget(m_pFileAssiant);
	mainLayout->addWidget(m_pMyShouCang);
	mainLayout->addWidget(m_pFind);
	mainLayout->addWidget(m_pAppBaby);
	mainLayout->setSpacing(0);
	mainLayout->setMargin(0);



	

}

AppWidget::~AppWidget()
{

}

// void AppWidget::paintEvent( QPaintEvent *event )
// {
// 
// 	return QWidget::paintEvent(event);
// 
// }
