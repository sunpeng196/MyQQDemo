#include "userinfowidget2.h"
#include <QMenu>

UserInfoWidget2::UserInfoWidget2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.lineEdit->setAttribute(Qt::WA_TranslucentBackground, true);  


	QMenu *pMenu = new QMenu((QWidget*)(this->parent()));
	pMenu->setFixedWidth(160);
	pMenu->addAction(tr("我在线上"));
	pMenu->addAction(tr("Q我吧"));
	pMenu->addAction(tr("离开"));
	pMenu->addAction(tr("忙碌"));
	pMenu->addAction(tr("请勿打扰"));
	pMenu->addAction(tr("隐身"));

	pMenu->addAction(tr("离线"));
	pMenu->addAction(tr("添加状态信息"));

	pMenu->addSeparator();
	pMenu->addAction(tr("关闭所有声音"));

	pMenu->addAction(tr("关闭头像闪动"));
	pMenu->addAction(tr("添加状态信息"));
	pMenu->addAction(tr("锁定QQ Ctrl +Alt + L"));

	pMenu->addSeparator();

	pMenu->addAction(tr("系统设置"));
	pMenu->addAction(tr("我的质料"));
	pMenu->addAction(tr("我的QQ中心"));
	ui.toolButton->setMenu(pMenu);
	ui.toolButton->setPopupMode(QToolButton::InstantPopup);
}

UserInfoWidget2::~UserInfoWidget2()
{

}
