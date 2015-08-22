#ifndef CHATSESSIONLISTDELEGATE_H
#define CHATSESSIONLISTDELEGATE_H

#include <QAbstractItemDelegate>

class ChatSessionListDelegate : public QAbstractItemDelegate
{
	Q_OBJECT

public:
	ChatSessionListDelegate(QObject *parent);
	~ChatSessionListDelegate();

	void paint(QPainter *painter, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	QSize sizeHint(const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

private:
	
};

#endif // CHATSESSIONLISTDELEGATE_H
