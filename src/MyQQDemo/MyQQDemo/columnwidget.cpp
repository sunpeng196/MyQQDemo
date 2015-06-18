#include "columnwidget.h"
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QMenu>
#include <QLabel>

ColumnWidget::ColumnWidget(QWidget *parent)
	: QWidget(parent)
{
// 	setFixedHeight(32);
// 	setFixedWidth(260);

	setAutoFillBackground(true);

	//QPalette palette;
	//palette.setColor(QPalette::Background, QColor(231,239,248));
	//palette.setBrush(QPalette::Background, QBrush(QPixmap(":/MainTab/Resources/main_tabctrl_background.png")));
	//this->setPalette(palette);


	setObjectName("columnWidget");

	//setStyleSheet("QPushButton{border:0px;background-image: url(:/MainTab/Resources/main_tab_check.png)}");

	m_pHBoxLayout = new QHBoxLayout(this);
	m_pHBoxLayout->setSpacing(0);
	m_pHBoxLayout->setContentsMargins(0,0,0,0);


	m_pContractBtn = new QQStylePushButton(":/ColumnIcon/Resources/icon_contacts_normal.png",
		":/ColumnIcon/Resources/icon_contacts_hover.png",
		":/ColumnIcon/Resources/icon_contacts_selected.png","联系人",this);

	m_pContractBtn->setObjectName("pushBtnContract");

	m_pGroupBtn = new QQStylePushButton(":/ColumnIcon/Resources/icon_group_normal.png",
		":/ColumnIcon/Resources/icon_group_hover.png",
		":/ColumnIcon/Resources/icon_group_selected.png",
		"群/讨论组",
		this);
	m_pGroupBtn->setObjectName("groupBtn");


	m_pLastBtn = new QQStylePushButton(":/ColumnIcon/Resources/icon_last_normal.png",
		":/ColumnIcon/Resources/icon_last_hover.png",
		":/ColumnIcon/Resources/icon_last_normal_msg.png",
		"回话",
		this);
	m_pLastBtn->setObjectName("lastBtn");

	m_tabBarGroup = new QButtonGroup();
	m_tabBarGroup->addButton(m_pContractBtn);
	m_tabBarGroup->addButton(m_pGroupBtn);
	m_tabBarGroup->addButton(m_pLastBtn);

	m_pContractBtn->setCheckable(true);
	m_pContractBtn->setChecked(true);

	m_pGroupBtn->setCheckable(true);
	m_pLastBtn->setCheckable(true);


	m_pContractBtn->setFlat(true);
	m_pGroupBtn->setFlat(true);
	m_pLastBtn->setFlat(true);

	QMenu *pMenu = new QMenu(m_pLastBtn);
	m_pLastBtn->setMenu(pMenu);
	pMenu->addAction("漫游回话列表");
	pMenu->addAction("清空回话列表");

	m_pHBoxLayout->addWidget(m_pContractBtn);
	m_pHBoxLayout->addWidget(m_pGroupBtn);
	m_pHBoxLayout->addWidget(m_pLastBtn);

	setLayout(m_pHBoxLayout);

//  	m_StackedWidget = new QStackedWidget;
// 
// 	m_MainLayout = new QVBoxLayout(this);
// 
// 	m_MainLayout->addLayout(m_pHBoxLayout);
// 	m_MainLayout->addWidget(m_StackedWidget);
// 
// 	m_MainLayout->addStretch(1);
// 
// 	m_StackedWidget->addWidget(new QLabel("聊天窗口"));
// 	m_StackedWidget->addWidget(new QLabel("回话窗口"));
// 	m_StackedWidget->addWidget(new QLabel("群组窗口"));
// 
// 	m_StackedWidget->setCurrentIndex(0);
// 
// 	QObject::connect(m_pContractBtn,SIGNAL(pressed()),m_StackedWidget,SLOT(setCurrentIndex(0)));
// 
// 	QObject::connect(m_pContractBtn,SIGNAL(pressed()),m_StackedWidget,SLOT(setCurrentIndex(1)));
// 	QObject::connect(m_pContractBtn,SIGNAL(pressed()),m_StackedWidget,SLOT(setCurrentIndex(2)));

}

ColumnWidget::~ColumnWidget()
{

}
