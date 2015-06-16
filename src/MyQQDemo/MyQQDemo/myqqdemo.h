#ifndef MYQQDEMO_H
#define MYQQDEMO_H

#include <QtGui/QFrame>
class TitleBar;
class ColumnWidget;
class ToolWidget;
class QSystemTrayIcon;

class MyQQDemo : public QFrame
{
	Q_OBJECT

public:
	MyQQDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyQQDemo();

private:
	TitleBar *m_pTitleBar;

	ColumnWidget *m_pColumnWidget;

	ToolWidget *m_pToolWidget;

	QSystemTrayIcon *m_pSytemTrayIcon;

};

#endif // MYQQDEMO_H
