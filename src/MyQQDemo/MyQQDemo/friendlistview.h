#ifndef FRIENDLISTVIEW_H
#define FRIENDLISTVIEW_H

#include <QTreeView>

class FriendInfoUI;

class FriendListView : public QTreeView
{
	Q_OBJECT

public:
	FriendListView(QWidget *parent);
	~FriendListView();

	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);

	void mouseMoveEvent(QMouseEvent *event);

	public slots:
	void CheckMousePosForShowMessage(QModelIndex index);

	signals:
		void mouseHoverIndexChanged(QModelIndex index);

private:

	FriendInfoUI *m_pWidget;
	QTimer *m_pTimeChecker;

	QModelIndex m_CurMouseHoverIndex;
	
};

#endif // FRIENDLISTVIEW_H
