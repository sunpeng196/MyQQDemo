#include "qfriendlistmodel.h"
#include "QJson/Parser"
#include <QDebug>
#include "FriendGroupInfo.h"
#include "FriendInfo.h"
#include <QTimer>

QFriendListModel::QFriendListModel(QObject *parent)
	: QAbstractItemModel(parent)
{
	m_pTimer = new QTimer(this);
	m_pTimer->setInterval(200);
	m_pTimer->stop();
}

QFriendListModel::~QFriendListModel()
{

}

void QFriendListModel::ParserContentFromString(QByteArray& strContent )
{
	QJson::Parser parser;
	bool ok;
	QVariant all = parser.parse (strContent, &ok);

	int iRetCode = all.toMap()["retcode"].toInt();
	if (iRetCode == 0)
	{
		QVariant content = all.toMap()["result"].toMap()["categories"];
		QList<QVariant> categories = content.toList();
		int iCount = categories.count();
		m_GroupList.resize(categories.count()+1);

		FriendGroupInfo *pNewFriendGroup = new FriendGroupInfo();
		pNewFriendGroup->m_GroupInfoName = tr("我的好友");
		m_GroupList[0] = pNewFriendGroup;

		foreach(QVariant var,categories)
		{
			QVariantMap tempMap = var.toMap();
			int iIndex = tempMap["index"].toInt();
			int iSort = tempMap["sort"].toInt();
			QString strName = tempMap["name"].toString();

			FriendGroupInfo *pNewFriendGroup = new FriendGroupInfo();
			pNewFriendGroup->m_GroupInfoName = strName;

			m_GroupList[iIndex] = pNewFriendGroup;

		}
		QList<QVariant> friendList = all.toMap()["result"].toMap()["friends"].toList();
		foreach(QVariant var,friendList)
		{
			QVariantMap temp = var.toMap();
			int iCategories = temp["categories"].toInt();
			qint64 uin = temp["uin"].toULongLong();

			FriendInfo *pFriendInfo = new FriendInfo();
			pFriendInfo->m_uin = uin;
			pFriendInfo->m_Cate = iCategories;

			m_GroupList[iCategories]->AddFriendFriendList(pFriendInfo);
		}

		QList<QVariant> markNames = all.toMap()["result"].toMap()["marknames"].toList();
		foreach(QVariant var,markNames)
		{
			QVariantMap temp = var.toMap();
			qint64 uin = temp["uin"].toULongLong();
			QString marName = temp["markname"].toString();
			int iType = temp["type"].toInt();

			FriendInfo *pInfo = GetFriendInfo(uin);
			if (pInfo)
			{
				pInfo->m_Markname = marName;
				pInfo->m_iType = iType;

			}
		}


		QList<QVariant> infos = all.toMap()["result"].toMap()["info"].toList();
		foreach(QVariant var,infos)
		{
			QVariantMap temp = var.toMap();
			int iFaceIndex = temp["face"].toInt();
			QString nickName = temp["nick"].toString();
			qint64 uin = temp["uin"].toULongLong();

			FriendInfo *pInfo = GetFriendInfo(uin);
			if (pInfo)
			{
				pInfo->m_nickName = nickName;
				pInfo->m_iFaceIndex = iFaceIndex;

			}
		}
	}

}

QModelIndex QFriendListModel::index( int row, int column, const QModelIndex & parent /*= QModelIndex() */ ) const
{
	if (!parent.isValid())//表明是根节点
	{
		FriendGroupInfo *pGroupInfo = m_GroupList.at(row);
		return createIndex(row,column,pGroupInfo);
	}
	else
	{
		FriendGroupInfo *pGroupInfo = (FriendGroupInfo*)parent.internalPointer();
		FriendInfo *pFriendInfo = pGroupInfo->m_FriendInfoList.at(row);

		return createIndex(row,column,pFriendInfo);
	}
}

QModelIndex QFriendListModel::parent( const QModelIndex & index ) const
{
	if (!index.isValid())//非法的。
	{
		return QModelIndex();
	}

	FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
	if (pGroupInfo)
	{
		return QModelIndex();
	}

	FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());
	int iIndex = pInfo->m_Cate;

	FriendGroupInfo *pTemp = m_GroupList[iIndex];
	return createIndex(iIndex,0,pTemp);

		

}

int QFriendListModel::rowCount( const QModelIndex & parent /*= QModelIndex() */ ) const
{
	if (!parent.isValid())
	{
		return m_GroupList.count();//返回的是分组的个数
	}
	else
	{
		FriendGroupInfo *pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)parent.internalPointer());
		if (pGroupInfo)
		{
			return pGroupInfo->m_FriendInfoList.count();			
		}
		else
		{
			return 0;
		}

	}
}

int QFriendListModel::columnCount( const QModelIndex & parent /*= QModelIndex() */ ) const
{
	return 1;
}

QVariant QFriendListModel::data( const QModelIndex & index, int role /*= Qt::DisplayRole */ ) const
{
	if (!index.isValid())
		return QVariant();

	if (role == Qt::DisplayRole)
	{
		FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
		if (pGroupInfo)
		{
			return pGroupInfo->m_GroupInfoName;
		}

		FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());
		if (pInfo)
		{
			return pInfo->m_uin;
		}
	}

	return QVariant();
}

FriendInfo * QFriendListModel::GetFriendInfo( qint64 uin )
{
	FriendInfo *pInfo = 0;
	foreach(FriendGroupInfo *groupInfo,m_GroupList)
	{
		foreach(FriendInfo *info,groupInfo->m_FriendInfoList)
		{
			if (info->m_uin == uin)
			{
				pInfo = info;
				break;
			}
		}

	}

	return pInfo;

}

void QFriendListModel::ParserOnlineClient( QByteArray& strContent )
{
	QJson::Parser parser;
	bool ok;
	QVariant all = parser.parse (strContent, &ok);

	int iRetCode = all.toMap()["retcode"].toInt();
	if (iRetCode == 0)
	{
		QList<QVariant> result = all.toMap()["result"].toList();
		foreach(QVariant var,result)
		{
			QVariantMap temp = var.toMap();
			qint64 uin = temp["uin"].toULongLong();
			QString status = temp["status"].toString();
			int iType = temp["client_type"].toInt();

			FriendInfo *pFriendInfo = GetFriendInfo(uin);
			pFriendInfo->m_iType = iType;
			pFriendInfo->m_status = status;

		}
	}

}

void QFriendListModel::SetMessageArrive( quint64 uin )
{
	int iGroupIndex = 0;
	int iFriendIndex = 0;
	foreach(FriendGroupInfo* pGroupInfo,m_GroupList)
	{
		foreach(FriendInfo* pInfo,pGroupInfo->m_FriendInfoList)
		{
			if (pInfo->m_uin == uin)
			{
				pInfo->m_bMessageArrive = true;
				QObject::connect(m_pTimer,SIGNAL(timeout()),
					this,
					SLOT(Slash()));

				QModelIndex parent = index(iGroupIndex,0,QModelIndex());
				QModelIndex curIndex = index(iFriendIndex,0,parent);

				FriendInfo *pInfo = (FriendInfo*)curIndex.internalPointer();

				m_List.append(parent);
				m_List.append(curIndex);

				m_pTimer->start();


				return;
			}
			++iFriendIndex;
		}
		iFriendIndex = 0;
		++iGroupIndex;
	}
}

void QFriendListModel::Slash()
{
	foreach(QModelIndex index,m_List)
	{
		emit dataChanged(index,index);
	}

}
