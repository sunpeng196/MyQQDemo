#include "columnwidget.h"
#include <QPushButton>
#include <QButtonGroup>

ColumnWidget::ColumnWidget(QWidget *parent)
	: QWidget(parent)
{
	setFixedHeight(32);
	setFixedWidth(260);

	setAutoFillBackground(true);

	QPalette palette;
	palette.setColor(QPalette::Background, QColor(192,253,123));
	palette.setBrush(QPalette::Background, QBrush(QPixmap(":/MainTab/Resources/main_tabctrl_background.png")));
	this->setPalette(palette);


	setObjectName("columnWidget");

	setStyleSheet("QPushButton{border:0px;background-image: url(:/MainTab/Resources/main_tab_check.png)}");

	m_pHBoxLayout = new QHBoxLayout(this);
	m_pHBoxLayout->setSpacing(0);
	m_pHBoxLayout->setContentsMargins(0,0,0,0);

	setLayout(m_pHBoxLayout);

	m_pContractBtn = new QPushButton();
	m_pContractBtn->setObjectName("pushBtnContract");

	m_pGroupBtn = new QPushButton();
	m_pGroupBtn->setObjectName("groupBtn");

	QIcon icon14;
	icon14.addFile(QString::fromUtf8(":/ColumnIcon/Resources/icon_group_normal.png"), QSize(), QIcon::Normal, QIcon::On);
	icon14.addFile(QString::fromUtf8(":/ColumnIcon/Resources/icon_group_selected_Blue.png"), QSize(), QIcon::Selected, QIcon::On);
	icon14.addFile(QString::fromUtf8(":/ColumnIcon/Resources/icon_group_hover.png"), QSize(), QIcon::Active, QIcon::On);
	icon14.addFile(QString::fromUtf8(":/ColumnIcon/Resources/icon_group_selected.png"), QSize(), QIcon::Disabled, QIcon::On);



	m_pGroupBtn->setIcon(icon14);





	m_pLastBtn = new QPushButton();
	m_pLastBtn->setObjectName("lastBtn");

	m_tabBarGroup = new QButtonGroup();
	m_tabBarGroup->addButton(m_pContractBtn);
	m_tabBarGroup->addButton(m_pGroupBtn);
	m_tabBarGroup->addButton(m_pLastBtn);

	m_pContractBtn->setCheckable(true);
	m_pContractBtn->setChecked(true);

	m_pGroupBtn->setCheckable(true);
	m_pLastBtn->setCheckable(true);


// 	m_pContractBtn->setFlat(true);
// 	m_pGroupBtn->setFlat(true);
// 	m_pLastBtn->setFlat(true);

	m_pHBoxLayout->addWidget(m_pContractBtn);
	m_pHBoxLayout->addWidget(m_pGroupBtn);
	m_pHBoxLayout->addWidget(m_pLastBtn);


}

ColumnWidget::~ColumnWidget()
{

}
