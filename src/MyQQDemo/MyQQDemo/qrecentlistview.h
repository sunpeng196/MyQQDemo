#ifndef QRECENTLISTVIEW_H
#define QRECENTLISTVIEW_H

#include <QListView>

class QRecentListView : public QListView
{
	Q_OBJECT

public:
	QRecentListView(QWidget *parent);
	~QRecentListView();

private:
	
};

#endif // QRECENTLISTVIEW_H
