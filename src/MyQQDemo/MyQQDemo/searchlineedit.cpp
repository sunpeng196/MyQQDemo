#include "searchlineedit.h"
#include <QLabel>
#include <QtGui/QMouseEvent>
#include <QPainter>

SearchLineEdit::SearchLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	setAttribute(Qt::WA_TranslucentBackground);
	setStyleSheet("background: transparent;border:none;");
	
// 	m_pSerachPixMap = new QLabel(this);
// 	m_pSerachPixMap->setStyleSheet("border-width:0px");
// 	m_pSerachPixMap->setPixmap(QPixmap(":/SearchLineEdit/Resources/finger_normal.png"));
// 	m_pSerachPixMap->setAttribute(Qt::WA_TranslucentBackground);

	m_bFocusIn = false;
}

SearchLineEdit::~SearchLineEdit()
{

}

// void SearchLineEdit::paintEvent( QPaintEvent * e )
// {
// // 	m_pSerachPixMap->setGeometry(width()- QPixmap(":/SearchLineEdit/Resources/finger_normal.png").width(),
// // 		6,
// // 		QPixmap(":/SearchLineEdit/Resources/finger_normal.png").width(),
// // 		QPixmap(":/SearchLineEdit/Resources/finger_normal.png").height());
// // 
// // 	return QLineEdit::paintEvent(e);
// 	QPainter painter(this);
// 	if (!m_bFocusIn)
// 	{	
// 		painter.drawPixmap(rect(),QPixmap(":/Search/Resources/main_search_bkg.png"));
// 	}
// 	else
// 	{
// 		painter.drawPixmap(rect(),QPixmap(":/Search/Resources/mainSearch/main_search_frame.png"));
// 		QRect rc(rect().width()-30,8,16,16);
// 		painter.drawPixmap(rc,QPixmap(":/Search/Resources/mainSearch/main_search_deldown.png"));
// 		for (int i = 1;i<6;++i)
// 		{
// 			QRect tempRect(rect().left(),rect().top() + i * 30,270,30);
// 			painter.drawPixmap(tempRect,QPixmap(":/Search/Resources/mainSearch/main_search_frame.png"));
// 			painter.drawText(tempRect,"江南大学公社(347744583)");
// 		}
// 
// 	}
// 
// 	return QLineEdit::paintEvent(e);
// 
// 
// }

void SearchLineEdit::mousePressEvent( QMouseEvent *e )
{
	m_bFocusIn = true;
	update();
}

void SearchLineEdit::focusInEvent( QFocusEvent * e )
{
	if (!e->gotFocus())
	{
		m_bFocusIn = false;
		update();
	}

}

void SearchLineEdit::leaveEvent( QEvent * e )
{
	m_bFocusIn = false;
	update();
}
