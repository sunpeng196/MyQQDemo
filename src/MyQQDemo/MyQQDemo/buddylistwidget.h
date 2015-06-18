#ifndef BUDDYLISTWIDGET_H
#define BUDDYLISTWIDGET_H

#include <QWidget>
#include <QList>
#include "BuddyTeam.h"
#include <QRect>

class BuddyListWidget : public QWidget
{
	Q_OBJECT

public:
	BuddyListWidget(QWidget *parent);
	~BuddyListWidget();

	void paintEvent(QPaintEvent *e);

	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);


	void InitList();

	QRect GetRectByIndex(int iIndex);

	int GetIndexFromPoint(const QPoint& pt);

private:



	QList<BuddyTeam*> m_BuddyList;

	int m_iCurrentSelectd;

	
};

#endif // BUDDYLISTWIDGET_H
