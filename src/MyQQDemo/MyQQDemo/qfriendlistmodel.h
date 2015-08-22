#ifndef QFRIENDLISTMODEL_H
#define QFRIENDLISTMODEL_H

#include <QAbstractItemModel>
#include <QVector>
#include <QModelIndexList>
#include <QTimer>

class FriendGroupInfo;
class FriendInfo;

class QFriendListModel:public QAbstractItemModel
{
	Q_OBJECT

public:
	QFriendListModel(QObject *parent);
	~QFriendListModel();

	 QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex() ) const;

	 QModelIndex parent ( const QModelIndex & index ) const;

	 int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
	 int columnCount ( const QModelIndex & parent = QModelIndex() ) const;

	FriendInfo *GetFriendInfo(qint64 uin);

	void SetMessageArrive(quint64 uin);


	 QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;


	void ParserContentFromString(QByteArray& strContent);

	void ParserOnlineClient(QByteArray& strContent);

	public slots:
		void Slash();

private:
	QVector<FriendGroupInfo*> m_GroupList;
	QModelIndexList m_List;
	QTimer *m_pTimer;
	
};

#endif // QFRIENDLISTMODEL_H
