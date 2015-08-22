#include "qrecentsessionmodel.h"
#include "QJson/parser"
#include "RecentChat.h"

QRecentSessionModel::QRecentSessionModel(QObject *parent)
	: QAbstractListModel(parent)
{

}

QRecentSessionModel::~QRecentSessionModel()
{

}

void QRecentSessionModel::AppendSession( quint64 uin,int iType )
{
	RecentChat *pChat = new RecentChat();
	pChat->m_iType = iType;
	pChat->m_uin = uin;

	m_RecentList.append(pChat);
}

void QRecentSessionModel::ParserContent( QByteArray &content )
{
	QJson::Parser parser;
	bool ok;
	QVariant all = parser.parse (content, &ok);
	int iRetCode = all.toMap()["retcode"].toInt();
	if (iRetCode == 0)
	{
		QList<QVariant> result = all.toMap()["result"].toList();
		foreach(QVariant var,result)
		{
			QVariantMap temp = var.toMap();
			quint64 uin = temp["uin"].toULongLong();
			int iType = temp["type"].toInt();
			AppendSession(uin,iType);
		}
	}

}

int QRecentSessionModel::rowCount( const QModelIndex & parent /*= QModelIndex() */ ) const
{
	return m_RecentList.count();
}

int QRecentSessionModel::columnCount( const QModelIndex & parent /*= QModelIndex() */ ) const
{
	return 1;
}

QVariant QRecentSessionModel::data( const QModelIndex & index, int role /*= Qt::DisplayRole */ ) const
{
	if (!index.isValid())
	{
		return QVariant();
	}
	if (role == Qt::DisplayRole)
	{
		return QVariant("asdfasfasdf");
	}

	return QVariant();

}

QModelIndex QRecentSessionModel::index( int row, int column, const QModelIndex & parent /*= QModelIndex() */ ) const
{
	if (!parent.isValid())//表明是父节点
	{
		return createIndex(row,0,m_RecentList.at(row));
	}

	return QModelIndex();
}
