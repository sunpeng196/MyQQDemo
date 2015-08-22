#ifndef QFRIENDLISTDELEGATE_H
#define QFRIENDLISTDELEGATE_H

#include <QItemDelegate>

class QFriendListDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	QFriendListDelegate(QObject *parent);
	~QFriendListDelegate();

	void paint(QPainter *painter, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	QSize sizeHint(const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

private:
	
};

#endif // QFRIENDLISTDELEGATE_H
