#include "qfriendlistdelegate.h"
#include "FriendGroupInfo.h"
#include "FriendInfo.h"
#include <QPainter>
#include <QTreeView>

QFriendListDelegate::QFriendListDelegate(QObject *parent)
	: QItemDelegate(parent)
{

}

QFriendListDelegate::~QFriendListDelegate()
{

}

void QFriendListDelegate::paint( QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	QRect rect = option.rect;

	FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
	FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());
	if (pGroupInfo)
	{
		QString str;
		if (pGroupInfo->HasMessageArrive())
		{
			if (pGroupInfo->m_bShowM||((QTreeView*)(this->parent()))->isExpanded(index))
			{
				QString strGroupName = pGroupInfo->m_GroupInfoName;
				int iOnLineNumber = pGroupInfo->GetOnLineNumber();
				int iAllNumber = pGroupInfo->m_FriendInfoList.count();

				str = QString("%1 %2/%3").arg(strGroupName).arg(iOnLineNumber).arg(iAllNumber);
			}

			pGroupInfo->m_bShowM = !(pGroupInfo->m_bShowM);
		
		}
		else
		{
			QString strGroupName = pGroupInfo->m_GroupInfoName;
			int iOnLineNumber = pGroupInfo->GetOnLineNumber();
			int iAllNumber = pGroupInfo->m_FriendInfoList.count();
			str = QString("%1 %2/%3").arg(strGroupName).arg(iOnLineNumber).arg(iAllNumber);
		}

		painter->drawText(rect.left()+2 + 16,rect.top()+2,100,30,0,str);


	}
	if (pInfo)
	{
		if (option.state & QStyle::State_MouseOver)
		{
			painter->drawPixmap(option.rect,QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));
		}

		if (option.state & QStyle::State_Selected)
		{
			painter->drawPixmap(option.rect,QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));
		}

		QString strNickName = pInfo->m_Markname;
		QString headerPath = QString(":/headers/Resources/headers/%1.png").arg((pInfo->m_iFaceIndex)%264 + 1);

		QIcon icon;
		QImage image(headerPath);
		if (!image.isNull())
		{
			if ((pInfo->m_status == "away")||(pInfo->m_status == "online")||(pInfo->m_status == "busy"))
			{
				 icon.addPixmap(QPixmap::fromImage(image),QIcon::Normal, QIcon::Off);
			}
			else
			{
				 icon.addPixmap(QPixmap::fromImage(image), QIcon::Disabled,QIcon::Off);
			}
		}

		QRect headerImg(rect);
		headerImg.setWidth(image.width());
		headerImg.setHeight(image.height());
		headerImg.setLeft(rect.left()+2);
		headerImg.setTop(rect.top()+2);

		QPoint pts[] = {QPoint(-1,1),QPoint(0,0),QPoint(1,1),QPoint(0,0)};

		if (pInfo->m_bMessageArrive)
		{
			headerImg.translate(pts[pInfo->m_iHeaderFlashIndex++]);
			if (pInfo->m_iHeaderFlashIndex >= 4)
			{
				pInfo->m_iHeaderFlashIndex = 0;
			}

		}


		QPixmap pixmap = icon.pixmap(QSize(image.width(),image.height()),QIcon::Disabled, QIcon::Off);

		painter->drawPixmap(headerImg,pixmap);

		QString strShow = QString("%1 (%2)").arg(pInfo->m_Markname).arg(pInfo->m_nickName);
		painter->drawText(rect.left()+2+48,rect.top()+2,300,30,0,strShow);

	}

}

QSize QFriendListDelegate::sizeHint( const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
	if (pGroupInfo)
	{
		return QSize(300,20);
	}

	FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());
	if (pInfo)
	{
		return QSize(300,50);
	}

	return QSize(0,0);
}
