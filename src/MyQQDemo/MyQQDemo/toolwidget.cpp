#include "toolwidget.h"
#include <QToolButton>
#include <QBoxLayout>

ToolWidget::ToolWidget(QWidget *parent)
	: QWidget(parent)
{
	setFixedHeight(32);
	m_pHBoxLayout = new QHBoxLayout(this);
	setLayout(m_pHBoxLayout);

	m_pMainMenuButton = new QToolButton();
	m_pMainMenuButton->setObjectName("toolBtnMainMenu");
	m_pMainMenuButton->setAutoRaise(true);
	m_pMainMenuButton->setFixedSize(32,32);

	m_pMainMenuButton->setIconSize(QSize(24,24));

	m_pHBoxLayout->addWidget(m_pMainMenuButton);

}

ToolWidget::~ToolWidget()
{

}
