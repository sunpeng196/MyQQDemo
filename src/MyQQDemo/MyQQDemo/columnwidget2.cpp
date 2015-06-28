#include "columnwidget2.h"
#include <QPushButton>

ColumnWidget2::ColumnWidget2(QWidget *parent)
	: QWidget(parent)
{
	m_pContractBtn = new QPushButton(this);
	m_pContractBtn->setObjectName("pushBtnContract");

}

ColumnWidget2::~ColumnWidget2()
{

}
