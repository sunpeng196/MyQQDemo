#ifndef MYQQDEMO_H
#define MYQQDEMO_H

#include <QtGui/QFrame>
#include "appwidget.h"
class TitleBar;
class ColumnWidget;
class ToolWidget;
class QSystemTrayIcon;
class SearchLineEdit;
class BuddyListWidget;

class MyQQDemo : public QFrame
{
	Q_OBJECT

public:
	MyQQDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyQQDemo();

	void mousePressEvent(QMouseEvent * e);
	void mouseMoveEvent(QMouseEvent * e);
	void mouseReleaseEvent(QMouseEvent * e);


private:
	TitleBar *m_pTitleBar;

	ColumnWidget *m_pColumnWidget;

/*	ToolWidget *m_pToolWidget;*/

	QSystemTrayIcon *m_pSytemTrayIcon;

	SearchLineEdit *m_pSearchLineEdit;

	BuddyListWidget *m_pBuddyList;


	AppWidget *m_pAppWidget;



	

};

#endif // MYQQDEMO_H
