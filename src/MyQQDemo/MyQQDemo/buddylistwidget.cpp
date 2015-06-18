#include "buddylistwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QString>

BuddyListWidget::BuddyListWidget(QWidget *parent)
	: QWidget(parent)
{
	QPalette palette;
	setAutoFillBackground(true);
	QBrush brush(QPixmap(":/MyQQDemo/Resources/Bg.png"));
	palette.setBrush(this->backgroundRole(),brush);
	this->setPalette(palette);

	InitList();

	setMouseTracking(true);

	m_iCurrentSelectd = -1;

}

BuddyListWidget::~BuddyListWidget()
{

}

void BuddyListWidget::paintEvent( QPaintEvent *e )
{
	QPainter painter(this);
	//painter.drawPixmap(2,2,40,40,QPixmap(":/headers/Resources/93.png"));

// 	painter.drawPixmap(4,6,14,14,QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexture.png"));
// 	painter.drawText(22,6,254,24,0,"我的好友[12/24]");

	for (int i = 0;i < m_BuddyList.size();++i)
	{
		BuddyTeam *const pItem = m_BuddyList.at(i);

		QRect s = GetRectByIndex(i);
		if (pItem->Expand())
		{
			painter.drawPixmap(s.left()+4, s.top()+6,14,14,QPixmap(":/MainPanel/Resources/mainpanel_foldernode_expandtexture.png"));
		}
		else
		{
			painter.drawPixmap(s.left()+4, s.top()+6,14,14,QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexture.png"));
		}
		painter.drawText(s.left()+22,s.top()+6,254,24,0,pItem->GetDesc());

	}

	if (m_iCurrentSelectd != -1)
	{
		QRect s = GetRectByIndex(m_iCurrentSelectd);
		painter.drawPixmap(s.left(),s.top(),s.width(),s.height(),QPixmap(":/MainPanel/Resources/mainpanel/main_group_highlight.png"));

	}

}

void BuddyListWidget::InitList()
{
	BuddyTeam *pUserList = new BuddyTeam("我的好友",48,12);
	m_BuddyList.append(pUserList);

	pUserList = new BuddyTeam("同事",48,12);
	m_BuddyList.append(pUserList);

	pUserList = new BuddyTeam("同学",48,12);
	m_BuddyList.append(pUserList);

}

void BuddyListWidget::mousePressEvent( QMouseEvent *e )
{
	if (e->buttons() == Qt::LeftButton)
	{
		QPoint t = e->pos();

		int iIndex = GetIndexFromPoint(t);

		BuddyTeam *const pItem = m_BuddyList.at(iIndex);
		pItem->setExpand(!pItem->Expand());
		update();

		
	}

}

void BuddyListWidget::mouseReleaseEvent( QMouseEvent *e )
{


}

void BuddyListWidget::mouseMoveEvent( QMouseEvent *e )
{
	QPoint t = e->pos();
	int iIndex = GetIndexFromPoint(t);

	m_iCurrentSelectd = iIndex;


	update();
}

QRect BuddyListWidget::GetRectByIndex( int iIndex )
{
	int yPoint = 0 + 24*iIndex;

	return QRect(0,yPoint,268,24);
}

int BuddyListWidget::GetIndexFromPoint( const QPoint& pt )
{
	int y = pt.y();

	return y/24;

}
