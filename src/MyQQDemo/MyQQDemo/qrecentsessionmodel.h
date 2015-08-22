#ifndef QRECENTSESSIONMODEL_H
#define QRECENTSESSIONMODEL_H

#include <QAbstractListModel>

class RecentChat;

class QRecentSessionModel : public QAbstractListModel
{
	Q_OBJECT

public:
	QRecentSessionModel(QObject *parent);
	~QRecentSessionModel();
	void AppendSession(quint64 uin,int iType);
	void ParserContent(QByteArray &content);



	QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex() ) const;

	int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
	int columnCount ( const QModelIndex & parent = QModelIndex() ) const;

	QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

private:

	QList<RecentChat*> m_RecentList;
	
};

#endif // QRECENTSESSIONMODEL_H
