#include "appwidget2.h"
#include "QMenu"

AppWidget2::AppWidget2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QMenu *pMenu = new QMenu((QWidget*)(this->parent()));
	pMenu->addAction(tr("传文件到手机"));
	pMenu->addAction(tr("导出手机相册"));
	pMenu->addAction(tr("我的收藏"));

	pMenu->addAction(tr("所有服务"));
	pMenu->addAction(tr("QQ会员"));
	pMenu->addAction(tr("工具"));

	pMenu->addAction(tr("安全"));
	pMenu->addAction(tr("帮助"));
	pMenu->addAction(tr("工具"));
	pMenu->addAction(tr("软件升级"));
	pMenu->setFixedWidth(212);
	ui.toolButton->setMenu(pMenu);
	ui.toolButton->setPopupMode(QToolButton::InstantPopup);

	setAutoFillBackground(true);


	QPalette palette;
	setAutoFillBackground(true);
	QBrush brush(QColor(233,221,213));
	palette.setBrush(this->backgroundRole(),brush);
	this->setPalette(palette);
}

AppWidget2::~AppWidget2()
{

}
