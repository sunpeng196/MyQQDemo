#ifndef FRIENDLISTVIEW_H
#define FRIENDLISTVIEW_H

#include <QTreeView>

class FriendListView : public QTreeView
{
	Q_OBJECT

public:
	FriendListView(QWidget *parent);
	~FriendListView();

	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);

private:
	
};

#endif // FRIENDLISTVIEW_H
