#include "friendlistview.h"
#include <QMouseEvent>
#include "FriendGroupInfo.h"
#include "FriendInfo.h"
#include <QMenu>

FriendListView::FriendListView(QWidget *parent)
	: QTreeView(parent)
{

}

FriendListView::~FriendListView()
{

}

void FriendListView::mouseDoubleClickEvent( QMouseEvent *event )
{
	QPoint pt = event->pos();

	QModelIndex index = indexAt(pt);

	FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
	FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());
	if (pGroupInfo)
	{
		if (isExpanded(index))
		{
			setExpanded(index,false);
		}
		else
		{
			setExpanded(index,true);
		}
		
	}

	if (pInfo)
	{
	}


}

void FriendListView::mousePressEvent( QMouseEvent *event )
{
	if (event->button() == Qt::RightButton)
	{
		QModelIndex index = indexAt(event->pos());
		FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
		FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());
		if (pGroupInfo)
		{
			return;
		}
		QMenu menu;
		menu.setFixedWidth(150);
		menu.addAction(tr("发送即时消息"));
		menu.addAction(tr("发送电子邮件"));
		menu.addSeparator();
		menu.addAction(tr("查看资料"));
		menu.addAction(tr("消息记录"));
		menu.addSeparator();
		menu.addAction(tr("设置权限"));
		menu.addAction(tr("修改备注姓名"));
		menu.addAction(tr("移动联系人至"));
		menu.addAction(tr("删除好友"));
		menu.addAction(tr("举报此用户"));
		menu.addAction(tr("好友管理"));
		menu.addSeparator();
		menu.addAction(tr("会员快捷功能"));
		menu.addAction(tr("进入QQ空间"));
		menu.exec(mapToGlobal(event->pos()));

	}

}
