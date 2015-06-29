#include "stylewidget.h"
#include <QMouseEvent>
#include <QDesktopWidget>

StyleWidget::StyleWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_iStartTimer = 0;

	this->setFixedHeight(380);
	this->setWindowFlags(Qt::FramelessWindowHint);
}

StyleWidget::~StyleWidget()
{

}

void StyleWidget::mousePressEvent( QMouseEvent *e )
{
	QPoint pt = this->pos();

	int iWidth = QApplication::desktop()->width();
	int iHeight = QApplication::desktop()->height();

	//if (pt.y() <= 20)
	{
		m_iStartTimer = startTimer(10);		
	}


}

void StyleWidget::timerEvent( QTimerEvent * e )
{
	QPoint pt = this->pos();

	int iStep = (pt.y()+ this->height() - 8)/7;

	if (pt.y() + this->height() >= 8)
	{
		int y = pt.y() - iStep;
		this->move(pt.x(),y);
	}
	else
	{
		int y = pt.y();
		int height = this->height();
		killTimer(m_iStartTimer);
	}
}
