#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QBoxLayout>
#include <QToolButton>
#include <QLabel>
#include <QPoint>

class TitleBar : public QWidget
{
	Q_OBJECT

public:
	TitleBar(QWidget *parent);
	~TitleBar();

	void mousePressEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);

private:

	QLabel *m_pQQLabelIcon;

	QLabel *m_pQQLableTitle;

	QToolButton *m_pMinButton;
	QToolButton *m_pCloseButton;


	QHBoxLayout *m_hBoxLayout;

	QPoint m_ptMove;
	QPoint m_ptPrev;

	bool m_bLeftPressDown;
	
};

#endif // TITLEBAR_H
