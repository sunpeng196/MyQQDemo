#ifndef BUDDYLISTWIDGET_H
#define BUDDYLISTWIDGET_H

#include <QWidget>
#include <QList>
#include "BuddyTeam.h"
#include <QRect>
#include <QScrollArea>
class QScrollBar;


class BuddyListWidget : public QWidget
{
	Q_OBJECT

public:
	BuddyListWidget(QWidget *parent);
	~BuddyListWidget();

	void paintEvent(QPaintEvent *e);

	void showEvent(QShowEvent * e);

	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);

	void wheelEvent ( QWheelEvent * event );

	void mouseLeaveEvent(QMouseEvent *e);


	void InitList();

	QRect GetRectByIndex(int iIndex,int iSubIndex);

/*	int GetIndexFromPoint(const QPoint& pt);*/

	void AddBuddyItem(int iGroupIndex);

	bool GetItemRectByIndex( int nTeamIndex,int nIndex,QRect &rect);
	void HitTest(QPoint pt, int& nTeamIndex, int& nIndex);
	void DrawBuddyTeam(int nIndex);
	void CalcCenterRect(const QRect& rcDest, int cx, int cy, QRect& rcCenter );
	void DrawBuddyItemInBigIcon(int nTeamIndex, int nIndex);
	BuddyItem * GetBuddyItemByIndex(int nTeamIndex, int nIndex);
	void Scroll();
private:

/*	 bool eventFilter(QObject *, QEvent *);*/

	QList<BuddyTeam*> m_BuddyList;

	int m_iCurrentSelectd;


	int m_nHoverTeamIndex, m_nHoverIndex;

	int m_nPressTeamIndex, m_nPressIndex;

	int m_nSelTeamIndex;

	int m_nSelIndex;

	int m_VecScroll;

	int m_nLeft, m_nTop;

	QScrollBar *m_pScrollBar;

	bool m_bScrollButtonDown;
	QPoint m_LastPt;

	int GetContentHeight();


	public slots:
		void ScrollBarValueChanged(int value);

	
};

#endif // BUDDYLISTWIDGET_H
